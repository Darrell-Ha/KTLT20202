#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    system("cls");
    srand(time(NULL));
    int arr[10];
    int x, count=0;
    int max, min;
    cout << "Nhap so x can tim trong mang?: \n";
    cin >> x;
    for(int i=0; i<10; i++){
        arr[i]= rand()%(20-0+1);
        cout << "Phan tu " << i << " trong mang la: " << arr[i] <<"\n";
        if(arr[i] == x){
            count++;
        }
        if(i==0){
            max=arr[i];
            min=arr[i];
        }else{
            max=(arr[i]>max)? arr[i]: max ;
            min=(arr[i]<min)? arr[i]: min ;
        }
    }
    if(count!=0){
        cout<<"Gia tri" << x <<" co xuat hien: "<< count <<" lan";
    }else{
        cout<<x<<" khong xuat hien lan nao";
    }
    cout<<"\nMax array= "<<max;
    cout<<"\nMin array= "<<min;

    return 0;
}