#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){

    std::ifstream inputFile("./test_cases/Sample_test/Test_1/input_matrix.txt");
    if(!inputFile){
        cerr<<"Unable to open file!";
        return 1;
    }
    string content;
    if(getline(inputFile, content)){
        cout<<'\n'<<content;
    }
    inputFile.close(); // close after reading 

    
    int settings[4] = {};
    int settingsLimit = 4;

    for(int i = 0; i < settingsLimit; i++){
        if(content[i] != ' '){
            int index = 4-settingsLimit;
            settings[index] = content[i]-'0';
            settingsLimit -=1;
        }
    }




    return 0;
}