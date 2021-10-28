//phuong phap hinh thang
//tinh tich phan gan dung cho bieu thuc: x*sin(x) 
#include<iostream>
#include<cmath>
using namespace std;
float f_x(float x){
	float a;
	a=exp(-x)*sin(x);
	return a;
} 
int main(){
	int n;
	float a,b,h;
	cout<<"Phuong phap hinh thang !!!"<<endl;
	cout<<"=============="<<endl;
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
	return 0;
	
}
