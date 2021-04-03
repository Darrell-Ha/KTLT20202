#include <iostream>

using namespace std;
int func_xn(int x, int n);
int func_fact2n(int n);

int main(){
    int x, n;
    cout << "input x,n: ";
    cin >> x >> n;
    cout << "f(" << x <<"," << n << ")=" << x << "^" << n <<"= " <<func_xn(x,n);
    cout << "\ns(" << n << ")=(2x"<< n <<")!= " << func_fact2n(2*n);
    return 0;
}

int func_xn(int x, int n){
    if(n<0){
        cout<<"Input is illegal, please check it out now!\n";
        return -1;
    }else if(n>0){
        return x*func_xn(x,n-1);
    }else{
        return 1;
    }
}
int func_fact2n(int n){
    if(n<0){
        cout<<"Input is illegal, please check it out now!\n";
        return -1;
    }else if(n>0){
        return n*func_fact2n(n-1);
    }else{
        return 1;
    }
}
