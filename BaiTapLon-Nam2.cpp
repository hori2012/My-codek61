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
		void set_Gpa() ;
};

istream& operator >> (istream& is, Profile &pf1){
	cout<<"Nhap ho ten sinh vien: ";
	fflush(stdin);
	getline(is, pf1.fullname);
	cout<<endl;
	cout<<"Nhap ma so sinh vien: ";
	fflush(stdin);
	getline(is, pf1.mssv);
	cout<<endl;
	cout<<"Nhap lop: ";
	fflush(stdin);
	getline(is, pf1.Class);
	cout<<endl;
	cout<<"Nhap que cua sinh vien: ";
	fflush(stdin);
	getline(is, pf1.province);
	cout<<endl;
	cout<<"Nhap diem trung binh: ";
	is>>pf1.gpa;
	cout<<endl;
	return is;
}
ostream& operator << (ostream& os, Profile &pf1){
	os<<"Ho va ten: "<<pf1.fullname<<endl;
	os<<"MSSV: "<<pf1.mssv<<endl;
	os<<"Lop: "<<pf1.Class<<endl;
	os<<"Que: "<<pf1.province<<endl;
	os<<"Diem trung binh: "<<pf1.gpa<<endl;
	return os;
}
float Profile::getGpa(){
	return this->gpa;
}
string Profile::getName(){
	return this->fullname;
}
void Profile::set_Gpa(){
	float temp;
	cout<<"Nhap diem trung binh thay the: ";
	cin>>temp;
	cout<<endl;
	this->gpa=temp;
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
		int get_n_Allow();
		void set_Lesson();
		void set_Allow();
		void set_n_Allow();
};

istream& operator >> (istream& is, Practise &pt1){
	cout<<"Nhap tong so buoi hoc (1 ki): ";
	is>>pt1.s_lesson;
	cout<<endl;
	cout<<"Nhap so buoi da hoc: ";
	is>>pt1.lesson;
	cout<<endl;
	cout<<"Nhap so buoi nghi co phep: ";
	is>>pt1.allow;
	cout<<endl;
	cout<<"Nhap so buoi nghi khong phep: ";
	is>>pt1.n_allow;
	cout<<endl;
	return is;
}
ostream& operator << (ostream& os, Practise &pt1){
	os<<"Tong so buoi (1 ki): "<<pt1.s_lesson<<endl;
	os<<"So buoi hoc: "<<pt1.lesson<<endl;
	os<<"Nghi co phep: "<<pt1.allow<<endl;
	os<<"Nghi khong phep: "<<pt1.n_allow<<endl;
	os<<"Diem ren luyen: "<<pt1.getPractise()<<endl;
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
int Practise::get_n_Allow(){
	return this->n_allow;
}
void Practise::set_Lesson(){
	int number;
	cout<<"Nhap tong so buoi da hoc: ";
	cin>>number;
	cout<<endl;
	this->lesson=number;
}
void Practise::set_Allow(){
	int number;
	cout<<"Nhap so buoi nghi co phep: ";
	cin>>number;
	cout<<endl;
	this->allow=number;
}
void Practise::set_n_Allow(){
	int number;
	cout<<"Nhap so buoi nghi khong phep: ";
	cin>>number;
	cout<<endl;
	this->n_allow=number;
}

class Scholarship : public Practise{
	private:
		string namebank;
		int numberbank;
	public:
		friend istream& operator >> (istream& is, Scholarship &ip1);
		friend ostream& operator << (ostream& os, Scholarship &ip1);
		bool check();	
		void set_Namebank();
		void set_Numberbank();
};
istream& operator >> (istream& is, Scholarship &ip1){
		cout<<"Nhap ten ngan hang: ";
		fflush(stdin);
		getline(is, ip1.namebank);
		cout<<endl;
		cout<<"Nhap so tai khoan: ";
		is>>ip1.numberbank;
		cout<<endl;
		return is;
}
ostream& operator << (ostream& os, Scholarship &ip1){
		os<<"Ten ngan: "<<ip1.namebank<<endl;
		os<<"So tai khoan: "<<ip1.numberbank<<endl;
		return os;
}
bool Scholarship::check(){
	if(getGpa() >= 7.9 && getPractise() >= 4 && get_n_Allow() < 3)
		return true;
	else 
		return false;	
}
void Scholarship::set_Namebank(){
	string str;
	cout<<"Nhap ten ngan hang: ";
	fflush(stdin);
	getline(cin, str);
	cout<<endl;
	this->namebank;
}
void Scholarship::set_Numberbank(){
	int number;
	cout<<"Nhap so tao khoan ngan hang: ";
	cin>>number;
	cout<<endl;
	this->numberbank=number;
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
		void fix_infor();
			
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
Student_Management::Student_Management(const Student_Management &slist){
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
	File<<"=====DANH SACH THONG TIN SINH VIEN======"<<endl;
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
		cout<<"Nhap so luong sinh vien: ";
		cin>>n;
		cout<<endl;
	}while(n==0);
	
	for(int i=0;i<n;i++){
		cout<<"Sinh vien "<<i+1<<": "<<endl;
		cin>>value;
		addLast(value);
	}
}
void Student_Management::list_sholarship(){
	fstream File;
	File.open("list_scholarship.txt", ios::out);
	File<<"======DANH SACH HOC BONG====== "<<endl;
	cout<<"======DANH SACH HOC BONG====== "<<endl;
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
	cout<<"Nhap ten muon tim: ";
	fflush(stdin);
	getline(cin, str);
	cout<<endl;
	Node* p=head;
	while(p!=NULL){
		if(p->data.getName() == str)
			cout<<p->data;
		else{
			cout<<"Don't the name you want to search !!"<<endl;
		}	
		p=p->next;	
	}
	delete p;
}
void Student_Management::Delete(){
	string str;
	cout<<"Nhap ten muon xoa: ";
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
	cout<<"Nhap so luong sinh vien muon them: ";
	cin>>n;
	if(n==0){
		return;
	}
	Student value;
	for(int i=0; i<n;i++){
		cout<<"Sinh vien "<<i+1<<endl;
		cin>>value;
		addLast(value);
	}	
}
void Student_Management::fix_infor(){
	string str;
	cout<<"Nhap ten sinh vien can sua thong tin: ";
	fflush(stdin);
	getline(cin, str);
	cout<<endl;
	Node *p=head;
	while(p!=NULL){
		if(p->data.getName() == str){
			int choice;
			do{
				cout<<"-------Cac noi dung sua-------"<<endl;
				cout<<"1. Sua diem trung binh"<<endl;
				cout<<"2. Sua tong so buoi da hoc"<<endl;
				cout<<"3. Sua so buoi nghi co phep"<<endl;
				cout<<"4. Sua so buoi nghi khong phep"<<endl;
				cout<<"5. Sua ten ngan hang"<<endl;
				cout<<"6. Sua so tai khoan ngan hang"<<endl;
				cout<<"Nhan phim 0 de tro lai menu chinh !!"<<endl;
				cout<<"--->Vui long chon chuc nang: ";
				cin>>choice;
				cout<<endl;
				switch(choice){
					case 1:
						p->data.set_Gpa();
						break;
					case 2:
						p->data.set_Lesson();
						break;
					case 3:
						p->data.set_Allow();
						break;
					case 4:
						p->data.set_n_Allow();
						break;
					case 5:
						p->data.set_Namebank();
						break;
					case 6:
						p->data.set_Numberbank();
						break;
					default:
						choice=0;
						break;			
				}
			}while(choice != 0);
		}
		p=p->next;
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
				cout<<"--------Danh sach sau khi them--------"<<endl;
				list.traverse();
				break;
			case 5:
				list.Delete();
				cout<<"--------Danh sach sau khi xoa--------"<<endl;
				list.traverse();
				break;
			case 6:
				list.fix_infor();
				break;
			case 7:
				list.searchName();	
				break;
			default:
				choice=0;
				break;				
		}
	}while(choice!=0);

	
	return 0;
}
