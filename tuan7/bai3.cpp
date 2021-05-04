#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <cmath>

#define Mac_RandIN(a,b) rand()%(b-a+1)+a
#define sizeArr 20
using namespace std;

int arr[sizeArr];
void PrintArr(int begin, int size);
void Original();
void RandomValueArr();
void FindSubArr(int m);


int main(){
    int m;
    srand(time(NULL));
    RandomValueArr();
    Original();
    cout << "Input M: ";
    cin >> m;
    FindSubArr(m);

    return 0;
}


void RandomValueArr(){
    for (int i = 0; i < sizeArr; i++){
        arr[i]=Mac_RandIN(-20,20);
    }   
}
void Original(){
    cout<<"Original: \n\t";
    for(int i = 0; i < sizeArr; i++){
        cout << arr[i]<<" ";
    }
    cout << "\n";
}
void PrintArr(int begin, int size){
    cout<<"begin at: [" << begin <<"]\t";
    for(int i = begin; i < size; i++){
        cout << arr[i]<<" ";
    }
    cout << "\n";
}
void FindSubArr(int m){
    int countSol=0;
    for(int i = 0; i < sizeArr-1;i++){
        int sum=arr[i];
        int count = 1;
        for (int j = i+1; j<sizeArr; j++){
            count++;
            sum+=arr[j];
            if(sum == m){
                int begin=i;
                int size=i+count;
                PrintArr(begin,size);
                countSol++;
            }
        }
    }
    if(countSol!=0){
        cout <<"\tThere is "<<countSol<<" solutions.";
    }else{
        cout << "\tNo Solution!";
    }
}
