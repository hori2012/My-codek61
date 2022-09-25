using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QL_NhanVien
{
    internal class QLNV
    {
        private List<NhanVien> m_index = new List<NhanVien>();

        public QLNV()
        {

        }
        public QLNV(List<NhanVien> list)
        {
            m_index = list;
        }

        internal List<NhanVien> Index { get => m_index; set => m_index = value; }

        public void NhapDs()
        {
            int[] arr = new int[2];
            Console.Write("Nhập số lượng Lễ Tân: ");
            arr[0] = Convert.ToInt32(Console.ReadLine());
            Console.Write("\nNhập số lượng Thu Ngân: ");
            arr[1] = Convert.ToInt32(Console.ReadLine());
            if (arr[0] != 0)
            {
                Console.WriteLine("***************** Nhập thông tin Lễ Tân *****************");
                for (int i = 0; i < arr[0]; i++)
                {
                    NhanVien value = new LeTan();
                    Console.WriteLine("---Lễ Tân {0}---", i + 1);
                    value.MaNV1 = "NV.LT" + (i + 1);
                    value.Input();
                    m_index.Add(value);
                }
            }
            if (arr[1] != 0)
            {
                Console.WriteLine("***************** Nhập thông tin Thu Ngân *****************");
                for (int i = 0; i < arr[1]; i++)
                {
                    NhanVien value = new ThuNgan();
                    Console.WriteLine("---Thu Ngân {0}---", i + 1);
                    value.MaNV1 = "NV.TN" + (i + 1);
                    value.Input();
                    m_index.Add(value);
                }
            }
            
        }
        public void XuatDs()
        {
            int count = 0;
            int [] arr = {0, 0};
            for (int i = 0; i < m_index.Count; i++)
            {
                if (String.Compare(m_index[i].CheckType(), "Le Tan") == 0)
                {
                    arr[0]++;
                }
                else
                {
                    arr[1]++;
                }
            }
            Console.WriteLine("\t\t-------------------------- Danh sách thông tin nhân viên --------------------------");
            if (arr[0] != 0)
            {
                Console.WriteLine("\t***************** Thông tin Lễ Tân *****************");
                for (int i = 0; i < m_index.Count; i++)
                {
                    if (String.Compare(m_index[i].CheckType(), "Le Tan") == 0)
                    {
                        m_index[i].Output();
                        Console.WriteLine("");
                        count++;
                    }
                }
            }
            if (arr[1] != 0)
            {
                Console.WriteLine("\t***************** Thông tin Thu Ngân *****************");
                for (int i = count; i < m_index.Count; i++)
                {
                    if (String.Compare(m_index[i].CheckType(), "Thu Ngan") == 0)
                    {
                        m_index[i].Output();
                        Console.WriteLine("");
                    }
                }
            }
        }
        //tim kiem nhan vien theo mot dieu kien nao do
        public void TimKiemNv(ref int choice)
        {
            int chon = 0;
            do
            {
                Console.WriteLine("\t\t\t******************* TÌM KIẾM *******************");
                Console.WriteLine("\t\t\t*      1. Tìm kiếm theo chức vụ                *");
                Console.WriteLine("\t\t\t*      2. Tìm kiếm theo mã nhân viên           *");
                Console.WriteLine("\t\t\t*      3. Tìm kiếm theo họ tên                 *");
                Console.WriteLine("\t\t\t*      4. Tìm kiếm theo giới tính              *");
                Console.WriteLine("\t\t\t*      5. Tìm kiếm theo trình độ học vấn       *");
                Console.WriteLine("\t\t\t*      6. Tìm kiếm theo tuổi                   *");
                Console.WriteLine("\t\t\t*      7. Thoát tìm kiếm                       *");
                Console.WriteLine("\t\t\t************************************************");
                Console.Write("\t--->> Nhập chức năng : ");
                chon = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine();
                switch (chon)
                {
                    case 1:
                        Console.Write("Nhập chức vụ cần tìm : ");
                        string chucvu = Console.ReadLine();
                        if(string.Compare(chucvu, "Lễ Tân", true) == 0)
                        {
                            chucvu = "Le Tan";
                        }
                        if (string.Compare(chucvu, "Thu Ngân", true) == 0)
                        {
                            chucvu = "Thu Ngan";
                        }
                        int count = 0;
                        for (int i = 0; i < m_index.Count; i++)
                        {
                            if(string .Compare(m_index[i].CheckType(), chucvu, true) == 0)
                            {
                                m_index[i].Output();
                                Console.WriteLine();
                                count++;
                            }
                        }
                        if(count == 0)
                        {
                            Console.WriteLine("Không tồn tại nhân viên {0} !! ", chucvu);
                        }
                        break;
                    case 2:
                        Console.Write("\nNhập mã nhân viên cần tìm: ");
                        string ma = Console.ReadLine();
                        int count1 = 0;
                        for(int i = 0; i < m_index.Count; i++)
                        {
                            if(string.Compare(ma, m_index[i].MaNV1) == 0)
                            {
                                m_index[i].Output();
                                count1++;
                            }
                        }
                        
                        if (count1 == 0)
                        {
                            Console.WriteLine("Không tồn tại nhân viên có mã {0} !! ", ma);
                        }
                        break;
                    case 3:
                        Console.Write("\nNhập họ tên cần tìm: ");
                        string hoten = Console.ReadLine();
                        int count2 = 0;
                        for(int i = 0; i < m_index.Count; i++)
                        {
                            if(string.Compare(hoten, m_index[i].HoTen1) == 0)
                            {
                                m_index[i].Output();
                                Console.WriteLine();
                                count2++;
                            }
                        }
                        if (count2 == 0)
                        {
                            Console.WriteLine("Không tồn tại nhân viên có tên {0} !! ", hoten);
                        }
                        break;
                    case 4:
                        Console.InputEncoding = Encoding.Unicode;
                        Console.Write("\nNhập giới tính cần tìm: ");
                        string gioitinh = Console.ReadLine();
                        if (string.Compare(gioitinh, "Nu", true) == 0)
                        {
                            gioitinh = "Nữ";
                        }
                        int count3 = 0;
                        for (int i = 0; i < m_index.Count; i++)
                        {
                            if (string.Compare(gioitinh, m_index[i].GioiTinh1, true) == 0)
                            {
                                m_index[i].Output();
                                Console.WriteLine();
                                count3++;
                            }
                        }
                        if (count3 == 0)
                        {
                            Console.WriteLine("Không tồn tại nhân viên có giới tính {0} !! ", gioitinh);
                        }
                        break;
                    case 5:
                        Console.Write("\nNhập trình độ học vấn cần tìm: ");
                        string hocvan = Console.ReadLine();
                        int count4 = 0;
                        for (int i = 0; i < m_index.Count; i++)
                        {
                            if (string.Compare(hocvan, m_index[i].HocVan1, true) == 0)
                            {
                                m_index[i].Output();
                                Console.WriteLine();
                                count4++;
                            }
                        }
                        if (count4 == 0)
                        {
                            Console.WriteLine("Không tồn tại nhân viên có học vấn  {0} !! ", hocvan);
                        }
                        break;
                    case 6:
                        int chon1;
                        do
                        {
                            Console.WriteLine("\t\t******************* Tìm Kiếm tuổi *******************");
                            Console.WriteLine("\t\t*        1. Tìm kiếm tuổi cố định                   *");
                            Console.WriteLine("\t\t*        2. Tìm kiếm trong khoảng tuổi              *");
                            Console.WriteLine("\t\t*        3. Trở lại tìm kiếm                        *");
                            Console.WriteLine("\t\t*****************************************************");
                            Console.Write("\t--->> Nhập chức năng : ");
                            chon1 = Convert.ToInt32(Console.ReadLine());
                            Console.WriteLine();
                            switch (chon1)
                            {
                                case 1:
                                    int tuoi;
                                    do
                                    {
                                        Console.Write("\nNhập tuổi cần tìm: ");
                                        tuoi = Convert.ToInt16(Console.ReadLine());
                                    } while (tuoi <= 0);
                                    for (int i = 0; i < m_index.Count; i++)
                                    {
                                        if (((DateTime.Now).Year - (m_index[i].NgaySinh1.Year)) == tuoi)
                                        {
                                            m_index[i].Output();
                                            Console.WriteLine();
                                        }
                                    }
                                    break;
                                case 2:
                                    int min, max;
                                    do
                                    {
                                        Console.Write("\nNhập khoảng tuổi cần tìm: ");
                                        Console.Write("\n\tTuổi nhỏ nhất: ");
                                        min = Convert.ToInt16(Console.ReadLine());
                                        Console.Write("\n\tTuổi lớn nhất: ");
                                        max = Convert.ToInt16(Console.ReadLine());
                                    } while ((min < 0 || max < 0) && (min > max));
                                    for (int i = 0; i < m_index.Count; i++)
                                    {
                                        if (((DateTime.Now).Year - (m_index[i].NgaySinh1.Year)) >= min && ((DateTime.Now).Year - (m_index[i].NgaySinh1.Year)) <= max)
                                        {
                                            m_index[i].Output();
                                            Console.WriteLine();
                                        }
                                    }
                                    break;
                                default:
                                    chon1 = 3;
                                    break;
                            }
                        } while (chon1 != 3);
                        break;
                    default:
                        chon = 7;
                        choice = 5;
                        break;
                }
            } while (chon != 7);
        }
        //them nhan vien moi
        public void ThemNv(ref int choice)
        {
            int chon1;
            int[] arr = { 0, 0 };
            for (int i = 0; i < m_index.Count; i++)
            {
                if (String.Compare(m_index[i].CheckType(), "Le Tan") == 0)
                {
                    arr[0]++;
                }
                else
                {
                    arr[1]++;
                }
            }
            do
            {
                Console.WriteLine("\t\t\t******************* Nhân Viên *******************");
                Console.WriteLine("\t\t\t*           1. Thêm Lễ Tân                      *");
                Console.WriteLine("\t\t\t*           2. Thêm Thu Ngân                    *");
                Console.WriteLine("\t\t\t*           3. Trở lại Thêm                     *");
                Console.WriteLine("\t\t\t*************************************************");
                Console.Write("\t--->> Nhập chức năng : ");
                chon1 = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine();
                switch (chon1)
                {
                    case 1:
                        int number;
                        Console.Write("Nhập số lượng Lễ Tân: ");
                        number = Convert.ToInt32(Console.ReadLine());
                        if (number != 0)
                        {
                            Console.WriteLine("***************** Nhập thông tin Lễ Tân *****************");
                            for (int i = arr[0]; i < arr[0] + number; i++)
                            {
                                NhanVien value = new LeTan();
                                Console.WriteLine("---Lễ Tân {0}---", i + 1);
                                value.MaNV1 = "NV.LT" + (i + 1);
                                value.Input();
                                m_index.Add(value);
                            }
                        }
                        break;
                    case 2:
                        int number1;
                        Console.Write("Nhập số lượng Thu Ngân: ");
                        number1 = Convert.ToInt32(Console.ReadLine());
                        if (number1 != 0)
                        {
                            Console.WriteLine("***************** Nhập thông tin Thu Ngân *****************");
                            for (int i = arr[1]; i < number1; i++)
                            {
                                NhanVien value = new ThuNgan();
                                Console.WriteLine("---Thu Ngân {0}---", i + 1);
                                value.MaNV1 = "NV.TN" + (i + 1);
                                value.Input();
                                m_index.Add(value);
                            }
                        }
                        break;
                    default:
                        chon1 = 3;
                        choice = 5;
                        break;
                }
            } while (chon1 != 3);
        }
        public void XoaNv(ref int choice)
        {

        }
        public void SuaNv()
        {

        }
        public void Menu()
        {

        }
    }
}
