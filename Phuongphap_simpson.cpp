//Phuong phap Simpson
// tinh tich phan gan dung cho bieu thuc : 1/(1+x^2)
#include<iostream>
#include<cmath>
using namespace std;
float f_x(float x){
	float a=1/(1+x*x);
	return a;
}
int main(){
	int n;
	float a,b,h;
	cout<<"Phuong phap Simpson !!"<<endl;
	cout<<"==============="<<endl;
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
	y2=f_x(x2);
	y4=f_x(x4);
	for(int i=1; i<=n-2;i++){
		x2+=h;
		x4+=h;
		y2+=f_x(x2);
		y4+=f_x(x4);
	}
	y2=2*y2;
	y4=4*(y4+f_x(x4+h));
	tp=h*(y2+y4+f_x(a)+f_x(b))/6;
	cout<<"Gia tri gan dung cua tich phan la: "<<tp<<endl;
	return 0;
}
