using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QL_NhanVien
{
    internal class LeTan : NhanVien
    {
        private double TiLeThuong;

        public LeTan()
        {

        }

        public LeTan(string MaNV, string Hoten, DateTime NgaySinh,string GioiTinh, string DiaChi, string SDT, double LuongCB, string HocVan, double TiLeThuong) : base(MaNV, Hoten, NgaySinh,GioiTinh, DiaChi, SDT, LuongCB, HocVan)
        {
            this.TiLeThuong1 = TiLeThuong;

        }

        public double TiLeThuong1 { get => TiLeThuong; set => TiLeThuong = value; }

        public override string CheckType()
        {
            return "Le Tan";
        }

        public override void Input()
        {
            Console.InputEncoding = Encoding.Unicode;
            //nhap ma nhan vien tu dong
            int a = 0;
            do
            {
                Console.Write("Nhập họ và tên : ");
                string name = Console.ReadLine();
                if (eventString(name))
                {
                    HoTen1 = name;
                    a = 1;
                }
            } while (a != 1);
            Console.Write("\nNhập ngày sinh : ");
            NgaySinh1 = eventTime();
            bool flag2 = true;
            do
            {
                Console.Write("\nNhập giới tính :");
                string gender = Console.ReadLine();
                flag2 = eventGender(gender);
                if (flag2 == true)
                {
                    GioiTinh1 = gender;
                }
            } while (flag2 == false);
            int b = 0;
            do
            {
                Console.Write("\nNhập địa chỉ :");
                string add = Console.ReadLine();
                if (eventString(add))
                {
                    DiaChi1 = add;
                    b = 1;
                }
            } while (b != 1);
            int c = 0;
            do
            {
                Console.Write("\nNhập số điện thoại :");
                string sdt = Console.ReadLine();
                if (KTSDT(sdt))
                {
                    SDT1 = sdt;
                    c = 1;
                }
            } while (c != 1);
            bool flag = true;
            do
            {
                Console.Write("\nNhập lương cơ bản :");
                double e = 0;
                string str = "\nNhập lươngg cơ bản :";
                flag = errorType(ref e, str);
                if (flag == true)
                {
                   LuongCB1 = e;
                }

            } while (flag == false);
            int d = 0;
            do
            {
                Console.Write("\nNhập trình độ học vấn :");
                string hocvan = Console.ReadLine();
                if (eventString(hocvan))
                {
                    HocVan1 = hocvan;
                    d = 1;
                }
            } while (d != 1);

            //ti le thuong %
            bool flag1 = true;
            do
            {
                Console.Write("\nNhập tỉ lệ  thưởng (%) :");
                double e = 0;
                string str = "\nNhập tỉ lệ  thưởng (%) :";
                flag1 = errorType(ref e, str);
                if(flag1 == true)
                {
                    TiLeThuong1 = e;
                }
                
            }while (flag1 == false);
        }

        public override void Output()
        {
            Console.OutputEncoding = Encoding.Unicode;
            Console.WriteLine("Mã nhân viên: {0}", MaNV1);
            Console.WriteLine("Họ và tên : {0}", HoTen1);
            Console.WriteLine("Ngày sinh : {0}", NgaySinh1.ToString("D"));
            Console.WriteLine("Giới tính: {0}", GioiTinh1);
            Console.WriteLine("Địa chỉ : {0}", DiaChi1);
            Console.WriteLine("Số điện thoại : {0}", SDT1);
            Console.WriteLine("Lương cơ bản: {0} VND", LuongCB1);
            Console.WriteLine("Trình độ học vấn: {0} ", HocVan1);
            Console.WriteLine("Tỉ lệ lương thưởng: {0}%", this.TiLeThuong);
        }
    }
}
