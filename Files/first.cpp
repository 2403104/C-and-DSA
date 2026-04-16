#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    // creating a file
    //  ofstream file("sample.txt");//this creates the files and opens the file[varName(fileName) or file is the object that represent the file]
    //  if(file.is_open()){
    //      file << "Hello, this is a file created using C++!" <<endl;
    //      file << "You can write multiple lines like this." <<endl;
    //      file.close();
    //      std::cout << "File created and data written successfully." << std::endl;
    //  }else{
    //      std::cout << "Failed to create the file." << std::endl;
    //  }

    // ifstream file("sample.txt");//OPEN FILE IN READING MODE
    // if(!file){
    //     cout << "File not found!" << endl;
    //     return 1;
    // }
    // string line;
    // while(getline(file,line)){//READS THE FILE LINE BY LINE
    //     cout<<line<<endl;
    // }
    // string word;
    // while(file>>word) cout<<word<<" ";//READS THE FILE WORD BY WORD
    // file.close();

    // ofstream file("sample.txt",ios::app);//OPENING FILE IN APPEND MODE
    // if (!file) {
    //     cout << "Error opening file!" << endl;
    //     return 1;
    // }
    // file << "This line is appended." << endl;
    // file.close();

    // cout << "Data appended successfully!" << endl;

    // fstream file("sample.txt", ios::in | ios::out | ios::trunc);//trunc = if already exists then content will be cleared
    // if (!file)
    // {
    //     cout << "File error!" << endl;
    //     return 1;
    // }
    // file << "First Line " << endl;
    // file << "Second Line " << endl;
    // file.seekg(0);
    // string line;
    // while (getline(file, line))
    // {
    //     cout << line << endl;
    // }
    // file.close();

    

    return 0;
}