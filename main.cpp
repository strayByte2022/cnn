#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){

    std::ifstream inputFile("./test_cases/Sample_test/Test_2/input_matrix.txt");
    if(!inputFile){
        cerr<<"Unable to open file!";
        return 1;
    }
    string content;
    // if(getline(inputFile, content)){
    //     cout<<'\n'<<content;
    // }
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

    // 0: size of image matrix 3 <= n <= 7 -> float
    // 1: size of kernel matrix 2 <= m <= 4 -> float
    // 2: size of padding 0 <= p <= 4
    // 3: the value of stride 1 <= s <= 3
    

    //check the size

    if(settings[0] < 3 || settings[0] > 7){
        return 0;
    }

    if(settings[1] < 2 || settings[1] > 4){
        return 0;
    }
    
    if(settings[2] < 0 || settings[2] > 4){
        return 0;
    }

    if(settings[3] < 1 || settings[1] > 3){
        return 0;
    }
    
    string rawArray [3];
    int j = 0;

    string a;

    while(inputFile >> a){
        rawArray[j] = a;
        j++;
    }

    for(int i =0; i < 3; i++){
        cout<<"Hello: "<<rawArray[i];
    }





    




    return 0;
}