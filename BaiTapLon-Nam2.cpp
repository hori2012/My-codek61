//van cong hao
//6151071045
//De tai: quan ly sinh vien
//menu: 
//1 Nhap thong tin sinh vien
//2 Xuat thong tin tat ca sinh vien
//3 them sinh vien
//4 xoa sinh vien
//5 danh sach sinh vien duoc nhan hoc bong
//6 thoat 
//7 du tru : sua thong tin sinh vien
#include<iostream>
#include<string>
#include<cmath>
#include<fstream>
using namespace std;

class Profile{
	private:
		string  fullname, mssv, province, Class;
		float gpa;
	public:
		friend istream& operator >> (istream& is, Profile &pf1);
		friend ostream& operator << (ostream& os, Profile &pf1);
		float getGpa();
		string getName();
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
string Profile::getName(){
	return this->fullname;
}

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
class Scholarship : public Practise{
	private:
		string namebank;
		int numberbank;
	public:
		friend istream& operator >> (istream& is, Scholarship &ip1);
		friend ostream& operator << (ostream& os, Scholarship &ip1);
		bool check();	
};
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

class Student: public Scholarship{
	public:
		friend istream& operator >> (istream& is, Student &st1);
		friend ostream& operator << (ostream& os, Student &st1);
		
};

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

struct Node{
	Student data;
	Node *next;
};

class Student_Management{
	private:
		long size;
		Node *head;
		Node *tail;
	public:
		Student_Management();
		Student_Management(long size, Node *head, Node *tail);
		Student_Management(const Student_Management &slist);
		~Student_Management();
		Node* createNode(Student st);
		void addLast(Student st);
		Node* previous(Node *p);
		void removeFirst();
		void removeLast();
		void remove(Node *p);
		void traverse();
		void list_student(int &n);
		void list_sholarship();
		void searchName();
		void Delete();
		void add_student();
			
};

Student_Management::Student_Management(){
	head=NULL;
	tail=NULL;
	size=0;
}
Student_Management::Student_Management(long size, Node* head, Node* tail){
	this->size=size;
	this->head=head;
	this->tail=tail;
}
Student_Management::Student_Management(const Student_Management&slist){
	this->size=slist.size;
	this->head=slist.head;
	this->tail=slist.tail;
}
Student_Management::~Student_Management(){
	delete head;
	delete tail;
	size=0;
}
Node* Student_Management::createNode(Student st){
	Node *p= new Node;
	p->data=st;
	p->next=NULL;
	return p;
}
void Student_Management::addLast(Student st){
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
Node* Student_Management::previous(Node *p) {
	Node *t = head;
	while (t->next != p)
		t = t->next;
	return t;
}
void Student_Management::removeFirst(){
	if(size==0)
		return;
	Node* temp=head;
	head=head->next;
	delete temp;
	size --;	
}
void Student_Management::removeLast(){
	if(size==0)
		return;
	if(size==1){
		delete head;
		size--;
		return;
	}
	Node *p=previous(tail);
	Node *temp=tail;
	p->next=NULL;
	tail=p;
	delete temp;
	size--;
		
}
void Student_Management::remove(Node *p) {
	if (p == head) {
		removeFirst();
		return;
	}
	if (p == tail) {
		removeLast();
		return;
	}
	Node *pre = previous(p);
	pre->next = p->next;
	delete p;
	size--;
}
void Student_Management::traverse(){
	Node *p=head;
	fstream File;
	File.open("List_student.txt", ios::out);
	File<<"=====List Information Student======"<<endl;
	while(p!=NULL){
		cout<<p->data;
		File<<p->data;
		p=p->next;
	}
	File.close();
	delete p;
}
void Student_Management::list_student(int &n){
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
void Student_Management::list_sholarship(){
	fstream File;
	File.open("list_scholarship.txt", ios::out);
	File<<"======List confirm Scholarship====== "<<endl;
	cout<<"======List confirm Scholarship====== "<<endl;
	Node *p=head;
	while(p!=NULL){
		if(p->data.check()){
			cout<<p->data;
			File<<p->data;
		}
		else
			cout<<"Don't student confirm scholarship !!"<<endl;
		p=p->next;
	}
	File.close();
	delete p;
}
void Student_Management ::searchName(){
	string str;
	cout<<"Enter the name you want to search: ";
	fflush(stdin);
	getline(cin, str);
	cout<<endl;
	Node* p=head;
	while(p!=NULL){
		if(p->data.getName() == str)
			cout<<p->data;
		p=p->next;	
	}
	delete p;
}
void Student_Management::Delete(){
	string str;
	cout<<"Enter the name you want to delete: ";
	fflush(stdin);
	getline(cin, str);
	cout<<endl;
	Node *p=head;
	while(p!=NULL){
		if(p->data.getName() == str){
			remove(p);
		}
		p=p->next;
	}
	delete p;
}
void Student_Management::add_student(){
	int n;
	cout<<"Enter the number af the add student: ";
	cin>>n;
	if(n==0){
		return;
	}
	Student value;
	for(int i=0; i<n;i++){
		cout<<"Student "<<i+1<<endl;
		cin>>value;
		addLast(value);
	}	
}
int main(){
	Student_Management list;
	int n;
	int choice;
	do{
		cout<<endl;
		cout<<"<-----------------MENU----------------->"<<endl;
		cout<<"1. Nhap thong tin sinh vien"<<endl;
		cout<<"2. Danh sach sinh vien "<<endl;
		cout<<"3. Danh sach sinh vien nhan hoc bong"<<endl;
		cout<<"4. Them sinh vien vao danh sach"<<endl;
		cout<<"5. Xoa sinh vien ra khoi danh sach"<<endl;
		cout<<"6. Sua thong tin sinh vien"<<endl;
		cout<<"7. Tim kiem sinh vien"<<endl;
		cout<<"Nhan phim 0 de thoat !!"<<endl;
		cout<<"<-----------------END----------------->"<<endl;
		cout<<"--> Vui long chon chuc nang: ";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:
				list.list_student(n);
				break;
			case 2:
				cout<<"============LIST STUDENT============"<<endl;
				list.traverse();
				break;
			case 3:
				list.list_sholarship();
				break;
			case 4:
				list.add_student();
				cout<<"Danh sach sau khi them "<<endl;
				list.traverse();
				break;
			case 5:
				list.Delete();
				cout<<"Danh sach sau khi xoa "<<endl;
				list.traverse();
				break;
			case 6:
				break;
			case 7:
				list.searchName();	
			default:
				choice=0;
				break;				
		}
	}while(choice!=0);

	
	return 0;
}
