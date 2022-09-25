using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QL_NhanVien
{

    internal abstract class NhanVien
    {
        private string MaNV;
        private string HoTen;
        private DateTime NgaySinh;
        private string GioiTinh;
        private string DiaChi;
        private string SDT;
        private double LuongCB;
        private string HocVan;

        public NhanVien()
        {

        }

        public NhanVien(string MaNV, string Hoten, DateTime NgaySinh, string GioiTinh, string DiaChi, string SDT, double LuongCB, string HocVan)
        {
            this.MaNV1 = MaNV;
            this.HoTen1 = Hoten;
            this.NgaySinh1 = NgaySinh;
            this.GioiTinh = GioiTinh;
            this.DiaChi1 = DiaChi;
            this.SDT1 = SDT;
            this.LuongCB1 = LuongCB;
            this.HocVan1 = HocVan;
        }

        public string MaNV1 { get => MaNV; set => MaNV = value; }
        public string HoTen1 { get => HoTen; set => HoTen = value; }
        public DateTime NgaySinh1 { get => NgaySinh; set => NgaySinh = value; }
        public string DiaChi1 { get => DiaChi; set => DiaChi = value; }
        public string SDT1 { get => SDT; set => SDT = value; }
        public double LuongCB1 { get => LuongCB; set => LuongCB = value; }
        public string HocVan1 { get => HocVan; set => HocVan = value; }
        public string GioiTinh1 { get => GioiTinh; set => GioiTinh = value; }

        abstract public void Input();
        abstract public void Output();
        abstract public string CheckType();

        static private bool KTString(char c)
        {
            int count = 0;
            char[] arr = {'á', 'ả', 'ã', 'ạ', 'à', 'â', 'ấ', 'ẫ', 'ẩ', 'ậ', 'ầ', 'ă', 'ắ', 'ẵ', 'ặ', 'ẳ', 'ằ', 'ê',
                'ế', 'ề', 'ễ', 'ệ', 'ể', 'đ', 'i','í', 'ì', 'ị', 'ĩ', 'ỉ', 'ó', 'ò', 'ỏ', 'õ' , 'ọ', 'ú', 'ù' ,'ũ',
                'ủ', 'ụ', 'ý', 'ỳ', 'ỷ', 'ỹ', 'ỵ','ơ','ớ','ở', 'ợ', 'ỡ', 'ờ','ô','ố', 'ồ', 'ộ', 'ỗ', 'ổ','ứ', 'ừ', 'ử',
                'ữ','ự','é', 'è', 'ẽ', 'ẻ', 'ẹ','Á', 'Ả', 'Ã', 'Ạ', 'À', 'Â', 'Ấ', 'Ẫ', 'Ẩ', 'Ậ', 'Ầ', 'Ă', 'Ắ', 'Ẵ', 'Ặ', 'Ằ', 'Ê',
                'Ế', 'Ề', 'Ễ', 'Ệ', 'Ể', 'Đ', 'I','Í', 'Ì', 'Ị', 'Ĩ', 'Ỉ', 'Ó', 'Ò', 'Ỏ', 'Õ' , 'Ọ', 'Ú', 'Ù',
                'Ũ', 'Ủ', 'Ụ', 'Ý', 'Ỳ', 'Ỷ', 'Ỹ','Ỵ', 'Ớ','Ở', 'Ợ', 'Ỡ', 'Ờ','Ố', 'Ồ', 'Ộ', 'Ỗ', 'Ổ','Ứ', 'Ừ',
                'Ử', 'Ữ','Ự','É', 'È', 'Ẽ', 'Ẻ', 'Ẹ'};
            for (int i = 0; i < arr.Length; i++)
            {
                if (c == arr[i])
                {
                    count = 1;
                    //break;
                }
            }
            if (count != 1)
            {
                return false;
            }
            return true;
        }
        static protected bool eventString(string str)
        {
            Console.InputEncoding = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;
            int count = 0;
            for (int i = 0; i < str.Length; i++)
            {
                if (KTString(str[i]) == true)
                {
                    count++;
                }
                else if ((str[i] >= 65 && str[i] <= 90) || str[i] == 32 || ((str[i] >= 97 && str[i] <= 122)))
                {
                    count++;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        static protected DateTime eventTime()
        {
            int day, month, year;
            do
            {
                Console.Write("\n\tEnter day:");
                day = Convert.ToInt32(Console.ReadLine());
            } while (day > 31 || day < 1);
            do
            {
                Console.Write("\n\tEnter month:");
                month = Convert.ToInt32(Console.ReadLine());
            } while (month > 12 || month <= 0);
            do
            {
                Console.Write("\n\tEnter year:");
                year = Convert.ToInt32(Console.ReadLine());
            } while (year > (DateTime.Now).Year && year < 1960);
            DateTime time = new DateTime(year, month, day);
            return time;
        }
        static protected bool KTSDT(string sdt)
        {
            for (int i = 0; i < sdt.Length; i++)
            {
                if (sdt[i] >= 48 && sdt[i] <= 57)
                {
                    int count = 0;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        static protected bool eventGender(string gender)
        {
            if ((gender != "Nam" && gender != "nam") && (gender != "Nu" && gender != "nu" && gender != "Nữ" && gender != "nữ"))
            {
                return false;
            }
            return true;
        }
        static protected bool errorType(ref double c, string str)
        {
            bool flag = true;
            try
            {
                c = Convert.ToDouble(Console.ReadLine());
            }
            catch (FormatException e)
            {
                Console.WriteLine("Only enter number !!!!");
                Console.Write(str);
                flag = false;
            }
            finally
            {
                if (flag == false)
                {
                    errorType(ref c, str);
                }
            }
            return true;
        }
    }
}
