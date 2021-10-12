//van cong hao 
//mssv: 6151071045
#include<iostream>
using namespace std;
class  Student{
	private:
		string Fullname;
		float Math,Literature;
	public:
		static int count;
		Student();
		Student(string fullname);
		Student(const Student &st);
		~Student();
		friend istream& operator >> (istream &is, Student &st);
		friend ostream& operator << (ostream &os, const Student&st );
		float getMath();
		float getLiterature();
		bool operator > (Student st1);
		bool operator < (Student st1);
		bool operator >= (Student st1);
		bool operator <= (Student st1);
		bool operator == (Student st1);
		bool operator != (Student st1);
		void operator = (Student st1);	
};
int Student :: count=0;
Student::Student(){
	this->Fullname= "cao nam";
	this->Math = 5;
	this->Literature = 5;
	count ++;
}
Student::Student(string fullname){
	this->Fullname= fullname;
	this->Math=0;
	this->Literature=0;
	count++;
}
Student::Student(const Student &st){
	this->Fullname=st.Fullname;
	this->Math=st.Math;
	this->Literature=st.Literature;
//	count++;
}
Student::~Student(){
	
}
istream& operator >>(istream& is, Student& st1){
	cout<<"Enter fullname: "<<endl;
	fflush(stdin);
	getline(is, st1.Fullname);
	cout<<"Enter point math: "<<endl;
	is>>st1.Math;
	cout<<"Enter point literature: "<<endl;
	is>>st1.Literature;
	return is;
}
ostream& operator <<(ostream& os, const Student&st1){
	os<<"STT Student: "<<st1.count<<endl;
	os<<"Fullname: "<<st1.Fullname<<endl;
	os<<"Math: "<<st1.Math<<endl;
	os<<"Literature: "<<st1.Literature<<endl;
	os<<"===================="<<endl;
	return os;
}
float Student::getMath(){
	return this->Math;
}
float Student::getLiterature(){
	return this->Literature;
}
bool Student:: operator >(Student st1){
	if((getMath()+ getLiterature())/2 >(st1.getMath() +st1.getLiterature())/2)
		return true;
	else 
		return false;	
}
bool Student:: operator <(Student st1){
	if((getMath()+ getLiterature())/2 <(st1.getMath() +st1.getLiterature())/2)
		return true;
	else 
		return false;	
}
bool Student:: operator >=(Student st1){
	if((getMath()+ getLiterature())/2 >=(st1.getMath() +st1.getLiterature())/2)
		return true;
	else 
		return false;	
}
bool Student:: operator <=(Student st1){
	if((getMath()+ getLiterature())/2 <=(st1.getMath() +st1.getLiterature())/2)
		return true;
	else 
		return false;	
}
bool Student:: operator ==(Student st1){
	if((getMath()+ getLiterature())/2 ==(st1.getMath() +st1.getLiterature())/2)
		return true;
	else 
		return false;	
}
bool Student:: operator !=(Student st1){
	if((getMath()+ getLiterature())/2 !=(st1.getMath() +st1.getLiterature())/2)
		return true;
	else 
		return false;	
}
void Student :: operator = (Student st1){
	this->Fullname=st1.Fullname;
	this->Math=st1.Math;
	this->Literature=st1.Literature;

}

int main(){
	Student a;
	cout<<a;
	Student b("ha nam");
	cout<<b;
	Student d(a);
	cout<<d;
	if(a!=b) 
		cout<<"a b khac nhau"<<endl;
	cout<<"===================="<<endl;
	Student c;	
	cout<<"enter information c: "<<endl;
	cin>>c;
	cout<<c;
	if(a<c)
		cout<<"c lon hon"<<endl;
	Student e;
	e=a;
	cout<<e;	
	return 0;
}
