#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

#define Mac_RandIN(a,b) rand()%(b-a+1)+a
#define sizeArr 20
using namespace std;

int arr[sizeArr];
void RandomValue_andPrint_Arr();
float AverageDistance();

int main(){
    srand(time(NULL));
    RandomValue_andPrint_Arr();
    cout << "Average value = " << AverageDistance();
    return 0;
}


void RandomValue_andPrint_Arr(){
    cout << "\t";
    for (int i = 0; i < sizeArr; i++){
        arr[i]=Mac_RandIN(0,100);
        cout << arr[i] << " ";
    }
    cout << "\n";    
}
float AverageDistance(){
    float sum=0;
    for(int i = 0; i < sizeArr-1; i++){
        for(int j = i+1; j < sizeArr; j++){
            sum+=abs(arr[i]-arr[j]);
        }
    }
    sum/=(sizeArr*(sizeArr-1))/2;
    return sum;
}

