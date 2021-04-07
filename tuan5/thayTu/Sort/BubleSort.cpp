#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h>
#define sizeArr 10
using namespace std;

///// Color ///
//// Ý tưởng Color từ bạn Hoàng Mỹ Gia Huy /////
HANDLE hConsole;
void setColor(int c){
	SetConsoleTextAttribute(hConsole, c);
}

int arr[sizeArr];
void SetValuetoArr();
void BubleSort();
void PrintArr();
void PrintArrWithColor(int swapped, int countStep);


int main (){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetValuetoArr();
    BubleSort();
    return 0;
}


void SetValuetoArr(){
    srand(time(NULL));
    for(int i = 0; i < sizeArr; i++){
        arr[i] = rand()%21 + 1;
    }
}
void PrintArr(){
    cout << setw(7);
    for(int i = 0; i < sizeArr; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void PrintArrWithColor(int index, int countStep){
    setColor(15);
    cout<< countStep << ": " << setw(3);
    for(int i = 0; i < sizeArr; i++){
        if(i == index || i == index + 1){
            if (i == index){
                setColor(11);
                cout << arr[i] << " ";
                setColor(0);
            }else{
                setColor(14);
                cout << arr[i] << " ";
                setColor(0);
            }
        }else{
            setColor(0);
            cout << arr[i] << " ";
        }
        
    }
    cout << "\n";
}
//// theo chiều tăng dần từ trái sang phải /////
void BubleSort(){ 
    setColor(15); 
    cout << "Original Array: \n";
    PrintArr();  
    int count = 0;   
    for(int i = 1; i < sizeArr; i++){
        for(int j = 0; j < sizeArr-1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                PrintArrWithColor(j, ++count);
            }
        }
    }
    setColor(14);
    cout << "Finalyy: \n";
    PrintArr();
    
}
