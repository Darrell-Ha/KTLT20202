#include <iostream>
#include <string>
using namespace std;

string hashTable[21];
int hashTableSize = 21;
int hashFunc(string a);
void insertToHashTab (string a);
void searchInHashTab (string a);
using namespace std;
int main(){
    int n;
    string str;
    cout<<"Nhap so chuoi ban muon them: ";
    cin >> n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Chuoi "<<i+1<<" :";
        getline(cin,str);
        insertToHashTab(str);
    }
    int choice=0;
    do{
        cout<<"\nNhap 1 de xem chuoi co ton tai khong";
        cout<<"\nNhap 2 de them chuoi vao bang";
        cout<<"\nNhap 3 de thoat\n";
        cin >> choice;
        cin.ignore();
        switch(choice){
            case 1:
                cout<<"\nTEST: tim kiem chuoi\n";
                cout<<"Nhap chuoi:\n";
                getline(cin,str);
                searchInHashTab(str);
            break;
            case 2:
                cout<<"\nNhap chuoi\n";
                getline(cin,str);
                insertToHashTab(str);
            break;
            default:
                cout<<"\nThanks";
            break;
        }
        
    }while(choice!=3);
    
    return 0;
}
int hashFunc(string a){
    int sum=0;
    for(int i=0; i<a.size();i++){
        sum+=(int)a[i]*10+i;
    }
    return sum%2017;
}
void insertToHashTab(string a){
    int index=hashFunc(a);
    while(hashTable[index]!=""){
        index=(index+1)%hashTableSize;
    }
    hashTable[index]=a;
}
void searchInHashTab(string a){
    int index = hashFunc(a);
    while(hashTable[index]!= a && hashTable[index]!=""){
        index=(index+1)%hashTableSize;
    }
    if(hashTable[index]==a){
        cout<<"\nCo nam trong bang bam";
    }else{
        cout<<"\nChua dc them vao bang bam";
    }
}