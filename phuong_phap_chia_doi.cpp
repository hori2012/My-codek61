#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
/*Nhap vao mot da thuc luu he so trong A[] va co Bac*/
double*NhapDaThuc(int Bac) {
   double *A = new double [Bac+1];
   for(int i= 0; i<=Bac; i++) {
      cout<<"a"<<i<<" = ";
      cin>>A[i];
   }
   return A;
}

/*Xuat da thuc co he so A[] va Bac*/
void XuatDaThuc( double*A,int Bac) {
   string f="f(x)";
   cout<<"Da Thuc Vua Nhap la:\n";
   cout<<f<<"="<<A[Bac];
   for(int i=0; i< Bac; i++){
      if(A[i]>0) {
         cout<<" + "<<A[i]<<"x^"<<Bac-i;
      }
      if(A[i]<0) {
         cout<<A[i]<<"x^"<<Bac-i;
      }
   }
}

/*Tinh gia tri cua da thuc tai diem x*/
/*Su dung luoc do hoocner*/
double f(double*A, int Bac, double x) {
    double KetQua = A[0];
    for(int i=1; i<= Bac; i++)
      KetQua=KetQua*x + A[i];
    return KetQua;
}
/*Phuong phap chia doi*/
double PPChiaDoi(double*A, int Bac, double a, double b, double Epxilon){
   double x=(b+a)/2, E = fabs(b-a);
   while(E>Epxilon){
        if(f(A,Bac,a)*f(A,Bac,x)<=0)
            b = x;
        else
            a = x;
        E = fabs(b -a);
        x = (b + a)/2;
   }
   return a;
}
/*Chuong Trinh Chinh*/
int main(){
   double*Fx,a,b,Epxilon;
   int n;
   cout<<"Nhap Vao Bac Cua Phuong Trinh:";
   cin>>n;
   Fx = NhapDaThuc(n);
   XuatDaThuc(Fx,n);
   cout<<"\nNhap Khoang Cach Ly Nghiem [a,b]:\n";
   cout<<"a = ";
   cin>>a;
   cout<<"b = ";
   cin>>b;
   cout<<"Nhap Sai So Gan Dung Epxilon: ";
   cin>>Epxilon;
   cout<<"Nghiem x = "<<PPChiaDoi(Fx,n,a,b,Epxilon);
   getch();
   delete Fx;
   return 0;
}
