#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int arr[50];
    int n=17;
    ///// ----------- Nhập giá trị random [0,30] vào mảng ----------///////
    //cout>>"Nhap kich thuoc mang: ";
    //cin >> n;
    for(int i=0; i<n; i++){
        arr[i]=rand()%(30+1);
    }
    //// ------------ Sắp xếp mảng theo thứ tự tăng dần -----------///////
    for(int i=0; i<n-1; i++){
        int indexMin = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[indexMin]){
                indexMin=j;
            }
        }
        if(indexMin!=i){
            int temp = arr[i];
            arr[i]=arr[indexMin];
            arr[indexMin]=temp;
        }
    }
    ////////------------ INPUT ----------/////////
    int x;
    cout<<"Nhap gia tri x can tim kiem trong mang: ";
    cin >> x;
    for(int i=0;i<n;i++){
        cout<< arr[i]<< " ";
    }
    cout<<"\n";
    ///////------------- BINARY SEARCH -------//////
    int indexStart=0, indexEnd=n-1;
    while(indexStart!=indexEnd){
        int k=(indexStart+indexEnd)/2;
        if(arr[k]>x){
            indexEnd=k-1;
        }else if(arr[k]<x){
            indexStart=k+1;
        }else{
            cout<<"Co ton tai gia tri "<< x<< " la phan tu chi so "<<k;
            return 0;
        }
    }
    cout<<"Khong ton tai "<< x << " trong mang.";
    return 0;
}