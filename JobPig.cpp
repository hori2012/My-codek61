//van cong hao
//6151071045
#include<iostream>
#include<string>
using namespace std;
//class student
class Student{
	private:
		string Fullname, Mssv;
		float GPA;
		string Province, Birthday;
	public:
		friend istream& operator >> (istream &is, Student &st);
		friend ostream& operator << (ostream &os, const Student &st);
	//	void Input1();
	//	void Output();
		float getGPA();
			
};
//khai bao Node
/*struct Node{
	Student data;
	Node* next;
};
//class khai bao danh sach lien ket
class Slist{
	private:
		Node* head;
		Node* tail;
		long size;
	public:
		Slist();
		~Slist();
		void addLast(Student v);
		
		void traverse();	
		
};*/
// class tinh diem ren luyen
class Practise:public Student{
	private:
		int SumLesson,Allow, N_Allow ; // tong buoi hoc, nghi co phep, khong phep (15% so buoi duoc phep nghi nhung van bi tru diem khong phep -3/co phep -1)
		float f_Practise = 0 ; // diem ren luyen (mot buoi duoc 5 diem , diem ren luyen=trung binh cong buoi hoc)
		int Lesson = 0; // so buoi da hoc
	public:
		void Input2();
		void Output2();
		int getAllow();
		int getN_Allow();
		void setf_practise();
		float getf_practise();
		void setLesson();
		int getLesson();
};

// xet hoc bong va danh sach sinh vien duoc nhan
class Scholarship:public Practise{
	private:		// dieu kien hoc bong: khong duoc nghi qua 15% so buoi hc, ren luyen tu 4 diem, GPA 7.5 tro len, lay 8% so sinh vien dat yeu cau tu tren xuong 
		double NumberBank;
		string NameBank;
	public:
		void Input3();
		void Output3();
		void List_Scholar();
			
};
// phuong thuc class student
istream& operator >> (istream& is, Student &st){
	//cin.ignore();
	cout<<"Enter of the fullname: "<<endl;
	fflush(stdin);
	getline(is, st.Fullname);
	cout<<"Enter of the Mssv: "<<endl;
	fflush(stdin);
	getline(is, st.Mssv);
	cout<<"Enter of the province: "<<endl;
	fflush(stdin);
	getline(is, st.Province);
	cout<<"Enter of the birthday (dd/mm/yyyy): "<<endl;
	getline(is, st.Birthday);
	cout<<"Enter of the GPA: "<<endl;
	is>>st.GPA;
	return is;
}
ostream& operator << (ostream & os, const Student &st){
	os<<"Fullname: "<<st.Fullname<<endl;
	os<<"Mssv: "<<st.Mssv<<endl;
	os<<"Province: "<<st.Province<<endl;
	os<<"Birthday: "<<st.Birthday<<endl;
	os<<"GPA: "<<st.GPA<<endl;
	return os;
}
float Student::getGPA(){
	return this->GPA;
}
// phuong thuc class practise
void Practise::Input2(){
	cout<<"Enter of the Sumlesson: "<<endl;
	cin>>SumLesson;
	cout<<"Enter of the Allow: "<<endl;
	cin>>Allow;
	cout<<"Enter of the N_Allow: "<<endl;
	cin>>N_Allow;
}
void Practise::setf_prctise(){
	
}
// phuong thuc class scholarship

//het
int main(){
	Student Array[100];
	int n;
	do{
		cout<<"Enter of the number elements: "<<endl;
		cin>>n;
	}while(n==0 || n>101);
	for(int i=0; i<n;i++){
		cout<<"Enter frofile student "<<i+1<<": "<<endl;
		cin>>Array[i];
	}
	cout<<"========List====== "<<endl;
	for(int i=0; i<n;i++){
		cout<<Array[i];
		cout<<"~~~"<<endl;
	}
	return 0;
}



