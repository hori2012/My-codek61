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
double f(double*A, int Bac, double x) {
    double KetQua ;
   for(int i=0; i< Bac-1; i++)
      KetQua=KetQua + A[i]*x +A[i+1] ;
   return KetQua=(-A[Bac]-KetQua)/A[Bac-1];
}

/*Tinh dao ham cua ham so y =f(x)*/
double*DaoHam(double*A, int Bac){
   double* temp = new double[Bac]; 
   for(int i=0; i < Bac; i++)
      temp[i]=(Bac-i)*A[i];
   return temp;
   A[Bac]=0;
}

/*Phuong Phap Lap Don*/
double PPLapDon(double*A, int Bac, double a, double b, double Epxilon){
    double x0=(a+b)/2,E,q;
    double x=x0;
    double xpre;
    double *fx;
    fx=DaoHam(A, Bac);
    q=f(fx, Bac-1, x0);
    while(q>1){
    	q=q-0.5;
	}
    do{
    	xpre=x;
    	x=f(A, Bac, xpre);
    	E=q*fabs(x-xpre)/(1.0-q);
	}while(E > Epxilon);
    return x;
}

/*Chuong Trinh Chinh*/
int main(){
   double*Fx,a,b,Epxilon;
   int n;
   cout<<"Nhap Vao Bac Cua Phuong Trinh:";
   cin>>n;
   cout<<endl;
   cout<<"Luu y: nhap he so truoc A[Bac - 1] khac 0 !!"<<endl; 
   Fx = NhapDaThuc(n);
   XuatDaThuc(Fx,n);
   cout<<"\nNhap Khoang Cach Ly Nghiem [a,b]:\n";
   cout<<"a = ";
   cin>>a;
   cout<<"b = ";
   cin>>b;
   cout<<"Nhap Sai So Gan Dung Epxilon: ";
   cin>>Epxilon;
   cout<<"Nghiem x = "<<PPLapDon(Fx,n,a,b,Epxilon);
   getch();
   delete Fx;
   return 0;
}
