#include <iostream>
using namespace std;
int main(){
    int a,b,modulo,tich;
    cout<<"Tim UCLN va BCNN cua hai so nguyen a ,b\n";
    cout<<"Nhap so a: "; 
    cin>>a;
    cout<<"Nhap so b: ";
    cin>>b;
    tich=a*b;
    while(b!=0){                                /////-------Áp dụng giải thuật Euclid--------/////
        modulo=a%b;                             ////----------- gcd(a,b)=gcd(b,a%b);--------////
        a=b;                                    ///------------ bcnn(a,b)=a*b/gcd(a,b)------///
        b=modulo;
    }
    cout<<"Uoc chung lon nhat la: "<<a<<"\n";
    cout<<"Boi chung nho nhat la: "<<tich/a;

    return 0;
}