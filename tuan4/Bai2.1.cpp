#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main(){
    srand(time(NULL));
    int arr[20];
    int n;
    int *ptr =arr;
    cout<<"Nhap so phan tu mang: ";
    cin >> n;
    for(int i=0;i<n;i++){
        *(ptr+i)=rand()%31;
        cout<<*(ptr+i)<<" ";
    }
    cout<<"\nDay dao nguoc:\n";
    for(int i=n-1;i>-1;i--){
        cout<<*(ptr+i)<<" ";
    }
    return 0;
}