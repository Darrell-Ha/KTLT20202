#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#define sizeArr 20

using namespace std;

///// Color ///
//// Ý tưởng Color từ bạn Hoàng Mỹ Gia Huy /////
HANDLE hConsole;
void setColor(int c){
	SetConsoleTextAttribute(hConsole, c);
}

int arr[sizeArr];
void SetValuetoArr();
void InsertionSort();
void PrintArr();
void PrintArrWithColor(int keyj, int countStep,int last);

int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetValuetoArr();
    InsertionSort();
    return 0;
}

void SetValuetoArr(){
    srand(time(NULL));
    for(int i = 0; i < sizeArr; i++){
        arr[i] = rand()%21 + 1;
    }
}
void PrintArr(){
    cout << setw(6);
    for(int i = 0; i < sizeArr; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void PrintArrWithColor(int keyj, int countStep, int last){
    setColor(15);
    cout<< countStep << setw(3) << ": " ;
    for(int i = 0; i < sizeArr; i++){
        if(i == keyj){
            setColor(11);
            cout << arr[i] << " ";
            setColor(0);
        }else if (i <= last){
            setColor(12);
            cout << arr[i] << " ";
            setColor(0);
        }else{
            setColor(10);
            cout << arr[i] << " ";
            setColor(0);
        }
    }
    cout << "\n";
}
/// Insertion sort giống quá trình tìm sách trên một ngăn theo chiều từ phải sang trái
//// Sắp xếp theo chiều tăng dần từ trái sang phải /////
/// đang sửa chữa /////
void InsertionSort(){ 
    setColor(15); 
    cout << "Original Array: \n";
    PrintArr();  
    int count = 0;
    int last = 0;
    for(int i = 1; i<sizeArr; i++){
        int valueNow = arr[i];
        int j = i-1;
        while(j > -1 && arr[j]>valueNow){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = valueNow;
        PrintArrWithColor(j+1,++count, last++);
    }
    setColor(14);
    cout << "Finalyy: \n";
    PrintArr();
    
}
