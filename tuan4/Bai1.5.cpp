#include <iostream>
#include <cstdlib>
using namespace std;

struct matrix{
    int arr[10][10];
    int dim1, dim2;    
} ;
matrix A,B;

void multMatrix(matrix a, matrix b);
void addMatrix(matrix a, matrix b);
void printMatrix(matrix a);
matrix writeMatrix(matrix a);
void progr3();
void progr4();

int main(){
    int status = 0;
    do{
        cout<<"\nNhap 1 de in ra hai ma tran";
        cout<<"\nNhap 2 de tinh tong ma tran";
        cout<<"\nNhap 3 de tinh tich ma tran AxB hoac BxA"; 
        cout<<"\nNhap 4 de viet lai 2 ma tran";
        cout<<"\nNhap 5 de thoat\n";
        cin >> status;
        //system("cls");
        switch (status){
        case 1:
            cout<<"A=\n";
            printMatrix(A);
            cout<<"B=\n";
            printMatrix(B);
            break;
        case 2:
            addMatrix(A,B);
            break;
        case 3:
            progr3();
            break;
        case 4:
            progr4();
            break;
        default:
            cout<<"Tam biet";
            break;
        }
    }while(status!=5);
    
    

    return 0;
}
void multMatrix(matrix a, matrix b){
    if(a.dim2!=b.dim1){
        cout<<"\nKhong the thuc hien duoc, yeu cau nhap lai so chieu";
    }else{
        matrix tich;
        tich.dim1=a.dim1;
        tich.dim2=b.dim2;
        for(int i=0;i<tich.dim1;i++){
            for(int j=0;j<tich.dim2;j++){
                int sum=0;
                for(int cot=0;cot<tich.dim2;cot++){
                    sum+=a.arr[i][cot]*b.arr[cot][j];
                }
                tich.arr[i][j]=sum;
            }
        }
        cout<<"Tich thu duoc\n";
        printMatrix(tich);
    }
}
void addMatrix(matrix a, matrix b){
    matrix tong;
    tong.dim1=a.dim1;
    tong.dim2= a.dim2;
    if(a.dim1!=b.dim1 || a.dim2!=b.dim2){
        cout<<"\nKhong the thuc hien duoc, yeu cau nhap lai so chieu\n";
    }else{
        if(tong.dim2-1!=0){
            for(int i=0; i<tong.dim1; i++){
                for(int j=0; j<tong.dim2; j++){
                    tong.arr[i][j]=a.arr[i][j]+b.arr[i][j];
                }
            }
        }else{
            for(int i=0; i<tong.dim1; i++){
                tong.arr[i][0]=a.arr[i][0]+b.arr[i][0];
            }
        }
        cout<<" Tong hai ma tran (vecto) thu duoc\n";
        printMatrix(tong);
    }
}
void printMatrix(matrix a){
    if(a.dim2-1!=0){
        for(int i=0; i<a.dim1; i++){
            for(int j=0; j<a.dim2;j++){
                cout << a.arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }else{
        cout<<"( ";
        for(int i=0;i<a.dim1;i++){
            cout << a.arr[i][0]<<" ";
        }
        cout<<")"; 
    }
    cout<<"\n\n";
}
matrix writeMatrix(matrix a){
    cout<<"\nNhap gia tri cho ma tran\n";
    if(a.dim2-1!=0){
        for(int i=0; i<a.dim1; i++){
            for(int j=0; j<a.dim2;j++){
                cin >> a.arr[i][j];
            }
        }
    }else{
        for(int i=0;i<a.dim1;i++){
            cin>> a.arr[i][0];
        }
    }
    return a;
}
void progr3(){
    int choice=0;
    cout<<"\nBan chon AxB (bam 1, neu khong bam 2)";
    cin>> choice;
    if(choice==1){
        multMatrix(A,B);
    }else{
        multMatrix(B,A);
    }
}
void progr4(){
    int choice=0;
    cout<<"\nBan chon thay doi ma tran A (bam 1, neu khong bam 2) ";
    cin>> choice;
    if(choice==1){
        cout<<"Nhap 2 chieu ma tran (vecto theo chieu doc) A: ";
        cin  >> A.dim1 >> A.dim2;
        A=writeMatrix(A);
    }else{
        cout<<"Nhap 2 chieu ma tran (vecto theo chieu doc) B: ";
        cin  >> B.dim1 >> B.dim2; 
        B=writeMatrix(B);
    }
}
