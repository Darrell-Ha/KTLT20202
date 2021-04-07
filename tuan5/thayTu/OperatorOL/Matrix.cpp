#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

#define Mac_randomIN(a,b) rand()%(b-a+1)+a
using namespace std;

class Matrix {
    private:
        string nameMatrix;
        int arr[10][10];
        int row, column;
    public:
        Matrix (string nameMatrix ="", int row = 1, int column = 1) {
            this->nameMatrix = nameMatrix;
            this->row = row;
            this->column = column;
        }
        /// Tích vô hướng /////
        friend long scalar(Matrix v1, Matrix v2){
            long scalar = 0;
            if(v1.row==1 && v2.row==1){
                if(v1.column!=v2.column){
                    cout << "ERROR!!: NOT HAVING SAME COLUMN\n";
                    return -1;
                }else{
                    for(int i = 0; i<v1.column; i++){
                        scalar+=v1.arr[0][i]*v2.arr[0][i];
                    }
                    return scalar;
                }
            }else{
                cout << "ERROR!!: NOT A VECTO\n";
                return -1;
            }
        }
        void RandomValuetoMatrix(){
            int row = this->row;
            int col = this->column;
            for(int i = 0; i<row ;i++){
                for(int j = 0; j<col; j++){
                    this->arr[i][j] = Mac_randomIN(-20,20);
                }
            }
        }
        friend istream &operator >>(istream &is, Matrix &a){
            cout<<"\nNhap gia tri cho ma tran " << a.nameMatrix <<"\n";
            cout << "Co " << a.row <<" hang, " << a.column << " cot: \n";
            for(int i=0; i<a.row; i++){
                for(int j=0; j<a.column;j++){
                    is >> a.arr[i][j];
                }
            }
            return is;
        }
        friend ostream &operator <<(ostream &os, Matrix a){
            os << a.nameMatrix << " = ";
            if(a.row-1!=0){
                for(int i=0; i<a.row; i++){
                    os << "\n\t";
                    for(int j=0; j<a.column;j++){
                        os << a.arr[i][j]<<" " <<setw(3);
                    }
                }
            }else{
                os<<"\t( ";
                for(int i=0;i<a.column;i++){
                    os << a.arr[0][i]<<", ";
                }
                os<<")"; 
            }
            os<<"\n";
            return os;
        }
        friend Matrix operator + (Matrix a, Matrix b){
            Matrix sum = Matrix(a.nameMatrix+" + "+b.nameMatrix, a.row, a.column);
            if(a.row != b.row || a.column != b.column){
                cout <<"ERROR!!!\n";
            }else{
                for(int i = 0; i<sum.row; i++){
                    for(int j = 0; j<sum.column; j++){
                        sum.arr[i][j] = a.arr[i][j] + b.arr[i][j];
                    }
                }
            }
            return sum;
        }
        friend Matrix operator - (Matrix a, Matrix b){
            Matrix sub = Matrix(a.nameMatrix+" - "+b.nameMatrix, a.row, a.column);
            if(a.row != b.row || a.column != b.column){
                cout <<"ERROR!!!\n";
            }else{
                for(int i = 0; i<sub.row; i++){
                    for(int j = 0; j<sub.column; j++){
                        sub.arr[i][j] = a.arr[i][j] - b.arr[i][j];
                    }
                }
            }
            return sub;
        }
        friend Matrix operator *(Matrix a, Matrix b){
            Matrix mul = Matrix(a.nameMatrix+" * "+b.nameMatrix, a.row, b.column);
            if(a.column!=b.row){
                cout << "ERROR!!\n";
            }else{
                for(int i=0;i<mul.row;i++){
                    for(int j=0;j<mul.column;j++){
                        int sum=0;
                        for(int col=0;col<mul.column;col++){
                            sum+=a.arr[i][col]*b.arr[col][j];
                        }
                        mul.arr[i][j]=sum;
                    }
                }
            }
            return mul;
        }

};


int main(){
    /** 
      * 1.
      *  Quy định số hàng, số cột chỉ từ 1 đến 5 nên random trong khoảng này
      *     Matrix a = Matrix("A", Mac_randomIN(1,5), Mac_randomIN(1,5));
      *     Matrix b = Matrix("B", Mac_randomIN(1,5),Mac_randomIN(1,5));
      *  Muốn quy định nhiều hơn thì thay đổi cận trong Mac_randomIN(a,b)
      * 
      * 2.
      *     cin >> a ;       hoàn toàn có thể nhập nhưng để nhanh
      *     cin >> b;        nên bài code để random giá trị cho các ô
      * 
      * 3.
      *  Dưới đây là trường hợp đặc biệt
      *     (hai matran có số hàng và cột bằng nhau)
      *         
    **/  
    srand(time(NULL));
    Matrix a = Matrix("A",4,4);
    Matrix b = Matrix("B",4,4);
    a.RandomValuetoMatrix();
    b.RandomValuetoMatrix();
    cout << a;
    cout << b;
    cout << a * b << "\n";
    cout << a + b << "\n";
    return 0;
}