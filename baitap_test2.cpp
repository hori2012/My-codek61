//Van Cong Hao
//6151071045
#include<iostream>
#include<string>
using namespace std;
class MatHang{
	private:
		string TenMatHang;
		int SoLuong;
		float DonGia;
	public:
		virtual void Nhap();
		virtual void Xuat();
		float Tien();	
};
void MatHang::Nhap(){
	cout<<"Nhap ten mat hang: ";
	fflush(stdin);
	getline(cin, this->TenMatHang);
	cout<<endl;
	cout<<"Nhap so luong: ";
	cin>>this->SoLuong;
	cout<<endl;
	cout<<"Nhap don gia: ";
	cin>>this->DonGia;
	cout<<endl;
}
void MatHang::Xuat(){
	cout<<"Ten mat hang: "<<this->TenMatHang<<endl;
	cout<<"So luong: "<<this->SoLuong<<endl;
	cout<<"Don gia: "<<this->DonGia<<endl;
}
float MatHang::Tien(){
	return (float)SoLuong*DonGia;
}
class HoaDon: public MatHang{
	private:
		string TenHoaDon, DanhSachMatHang;
		int SoLuongMatHang;
	public:
		void Nhap();
		void Xuat();
		float TongHoaDon(float *t, int n);
		float Tien();
		int getSoLuongMatHang();
		string getTenHoaDon();	
	protected:
		MatHang *temp;	
};
void HoaDon::Nhap(){
	cout<<"Nhap ten hoa don: ";
	fflush(stdin);
	getline(cin, this->TenHoaDon);
	cout<<endl;
	cout<<"Nhap so luong cac mat hang: ";
	cin>>this->SoLuongMatHang;
	cout<<endl;
	cout<<"Nhap danh danh sach cac mat hang: ";
	fflush(stdin);
	getline(cin, this->DanhSachMatHang);
	cout<<endl;
	temp=new MatHang[this->SoLuongMatHang]; 
	for(int i=0; i<this->SoLuongMatHang;i++){
		(temp+i)->Nhap();
	}
	cout<<endl;

}
void HoaDon::Xuat(){
	cout<<"Ten hoa don: "<<this->TenHoaDon<<endl;
	cout<<"So luong cac mat hang: "<<this->SoLuongMatHang<<endl;
	cout<<"Danh sach cac mat hang: "<<this->DanhSachMatHang<<endl;
	for(int i=0; i<this->SoLuongMatHang;i++){
		cout<<endl;
		(temp+i)->Xuat();
	}
}
/*float HoaDon::TongHoaDon(float *t, int n){
	n=this->SoLuongMatHang;
	for(int i=0;i<n;i++){
		(t+i)=(temp+i)->Tien();
	}
}*/
string HoaDon::getTenHoaDon(){
	return this->TenHoaDon;
}
void NhapDS(HoaDon *A, int &n){
	for(int i=0;i<n;i++){
		cout<<"Hoa don "<<i+1<<endl;
		(A+i)->Nhap();
	}
}
void XuatDS(HoaDon *A, int n){
	cout<<"=========DANH SACH HOA DON============="<<endl;
	for(int i=0;i<n;i++){
		cout<<"Hoa don "<<i+1<<endl;
		(A+i)->Xuat();
		cout<<"~~~~~~~~~~~~~~~~~~"<<endl;
	}
}
void TimKiem(HoaDon *A, int n){
	string str;
	cout<<"Nhap ten hoa don can tim: ";
	fflush(stdin);
	getline(cin, str);
	cout<<endl;
	cout<<"=======THONG TIN HOA DON CAN TIM=========="<<endl;
	for(int i=0; i<n;i++){
		if(str == (A+i)->getTenHoaDon()){
			(A+i)->Xuat();
		}
	}
}
int main(){
	HoaDon *A;
	int n;
	cout<<"=============MENU=================="<<endl;
	cout<<"1. Nhap danh sach hoa don"<<endl;
	cout<<"2. Xuat danh sach hoa don"<<endl;
	cout<<"3. Tong hoa don cao nhat"<<endl;
	cout<<"4. Tim hoa don"<<endl;
	cout<<"Nhan phim 0 de thoat !!"<<endl;
	int chon;
	do{
		cout<<"--------------------"<<endl;
		cout<<"vui long chon chuc nang: ";
		cin>>chon;
		cout<<endl;
		switch(chon){
			case 1:	
				do{
					cout<<"Nhap so luong hoa don: ";
					cin>>n;
					cout<<endl;
				}while(n==0);
				A=new HoaDon[n];
				NhapDS(A, n);
				break;
			case 2:
				XuatDS(A, n);
				break;
			case 3:
				break;
			case 4:
				TimKiem(A,n);
				break;
				default:
					chon=0;
					break;
		}
	}while(chon!=0);
	delete [ ] A;
	return 0;
}
