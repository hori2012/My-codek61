#include<bits/stdc++.h>
#include<math.h>
#include<conio.h>
#define run() int T; cin>>T; cin.ignore(); while(T--)
#define MAX 10
using namespace std;
//Ham Lagrange
void Lagrange(){
    float x[7],y[7];
    int n;
	cout<<"Nhap n:"; 
	cin>>n;
    for(int i=0;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    cout<<setiosflags(ios::showpoint)<<setprecision(5);
    run(){
    float f=0, xx;
    cin>>xx;
    for(int i=0;i<=n;i++){
        float p=1;
        for(int j=0;j<=n;j++)
        if(j!=i) p*=(xx-x[j])/(x[i]-x[j]);
        f+=y[i]*p;
    }
    cout<<"f("<<xx<<")="<<f<<endl; 
    }
}
//Ham Newton tren luoi Deu
void NewtonLuoiDeu(){
    int n, l, t, k;
    cout<<"Enter n: ";    cin>>n;
    float x[n], y[n], p[n][n], c, kq;
    for(int i=0; i<n;i++){
        cout<<"Enter x["<<i<<"], y["<<i<<"]: ";
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<n;i++){
        p[i][0]=x[i];
        p[i][1]=y[i];
    }
    int z=1;
	float h;
	for(int i=0; i<n;i++){
		k=i+2;
		for(int t=1;t<n;t++){
			h=(p[t][k-1]-p[t-1][k-1]);
			p[t][k]=(p[t][k-1]-p[t-1][k-1])/(z*(i+1) *pow(h,i+1));
		}
	}
    for(int i=0; i<n;i++){
        for(int j=0; j<n+2;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter number need to calc: ";
    cin>>c;
    float mul;
    for(int i=0; i<n;i++){
        mul=1;
        for(int j=0; j<i;j++){
            mul *= (c-x[j]);
        }
        kq= kq+p[i][i+1]*mul;
    }
    cout<<"Answer: "<<kq<<endl;
}
//Ham Newton tren Khong luoi Deu
void NewtonLuoiKhongDeu(){
    int n, l, t, k;
    cout<<"Enter n: ";   
    cin>>n;
    float x[n], y[n], p[n][n], c, kq;
    for(int i=0; i<n;i++){
        cout<<"Enter x["<<i<<"], y["<<i<<"]: ";
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<n;i++){
        p[i][0]=x[i];
        p[i][1]=y[i];
    }
    l = 1;
    for(int j=0;j<n;j++){
        k=j+2;
        for(t = l; t<n; t++){
            p[t][k]=(p[t][k-1]-p[t-1][k-1])/(x[t]-x[t-1]);
        }
        l=l+1;
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n+2;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter number need to calc: ";
    cin>>c;
    float mul;
    for(int i=0; i<n;i++){
        mul=1;
        for(int j=0; j<i;j++){
            mul *= (c-x[j]);
        }
        kq= kq+p[i][i+1]*mul;
    }
    cout<<"Answer: "<<kq<<endl;
}
//Ham tinh f(x) tai x
float f_x(float x){
	float a;
	a=exp(-x)*sin(x);
	return a;
} 
//Ham tinh bang pp Hinh Thang
void HinhThang(){
	int n;
	float a,b,h;
	cout<<"Nhap can duoi a: ";
	cin>>a;
	cout<<endl;
	cout<<"Nhap can tren b: ";
	cin>>b;
	cout<<endl;
	cout<<"Nhap so doan n: ";
	cin>>n;
	cout<<endl;
	h=(b-a)/n;
	float x,s,tp;
	x=a;
	s=(f_x(a)+f_x(b))/2;
	for(int i=1; i<=n; i++){
		x=x+h;
		s=s+f_x(x);
	}
	tp=s*h;
	cout<<"Gia tri gan dung cua tich phan la: "<<tp<<endl;
}
//Ham tinh f(x) tai x
float f_x1(float x){
	float a=1/(1+x*x);
	return a;
}
//Ham tinh bang pp Simpson
void Simpson(){
	int n;
	float a,b,h;
	cout<<"Nhap can duoi a: ";
	cin>>a;
	cout<<endl;
	cout<<"Nhap can tren b: ";
	cin>>b;
	cout<<endl;
	cout<<"Nhap so doan n: ";
	cin>>n;
	cout<<endl;
	h=(b-a)/n;
	float x2, x4,y2, y4, tp;
	x2=a+h;
	x4=a+h/2;
	y2=f_x1(x2);
	y4=f_x1(x4);
	for(int i=1; i<=n-2;i++){
		x2+=h;
		x4+=h;
		y2+=f_x1(x2);
		y4+=f_x1(x4);
	}
	y2=2*y2;
	y4=4*(y4+f_x1(x4+h));
	tp=h*(y2+y4+f_x1(a)+f_x1(b))/6;
	cout<<"Gia tri gan dung cua tich phan la: "<<tp<<endl;
}
//Ham Gauss
void Gauss(){
	float A[MAX][MAX], B[MAX], X[MAX];
	int n,i,j,k;
	float s;
	cout<<"Nhap so luong an n: ";
	cin>>n;
	cout<<endl;
	cout<<"Nhap cac he so cua x ( ma tran A)"<<endl;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=n;j++){
			cout<<"a["<<i<<"]"<<"["<<j<<"] = ";
			cin>>A[i][j];
			cout<<endl;
		}
	}
	cout<<"Ma tran A da nhap : "<<endl;
	for(int i=1; i<=n;i++){
		for (int j=1; j<=n;j++){
			cout<<"\t"<<A[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<"Nhap cac he so tu do (ma tra B)"<<endl;
	for(int i=1;i<=n;i++){
		cout<<"b["<<i<<"] = ";
		cin>>B[i];
		cout<<endl; 
	}		
	cout<<"Ma tran B da nhap : "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"\t"<<B[i]<<endl;
	}
	for (int k=1;k<=n-1;k++){
		for (i=k+1;i<=n;i++){ 
			B[i]=B[i]-B[k]*A[i][k]/A[k][k]; 
			for (j=k+1;j<=n;j++){
				A[i][j]=A[i][j]-A[k][j]*A[i][k]/A[k][k];
			}
 		}
	} 
	if(A[n][n]==0){
		if(B[n]==0)
			cout<<"He pt vo nghiem !"<<endl;
		else 
			cout<<"He pt co vo so nghiem !"<<endl;	
	}
	else{
		X[n]=B[n]/A[n][n];
		for(int i=n-1;i>=1;i--){
			s=0;
			for(int k=i+1;k<=n;k++){
				s=s+A[i][k]*X[k];
				X[i]=(B[i]-s)/A[i][i];
			}
		}
	}
	cout<<"nghiem cua ht pt "<<endl;
	for(int i=1;i<=n;i++){
		cout<<"x"<<i<<"= "<<X[i];
		cout<<endl;
	}
}
//Ham Jacobi
void Jacobi(){
    double a[10][10],x[10],y[10];
    int i,j,n;
    char ch;
    cout<<"Enter n: ";
    cin>>n;
    for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++)
                {
                    cout<<"a"<<i<<j<<" = ";
                    cin>>a[i][j];
                }
            cout<<"b"<<i<<" = ";
            cin>>a[i][j];
            x[i] = y[i] = 0;
        }
    cout<<endl<<"The results are as follows...."<<endl<<
           "press 'enter' key to continue iterations &"
           " press 'q' to stop iterations...."<<endl;
    while(ch != 'q'){
            for(i = 1; i <= n; i++){
                    for(j = 1; j <= n; j++)
                        {
                            if(i == j) continue;
                            x[i] = x[i] - a[i][j]*y[j];
                        }
                    x[i] = x[i] + a[i][j];
                    x[i] = x[i]/a[i][i];
                }
            for(i = 1; i <= n; i++){
                    y[i] = x[i];
                    cout<<"x"<<i<<" = "<<x[i];
                    x[i] = 0;
                }
            ch = getch();
            cout<<endl;
    }
}
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
//Tinh da thuc tai x
double f(double*A, int Bac, double x) {
    double KetQua = A[0];
   for(int i=1; i<= Bac; i++)
      KetQua=KetQua*x + A[i];
   return KetQua;
}
//Tinh chia doi
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
//tong quat chung tinh bang pp Chia Doi
void ChiaDoi(){
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
    cout<<"Nghiem x = "<<PPChiaDoi(Fx,n,a,b,Epxilon)<<endl;
    getch();
    delete Fx;
}
//Tinh PP Day Cung
double PPDayCung(double*A, int Bac, double a, double b, double Epxilon){
    double x,E;
    do{
    	x=(a*f(A, Bac, b) - b*f(A, Bac, a)) / (f(A, Bac, b) - f(A, Bac, a));
		if(f(A, Bac, x)*f(A, Bac, a) > 0){
			a=x;
		}
		else {
			b=x;
		}
        E = fabs(b-a);
    } while(E > Epxilon);
    return x;
}
//Tong quat tinh Day Cung
void DayCung(){
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
   cout<<"Nghiem x = "<<PPDayCung(Fx,n,a,b,Epxilon)<<endl;
   getch();
   delete Fx;
}
//Dao Ham Da Thuc
double*DaoHam(double*A, int Bac){
   double* temp = new double[Bac]; 
   for(int i=0; i < Bac; i++)
      temp[i]=(Bac-i)*A[i];
   return temp;
   A[Bac]=0;
}
//Tinh bang pp Tiep Tuyen
double PPTiepTuyen(double*A, int Bac, double a, double b, double Epxilon){
    double x0,x1,E;
    double* fx = DaoHam(A,Bac);
	double t=(a*f(A, Bac, b) - b*f(A, Bac, a)) / (f(A, Bac, b) - f(A, Bac, a));
	if(f(A, Bac, t)*f(A, Bac, a) < 0){
		x0=a;
	}
	else {
		x0=b;
	}
    do{
        x1 = x0 - f(A,Bac,x0)/f(fx,Bac-1,x0);
        E = fabs(x1-x0);
        x0 = x1;
    } while(E > Epxilon);
    return x1;
}
//Tong quat chung Tiep tuyen
void TiepTuyen(){
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
   cout<<"Nghiem x = "<<PPTiepTuyen(Fx,n,a,b,Epxilon)<<endl;
   getch();
   delete Fx;
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
//Tong quat chung cua pp Lap Don
void LapDon(){
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
   cout<<"Nghiem x = "<<PPLapDon(Fx,n,a,b,Epxilon)<<endl;
   getch();
   delete Fx;
}
void Menu(){
	int Key;
	do{
		cout<<"*****-------------MENU------------*****"<<endl;
		cout<<"1.Noi Suy Ham so Lagrange !"<<endl;
	    cout<<"2.Noi Suy Ham so Newton tren Luoi Deu !"<<endl;
	    cout<<"3.Noi Suy Ham so Newton Tren Luoi Khong Deu !"<<endl;
	    cout<<"4.Tinh Tich Phan Gan Dung theo CT Hinh Thang !"<<endl;
	    cout<<"5.Tinh Tich Phan Gan Dung theo CT Simpson !"<<endl;
	    cout<<"6.Giai HPT Tuyen Tinh Bang PP Gauss !"<<endl;
	    cout<<"7.Giai HPT Tuyen Tinh Bang PP Jacobi !"<<endl;
	    cout<<"8.Tinh Nghiem Gan Dung PT 1 Bien PP Chia Doi !"<<endl;
	    cout<<"9.Tinh Nghiem Gan Dung PT 1 Bien PP Day Cung !"<<endl;
	    cout<<"10.Tinh Nghiem Gan Dung PT 1 Bien PP Tiep Tuyen !"<<endl;
	    cout<<"11.Tinh Nghiem Gan Dung PT 1 Bien PP Lap !"<<endl;
	    cout<<"0.Thoat Chuong Trinh !"<<endl;
	    cout<<"Nhap key:";
	    cin>>Key;
        switch(Key){
		    case 1:
			    cout<<"*****--------Noi Suy Ham so Lagrange-------*****"<<endl;
			    Lagrange();
		    	cout<<"-------------------------------------------------"<<endl;
		    	cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
		    case 2:
		        cout<<"*****--------Noi Suy Ham so Newton tren Luoi Deu-------*****"<<endl;
			    NewtonLuoiDeu();
		     	cout<<"------------------------------------------------------------"<<endl;
		     	cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
		    case 3:
		        cout<<"*****--------Noi Suy Ham so Newton Tren Luoi Khong Deu-------*****"<<endl;
			    NewtonLuoiKhongDeu();
		    	cout<<"------------------------------------------------------------------"<<endl;
		    	cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
	     	case 4:
		        cout<<"*****--------Tinh Tich Phan Gan Dung theo CT Hinh Thang-------*****"<<endl;
                HinhThang();
		        cout<<"-------------------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
	     	case 5:
		        cout<<"*****--------Tinh Tich Phan Gan Dung theo CT Simpson-------*****"<<endl;
		        Simpson();
		        cout<<"-------------------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
		    case 6:
		        cout<<"*****-------Giai HPT Tuyen Tinh Bang PP Gauss---------*****"<<endl;
		        Gauss();
		        cout<<"-----------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
	    	case 7:
		        cout<<"*****-------Giai HPT Tuyen Tinh Bang PP Jacobi---------*****"<<endl;
		        Jacobi();
		        cout<<"-----------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
	        case 8:
	  	        cout<<"*****-------Tinh Nghiem Gan Dung PT 1 Bien PP Chia Doi---------*****"<<endl;
		        ChiaDoi();
		        cout<<"-----------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
		    case 9:
		    	cout<<"*****-------Tinh Nghiem Gan Dung PT 1 Bien PP Day Cung---------*****"<<endl;
		        DayCung();
		        cout<<"-----------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;		        
	    	case 10:
		        cout<<"*****-------Tinh Nghiem Gan Dung PT 1 Bien PP Tiep Tuyen---------*****"<<endl;
		        TiepTuyen();
		        cout<<"-----------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;
			case 11:
			    cout<<"*****-------Tinh Nghiem Gan Dung PT 1 Bien PP Lap--------*****"<<endl;
		        LapDon();
		        cout<<"-----------------------------------------------------------"<<endl;
		        cout<<"An phim bat ky de tiep tuc !"<<endl;
		    	getch();
		    	break;		 
		    case 0:
		    	cout<<"BAN DA THOAT !"<<endl;
		    	break;
		    default:
		    	cout<<"Hay Nhap Lai!"<<endl;
		    	break;
	    }
	}while(Key != 0);
}
int main(){
	Menu();
}
