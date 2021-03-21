#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int arr[20];
int sizeArrBasc=20;
int NumAndTimes[30];

void insertNum_toBasc(){
    srand(time(NULL));
    
    ///// ----------- Nhập giá trị random [0,30] vào mảng có 20 phần tử ----------///////

    for(int i=0; i<sizeArrBasc; i++){
        arr[i]=rand()%(30)+1;
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void insert_toNumTab(int num){
    if(NumAndTimes[num]== 0){
        int times=0;
        for(int i=0;i<sizeArrBasc;i++){
            if(num==arr[i]){
                times++;
            }
        }
        NumAndTimes[num]=times;
    } 
}
int main(){
    insertNum_toBasc();
    int max = 0;
    int number=0;
    for(int i=0; i<sizeArrBasc; i++){
        insert_toNumTab(arr[i]);
        if(NumAndTimes[arr[i]]>max){
            max=NumAndTimes[arr[i]];
            number=arr[i];
        }
    }
    int anot;
    cout<<"Phan tu xuat hien nhieu nhat: "<<number<<" voi "<<max<<" lan";
    cout<<"\nNgoai ra ban muon so lan xuat hien cua phan tu nao khac?: ";
    cin >> anot;
    cout<<"Phan tu "<<anot<<" xuat hien "<<NumAndTimes[anot]<<" lan.";

    

    return 0;
}