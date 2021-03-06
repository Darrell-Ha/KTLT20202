#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string data; 
    string const nameFile="testFile.txt";
    fstream myFile;
    ////////------------------RUNNING-------------------------------//////////////
    cout<<"Nhap thong tin ban muon them vao file: ";
    myFile.open(nameFile,ios::out|ios::app);
        getline(cin,data);
        cout<<"\n";
        myFile<<"\n"<<data;
    myFile.close();
    ////////////---------------- Kết thúc ghi file------------------///////////////
    myFile.open(nameFile,ios::in);
        while(!myFile.eof()){
            getline(myFile,data);
            cout<<data<<"\n";
        }
    myFile.close();
    /////////////--------------- Kết thúc đọc file------------------///////////////

    return 0;
}