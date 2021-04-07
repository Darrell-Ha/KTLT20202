#include <iostream>

using namespace std;
struct maTrix{
    long long matr[2][2];
    maTrix(){
        matr[0][0] = 0;
        matr[0][1] = 1;
        matr[1][0] = 1;
        matr[1][1] = 1;
    }
};
maTrix operator * (maTrix mat1, maTrix mat2){
    maTrix result ;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            result.matr[i][j] = 0;
            for(int k = 0; k < 2; k++){
                result.matr[i][j] += mat1.matr[i][k] * mat2.matr[k][j];
            }
        }
    }
    return result;
}
maTrix powerMatrix(maTrix a, long long n){
    if(n == 1){
        return a;
    }else if(n % 2){
        return powerMatrix(a,n-1) * a;
    }else{
        maTrix lower = powerMatrix(a,n/2);
        return lower * lower;
    }
}


int main(){
    int n;
    cout << "Nhap n la so thu \"n\" trong day Fibonaci: ";
    cin >> n;
    maTrix A;
    A = powerMatrix(A,n);
    cout << "So Fibonaci thu " << n << " la: " << A.matr[0][1];
    return 0;
}
