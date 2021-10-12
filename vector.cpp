//van cong hao
// mssv: 6151071045
#include<iostream>
#include<stdlib.h>
using namespace std;
class Vector{
	private:
		int n;
		float *v;
	public:
		Vector(); 
		Vector(int size);
		Vector(const Vector &vt);
		~Vector();
		friend istream& operator >>(istream& is, Vector &vt1);
		friend ostream& operator <<(ostream& os, const Vector &vt1);
		void operator = (Vector vt1);
		friend Vector operator + (Vector vt1,Vector vt2);
		bool Check(Vector vt1);	
};
Vector::Vector(){
	v= new float[n];
}
Vector::Vector(int size){
	n=size;
	v=new float[n];
}
Vector::Vector(const Vector &vt){
	this->n=vt.n;
	v=new float [vt.n];
	for(int i=0; i<vt.n;i++){
		v[i]=vt.v[i];
	}
	
}
Vector::~Vector(){
	delete [] v;
}
istream& operator >>(istream& is, Vector &vt1){
	cout<<"Enter the number of elements of the vector: "<<endl;
	is>>vt1.n;
	cout<<"Enter of the value element: "<<endl;
	for(int i=0;i<vt1.n;i++){
		cout<<"v"<<"["<<i<<"] : ";
		is>>vt1.v[i];
	}
	cout<<endl;
	return is;
}
ostream& operator <<(ostream& os, const Vector &vt1){
	os<<"The vector entered: ";
	os<<"(";
	for(int i=0;i<vt1.n;i++){
		os<<" "<<vt1.v[i]<<" ";
	}
	os<<")"<<endl;
	return os;
}
void Vector:: operator = (Vector vt1){
	this->n=vt1.n;
	for(int i=0;i<vt1.n;i++){
		v[i]=vt1.v[i];
	}
}
bool Vector::Check(Vector vt1){
	if(n == vt1.n)
		return true;
	else 
		return false;	
} 
Vector operator + (Vector vt1,Vector vt2){
	Vector c;
	c.n=vt1.n;
	for(int i=0;i<vt1.n;i++){
		c.v[i]=vt1.v[i] + vt2.v[i];
	}
	return c;
}

int main(){
	Vector a;
	cout<<"enter vector a: "<<endl;
	cin>>a;
	cout<<a;
	Vector b;
	cout<<"vector b: "<<endl;
//	cin>>b;
	b=a;
	cout<<b;
	Vector c;
	if(a.Check(b)){
		c=a+b;
		cout<<"Sum of the two vector: "<<endl<<c<<endl;
	}
	else
		cout<<"Not sum"<<endl;	
	return 0;
}
