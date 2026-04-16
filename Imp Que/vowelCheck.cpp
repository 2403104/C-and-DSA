#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        vector<string> ans;
        unordered_set<string> exact;
        unordered_map<string, string> inSen, vowelErr; // transform,original
        for (auto word : wordlist)
        {
            string cpy;
            cpy.assign(word);
            exact.insert(word);
            transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);
            if (inSen.find(cpy) == inSen.end())
                inSen[cpy] = word;
            string mod = cpy;
            for (char &ch : mod)
            {
                if (isVowel(ch))
                    ch = '*';
            }
            if (vowelErr.find(mod) == vowelErr.end())
                vowelErr[mod] = word;
        }

        for (string word : queries)
        {
            if (exact.count(word))
            {
                ans.push_back(word);
                continue;
            }
            string cpy;
            cpy.assign(word);
            transform(cpy.begin(), cpy.end(), cpy.begin(), ::tolower);
            if (inSen.count(cpy))
            {
                ans.push_back(inSen[cpy]);
                continue;
            }
            string mod = cpy;
            for (char &ch : mod)
            {
                if (isVowel(ch))
                    ch = '*';
            }
            if (vowelErr.count(mod))
            {
                ans.push_back(vowelErr[mod]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
int main()
{

    return 0;
}