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
void MergeSort(int pulp1, int pulp2);
void Merge(int pulp1, int mid, int pulp2);
void PrintArr();
void PrintArrWithColor(int pulp1, int mid, int pulp2);

int main(){
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetValuetoArr();
    setColor(15);
    cout << "Original Array: \n";
    PrintArr();
    MergeSort(0,sizeArr-1);
    setColor(15);
    cout << "Finalyy: \n";
    setColor(14);
    PrintArr();
    
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
void PrintArrWithColor(int pulp1, int mid, int pulp2){
    setColor(15);
    cout << setw(6);
    for(int i = 0; i < sizeArr; i++){
        if(i >= pulp1 && i <=mid){
            setColor(11);
            cout << arr[i] << " ";
            setColor(0);
        }else if (i >= mid+1 && i<=pulp2){
            setColor(12);
            cout << arr[i] << " ";
            setColor(0);
        }else{
            setColor(0);
            cout << arr[i] << " ";
            setColor(0);
        }
    }
    cout << "\n";
}
void Merge(int pulp1, int mid, int pulp2){
    int index = pulp1;
    int sizeL = mid - pulp1 + 1;
    int sizeR = pulp2 - mid;
    int indL = 0, indR = 0;
    int arrL[sizeL], arrR[sizeR];

    for(int i = 0; i < sizeL; i++){
        arrL[i] = arr[pulp1+i];
    }
    for(int i = 0; i < sizeR; i++){
        arrR[i] = arr[mid+1+i];
    }

    while((indL < sizeL) && (indR < sizeR)){
        int l,r;
        if(arrL[indL] <= arrR[indR]){
            arr[index] = arrL[indL];
            indL++;
        }else{
            arr[index] = arrR[indR];
            indR++;
        }
        index++;
    }
    while (indL < sizeL){
        arr[index] = arrL[indL];
        index++;
        indL++;
    }
    while (indR < sizeR){
        arr[index] = arrR[indR];
        index++;
        indR++;
    }
}
/// MergeSort - chia để trị 
/// - sắp xếp các dãy con trước rồi tập hợp lại thành dãy lớn -
//// Sắp xếp theo chiều tăng dần từ trái sang phải /////
/// đang sửa chữa /////
void MergeSort(int pulp1 ,int pulp2){ 
    if(pulp1<pulp2){
        int mid = (pulp1+pulp2)/2;
        MergeSort(pulp1,mid);
        MergeSort(mid+1,pulp2);
        Merge(pulp1,mid,pulp2);
        PrintArrWithColor(pulp1,mid,pulp2);
    } 
}

    

