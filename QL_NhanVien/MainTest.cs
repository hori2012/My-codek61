using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QL_NhanVien
{
    internal class MainTest
    {
        static void Main(string[] args)
        {
            NhanVien nhanVien = new LeTan();
            NhanVien thungan = new ThuNgan();
            QLNV list = new QLNV();
            list.NhapDs();
            list.XuatDs();
            int c = 0;
            list.TimKiemNv(ref c);
            list.ThemNv(ref c);
            list.XuatDs();
            //nhanVien.Input();
            //nhanVien.Output();
            //thungan.Input();
            //thungan.Output();
            Console.ReadKey();
        }
    }
}
