#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

int main() {
    
    std::fstream file;
    std::string path;
    std::string line;
    const int maxCount = 1000000;
    
    std::cout <<  "give the file path";
    std::cout << std::endl;
    std::cin >> path;
    std::bitset<maxCount> bit; // reserve 1 million
    file.open(path);
    if(file.is_open())
    {
        while(!file.eof())
        {
            std::getline(file,line);
            if(line != "") 
            {
                bit[std::stoi(line)] = 1 ;
            }
        }
    }
    else
    {
        std::cout << "This File is invalid" << std::endl;
        std::cout << "Provide the full path of the file, please!";
        std::exit(0);
    }
    file.close();
    std::fstream sortedTextFile;
    sortedTextFile.open("sortedTextFile.txt",std::ios_base::out);
    for( int i = 0; i < bit.size(); ++i)
    {
        if(bit[i]) sortedTextFile << i << "\n";
    }
    return 0;
}  