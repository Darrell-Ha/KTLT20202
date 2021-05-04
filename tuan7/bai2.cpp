#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <cmath>

#define Mac_RandIN(a,b) rand()%(b-a+1)+a
#define sizeArr 20
using namespace std;

int arr[sizeArr];
int newArr[sizeArr];
void RandomValueArr();
void PrintArr(int* arr,int size);
int Erase();

int main(){
    srand(time(NULL));
    RandomValueArr();
    cout <<"Original:\n";
    PrintArr(arr,sizeArr);
    int sizeOfnew=Erase();
    cout <<"Delete Duplicate: \n";
    PrintArr(newArr,sizeOfnew);
    
    return 0;
}


void RandomValueArr(){
    for (int i = 0; i < sizeArr; i++){
        arr[i]=Mac_RandIN(0,20);
    }   
}
void PrintArr(int *arr, int size){
    cout << "\t";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int Erase(){
    int size=1;
    newArr[0]=arr[0];
    for(int i = 1; i < sizeArr; i++){
        int valueNow = arr[i];
        int count=0;
        for(int j = 0;j<size; j++){
            if(valueNow!=newArr[j]){
                count++;
            }
        }
        if(count==size){
            size++;
            newArr[size-1]=valueNow;
        }
    }
    return size;
    
}

