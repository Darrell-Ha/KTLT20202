#include <iostream>
using namespace std;
void swapNumber(int *a, int *b);
void swapAnd_sumNumber();
void sumArr();
void lenStr();
int main(){
    int bai;
    do{
        cout<<"Nhap 1 hoac 2 de vao bai 2.1_2.2\n";
        cout<<"Nhap 3 de vao bai 2.3\n";
        cout<<"Nhap 4 de vao bai 2.4\n";
        cout<<"Nhap 5 de thoat khoi chuong trinh\n";
        cin>>bai;
        cin.ignore();
        if(bai!=5){
            if(bai==1||bai==2){
                swapAnd_sumNumber();
            }else if(bai==3){
                sumArr();
            }else {
                lenStr();
            }
        }
        
    }while(bai!=5);
    return 0;
}
void swapNumber(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void swapAnd_sumNumber(){
    int a,b;
    int *apt,*bpt;
    cout<<"Nhap vao 2 so: \n";
    cin>>a;
    apt = &a;
    cin>>b;
    bpt = &b;
    cout<<"Ban dau: a= "<<a<<", b= "<<b;
    swapNumber(apt,bpt);
    cout<<"\nSau do: a= "<<a<<", b= "<<b;
    cout<<"\nTong cua a+b= "<<*apt+*bpt<<"\n\n\n\n\n\n";
}
void sumArr(){
    int arr[100];
    int n,sum=0;
    int *arpt=arr;
    cout<<"Nhap so phan tu cho mang: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap phan tu thu "<<i+1<<": ";
        cin>>arr[i];
        sum+=*(arpt+i);
    }
    cout<<"Tong cua cac phan tu la: "<<sum<<"\n\n\n\n\n\n";
}
void lenStr(){
    char str[100];
    char *strpt=str;
    int length=0;
    cout<<"Nhap vao day mot chuoi: ";
    cin.getline(str,sizeof(str));
    while(*strpt!='\0'){
        length+=1;
        strpt++;
    }
    cout<<"\nChuoi tren co do dai: "<<length<<"\n\n\n\n\n\n";
}