#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <x86intrin.h>   // for __rdtsc() — reads CPU timestamp register directly

const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string BOLD   = "\033[1m";

// ─────────────────────────────────────────────────────────
// __rdtsc() reads the x86 TSC (Time Stamp Counter) register
// directly via the RDTSC instruction.
// This is a REAL hardware register — increments every CPU cycle.
// Available on WSL, no root needed.
// ─────────────────────────────────────────────────────────
inline uint64_t read_tsc() {
    _mm_lfence();        // memory fence — prevent instruction reorder
    uint64_t t = __rdtsc();
    _mm_lfence();
    return t;
}

std::vector<int> equal_work_chunks(int N, int COLS) {
    long long total          = (long long)N * (N - 1) / 2;
    long long target_per_col = total / COLS;

    std::vector<int> starts;
    starts.push_back(0);

    long long accum = 0;
    for (int i = 0; i < N; i++) {
        accum += (N - i - 1);
        if ((long long)starts.size() < COLS &&
            accum >= target_per_col * (long long)starts.size()) {
            starts.push_back(i + 1);
        }
    }
    starts.push_back(N);
    while ((int)starts.size() < COLS + 1)
        starts.push_back(N);

    return starts;
}

// ─────────────────────────────────────────────────────────
// Measure TSC cycles per chunk.
// Run the sorted array FIRST as the baseline — it gives
// the minimum possible cycles for each chunk (perfect
// branch prediction). Then compare unsorted against it.
// ─────────────────────────────────────────────────────────
std::vector<uint64_t> measure_tsc_chunks(const std::vector<int>& arr,
                                         const std::vector<int>& chunks,
                                         int COLS) {
    const int N = arr.size();
    volatile int sink = 0;
    std::vector<uint64_t> timings(COLS);

    for (int col = 0; col < COLS; col++) {
        int i_start = chunks[col];
        int i_end   = chunks[col + 1];

        uint64_t t0 = read_tsc();   // read hardware cycle counter

        int cnt = 0;
        for (int i = i_start; i < i_end; i++)
            for (int j = i + 1; j < N; j++)
                if (arr[i] < arr[j]) cnt++;

        uint64_t t1 = read_tsc();   // read hardware cycle counter again

        sink += cnt;
        timings[col] = t1 - t0;    // REAL CPU cycles elapsed
    }
    return timings;
}

void display(const std::string& name,
             const std::vector<uint64_t>& timings,      // this run
             const std::vector<uint64_t>& baseline,     // sorted run (ground truth)
             int COLS,
             double threshold) {

    std::cout << "\n" << BOLD << "=== " << name << " ===" << RESET << "\n";

    int stalls = 0;
    for (int col = 0; col < COLS; col++) {
        // How many MORE cycles did this chunk take vs sorted baseline?
        double ratio = (double)timings[col] / (double)baseline[col];
        bool stalled = (ratio > threshold);
        if (stalled) stalls++;

        std::cout << (stalled ? RED : GREEN) << "█" << RESET << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }

    std::cout << "\nCPU Pipeline Stalls (Red Blocks): "
              << RED << stalls << RESET << " / 50\n";
}

int main() {
    const int N    = 15000;
    const int COLS = 50;

    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = rand() % 100;

    std::vector<int> chunks = equal_work_chunks(N, COLS);

    // ── Warmup: run both once to prime caches ──
    std::cout << BOLD << "Warming up CPU caches and branch predictor...\n" << RESET;
    {
        std::vector<int> warm = arr;
        measure_tsc_chunks(warm, chunks, COLS);
        std::sort(warm.begin(), warm.end());
        measure_tsc_chunks(warm, chunks, COLS);
    }

    // ── Measure SORTED first → this is the hardware baseline ──
    // Sorted = perfect branch prediction = minimum possible TSC cycles
    // for each chunk. This is our ground truth from hardware.
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());

    std::cout << BOLD << "Reading TSC hardware register...\n" << RESET;
    std::vector<uint64_t> sorted_cycles   = measure_tsc_chunks(sorted_arr, chunks, COLS);
    std::vector<uint64_t> unsorted_cycles = measure_tsc_chunks(arr,        chunks, COLS);

    std::cout << "\nLegend: "
              << GREEN << "█ Smooth CPU Pipeline" << RESET
              << " | "
              << RED   << "█ CPU Stalled (Branch Miss)" << RESET
              << "\n";

    // sorted is baseline → should be all green (ratio = ~1.0)
    // unsorted compared against sorted baseline → shows real branch cost
    display("Real-Time Unsorted Array (fun1)", unsorted_cycles, sorted_cycles, COLS, 1.30);
    display("Real-Time Sorted Array  (fun2)", sorted_cycles,   sorted_cycles, COLS, 1.30);

    return 0;
}