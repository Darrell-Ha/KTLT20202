#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void inputFile();
void readFile(string file);
void clearFile();
void updateFile();
string const nameFile="testFile.txt";
string const nameFileDel="deleteFile.txt";
int main(){
    int exe;
    cin>>exe;
    cin.ignore();
    if(exe==1){
        cout<<"Bai 1.1 Doc du lieu tu file\n";
        readFile(nameFile);
    }else if(exe==2){
        cout<<"Bai 1.2 Them du lieu vao file\n";
        inputFile();
    }else if(exe==3){
        cout<<"Bai 1.3 Xoa du lieu file\n";
        clearFile();
    }else{
        cout<<"Bai 1.4 Update File\n";
        updateFile();
    }
    

    return 0;
}
void updateFile(){
    int choice;
    string data;
    fstream myFile,temp;
    cout<<"Noi dung Ban dau cua file: ";
    readFile(nameFile);
    cout<<"Ban muon sua thong tin gi trong file\n";
    cout<<"Nhan 1 de sua lai thong tin\n";
    cout<<"Nhan 2 de thoat\n";
    cin>>choice;
    cin.ignore();
    if(choice==1){
        string replaced;
        string changed;
        int count=0;
        cout<<"thong tin do thay the cho thong tin nao\n";
        getline(cin,replaced);
        cout<<"Ban muon sua thanh?\n";
        getline(cin,changed);
        
        temp.open("temp.txt",ios::out|ios::app);
            myFile.open(nameFile,ios::in);
                while(!myFile.eof()){
                    getline(myFile,data);
                    int index=data.find(replaced);
                    if(index!=-1){
                        data.replace(index,replaced.length(),changed);
                        count++;
                    }
                    data+="\n";
                    temp<<data;
                }
            myFile.close();
        temp.close();
        // ////////////////////// chỉnh sửa ở file temp.txt
        /////////////////////////////// hoàn tất công việc khi chuyển ndung từ temp->file ban dau
        if(count!=0){
            cout<<"\nNdung file da chinh sua\n";
            temp.open("temp.txt",ios::in);
                myFile.open(nameFile,ios::out);
                    while(!temp.eof()){
                        getline(temp,data);
                        myFile<<data<<"\n";
                        cout<<data<<"\n";
                    }
                myFile.close();
            temp.close();
        }else{
            cout<<"Khong tim thay ndung can chinh sua, file giu nguyen";
        }
        temp.open("temp.txt",ios::out);
        temp<<"";
        temp.close();
        
    }
}
void inputFile(){
    cout<<"Ban dau";
    readFile(nameFile);
    string data; 
    fstream myFile;
    cout<<"\nNhap thong tin ban muon them vao file: ";
    myFile.open(nameFile,ios::out|ios::app);
        getline(cin,data);
        cout<<"\n";
        myFile<<"\n"<<data;
    myFile.close();
    cout<<"Sau khi them\n\n";
    readFile(nameFile);
}
void readFile(string file){
    string data; 
    fstream myFile;
    myFile.open(file,ios::in);
        while(!myFile.eof()){
            getline(myFile,data);
            cout<<data<<"\n";
        }
    myFile.close();
}
void clearFile(){
    //// Ndung file "deleteFile.txt = copy file "testFile.txt""///
    string data;
    fstream deleteFile,testFile;
    testFile.open(nameFile,ios::in);
        deleteFile.open(nameFileDel,ios::out);
            while(!testFile.eof()){
                getline(testFile,data);
                deleteFile<<data<<"\n";
            }
        deleteFile.close();
    testFile.close();
    //// Xóa file "deleteFile.txt"////
    cout<<"Ban dau\n";
    readFile(nameFileDel);
    cout<<"\nVe sau";
    deleteFile.open(nameFileDel,ios::out|ios::trunc);
    deleteFile.close();
    cout<<"File trong rong";
}