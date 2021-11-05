//Sua bai tap ve tinh da hinh
#include<iostream>
#include<vector> 
#include<iomanip>
using namespace std;
class GiangVien{
    protected:
        string MaSo, HoTen;
        int Tuoi;
        float Luong;
    public:
        virtual void Nhap(){
            cout<<"Nhap ma so: ";
            cin.ignore(256, '\n');
            getline(cin,MaSo);
            cout<<"Nhap ho ten: ";
            fflush(stdin);
            getline(cin,HoTen);
            cout<<"Nhap tuoi: ";
            cin>>Tuoi;
        }
        virtual void Xuat(){
            cout<<"Ma so: "<<MaSo<<endl;
            cout<<"Ho ten: "<<HoTen<<endl;
            cout<<"Tuoi: "<<Tuoi<<endl;
        }
        virtual void TinhLuong()=0;
        float getLuong(){
            return Luong;
        }
};
class GiangVienCoHuu:public GiangVien{
    private:
        float HeSoLuong,ThamNien;
    public:
        void Nhap(){
            GiangVien::Nhap();
            cout<<"Nhap he so luong: ";
            cin>>HeSoLuong;
            cout<<"Nhap tham nien: ";
            cin>>ThamNien;
        }
        void Xuat(){
            GiangVien::Xuat();
            cout<<"He so luong: "<<HeSoLuong<<endl;
            cout<<"Tham nien: "<<ThamNien<<endl;
            this->TinhLuong();
            cout<<"Luong: "<<Luong<<endl;
        }
        void TinhLuong(){
            Luong= HeSoLuong*1600 + ThamNien*500;
        }
};
class GiangVienThinhGiang:public GiangVien{
    private:
        int SoTiet;
        float DonGia;
    public:
        void Nhap(){
            GiangVien::Nhap();
            cout<<"Nhap so tiet: ";
            cin>>SoTiet;
            cout<<"Nhap don gia: ";
            cin>>DonGia;
        }
        void Xuat(){
            GiangVien::Xuat();
            cout<<"So tiet: "<<SoTiet<<endl;
            cout<<"Don gia: "<<DonGia<<endl;
            this->TinhLuong();
            cout<<"Luong: "<<Luong<<endl;
        }
        void TinhLuong(){
            this->Luong = this->SoTiet*this->DonGia; 
        }
};
class QuanLyGiangVien{
    private:
        //Ap dung cac cau truc du lieu
        vector<GiangVien *> GV;
    public:
        void NhapDS(){
            GiangVien *gv;
            int n,m;
            cout<<"Nhap so luong giang vien co huu: ";
            cin>>n;
            for(int i=0;i<n;i++){
                gv=new GiangVienCoHuu;
                gv->Nhap();
                GV.push_back(gv);
                cout<<endl;
            }
            cout<<"Nhap so luong giang vien thinh giang: ";
            cin>>m;
            for(int i=0;i<m;i++){
                gv=new GiangVienThinhGiang;
                gv->Nhap();
                GV.push_back(gv);
                cout<<endl;
            }
        }
        void XuatDS(){
            cout<<endl<<"*******Danh sach giang vien*******"<<endl;
            for(int i=0; i<this->GV.size();i++){
                this->GV.at(i)->Xuat();
                cout<<endl;
            }
        }
        void SapXep(){
            for(int i=0;i<GV.size()-1;i++){
                for(int j=i+1;j<GV.size();j++){
                    if(GV.at(i)->getLuong() > GV.at(j)->getLuong()){
                        GiangVien *t= GV.at(i);
                        GV.at(i)=GV.at(j);
                        GV.at(j)=t;
                    }
                }
            }
            XuatDS();
        }
        void MaxLuong(){
            GiangVien *max= GV.at(0);
            for(int i=1;i<GV.size();i++){
                if(GV.at(i)->getLuong() > max->getLuong())
                    max= GV.at(i);
            }
            cout<<endl<<"Giang vien co luong cao nhat: "<<endl;
            max->Xuat();
        }
        void TongLuong(){
            float tong=0;
            for(int i=0;i<GV.size();i++){
                tong+=GV.at(i)->getLuong();
            }
            cout<<endl<<"Tong luong giang vien trong truong: "<<setprecision(2)<<fixed<<tong<<endl;
        }
};
int main(){
    QuanLyGiangVien a;
    a.NhapDS();
    a.XuatDS();
    cout<<endl<<"Danh sach giang vien da sap xep theo luong"<<endl;
    a.SapXep();
    a.MaxLuong();
    a.TongLuong();
}
