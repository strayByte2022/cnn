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
    while(getline(inputFile, content)){
        cout<<content<<endl;
    }   
    inputFile.close();
    return 0;
}