using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhanSo
{
    internal class PS
    {
        private int tu;
        private int mau;
        public PS()
        {

        }
        public PS(int tu, int mau)
        {
            this.tu = tu;
            this.mau = mau;
        }
        public int getTu()
        {
            return this.tu; 
        }
        public int getMau()
        {
            return this.mau;
        }
        public void Xuat()
        {
            Console.Write("{0}/{1}", this.tu, this.mau);
        }
        public PS Cong(PS a)
        {
            if (a.getMau() == this.mau)
            {
                return new PS(this.tu + a.getTu(), this.mau);
            }
            else
            {
                int t = (a.getTu() * this.mau);
                int tr= (this.mau * a.getMau());
                int b = a.getMau() * this.tu;
                int c = a.getMau() * this.mau;
                return new PS(b + t, c);

            }
        }
        public PS Tru(PS a)
        {
            if (a.getMau() == this.mau)
            {
                return new PS(this.tu - a.getTu(), this.mau);
            }
            else
            {
                int t = (a.getTu() * this.mau);
                int tr = (this.mau * a.getMau());
                int b = a.getMau() * this.tu;
                int c = a.getMau() * this.mau;
                return new PS(b - t, c);


            }
        }
        public PS Nhan(PS a)
        {
            return new PS(this.tu * a.getTu(), this.mau * a.getMau());
        }
        public PS Chia(PS a)
        {
            return new PS(this.tu * a.getMau(), this.mau * a.getTu());
        }
        public int Ucln(int a, int b)
        {
            if (b == 0) return a;
            else return Ucln(b, a % b);
        }
        public bool Kiemtra()
        {
            if(Ucln(this.tu, this.mau) == 1){
                return false;
            }
            return true;
        }
        public void ToiGian()
        {
            int key = Ucln(this.tu, this.mau);
            this.tu = this.tu / key;
            this.mau = this.mau / key;
        }
        static public void NhapDay( ref List<PS> arr )
        {
            Console.WriteLine("Nhap so luong phan so: ");
            int n = Convert.ToInt16((string)Console.ReadLine());
            for(int i = 0; i < n; i++)
            {
                Console.WriteLine("Nhap phan so {0} ", i);
                Console.Write("Nhap tu so: ");
                int tu = Convert.ToInt32((string)Console.ReadLine());
                int mau;
                do
                {
                    Console.Write("\nNhap mau so: ");
                    mau = Convert.ToInt32((string)Console.ReadLine());
                } while (mau == 0);
                Console.WriteLine("");
                arr.Add(new PS(tu, mau));
            }
        }
        static public void XuatDay(List<PS> arr)
        {
            Console.WriteLine("Day phan so da nhap: ");
            for(int i = 0; i < arr.Count; i++)
            {
                arr[i].Xuat();
                Console.Write("\t");
            }
            Console.WriteLine("\n");
        }
        static public void Menu()
        {
            int choice = 0;
            List<PS> arr = new List<PS>();
            do
            {   
                Console.WriteLine("\t\t\t\t**********Menu*************");
                Console.WriteLine("\t\t\t\t*  1. Nhap day phan so.   *");
                Console.WriteLine("\t\t\t\t*  2. Xuat day phan so.   *");               
                Console.WriteLine("\t\t\t\t*  3. Cong phan so.       *");
                Console.WriteLine("\t\t\t\t*  4. Tru phan so.        *");
                Console.WriteLine("\t\t\t\t*  5. Nhan phan so.       *");
                Console.WriteLine("\t\t\t\t*  6. Chia phan so.       *");
                Console.WriteLine("\t\t\t\t*  7. Toi gian phan so.   *");
                Console.WriteLine("\t\t\t\t*  8. Thoat chuc nang.    *");
                Console.WriteLine("\t\t\t\t***************************");
                Console.Write("Nhap lua chon: ");
                choice = Convert.ToInt16(Console.ReadLine());
                Console.WriteLine("\n");
                switch (choice)
                { 
                    case 1:
                        NhapDay(ref arr);
                        break;
                    case 2:
                        Console.WriteLine(arr.Count);
                        if (arr.Count == 0)
                        {
                            Console.WriteLine("Khong co phan so de in ra !!");
                        }
                        else
                        {
                            XuatDay(arr);
                        }
                        break;
                    case 3:
                        if (arr.Count == 0)
                        {
                            Console.WriteLine("Khong co phan so de Cong !!");
                        }
                        else
                        {
                            PS answer = new PS();
                            answer = arr[0];
                            for (int i = 1; i < arr.Count ; i++)
                            {
                                answer = answer.Cong(arr[i]);
                            }
                            Console.Write("Ket qua la: ");
                            answer.ToiGian();
                            answer.Xuat();
                        }
                        break;
                    case 4:
                        if (arr.Count == 0)
                        {
                            Console.WriteLine("Khong co phan so de Tru !!");
                        }
                        else
                        {
                            PS answer = new PS();
                            answer = arr[0];
                            for (int i = 1; i < arr.Count; i++)
                            {
                                answer = answer.Tru(arr[i]);
                            }
                            Console.Write("Ket qua la: ");
                           // answer.ToiGian();
                            answer.Xuat();
                        }
                        break;
                    case 5:
                        if (arr.Count == 0)
                        {
                            Console.WriteLine("Khong co phan so de Nhan !!");
                        }
                        else
                        {
                            PS answer = new PS();
                            answer = arr[0];
                            for (int i = 1; i < arr.Count; i++)
                            {
                                answer = answer.Nhan(arr[i]);
                            }
                            Console.Write("Ket qua la: ");
                           // answer.ToiGian();
                            answer.Xuat();
                        }
                        break;
                    case 6:
                        if (arr.Count == 0)
                        {
                            Console.WriteLine("Khong co phan so de Chia !!");
                        }
                        else
                        {
                            PS answer = new PS();
                            answer = arr[0];
                            for (int i = 1; i < arr.Count; i++)
                            {
                                
                                answer = answer.Chia(arr[i]);
                            }
                            Console.Write("Ket qua la: ");
                            //answer.ToiGian();
                            answer.Xuat();
                        }
                        break;
                    case 7:
                        if(arr.Count == 0)
                        {
                            Console.WriteLine("Khong co phan so de Toi Gian !!");
                        }
                        else
                        {
                            Console.Write("Phan so truoc khi toi gian: ");
                            XuatDay(arr);
                            Console.Write("\nPhan so sau khi toi gian: ");
                            for (int i = 0; i < arr.Count; i++)
                            {
                                if (arr[i].Kiemtra())
                                {
                                    arr[i].ToiGian();
                                }
                            }
                            XuatDay(arr);
                        }
                        break;
                    default:
                        choice = 8;
                        break;
                }
            } while (choice != 8);
        }
        static void Main(string[] args)
        {
            Menu();
            Console.WriteLine("Nhan Enter de thoat chuong trinh !!");
            Console.ReadKey();
        }
    }
}
