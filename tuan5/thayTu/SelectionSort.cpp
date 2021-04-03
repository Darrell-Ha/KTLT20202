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
void SelectionSort();
void PrintArr();
void PrintArrWithColor(int keyi, int keyj, int countStep, int last);

int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetValuetoArr();
    SelectionSort();
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

void PrintArrWithColor(int keyi, int keyj, int countStep, int last){
    setColor(15);
    cout<< countStep << setw(3) << ": " ;
    for(int i = 0; i < sizeArr; i++){
        if(i == keyi || i == keyj || i<last){
            if(i == keyi || i == keyj ){
                setColor(11);
                cout << arr[i] << " ";
                setColor(0);
            }else{
                setColor(14);
                cout << arr[i] << " ";
                setColor(0);
            }
        }else{
            //setColor(10);
            cout << arr[i] << " ";
        }
        
    }
    cout << "\n";
}
//// theo chiều tăng dần từ trái sang phải /////
void SelectionSort(){ 
    setColor(15); 
    cout << "Original Array: \n";
    PrintArr();  
    int count = 0;
    int last = 0;
    for(int i = 0; i<sizeArr-1; i++){
        int index = i;
        for(int j = i+1; j<sizeArr; j++){
            if(arr[index] > arr[j]){
                index = j;
            }
        }
        if(index != i){
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
        PrintArrWithColor(i,index,++count,last++);
    }
    setColor(14);
    cout << "Finalyy: \n";
    PrintArr();
    
}
