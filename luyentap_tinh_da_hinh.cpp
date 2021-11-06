//tinh da hinh
//van cong hao
//6151071045
#include<iostream>
#include<vector>
using namespace std;
class NhanVien{
	private:
		string HoTen;
		int Tuoi;
	protected:
		float BacLuong;
	public:
		virtual void Nhap();
		virtual void Xuat();
	//	virtual float TinhLuong()=0;		
};
void NhanVien::Nhap(){
	cout<<"Nhap ho va ten : ";
	fflush(stdin);
	getline(cin, this->HoTen);
	cout<<endl;
	cout<<"Nhap tuoi: ";
	cin>>this->Tuoi;
	cout<<endl;
	cout<<"Nhap bac luong : ";
	cin>>this->BacLuong;
	cout<<endl;
}
void NhanVien::Xuat(){
	cout<<"Ho va ten: "<<this->HoTen<<endl;
	cout<<"Tuoi : "<<this->Tuoi<<endl;
	cout<<"Bac luong: "<<this->BacLuong<<endl;
}
class ChinhThuc : public NhanVien{
	private:
		float ThamNien;
	public:
		void Nhap();
		void Xuat();
		float TinhLuong();
};
void ChinhThuc::Nhap(){
	NhanVien::Nhap();
	cout<<"Nhap tham nien : ";
	cin>>this->ThamNien;
	cout<<endl;
}
void ChinhThuc::Xuat(){
	NhanVien::Xuat();
	cout<<"Tham nien: "<<this->ThamNien<<endl;
	cout<<"Luong: "<<TinhLuong()<<endl;
}
float ChinhThuc::TinhLuong(){
	return BacLuong*1600;
}
class ThuViec: public NhanVien{
	private:
		string NgayVaoLam;
	public:
		void Nhap();
		void Xuat();
		float TinhLuong();	
};
void ThuViec::Nhap(){
	NhanVien::Nhap();
	cout<<"Nhap ngay vao lam viec: ";
	fflush(stdin);
	getline(cin, this->NgayVaoLam);
	cout<<endl;
}
void ThuViec::Xuat(){
	NhanVien::Xuat();
	cout<<"Ngay vao lam : "<<this->NgayVaoLam<<endl;
	cout<<"Luong: "<<TinhLuong()<<endl;
}
float ThuViec::TinhLuong(){
	return BacLuong*1600*0.8;
}
class CongTy{
	//ap dung cau truc vector
	private:
		vector<NhanVien *>NV;
	public:
		void Nhap();
		void Xuat();
		void TongLuongNhanVien();
};
void CongTy::Nhap(){
	int m, n;
	NhanVien *nv;
	cout<<"Nhap so luong nhan vien chinh thuc: ";
	cin>>m;
	cout<<endl;
	for(int i=0; i<m;i++){
		nv= new ChinhThuc;
		nv->Nhap();
		NV.push_back(nv);
	}
	cout<<"Nhap so luong nhanh vien thu viec: ";
	cin>>n;
	cout<<endl;
	for(int i=0; i<n;i++){
		nv=new ThuViec;
		nv->Nhap();
		NV.push_back(nv);
	}
}
void CongTy::Xuat(){
	cout<<endl<<"=========Danh sach nhan vien=========="<<endl;
	for(int i=0;i<this->NV.size();i++){
		this->NV.at(i)->Xuat();
		cout<<"~~~~~~~~~~~~~~~~~"<<endl;
	}	
}
void CongTy::TongLuongNhanVien(){
	cout<<"Tong Nhan Vien Trong Cong Ty: "<<this->NV.size()<<endl;
}
int main(){
	CongTy nv1;
	nv1.Nhap();
	nv1.Xuat();
	nv1.TongLuongNhanVien();
	return 0;
}
