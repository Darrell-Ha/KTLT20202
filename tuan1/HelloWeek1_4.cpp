#include <iostream>
using namespace std;
int main(){
    int n;
    ///---IN CÂY THÔNG THEO SỐ n ĐƯỢC NHẬP VÀO---///
    cout<<"Nhap chieu cao n: ";
    cin>>n;
    for(int i=0;i<n+n/4;i++){
        if(i<n){
            for(int j=0;j<n-i;j++){
                cout<<" ";
            }
            for(int k=0;k<(1+i*2);k++){         /// in phần lá
                cout<<"*";
            }
        }else{
            for(int j=0;j<(1+n*2)/2+1-(1+2*n)/10;j++){
                cout<<" ";
            }
            for(int k=0;k<(1+n*2)/5;k++){       ////in độ rộng của thân cây
                cout<<"^";
            }
        }
        cout<<"\n";
        
    }
    return 0;
}