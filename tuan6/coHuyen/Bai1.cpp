#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80

///////////////////-------------- CREATE A Menu -------------//////////////////
///// Menu em được các bạn hướng dẫn /////////
HANDLE hConsole;
string menuChoice[6]={"In ra hai ma tran","Tinh tong ma tran",
                    "Tinh tich ma tran AxB hoac BxA","Cac phep bien doi so cap tren ma tran",
                    "Viet lai 2 ma tran","Thoat"};
void setColor(int c){
	SetConsoleTextAttribute(hConsole, c);
}
void work (int status);
void menuBar(){
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int k = 0;
	char c;
	while (true){
		system("cls");
		for (int i = 0; i < 6; i++){
			if (i == k){
				setColor(130);
				cout << "=>> "<<menuChoice[i]<<'\n';
				setColor(14);
			}
			else{
                cout << menuChoice[i] << '\n';
            } 
		}
		c=getch();
		if (c == KEY_UP){
            k = (k + 5) % 6;
        }else if (c == KEY_DOWN){
            k = (k + 7) % 6;
        }else if (c == '\r'){
			if (k==5){
                cout<<"Tam biet";
                break;
            }
			work(k+1);
		}
	}
	setColor(14);
}
//////////// ---------Tương tác vs Matran ----------////////
struct matrix{
    int arr[10][10];
    int dim1, dim2;    
} ;
matrix A,B;


matrix WriteMatrix(matrix a);
void PrintMatrix(matrix a);
void AddMatrix(matrix a, matrix b);
void MultMatrix(matrix a, matrix b);
void TransformMatrix(matrix a);

void progr1();
void progr2();
void progr3();
void progr4();
void progr5();

int main(){
	menuBar();
    return 0;
}
matrix WriteMatrix(matrix a){
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
void PrintMatrix(matrix a){
    if(a.dim2-1!=0){
        for(int i=0; i<a.dim1; i++){
            for(int j=0; j<a.dim2;j++){
                cout << a.arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }else{
        for(int i=0;i<a.dim1;i++){
            cout << a.arr[i][0]<<"\n";
        } 
    }
    cout<<"\n";
}
void AddMatrix(matrix a, matrix b){
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
        PrintMatrix(tong);
    }
}
void MultMatrix(matrix a, matrix b){
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
        PrintMatrix(tich);
    }
}
void TransformMatrix(matrix a){
    while(true){
        matrix c = a;
        system("cls");
        int choice = 0;
        cout << "Chon 1 de Nhan 1 hang cua ma tran cho so alpha (so Z)\n";
        cout << "Chon 2 de hoan doi vi tri hai hang voi nhau\n";
        cout << "Chon 3 de cong 1 hang voi alpha (so Z) * hang khac\n";
        cout << "Chon 4 de thoat\n";
        cout << "Ban chon : ";
        cin >> choice ;
        system("cls");
        if(choice == 1){
            int alp, row;
            cout << "Nhap alp: ";
            cin >> alp;
            cout << "Nhap hang thu: ";
            cin >> row;
            if(row < 1 || row >c.dim2){
                cout << "Nhap sai so hang yeu cau nhap lai\n";
                char breakpoint = getch();
                continue;
            }else{
                for(int i = 0; i< c.dim2; i++){
                    c.arr[row-1][i]*=alp;
                }
            }
        }else if(choice == 2){
            int row1, row2;
            cout << "Nhap hang thu 1: ";
            cin >> row1;
            cout << "Nhap hang thu 2: ";
            cin >> row2;
            for(int i = 0; i<c.dim2; i++){
                int temp = c.arr[row1-1][i];
                c.arr[row1-1][i] = c.arr[row2-1][i];
                c.arr[row2-1][i] = temp;
            }
        }else if(choice == 3){
            int alp, row1, row2;
            cout << "Nhap hang duoc thay doi gia tri: ";
            cin >> row1;
            cout << "Nhap hang thu 2: ";
            cin >> row2;
            cout << "Nhap so alp (so Z): ";
            cin  >> alp;
            for(int i = 0; i<c.dim2; i++){
                c.arr[row1-1][i] =alp*c.arr[row2-1][i]; 
            }
        }else{
            break;
        }
        cout << "Ma tran cu \n";
        PrintMatrix(a);
        cout << "Ma tran thu duoc:\n";
        PrintMatrix(c);
        char key = getch();
    }
}
void progr1(){
    cout<<"A=\n";
    PrintMatrix(A);
    cout<<"B=\n";
    PrintMatrix(B);
}
void progr2(){
    AddMatrix(A,B);
}
void progr3(){
    int choice=0;
    cout<<"\nBan chon AxB (bam 1, neu khong bam 2)";
    cin>> choice;
    if(choice==1){
        MultMatrix(A,B);
    }else{
        MultMatrix(B,A);
    }
}
void progr5(){
    int choice=0;
    cout<<"\nBan chon thay doi ma tran A (bam 1, neu khong bam 2) ";
    cin>> choice;
    if(choice==1){
        cout<<"Nhap 2 chieu ma tran theo \"sohang socot\" (vecto la hang 1)cho  A: ";
        cin  >> A.dim1 >> A.dim2;
        A=WriteMatrix(A);
    }else{
        cout<<"Nhap 2 chieu ma tran theo \"sohang socot\" (vecto la hang 1)cho B: ";
        cin  >> B.dim1 >> B.dim2; 
        B=WriteMatrix(B);
    }
}
void progr4(){
    int choice=0;
    cout<<"\nBan chon tuong tac voi ma tran A (bam 1, neu khong bam 2) ";
    cin>> choice;
    if(choice==1){
        TransformMatrix(A);
    }else{
        TransformMatrix(B);
    }
}
void work (int status){
        system("cls");
        switch (status){
        case 1:
            progr1();
            break;
        case 2:
            progr2();
            break;
        case 3:
            progr3();
            break;
        case 4:
            progr4();
            break;
        case 5:
            progr5();
            break;
        default:
            break;
        }
    
    getch();
}

