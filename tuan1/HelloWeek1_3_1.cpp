#include <iostream>
#include <math.h>
using namespace std;            /// Không gian C z=a+bi =>> [z]=(a,b) thuộc R^2;
const float pi = 3.141593;
float heSo_Delta_no[6][2];      ///3 dòng đầu lưu hệ số a,b,c ///2 dòng sau lưu no1,no2/// dòng cuối lưu Delta
float tvhuong(int x, int y);    ////tính tích vô hướng vecto <x,y> vì không gian C thực chất cũng là R^2;
float nhanReal(int x,int y);    /// tính phần thực của x*y
float nhanImg(int x,int y);     /// tính phần ảo của x*y
float chiaReal(int x,int y);    /// tính phần thực của x/y
float chiaImg(int x, int y);    /// tính phần ảo của x/y
void vietNghiem(int x);
int main(){      
    ////------Run------////
    cout<<"Chuong trinh giai phuong trinh az2+bz+c=0 tren khong gian C"<<"\n";
    cout<<"Nhap lan luot he so viet trong khong gian C: "<<"\n";
    for(int i=0; i<3;i++){
        cout<<"Nhap he so z^"<<2-i<<"\n";   
        cout<<"phan thuc: ";
        cin>>heSo_Delta_no[i][0];
        cout<<"phan ao: ";
        cin>>heSo_Delta_no[i][1];
    }
    if(heSo_Delta_no[0][0]==0 && heSo_Delta_no[0][1]==0){
        if(heSo_Delta_no[1][0]==0 && heSo_Delta_no[1][1]==0){
            if(heSo_Delta_no[2][0]==0 && heSo_Delta_no[2][1]==0){
                cout<<"Phuong trinh vo so nghiem";
            }else{
                cout<<"Phuong trinh vo nghiem";
            }
        }else{
            heSo_Delta_no[3][0]=-chiaReal(2,1);            ////thực của -c/b
            heSo_Delta_no[3][1]=-chiaImg(2,1);            ///ảo của -c/b                                             
            cout<<"Phuong trinh co mot nghiem: ";vietNghiem(3);
        }
    }else{
        heSo_Delta_no[5][0]=nhanReal(1,1)-4*nhanReal(0,2);      /// tính Delta
        heSo_Delta_no[5][1]=nhanImg(1,1)-4*nhanImg(0,2);
        heSo_Delta_no[0][0]*=2;                             //// hệ số z^2 nhân 2 để tạo thành 1 số phức
        heSo_Delta_no[0][1]*=2;
        if(heSo_Delta_no[5][0]==0 && heSo_Delta_no[5][1]==0){   ///Nếu Delta =0
            heSo_Delta_no[3][0]=-chiaReal(1,0);
            heSo_Delta_no[3][1]=-chiaImg(1,0);
            heSo_Delta_no[4][0]=heSo_Delta_no[3][0];
            heSo_Delta_no[4][1]=heSo_Delta_no[3][1];
        }else{
            ////tính căn Delta/////
            float moduleDelta=sqrt(heSo_Delta_no[5][0]*heSo_Delta_no[5][0]+heSo_Delta_no[5][1]*heSo_Delta_no[5][1]);        
            float cosDelta=heSo_Delta_no[5][0]/moduleDelta;
            float arcosDelta=acos(cosDelta);
            if(cosDelta<0 && heSo_Delta_no[5][1]<0){
                arcosDelta=-arcosDelta;
            }
            float cosCanDelta=cos(arcosDelta/2);                 /// tính cos của số căn Delta
            float sinCanDelta=sin(arcosDelta/2);                  /// tính sin của số căn Delta
            
            float moduleCanDelta=sqrt(moduleDelta);                          /// tính modun số căn Delta
                        

            heSo_Delta_no[5][0]=moduleCanDelta*cosCanDelta;
            heSo_Delta_no[5][1]=moduleCanDelta*sinCanDelta;
            heSo_Delta_no[3][0]=(-heSo_Delta_no[1][0]+heSo_Delta_no[5][0]);     // viết phần tử số của x1
            heSo_Delta_no[3][1]=(-heSo_Delta_no[1][1]+heSo_Delta_no[5][1]);     
            heSo_Delta_no[4][0]=(-heSo_Delta_no[1][0]-heSo_Delta_no[5][0]);     // viết phần tử số của x2
            heSo_Delta_no[4][1]=(-heSo_Delta_no[1][1]-heSo_Delta_no[5][1]);
            /////////// chia cho 2 lần hệ số z^2 ////////////////////
            heSo_Delta_no[3][0]=chiaReal(3,0);
            heSo_Delta_no[3][1]=chiaImg(3,0);
            heSo_Delta_no[4][0]=chiaReal(4,0);
            heSo_Delta_no[4][1]=chiaImg(4,0); 

        }
        ////// viết nghiệm /////
        cout<<"Phuong trinh co nghiem z1= ";vietNghiem(3);
        cout<<"\nPhuong trinh co nghiem z2= ";vietNghiem(4);    
    
    }
    return 0;
    
}

float tvhuong(int x,int y){
    return heSo_Delta_no[x][0]*heSo_Delta_no[y][0]+heSo_Delta_no[x][1]*heSo_Delta_no[y][1];
}
float nhanReal(int x,int y){
    return heSo_Delta_no[x][0]*heSo_Delta_no[y][0]-heSo_Delta_no[x][1]*heSo_Delta_no[y][1];
}    
float nhanImg(int x,int y){
    return heSo_Delta_no[x][0]*heSo_Delta_no[y][1]+heSo_Delta_no[x][1]*heSo_Delta_no[y][0];
}     
float chiaReal(int x,int y){
    return tvhuong(x,y)/tvhuong(y,y);
}    
float chiaImg(int x, int y){
    return (heSo_Delta_no[x][1]*heSo_Delta_no[y][0]-heSo_Delta_no[x][0]*heSo_Delta_no[y][1])/tvhuong(y,y);
}    

void vietNghiem(int x){
    cout<<heSo_Delta_no[x][0]<<"+"<<heSo_Delta_no[x][1]<<"i";
}