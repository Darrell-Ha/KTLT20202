#include <iostream>
using namespace std;

struct matran2x2{               // a    b
    float a,b,c,d;              // c    d
    float det ;
};
matran2x2 matran_Heso;
float f1, f2;
float root[2];

void Giai(matran2x2 mat);
matran2x2 Input();

int main(){
    matran_Heso=Input();
    Giai(matran_Heso);
    return 0;
}
matran2x2 Input(){
    matran2x2 mat;
    cout << "Chuong trinh giai he pt 2 an:";
    cout << "\n\t ax+by=f1";
    cout << "\n\t cx+dy=f2";
    cout << "\nNhap thong tin cho he so: \n";
    cin >> mat.a >> mat.b >> mat.c >> mat.d;
    mat.det=mat.a*mat.d-mat.c*mat.b;
    cout << "Nhap f1, f2 lan luot: ";
    cin >> f1 >> f2;

    return mat;
}
void Giai(matran2x2 mat){
    if(mat.det==0){
        if(mat.a==0){
            if(mat.b*f2==mat.d*f1){
                cout<< "\nHe co vo so nghiem";
            }else{
                cout<<"\nHe vo nghiem";
            }
        }else{
            if(mat.a*f2==mat.c*f1){
                cout<< "\nHe co vo so nghiem";
            }else{
                cout<<"\nHe vo nghiem";
            }
        }
    }else{
        matran2x2 mat_x = mat;
        matran2x2 mat_y = mat;
        mat_x.a = f1; mat_x.c = f2;
        mat_y.b = f1; mat_y.d = f2;
        mat_x.det = mat_x.a*mat_x.d-mat_x.b*mat_x.c;
        mat_y.det = mat_y.a*mat_y.d-mat_y.b*mat_y.c;
        root[0] = mat_x.det/mat.det;
        root[1] = mat_y.det/mat.det;
        cout<<"\nx="<< root[0];
        cout<<"\ny="<< root[1];
    }
}