// BenhVien.cpp
#include "BenhVien.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

// Thêm các hàm này vào file BenhVien.cpp

void HeThongMenu::menuChinh()
{
    int luaChon;
    do
    {
        cout << "\n=== MENU CHINH ===\n";
        cout << "1. Quan ly benh nhan\n";
        cout << "2. Quan ly bac si\n";
        cout << "3. Quan ly lich kham\n";
        cout << "4. Thong ke & bao cao\n";
        cout << "5. Tim kiem\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
            menuQuanLyBenhNhan();
            break;
        case 2:
            menuQuanLyBacSi();
            break;
        case 3:
            menuQuanLyLichKham();
            break;
        case 4:
            menuThongKeBaoCao();
            break;
        case 5:
            menuTimKiem();
            break;
        case 0:
            cout << "Cam on ban da su dung he thong!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);
}

void HeThongMenu::chayChuongTrinh()
{
    menuChinh();
}
void HeThongMenu::xuatDanhSachBenhNhan()
{
    Patient *ds = quanLy.getDSBenhNhan();
    int soLuong = quanLy.getSoLuongBN();

    if (soLuong == 0)
    {
        cout << "\nKhong co benh nhan nao!\n";
        return;
    }

    cout << "\n=== DANH SACH BENH NHAN ===\n";
    for (int i = 0; i < soLuong; i++)
    {
        ds[i].hienthithongtinbn();
        cout << "------------------------\n";
    }
}

void HeThongMenu::xuatDanhSachBacSi()
{
    Doctor *ds = quanLy.getDSBacSi();
    int soLuong = quanLy.getSoLuongBS();

    if (soLuong == 0)
    {
        cout << "\nKhong co bac si nao!\n";
        return;
    }

    cout << "\n=== DANH SACH BAC SI ===\n";
    for (int i = 0; i < soLuong; i++)
    {
        ds[i].hienthithongtinbs();
        cout << "------------------------\n";
    }
}

void HeThongMenu::capNhatTrangThai()
{
    cout << "\n=== CAP NHAT TRANG THAI LICH KHAM ===\n";

    // Hiển thị danh sách lịch khám
    quanLy.hienThiLichKhamDayDu();

    string maLich;
    cout << "\nNhap ma lich kham can cap nhat: ";
    getline(cin, maLich);

    LichKham *lk = quanLy.timLichKham(maLich);
    if (!lk)
    {
        cout << "Khong tim thay lich kham voi ma: " << maLich << endl;
        return;
    }

    cout << "\nChon trang thai moi:\n";
    cout << "1. Hoan thanh\n";
    cout << "2. Da huy\n";
    cout << "3. Dang cho\n";
    cout << "Lua chon: ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        quanLy.capNhatTrangThai(maLich, "Hoan thanh");
        cout << "Da cap nhat trang thai thanh 'Hoan thanh'\n";
        break;
    case 2:
        quanLy.capNhatTrangThai(maLich, "Da huy");
        cout << "Da cap nhat trang thai thanh 'Da huy'\n";
        break;
    case 3:
        quanLy.capNhatTrangThai(maLich, "Dang cho");
        cout << "Da cap nhat trang thai thanh 'Dang cho'\n";
        break;
    default:
        cout << "Lua chon khong hop le!\n";
    }
}

void HeThongMenu::themBenhNhanMoi()
{
    cout << "\n=== THEM BENH NHAN MOI ===\n";
    Patient bn;
    bn.nhap();
    if (quanLy.themBenhNhan(bn))
    {
        cout << "Them benh nhan thanh cong!\n";
    }
    else
    {
        cout << "Them benh nhan that bai!\n";
    }
}
void HeThongMenu::datLichKhamMoi()
{
    cout << "\n=== DAT LICH KHAM MOI ===\n";

    // Hiển thị danh sách bệnh nhân
    cout << "\nDANH SACH BENH NHAN:\n";
    xuatDanhSachBenhNhan();

    // Hiển thị danh sách bác sĩ
    cout << "\nDANH SACH BAC SI:\n";
    xuatDanhSachBacSi();

    string maBN, maBS, ngay, gio;
    cout << "\nNhap ID benh nhan: ";
    getline(cin, maBN);
    cout << "Nhap ID bac si: ";
    getline(cin, maBS);
    cout << "Nhap ngay kham (dd/mm/yyyy): ";
    getline(cin, ngay);
    cout << "Nhap gio kham (hh:mm): ";
    getline(cin, gio);

    // Kiểm tra bệnh nhân và bác sĩ tồn tại
    Patient *bn = quanLy.timBenhNhan(maBN);
    Doctor *bs = quanLy.timBacSi(maBS);

    if (!bn)
    {
        cout << "Khong tim thay benh nhan voi ID: " << maBN << endl;
        return;
    }

    if (!bs)
    {
        cout << "Khong tim thay bac si voi ID: " << maBS << endl;
        return;
    }

    // Kiểm tra trùng lịch
    if (quanLy.kiemTraTrungLich(maBS, ngay, gio))
    {
        cout << "Bac si da co lich kham vao thoi gian nay! Vui long chon thoi gian khac.\n";
        return;
    }

    // Tạo mã lịch tự động
    int soLuongLK = quanLy.getSoLuongLK();
    string maLich = LichKham::taoMaTuDong(soLuongLK);

    // Tạo lịch khám mới
    LichKham lk(maLich, maBN, maBS, ngay, gio);

    // Tính tiền theo chuyên khoa
    int chuyenKhoa = bs->getck();
    double tien = LichKham::tinhTienTheoChuyenKhoa(chuyenKhoa);
    lk.setTien(tien);

    // Thêm lịch khám
    if (quanLy.themLichKham(lk))
    {
        cout << "Dat lich kham thanh cong!\n";
        cout << "Ma lich: " << maLich << endl;
        cout << "Tien kham: " << fixed << setprecision(0) << tien << " VND\n";
    }
    else
    {
        cout << "Dat lich kham that bai!\n";
    }
}

// Thêm hàm timKiemLichKham
void HeThongMenu::timKiemLichKham()
{
    cout << "\n=== TIM KIEM LICH KHAM ===\n";
    string keyword;
    cout << "Nhap tu khoa tim kiem (ma lich, ten benh nhan, ten bac si): ";
    getline(cin, keyword);

    // Chuyển về chữ thường để tìm kiếm không phân biệt hoa thường
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    LichKham *ds = quanLy.getDSLichKham();
    int soLuong = quanLy.getSoLuongLK();
    bool found = false;

    cout << "\nKET QUA TIM KIEM:\n";
    for (int i = 0; i < soLuong; i++)
    {
        string maLich = ds[i].getidlk();
        string tenBS = ds[i].getTenBacSi(quanLy.getDSBacSi(), quanLy.getSoLuongBS());
        string tenBN = ds[i].getTenBenhNhan(quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());

        // Chuyển về chữ thường để so sánh
        string maLichLower = maLich;
        string tenBSLower = tenBS;
        string tenBNLower = tenBN;
        transform(maLichLower.begin(), maLichLower.end(), maLichLower.begin(), ::tolower);
        transform(tenBSLower.begin(), tenBSLower.end(), tenBSLower.begin(), ::tolower);
        transform(tenBNLower.begin(), tenBNLower.end(), tenBNLower.begin(), ::tolower);

        if (maLichLower.find(keyword) != string::npos ||
            tenBSLower.find(keyword) != string::npos ||
            tenBNLower.find(keyword) != string::npos)
        {
            ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                               quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            cout << "------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay lich kham nao!\n";
    }
}
void HeThongMenu::themBacSiMoi()
{
    cout << "\n=== THEM BAC SI MOI ===\n";
    Doctor bs;
    bs.nhapbs();
    if (quanLy.themBacSi(bs))
    {
        cout << "Them bac si thanh cong!\n";
    }
    else
    {
        cout << "Them bac si that bai!\n";
    }
}

// Thêm menu QuanLyBenhNhan
void HeThongMenu::menuQuanLyBenhNhan()
{
    int luaChon;
    do
    {
        cout << "\n=== QUAN LY BENH NHAN ===\n";
        cout << "1. Xem danh sach benh nhan\n";
        cout << "2. Them benh nhan moi\n";
        cout << "3. Sua thong tin benh nhan\n";
        cout << "4. Xoa benh nhan\n";
        cout << "5. Xuat danh sach ra file\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
            xuatDanhSachBenhNhan();
            break;
        case 2:
            themBenhNhanMoi();
            break;
        case 3:
        {
            string id;
            cout << "Nhap ID benh nhan can sua: ";
            getline(cin, id);
            // Gọi hàm sua (cần implement)
            cout << "Chuc nang dang phat trien...\n";
            break;
        }
        case 4:
        {
            string id;
            cout << "Nhap ID benh nhan can xoa: ";
            getline(cin, id);
            if (quanLy.xoaBenhNhan(id))
            {
                cout << "Xoa thanh cong!\n";
            }
            else
            {
                cout << "Xoa that bai! ID khong ton tai.\n";
            }
            break;
        }
        case 5:
        {
            string tenFile;
            cout << "Nhap ten file de xuat (mac dinh: BangBenhNhan.txt): ";
            getline(cin, tenFile);
            if (tenFile.empty())
            {
                tenFile = "BangBenhNhan.txt";
            }

            Patient bnTemp;
            bnTemp.xuatdstufile("BenhNhan.txt", tenFile);
            cout << "Da xuat danh sach benh nhan ra file: " << tenFile << endl;
            break;
        }
        }
    } while (luaChon != 0);
}

// Thêm menu QuanLyBacSi
void HeThongMenu::menuQuanLyBacSi()
{
    int luaChon;
    do
    {
        cout << "\n=== QUAN LY BAC SI ===\n";
        cout << "1. Xem danh sach bac si\n";
        cout << "2. Them bac si moi\n";
        cout << "3. Xoa bac si\n";
        cout << "4. Xuat danh sach ra file\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
            xuatDanhSachBacSi();
            break;
        case 2:
            themBacSiMoi();
            break;
        case 3:
        {
            string id;
            cout << "Nhap ID bac si can xoa: ";
            getline(cin, id);
            if (quanLy.xoaBacSi(id))
            {
                cout << "Xoa thanh cong!\n";
            }
            else
            {
                cout << "Xoa that bai! ID khong ton tai.\n";
            }
            break;
        }
            // Thêm case 4 cho xuất file
        case 4:
        {
            string tenFile;
            cout << "Nhap ten file de xuat (mac dinh: BangBacSi.txt): ";
            getline(cin, tenFile);
            if (tenFile.empty())
            {
                tenFile = "BangBacSi.txt";
            }

            Doctor bsTemp;
            bsTemp.xuatdsbstufile("BacSi.txt", tenFile);
            cout << "Da xuat danh sach bac si ra file: " << tenFile << endl;
            break;
        }
        }
    } while (luaChon != 0);
}

// Thêm hàm này vào file BenhVien.cpp

void HeThongMenu::menuQuanLyLichKham()
{
    int luaChon;
    do
    {
        cout << "\n=== QUAN LY LICH KHAM ===\n";
        cout << "1. Xem danh sach lich kham\n";
        cout << "2. Dat lich kham moi\n";
        cout << "3. Cap nhat trang thai lich kham\n";
        cout << "4. Xoa lich kham\n";
        cout << "5. Tim kiem lich kham\n";
        cout << "6. Sap xep lich kham theo ngay\n";
        cout << "7. Xuat danh sach ra file\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
            quanLy.hienThiLichKhamDayDu();
            break;
        case 2:
            datLichKhamMoi();
            break;
        case 3:
            capNhatTrangThai();
            break;
        case 4:
        {
            string maLich;
            cout << "Nhap ma lich kham can xoa: ";
            getline(cin, maLich);
            if (quanLy.xoaLichKham(maLich))
            {
                cout << "Xoa thanh cong!\n";
            }
            else
            {
                cout << "Xoa that bai! Ma lich khong ton tai.\n";
            }
            break;
        }
        case 5:
            timKiemLichKham();
            break;
        case 6:
            cout << "Chuc nang sap xep dang phat trien...\n";
            break;
        case 7:
            string tenFile;
            cout << "Nhap ten file de xuat (mac dinh: BangLichKham.txt): ";
            getline(cin, tenFile);
            if (tenFile.empty())
            {
                tenFile = "BangLichKham.txt";
            }

            ofstream fout(tenFile);
            if (fout.is_open())
            {
                fout << "======================================== DANH SACH LICH KHAM ========================================\n";
                fout << left << setw(10) << "Ma Lich"
                     << setw(12) << "ID BS"
                     << setw(20) << "Ten Bac Si"
                     << setw(12) << "ID BN"
                     << setw(20) << "Ten Benh Nhan"
                     << setw(15) << "Ngay Kham"
                     << setw(10) << "Gio"
                     << setw(15) << "Trang Thai"
                     << setw(12) << "Tien Kham" << endl;
                fout << string(130, '=') << endl;

                for (int i = 0; i < quanLy.getSoLuongLK(); i++)
                {
                    LichKham &lk = quanLy.getDSLichKham()[i];
                    Doctor *bs = quanLy.timBacSi(lk.getIDBS());
                    Patient *bn = quanLy.timBenhNhan(lk.getIDBN());

                    string tenBS = bs ? bs->getTenBS() : "Khong tim thay";
                    string tenBN = bn ? bn->getName() : "Khong tim thay";

                    fout << left << setw(10) << lk.getidlk()
                         << setw(12) << lk.getIDBS()
                         << setw(20) << (tenBS.length() > 18 ? tenBS.substr(0, 15) + "..." : tenBS)
                         << setw(12) << lk.getIDBN()
                         << setw(20) << (tenBN.length() > 18 ? tenBN.substr(0, 15) + "..." : tenBN)
                         << setw(15) << lk.getday()
                         << setw(10) << lk.gettime()
                         << setw(15) << lk.trangThai.getTrangthai()
                         << setw(12) << fixed << setprecision(0) << lk.getTien() << " VND" << endl;
                }
                fout << string(130, '=') << endl;
                fout.close();
                cout << "Da xuat danh sach lich kham ra file: " << tenFile << endl;
            }
            else
            {
                cout << "Khong the mo file de ghi!\n";
            }
            break;
        }

    } while (luaChon != 0);
}
// Thêm menu ThongKeBaoCao
void HeThongMenu::menuThongKeBaoCao()
{
    int luaChon;
    do
    {
        cout << "\n=== THONG KE & BAO CAO ===\n";
        cout << "1. Thong ke luot kham theo ngay\n";
        cout << "2. Thong ke benh nhan theo thang\n";
        cout << "3. Thong ke doanh thu theo thang\n";
        cout << "4. Thong ke theo bac si\n";
        cout << "5. Thong ke trang thai lich kham\n";
        cout << "6. Thong ke doanh thu bac si\n";
        cout << "7. Xuat danh sach thong ke ra file\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        string input;
        switch (luaChon)
        {
        case 1:
            cout << "Nhap ngay (dd/mm/yyyy): ";
            getline(cin, input);
            thongKe.Thongkeluotkhamtrongngay(quanLy.getDSLichKham(),
                                             quanLy.getSoLuongLK(), input);
            break;
        case 2:
            cout << "Nhap thang (mm): ";
            getline(cin, input);
            thongKe.Thongkesobenhnhantrongthang(quanLy.getDSLichKham(),
                                                quanLy.getSoLuongLK(), input);
            break;
        case 3:
            cout << "Nhap thang (mm): ";
            getline(cin, input);
            thongKe.Tongdoanhthuthang(quanLy.getDSLichKham(),
                                      quanLy.getSoLuongLK(), input);
            break;
        case 4:
            cout << "Nhap ID bac si: ";
            getline(cin, input);
            thongKe.Thongkebacsikham(quanLy.getDSLichKham(),
                                     quanLy.getSoLuongLK(), input);
            break;
        case 5:
            thongKe.ThongkeTrangThai(quanLy.getDSLichKham(),
                                     quanLy.getSoLuongLK());
            break;
        case 6:
            cout << "Nhap ID bac si: ";
            getline(cin, input);
            thongKe.ThongkedoanhthutheoBacSi(quanLy.getDSLichKham(),
                                             quanLy.getSoLuongLK(), input);
            break;
            // Thêm option 7 trong menu thống kê
        case 7:
            // Xuất báo cáo thống kê ra file
            cout << "Nhap ten file de xuat bao cao (mac dinh: BaoCaoThongKe.txt): ";
            string tenFileBC;
            getline(cin, tenFileBC);
            if (tenFileBC.empty())
                tenFileBC = "BaoCaoThongKe.txt";

            xuatBaoCaoThongKe(tenFileBC);
            break;
        }
    } while (luaChon != 0);
}

void HeThongMenu::menuTimKiem()
{
    int luaChon;
    do
    {
        cout << "\n=== TIM KIEM NANG CAO ===\n";
        cout << "1. Tim kiem benh nhan\n";
        cout << "2. Tim kiem bac si\n";
        cout << "3. Tim kiem lich kham (nang cao)\n";
        cout << "4. Tim kiem theo ngay\n";
        cout << "5. Tim kiem theo trang thai\n";
        cout << "6. Tim kiem theo chuyen khoa\n";
        cout << "7. Tim kiem thong minh (toan he thong)\n";
        cout << "8. Xem tat ca lich kham cua benh nhan\n";
        cout << "9. Xem tat ca lich kham cua bac si\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
            timKiemBenhNhan();
            break;
        case 2:
            timKiemBacSi();
            break;
        case 3:
            timKiemLichKhamNangCao();
            break;
        case 4:
            timKiemTheoNgay();
            break;
        case 5:
            timKiemTheoTrangThai();
            break;
        case 6:
            timKiemTheoChuyenKhoa();
            break;
        case 7:
            timKiemThongMinh();
            break;
        case 8:
        {
            string idBN;
            cout << "Nhap ID benh nhan: ";
            getline(cin, idBN);
            xemLichKhamCuaBenhNhan(idBN);
            break;
        }
        case 9:
        {
            string idBS;
            cout << "Nhap ID bac si: ";
            getline(cin, idBS);
            xemLichKhamCuaBacSi(idBS);
            break;
        }
        case 0:
            cout << "Quay ve menu chinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (luaChon != 0);
}
// ========== CÁC HÀM TÌM KIẾM NÂNG CAO ==========

void HeThongMenu::timKiemBenhNhan()
{
    cout << "\n=== TIM KIEM BENH NHAN ===\n";
    cout << "Nhap tu khoa tim kiem (ten, SDT, CCCD, dia chi): ";
    string keyword;
    getline(cin, keyword);

    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    Patient *ds = quanLy.getDSBenhNhan();
    int soLuong = quanLy.getSoLuongBN();
    bool found = false;
    int count = 0;

    cout << "\nKET QUA TIM KIEM BENH NHAN:\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < soLuong; i++)
    {
        string tenLower = ds[i].getName();
        string sdtLower = ds[i].getsdt();
        string cccdLower = ds[i].getcccd();
        string diaChi = ds[i].getphuong() + " " + ds[i].gettp1();

        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        transform(sdtLower.begin(), sdtLower.end(), sdtLower.begin(), ::tolower);
        transform(cccdLower.begin(), cccdLower.end(), cccdLower.begin(), ::tolower);
        transform(diaChi.begin(), diaChi.end(), diaChi.begin(), ::tolower);

        if (tenLower.find(keyword) != string::npos ||
            sdtLower.find(keyword) != string::npos ||
            cccdLower.find(keyword) != string::npos ||
            diaChi.find(keyword) != string::npos ||
            ds[i].getID().find(keyword) != string::npos)
        {
            cout << "[" << ++count << "] ";
            ds[i].hienthithongtinbn();
            cout << "------------------------------------------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay benh nhan nao!\n";
    }
    else
    {
        cout << "Tim thay " << count << " benh nhan.\n";
    }
}

void HeThongMenu::timKiemBacSi()
{
    cout << "\n=== TIM KIEM BAC SI ===\n";
    cout << "Nhap tu khoa tim kiem (ten, SDT, chuyen khoa): ";
    string keyword;
    getline(cin, keyword);

    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    Doctor *ds = quanLy.getDSBacSi();
    int soLuong = quanLy.getSoLuongBS();
    bool found = false;
    int count = 0;

    cout << "\nKET QUA TIM KIEM BAC SI:\n";
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < soLuong; i++)
    {
        string tenLower = ds[i].getTenBS();
        string sdtLower = ds[i].getsdtbs();
        string chuyenKhoa;

        // Chuyển chuyên khoa từ số sang chuỗi
        switch (ds[i].getck())
        {
        case 1:
            chuyenKhoa = "Tim Mach";
            break;
        case 2:
            chuyenKhoa = "Noi Khoa";
            break;
        case 3:
            chuyenKhoa = "Ngoai Khoa";
            break;
        case 4:
            chuyenKhoa = "Da Lieu";
            break;
        case 5:
            chuyenKhoa = "Tai Mui Hong";
            break;
        case 6:
            chuyenKhoa = "Noi Tong Hop";
            break;
        default:
            chuyenKhoa = "Khong xac dinh";
            break;
        }

        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        transform(sdtLower.begin(), sdtLower.end(), sdtLower.begin(), ::tolower);
        transform(chuyenKhoa.begin(), chuyenKhoa.end(), chuyenKhoa.begin(), ::tolower);

        if (tenLower.find(keyword) != string::npos ||
            sdtLower.find(keyword) != string::npos ||
            chuyenKhoa.find(keyword) != string::npos ||
            ds[i].getIDBS().find(keyword) != string::npos)
        {
            cout << "[" << ++count << "] ";
            ds[i].hienthithongtinbs();
            cout << "------------------------------------------------------------\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay bac si nao!\n";
    }
    else
    {
        cout << "Tim thay " << count << " bac si.\n";
    }
}

void HeThongMenu::timKiemLichKhamNangCao()
{
    cout << "\n=== TIM KIEM LICH KHAM NANG CAO ===\n";

    int luaChon;
    cout << "1. Tim theo ma lich\n";
    cout << "2. Tim theo ten benh nhan\n";
    cout << "3. Tim theo ten bac si\n";
    cout << "4. Tim theo khoang thoi gian\n";
    cout << "Nhap lua chon: ";
    cin >> luaChon;
    cin.ignore();

    string keyword;
    LichKham *ds = quanLy.getDSLichKham();
    int soLuong = quanLy.getSoLuongLK();
    bool found = false;
    int count = 0;

    cout << "\nKET QUA TIM KIEM:\n";

    switch (luaChon)
    {
    case 1:
        cout << "Nhap ma lich (hoac mot phan): ";
        getline(cin, keyword);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

        for (int i = 0; i < soLuong; i++)
        {
            string maLich = ds[i].getidlk();
            transform(maLich.begin(), maLich.end(), maLich.begin(), ::tolower);

            if (maLich.find(keyword) != string::npos)
            {
                ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                                   quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
                cout << "------------------------\n";
                found = true;
                count++;
            }
        }
        break;

    case 2:
        cout << "Nhap ten benh nhan (hoac mot phan): ";
        getline(cin, keyword);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

        for (int i = 0; i < soLuong; i++)
        {
            string tenBN = ds[i].getTenBenhNhan(quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            transform(tenBN.begin(), tenBN.end(), tenBN.begin(), ::tolower);

            if (tenBN.find(keyword) != string::npos)
            {
                ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                                   quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
                cout << "------------------------\n";
                found = true;
                count++;
            }
        }
        break;

    case 3:
        cout << "Nhap ten bac si (hoac mot phan): ";
        getline(cin, keyword);
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

        for (int i = 0; i < soLuong; i++)
        {
            string tenBS = ds[i].getTenBacSi(quanLy.getDSBacSi(), quanLy.getSoLuongBS());
            transform(tenBS.begin(), tenBS.end(), tenBS.begin(), ::tolower);

            if (tenBS.find(keyword) != string::npos)
            {
                ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                                   quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
                cout << "------------------------\n";
                found = true;
                count++;
            }
        }
        break;

    case 4:
    {
        string tuNgay, denNgay;
        cout << "Nhap tu ngay (dd/mm/yyyy): ";
        getline(cin, tuNgay);
        cout << "Nhap den ngay (dd/mm/yyyy): ";
        getline(cin, denNgay);

        for (int i = 0; i < soLuong; i++)
        {
            string ngayKham = ds[i].getday();
            // So sánh ngày dạng dd/mm/yyyy
            if (ngayKham >= tuNgay && ngayKham <= denNgay)
            {
                ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                                   quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
                cout << "------------------------\n";
                found = true;
                count++;
            }
        }
        break;
    }
    }

    if (!found)
    {
        cout << "Khong tim thay lich kham nao!\n";
    }
    else
    {
        cout << "Tim thay " << count << " lich kham.\n";
    }
}

void HeThongMenu::timKiemTheoNgay()
{
    cout << "\n=== TIM KIEM THEO NGAY ===\n";
    cout << "Nhap ngay can tim (dd/mm/yyyy): ";
    string ngay;
    getline(cin, ngay);

    LichKham *ds = quanLy.getDSLichKham();
    int soLuong = quanLy.getSoLuongLK();
    bool found = false;
    int count = 0;

    cout << "\nLICH KHAM NGAY " << ngay << ":\n";

    for (int i = 0; i < soLuong; i++)
    {
        if (ds[i].getday() == ngay)
        {
            ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                               quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            cout << "------------------------\n";
            found = true;
            count++;
        }
    }

    if (!found)
    {
        cout << "Khong co lich kham nao vao ngay " << ngay << "!\n";
    }
    else
    {
        cout << "Tong cong: " << count << " lich kham.\n";
    }
}

void HeThongMenu::timKiemTheoTrangThai()
{
    cout << "\n=== TIM KIEM THEO TRANG THAI ===\n";
    cout << "Chon trang thai:\n";
    cout << "1. Dang cho\n";
    cout << "2. Hoan thanh\n";
    cout << "3. Da huy\n";
    cout << "Nhap lua chon: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string trangThai;
    switch (choice)
    {
    case 1:
        trangThai = "Dang cho";
        break;
    case 2:
        trangThai = "Hoan thanh";
        break;
    case 3:
        trangThai = "Da huy";
        break;
    default:
        cout << "Lua chon khong hop le!\n";
        return;
    }

    LichKham *ds = quanLy.getDSLichKham();
    int soLuong = quanLy.getSoLuongLK();
    bool found = false;
    int count = 0;

    cout << "\nLICH KHAM CO TRANG THAI '" << trangThai << "':\n";

    for (int i = 0; i < soLuong; i++)
    {
        if (ds[i].trangThai.getTrangthai() == trangThai)
        {
            ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                               quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            cout << "------------------------\n";
            found = true;
            count++;
        }
    }

    if (!found)
    {
        cout << "Khong co lich kham nao co trang thai '" << trangThai << "'!\n";
    }
    else
    {
        cout << "Tong cong: " << count << " lich kham.\n";
    }
}

void HeThongMenu::timKiemTheoChuyenKhoa()
{
    cout << "\n=== TIM KIEM THEO CHUYEN KHOA ===\n";
    cout << "1. Tim Mach\n";
    cout << "2. Noi Khoa\n";
    cout << "3. Ngoai Khoa\n";
    cout << "4. Da Lieu\n";
    cout << "5. Tai Mui Hong\n";
    cout << "6. Noi Tong Hop\n";
    cout << "Nhap lua chon chuyen khoa: ";

    int chuyenKhoa;
    cin >> chuyenKhoa;
    cin.ignore();

    if (chuyenKhoa < 1 || chuyenKhoa > 6)
    {
        cout << "Lua chon khong hop le!\n";
        return;
    }

    // Tìm bác sĩ thuộc chuyên khoa này
    Doctor *dsBS = quanLy.getDSBacSi();
    int soLuongBS = quanLy.getSoLuongBS();
    vector<string> dsIDBacSi;

    for (int i = 0; i < soLuongBS; i++)
    {
        if (dsBS[i].getck() == chuyenKhoa)
        {
            dsIDBacSi.push_back(dsBS[i].getIDBS());
        }
    }

    if (dsIDBacSi.empty())
    {
        cout << "Khong co bac si nao thuoc chuyen khoa nay!\n";
        return;
    }

    // Tìm lịch khám của các bác sĩ này
    LichKham *dsLK = quanLy.getDSLichKham();
    int soLuongLK = quanLy.getSoLuongLK();
    bool found = false;
    int count = 0;

    string tenChuyenKhoa;
    switch (chuyenKhoa)
    {
    case 1:
        tenChuyenKhoa = "Tim Mach";
        break;
    case 2:
        tenChuyenKhoa = "Noi Khoa";
        break;
    case 3:
        tenChuyenKhoa = "Ngoai Khoa";
        break;
    case 4:
        tenChuyenKhoa = "Da Lieu";
        break;
    case 5:
        tenChuyenKhoa = "Tai Mui Hong";
        break;
    case 6:
        tenChuyenKhoa = "Noi Tong Hop";
        break;
    }

    cout << "\nLICH KHAM CHUYEN KHOA " << tenChuyenKhoa << ":\n";

    for (int i = 0; i < soLuongLK; i++)
    {
        string idBS = dsLK[i].getIDBS();
        if (find(dsIDBacSi.begin(), dsIDBacSi.end(), idBS) != dsIDBacSi.end())
        {
            dsLK[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                                 quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            cout << "------------------------\n";
            found = true;
            count++;
        }
    }

    if (!found)
    {
        cout << "Khong co lich kham nao cho chuyen khoa nay!\n";
    }
    else
    {
        cout << "Tong cong: " << count << " lich kham.\n";
    }
}

void HeThongMenu::timKiemThongMinh()
{
    cout << "\n=== TIM KIEM THONG MINH ===\n";
    cout << "Nhap tu khoa tim kiem (tim trong toan he thong): ";
    string keyword;
    getline(cin, keyword);

    transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);

    cout << "\n=== KET QUA TOAN HE THONG ===\n";

    // Tìm trong bệnh nhân
    Patient *dsBN = quanLy.getDSBenhNhan();
    int soLuongBN = quanLy.getSoLuongBN();
    int countBN = 0;

    cout << "\n--- BENH NHAN ---\n";
    for (int i = 0; i < soLuongBN; i++)
    {
        string tenLower = dsBN[i].getName();
        string sdtLower = dsBN[i].getsdt();
        string cccdLower = dsBN[i].getcccd();

        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        transform(sdtLower.begin(), sdtLower.end(), sdtLower.begin(), ::tolower);
        transform(cccdLower.begin(), cccdLower.end(), cccdLower.begin(), ::tolower);

        if (tenLower.find(keyword) != string::npos ||
            sdtLower.find(keyword) != string::npos ||
            cccdLower.find(keyword) != string::npos ||
            dsBN[i].getID().find(keyword) != string::npos)
        {
            cout << "[" << ++countBN << "] ";
            dsBN[i].hienthithongtinbn();
            cout << "------------------------\n";
        }
    }

    // Tìm trong bác sĩ
    Doctor *dsBS = quanLy.getDSBacSi();
    int soLuongBS = quanLy.getSoLuongBS();
    int countBS = 0;

    cout << "\n--- BAC SI ---\n";
    for (int i = 0; i < soLuongBS; i++)
    {
        string tenLower = dsBS[i].getTenBS();
        string sdtLower = dsBS[i].getsdtbs();

        transform(tenLower.begin(), tenLower.end(), tenLower.begin(), ::tolower);
        transform(sdtLower.begin(), sdtLower.end(), sdtLower.begin(), ::tolower);

        if (tenLower.find(keyword) != string::npos ||
            sdtLower.find(keyword) != string::npos ||
            dsBS[i].getIDBS().find(keyword) != string::npos)
        {
            cout << "[" << ++countBS << "] ";
            dsBS[i].hienthithongtinbs();
            cout << "------------------------\n";
        }
    }

    // Tìm trong lịch khám
    LichKham *dsLK = quanLy.getDSLichKham();
    int soLuongLK = quanLy.getSoLuongLK();
    int countLK = 0;

    cout << "\n--- LICH KHAM ---\n";
    for (int i = 0; i < soLuongLK; i++)
    {
        string maLich = dsLK[i].getidlk();
        string tenBS = dsLK[i].getTenBacSi(quanLy.getDSBacSi(), quanLy.getSoLuongBS());
        string tenBN = dsLK[i].getTenBenhNhan(quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());

        transform(maLich.begin(), maLich.end(), maLich.begin(), ::tolower);
        transform(tenBS.begin(), tenBS.end(), tenBS.begin(), ::tolower);
        transform(tenBN.begin(), tenBN.end(), tenBN.begin(), ::tolower);

        if (maLich.find(keyword) != string::npos ||
            tenBS.find(keyword) != string::npos ||
            tenBN.find(keyword) != string::npos)
        {
            cout << "[" << ++countLK << "] ";
            dsLK[i].hienthilk();
            cout << "------------------------\n";
        }
    }

    cout << "\n=== TONG KET ===\n";
    cout << "Tim thay " << countBN << " benh nhan, ";
    cout << countBS << " bac si, ";
    cout << countLK << " lich kham.\n";
    cout << "Tong cong: " << (countBN + countBS + countLK) << " ket qua.\n";
}

// Thêm 2 hàm hỗ trợ
void HeThongMenu::xemLichKhamCuaBenhNhan(const string &idBN)
{
    LichKham *ds = quanLy.getDSLichKham();
    int soLuong = quanLy.getSoLuongLK();
    bool found = false;
    int count = 0;

    Patient *bn = quanLy.timBenhNhan(idBN);
    if (!bn)
    {
        cout << "Khong tim thay benh nhan voi ID: " << idBN << endl;
        return;
    }

    cout << "\n=== LICH KHAM CUA BENH NHAN: " << bn->getName() << " (" << idBN << ") ===\n";

    for (int i = 0; i < soLuong; i++)
    {
        if (ds[i].getIDBN() == idBN)
        {
            ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                               quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            cout << "------------------------\n";
            found = true;
            count++;
        }
    }

    if (!found)
    {
        cout << "Benh nhan nay chua co lich kham nao!\n";
    }
    else
    {
        cout << "Tong cong: " << count << " lich kham.\n";
    }
}

void HeThongMenu::xemLichKhamCuaBacSi(const string &idBS)
{
    LichKham *ds = quanLy.getDSLichKham();
    int soLuong = quanLy.getSoLuongLK();
    bool found = false;
    int count = 0;

    Doctor *bs = quanLy.timBacSi(idBS);
    if (!bs)
    {
        cout << "Khong tim thay bac si voi ID: " << idBS << endl;
        return;
    }

    cout << "\n=== LICH KHAM CUA BAC SI: " << bs->getTenBS() << " (" << idBS << ") ===\n";

    for (int i = 0; i < soLuong; i++)
    {
        if (ds[i].getIDBS() == idBS)
        {
            ds[i].hienThiDayDu(quanLy.getDSBacSi(), quanLy.getSoLuongBS(),
                               quanLy.getDSBenhNhan(), quanLy.getSoLuongBN());
            cout << "------------------------\n";
            found = true;
            count++;
        }
    }

    if (!found)
    {
        cout << "Bac si nay chua co lich kham nao!\n";
    }
    else
    {
        cout << "Tong cong: " << count << " lich kham.\n";
    }
}
void HeThongMenu::xuatBaoCaoThongKe(const string &filename)
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cout << "Khong the mo file de ghi bao cao!\n";
        return;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);

    fout << "========================================\n";
    fout << "       BAO CAO THONG KE PHONG KHAM\n";
    fout << "         Ngay: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\n";
    fout << "========================================\n\n";

    fout << "1. TONG QUAN HE THONG:\n";
    fout << "   - Tong so benh nhan: " << quanLy.getSoLuongBN() << "\n";
    fout << "   - Tong so bac si: " << quanLy.getSoLuongBS() << "\n";
    fout << "   - Tong so lich kham: " << quanLy.getSoLuongLK() << "\n\n";

    fout << "2. THONG KE TRANG THAI LICH KHAM:\n";
    int hoanthanh = 0, dangcho = 0, dahuy = 0;
    LichKham *dsLK = quanLy.getDSLichKham();

    for (int i = 0; i < quanLy.getSoLuongLK(); i++)
    {
        string tt = dsLK[i].trangThai.getTrangthai();
        if (tt == "Hoan thanh")
            hoanthanh++;
        else if (tt == "Dang cho")
            dangcho++;
        else if (tt == "Da huy")
            dahuy++;
    }

    fout << "   - Hoan thanh: " << hoanthanh << " ("
         << fixed << setprecision(1)
         << (quanLy.getSoLuongLK() > 0 ? (hoanthanh * 100.0 / quanLy.getSoLuongLK()) : 0) << "%)\n";
    fout << "   - Dang cho: " << dangcho << " ("
         << (quanLy.getSoLuongLK() > 0 ? (dangcho * 100.0 / quanLy.getSoLuongLK()) : 0) << "%)\n";
    fout << "   - Da huy: " << dahuy << " ("
         << (quanLy.getSoLuongLK() > 0 ? (dahuy * 100.0 / quanLy.getSoLuongLK()) : 0) << "%)\n\n";

    fout << "3. THONG KE CHUYEN KHOA:\n";
    Doctor *dsBS = quanLy.getDSBacSi();
    map<int, int> thongKeCK;

    for (int i = 0; i < quanLy.getSoLuongBS(); i++)
    {
        thongKeCK[dsBS[i].getck()]++;
    }

    for (auto &pair : thongKeCK)
    {
        string tenCK;
        switch (pair.first)
        {
        case 1:
            tenCK = "Tim Mach";
            break;
        case 2:
            tenCK = "Noi Khoa";
            break;
        case 3:
            tenCK = "Ngoai Khoa";
            break;
        case 4:
            tenCK = "Da Lieu";
            break;
        case 5:
            tenCK = "Tai Mui Hong";
            break;
        case 6:
            tenCK = "Noi Tong Hop";
            break;
        default:
            tenCK = "Khong xac dinh";
            break;
        }
        fout << "   - " << tenCK << ": " << pair.second << " bac si\n";
    }

    fout.close();
    cout << "Da xuat bao cao thong ke ra file: " << filename << endl;
}