//van cong hao
//6151071045
//De tai: quan ly sinh vien
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Profile{
	private:
		string fullname, mssv, province, Class;
		float gpa;
	public:
		friend istream& operator >> (istream& is, Profile &pf1);
		friend ostream& operator << (ostream& os, Profile &pf1);
		float getGpa();
};
class Practise:public Profile {
	private:
		int lesson, allow, n_allow;
		float practise;
		int s_lesson;
	public:
		friend istream& operator >> (istream& is , Practise &pt1);
		friend ostream& operator << (ostream& os, Practise &pt1);
		float point();
		void setPractise(float x);
		float getPractise();
};
class Scholarship : public Practise{
	private:
		string namebank;
		int numberbank;
	public:
		friend istream& operator >> (istream& is, Scholarship &ip1);
		friend ostream& operator << (ostream& os, Scholarship &ip1);
		bool check();	
};
class Student: public Scholarship{
	public:
		friend istream& operator >> (istream& is, Student &st1);
		friend ostream& operator << (ostream& os, Student &st1);
		
};
struct Node{
	Student data;
	Node *next;
};
class Slist{
	private:
		long size;
		Node *head;
		Node *tail;
	public:
		Slist();
		Slist(long size, Node *head, Node *tail);
		Slist(const Slist &slist);
		~Slist();
		Node* createNode(Student st);
		void addLast(Student st);
		Node* previous(Node *p);
		void remove(Node *p);
		void traverse();
		void list_student(int &n);
		void list_sholarship();
		void Delete(int i);
			
};
istream& operator >> (istream& is, Profile &pf1){
	cout<<"Enter of the name: ";
	fflush(stdin);
	getline(is, pf1.fullname);
	cout<<endl;
	cout<<"Enter of the mssv: ";
	fflush(stdin);
	getline(is, pf1.mssv);
	cout<<endl;
	cout<<"Enter of the class: ";
	fflush(stdin);
	getline(is, pf1.Class);
	cout<<endl;
	cout<<"Enter of the province: ";
	fflush(stdin);
	getline(is, pf1.province);
	cout<<endl;
	cout<<"Enter of the gpa: ";
	is>>pf1.gpa;
	cout<<endl;
	return is;
}
ostream& operator << (ostream& os, Profile &pf1){
	os<<"Fullname: "<<pf1.fullname<<endl;
	os<<"Mssv: "<<pf1.mssv<<endl;
	os<<"Class: "<<pf1.Class<<endl;
	os<<"Provice: "<<pf1.province<<endl;
	os<<"GPA: "<<pf1.gpa<<endl;
	return os;
}
float Profile::getGpa(){
	return this->gpa;
}
istream& operator >> (istream& is, Practise &pt1){
	cout<<"Enter of the sum lesson: ";
	is>>pt1.s_lesson;
	cout<<endl;
	cout<<"Enter of the lesson: ";
	is>>pt1.lesson;
	cout<<endl;
	cout<<"Enter of the allow: ";
	is>>pt1.allow;
	cout<<endl;
	cout<<"Enter of the not allow: ";
	is>>pt1.n_allow;
	cout<<endl;
	return is;
}
ostream& operator << (ostream& os, Practise &pt1){
	os<<"Sum lesson: "<<pt1.s_lesson<<endl;
	os<<"Lesson: "<<pt1.lesson<<endl;
	os<<"Allow: "<<pt1.allow<<endl;
	os<<"Not allow: "<<pt1.n_allow<<endl;
	os<<"Point practise: "<<pt1.getPractise()<<endl;
	return os;
}
float Practise::point(){
	int cur;   
	int pre;
	float temp;
	cur= allow + n_allow;
	if(cur > (float)(s_lesson * 0.15)){
		temp=0;
	}
	else{
		pre=lesson*5 + allow*3 + n_allow*2;
		temp=(float)(pre*1.0/s_lesson);
	}
	return temp;
} 
void Practise::setPractise(float x){
	this->practise=x;
}
float Practise::getPractise(){
         setPractise(point());
	return this->practise;
}
istream& operator >> (istream& is, Scholarship &ip1){
	if(ip1.check()){
		cout<<"Confirm Scholarship !!"<<endl;
		cout<<"Enter of the name bank: ";
		fflush(stdin);
		getline(is, ip1.namebank);
		cout<<endl;
		cout<<"Enter of the number bank: ";
		is>>ip1.numberbank;
		cout<<endl;
		return is;
	}
	cout<<"Don't Scholarship !!"<<endl;
	ip1.namebank="0";
	ip1.numberbank=0;
}
ostream& operator << (ostream& os, Scholarship &ip1){
		os<<"Name bank: "<<ip1.namebank<<endl;
		os<<"Number bank: "<<ip1.numberbank<<endl;
		return os;
}
bool Scholarship::check(){
	if(getGpa() >= 7.5 && getPractise() >= 4)
		return true;
	else 
		return false;	
}
istream& operator >> (istream& is, Student &st1){
	Profile *pf1=static_cast<Profile *>(&st1);
	is>>*pf1;
	Practise *pr1=static_cast<Practise *>(&st1);
	is>>*pr1;
	Scholarship *sp1=static_cast<Scholarship *>(&st1);
	is>>*sp1;
	return is;
}
ostream& operator << (ostream& os, Student &st1){
	os<<"~~~~~~~~~~~~~~~"<<endl;
	Profile *pf1=static_cast<Profile *>(&st1);
	os<<*pf1;
	Practise *pr1=static_cast<Practise *>(&st1);
	os<<*pr1;
	Scholarship *sp1=static_cast<Scholarship *>(&st1);
	os<<*sp1;
	return os;
}
Slist::Slist(){
	head=NULL;
	tail=NULL;
	size=0;
}
Slist::Slist(long size, Node* head, Node* tail){
	this->size=size;
	this->head=head;
	this->tail=tail;
}
Slist::Slist(const Slist &slist){
	this->size=slist.size;
	this->head=slist.head;
	this->tail=slist.tail;
}
Slist::~Slist(){
	delete head;
	delete tail;
	size=0;
}
Node* Slist::createNode(Student st){
	Node *p= new Node;
	p->data=st;
	p->next=NULL;
	return p;
}
void Slist::addLast(Student st){
	Node *temp=createNode(st);
	if(head==NULL){
		head=tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp; 
	}
	size++;
}
Node* Slist::previous(Node *p){
	Node *temp=head;
	while(temp->next !=p){
		temp=temp->next;
	}
	return temp;
}
void Slist::remove(Node *p){
	Node *q=previous(p);
	q->next=p->next;
	delete p;
	size--;
}
void Slist::traverse(){
	Node *p=head;
	cout<<"=====List Information Student======"<<endl;
	while(p!=NULL){
		cout<<p->data;
		p=p->next;
	}
	delete p;
}
void Slist::list_student(int &n){
	Student value;
	do{
		cout<<"Enter the number of the students: ";
		cin>>n;
		cout<<endl;
	}while(n==0);
	for(int i=0;i<n;i++){
		cout<<"Student "<<i+1<<": "<<endl;
		cin>>value;
		addLast(value);
	}
}
void Slist::list_sholarship(){
	cout<<"======List confirm Scholarship====== "<<endl;
	Node *p=head;
	while(p!=NULL){
		if(p->data.check()){
			cout<<p->data;
		}
		p=p->next;
	}
	delete p;
}
int main(){
	Slist list;
	int n;
	list.list_student(n);
	list.traverse();
	list.list_sholarship();
	return 0;
}
//menu: 
//1 Nhap thong tin sinh vien
//2 Xuat thong tin tat ca sinh vien
//3 them sinh vien
//4 xoa sinh vien
//5 danh sach sinh vien duoc nhan hoc bong
//6 thoat 
//7 du tru : sua thong tin sinh vien
