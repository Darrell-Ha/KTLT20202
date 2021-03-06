#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string nameTree[3]={"bananaTree.txt","pine.txt","broom.txt"};
int printTrees(int index);
int main(){
    int index=0;
    while(index!=4){
        cout<<"Nhap 1 de in cay CHUOI";
        cout<<"\nNhap 2 de in cay THONG";
        cout<<"\nNhap 3 de in cay CHOI";
        cout<<"\nNhap 4 de thoat\n";
        cin>>index;
        index=printTrees(index);
    }
    return 0;
}
int printTrees(int index){
    if(index==4){
        cout<<"Tam biet";
        return 4;
    }else{
        string nameFile=nameTree[index-1];
    char data;
    fstream myFile;
    myFile.open(nameFile,ios::in);
        while(!myFile.eof()){
            myFile.get(data);
            cout<<data;
        }
    myFile.close();
    return index;
    }
}