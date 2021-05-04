#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <cmath>

#define Mac_RandIN(a,b) rand()%(b-a+1)+a
#define sizeArr 20
using namespace std;

int arr[sizeArr];
void PrintArr(int begin, int size, int sum);
void Original();
void RandomValueArr();
void FindSubArr_MaxSum_Positive();

int main(){
    srand(time(NULL));
    RandomValueArr();
    Original();
    FindSubArr_MaxSum_Positive();
    return 0;
}
void RandomValueArr(){
    for (int i = 0; i < sizeArr; i++){
        arr[i]=Mac_RandIN(-10,30);
    }   
}
void Original(){
    cout<<"Original: \n\t";
    for(int i = 0; i < sizeArr; i++){
        cout << arr[i]<<" ";
    }
    cout << "\n";
}
void PrintArr(int begin, int size,int sum){
    cout<<"begin at: [" << begin <<"]\t";
    for(int i = begin; i < size; i++){
        cout << arr[i]<<" ";
    }
    cout << "\nMaxSum = "<<sum;
}

void FindSubArr_MaxSum_Positive(){
    int maxSum=arr[0];
    int begin=0;
    int sizeSubArr=1;
    for(int i=0; i<sizeArr-1;i++){
        if(arr[i]>0){
            int sum = arr[i];
            int count=1;
            for(int j=i+1; j<sizeArr;j++){
                if(arr[j]<0){
                    break;
                }else{
                    count++;
                    sum+=arr[j];
                    if(sum>maxSum){
                        begin=i;
                        sizeSubArr=i+count;
                        maxSum=sum;
                    }
                }
            }
        }
    }
    if(maxSum!=arr[0]){
        PrintArr(begin,sizeSubArr,maxSum);
    }else{
        cout << "There is no positive sub array.";
    }
    
}
