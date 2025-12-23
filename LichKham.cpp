#include <bits/stdc++.h>
#include "LichKham.h"
int LichKham::next_id = 1;
LichKham::LichKham()
{
    // MaLich = GioKham = NgayKham = "";
    MaLich = GioKham = NgayKham = id_bn = id_bs = "";
    trangThai.setTrangthai("Dang cho"); // Mặc định
}
LichKham::LichKham(string ma, string idBN, string idBS, string ngay, string gio)
    : MaLich(ma), id_bn(idBN), id_bs(idBS), NgayKham(ngay), GioKham(gio)
{
    trangThai.setTrangthai("Dang cho"); // Mặc định
}

void LichKham::nhap()
{
    cout << "\n Nhap ma lich kham: ";
    getline(cin, MaLich);
    cout << "\n Nhap ngay Kham (dd/mm/yyyy): ";
    getline(cin, NgayKham);
    cout << "\n Nhap gio kham: ";
    getline(cin, GioKham);
    // cout << "\n Nhap bac si kham: ";
    // BacSi.nhapbs();
    // cout << "\n Nhap thong tin benh nhan: ";
    // BenhNhan.nhap();
    cout << "\n Nhập thông tin trang thai lich kham: ";
    string tt;
    getline(cin, tt);
    if (!tt.empty())
    {
        trangThai.setTrangthai(tt);
        // Trang thai.nhap
    }
}
// void LichKham::hienthithongtinlk()
// {
//     cout << "\n === LICH KHAM ===";
//     cout << "\n ma lich: " << MaLich;
//     cout << "\n ngay kham: " << NgayKham;
//     cout << "\n gio kham: " << GioKham;
//     cout << "\n bac si: ";
//     BacSi.hienthithongtinbs();
//     cout << "\n benh nhan: ";
//     BenhNhan.hienthithongtinbn();
//     /*cout << "\n phong kham: ";
//     Phongkham.hienthithongtinpk();*/
//     cout << "\n trang thai: ";
//     Trangthai.hienthithongtin();
// }
void LichKham::hienthilk() const
{
    cout << "\n === LICH KHAM ===";
    cout << "\n Ma lich: " << MaLich;
    cout << "\n ID Benh nhan: " << id_bn;
    cout << "\n ID Bac si: " << id_bs;
    cout << "\n Ngay kham: " << NgayKham;
    cout << "\n Gio kham: " << GioKham;
    cout << "\n Trang thai: " << trangThai.getTrangthai();
    cout << "\n==================";
}
string LichKham::write() const
{
    stringstream ss;
    ss << MaLich << "|" << id_bn << "|" << id_bs << "|"
       << NgayKham << "|" << GioKham << "|" << trangThai.getTrangthai()
       << "|" << fixed << setprecision(0) << tien << '\n'; // Thêm tiền
    return ss.str();
}
// LichKham LichKham::read(const string &line)
// {
// LichKham lk;
// stringstream ss(line);
// string tk;
// getline(ss, lk.MaLich, '|');
// getline(ss, lk.NgayKham, '|');
// getline(ss, lk.GioKham, '|');

// string idbs, idbn;
// getline(ss, idbs, '|');
// getline(ss, idbn, '|');
// // getline(ss, lk.Trangthai, '|');

// lk.BacSi.setIDBS(idbs);
// lk.BenhNhan.setID(idbn);
// return lk;
LichKham LichKham::read(const string &line)
{
    stringstream ss(line);
    string ma, idbn, idbs, ngay, gio, tt, strTien;

    getline(ss, ma, '|');
    getline(ss, idbn, '|');
    getline(ss, idbs, '|');
    getline(ss, ngay, '|');
    getline(ss, gio, '|');
    getline(ss, tt, '|');
    getline(ss, strTien, '|'); // Đọc tiền

    LichKham lk(ma, idbn, idbs, ngay, gio);
    if (!tt.empty())
    {
        lk.trangThai.setTrangthai(tt);
    }

    // Xử lý tiền
    if (!strTien.empty())
    {
        try
        {
            lk.tien = stod(strTien);
        }
        catch (...)
        {
            lk.tien = 200000; // Giá trị mặc định nếu lỗi
        }
    }
    else
    {
        lk.tien = 200000; // Giá trị mặc định
    }

    return lk;
}
// bool LichKham::ktratrunglich(const LichKham *ds, int soluong) const
// {
//     for (int i = 0; i < soluong; i++)
//     {
//         if (ds[i].BacSi.getIDBS() == BacSi.getIDBS() &&
//             ds[i].NgayKham == NgayKham &&
//             ds[i].GioKham == GioKham)
//         {
//             return true; // trùng lịch
//         }
//     }
//     return false;
// }
// SỬA: Chỉ cần 2 tham số, sử dụng dữ liệu của đối tượng hiện tại
bool LichKham::ktratrunglich(const LichKham *ds, int soluong) const
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getIDBS() == this->getIDBS() &&
            ds[i].getday() == this->getday() &&
            ds[i].gettime() == this->gettime())
        {
            return true; // trùng lịch
        }
    }
    return false;
}

void LichKham::capnhatTrangThai()
{
    cout << "\nCap nhat trang thai:";
    cout << "\n1. Hoan thanh";
    cout << "\n2. Da huy";
    cout << "\n3. Dang cho";
    cout << "\nChon (1-3): ";

    int chon;
    cin >> chon;
    cin.ignore();

    switch (chon)
    {
    case 1:
        trangThai.setTrangthai("Hoan thanh");
        break;
    case 2:
        trangThai.setTrangthai("Da huy");
        break;
    case 3:
        trangThai.setTrangthai("Dang cho");
        break;
    default:
        cout << "Lua chon khong hop le! Giữ nguyên trang thai hien tai.\n";
        break;
    }
}
// void timkiemLichKham(LichKham *ds, int soluong, const string &key)
// {
//     string keylower = key;
//     transform(keylower.begin(), keylower.end(), keylower.begin(), ::tolower);
//     for (int i = 0; i < soluong; i++)
//     {
//         string tenbs = ds[i].BacSi.getTenBS();
//         string tenbn = ds[i].BenhNhan.getName();
//         transform(tenbs.begin(), tenbs.end(), tenbs.begin(), ::tolower);
//         transform(tenbn.begin(), tenbn.end(), tenbn.begin(), ::tolower);

//         if (ds[i].MaLich == key || tenbs.find(keylower) != string::npos || tenbn.find(keylower) != string::npos)
//         {
//             ds[i].hienthilk();
//         }
//     }
// }
void sapxepLichTheoNgay(LichKham *ds, int soluong)
{
    for (int i = 0; i < soluong - 1; i++)
    {
        for (int j = i + 1; j < soluong; j++)
        {
            if (ds[i].getday() > ds[j].getday())
            {
                swap(ds[i], ds[j]);
            }
        }
    }
}
void xoalich(LichKham *ds, int &soluong, const string &ma)
{
    for (int i = 0; i < soluong; i++)
    {
        if (ds[i].getidlk() == ma)
        {
            for (int j = i; j < soluong - 1; j++)
            {
                ds[j] = ds[j + 1];
            }
            soluong--;
            cout << "Da xoa lich kham co ma: " << ma << endl;
            return;
        }
    }
    cout << "Khong tim thay ma lich kham!\n";
}
void thongkeLich(LichKham *ds, int soluong)
{
    int hoanthanh = 0, dahuy = 0, dangcho = 0;
    for (int i = 0; i < soluong; i++)
    {
        string tt = ds[i].trangThai.getTrangthai();
        if (tt == "Hoan thanh")
            hoanthanh++;
        else if (tt == "Da huy")
            dahuy++;
        else
            dangcho++;
    }
    cout << "\n=== Thong ke lich kham ===\n";
    cout << "Hoan thanh: " << hoanthanh << endl;
    cout << "Da huy: " << dahuy << endl;
    cout << "Dang cho: " << dangcho << endl;
}
string LichKham::taoMaTuDong(int stt)
{
    stringstream ss;
    ss << "LK" << setw(3) << setfill('0') << stt + 1;
    return ss.str();
}
void ghifileLichKham(LichKham *ds, int soluong, const string &filename)
{
    ofstream f(filename);
    if (!f.is_open())
    {
        cout << "Khong mo duoc file!\n";
        return;
    }
    for (int i = 0; i < soluong; i++)
    {
        f << ds[i].write();
    }
    f.close();
}
string LichKham::getidlk() const { return MaLich; }
string LichKham::getday() const { return NgayKham; }
string LichKham::gettime() const { return GioKham; }
string LichKham::getIDBN() const { return id_bn; }
string LichKham::getIDBS() const { return id_bs; }

void LichKham::setid(const string &id) { MaLich = id; }
void LichKham::setday(const string &day) { NgayKham = day; }
void LichKham::settime(const string &gio) { GioKham = gio; }
void LichKham::setIDBN(const string &id) { id_bn = id; }
void LichKham::setIDBS(const string &id) { id_bs = id; }
// string LichKham::getidlk() const
// {
//     return MaLich;
// }
// string LichKham::getday() const
// {
//     return NgayKham;
// }
// string LichKham::gettime() const
// {
//     return GioKham;
// }
// void LichKham::setid(const string &id)
// {
//     MaLich = id;
// }
// void LichKham::setday(const string &day)
// {
//     NgayKham = day;
// }
// void LichKham::settime(const string &gio)
// {
//     GioKham = gio;
// }
// Patient &LichKham::getBN()
// {
//     return BenhNhan;
// }
// void LichKham::setBN(const Patient &bn)
// {
//     BenhNhan = bn;
// }
// Doctor &LichKham::getDT()
// {
//     return BacSi;
// }
// void LichKham::setDT(const Doctor &bs)
// {
//     BacSi = bs;
// }
double LichKham::getTien() const
{
    return tien;
}

void LichKham::setTien(double t)
{
    tien = t;
}

double LichKham::tinhTienTheoChuyenKhoa(int chuyenKhoa)
{
    switch (chuyenKhoa)
    {
    case 1:
        return 500000; // Tim Mach
    case 2:
        return 300000; // Noi Khoa
    case 3:
        return 700000; // Ngoai Khoa
    case 4:
        return 250000; // Da Lieu
    case 5:
        return 350000; // Tai Mui Hong
    case 6:
        return 200000; // Noi Tong Hop
    default:
        return 200000; // Mac dinh
    }
}
string LichKham::getTenBacSi(Doctor *dsBacSi, int soLuongBS) const
{
    for (int i = 0; i < soLuongBS; i++)
    {
        if (dsBacSi[i].getIDBS() == id_bs)
        {
            return dsBacSi[i].getTenBS();
        }
    }
    return "Khong tim thay";
}

string LichKham::getTenBenhNhan(Patient *dsBenhNhan, int soLuongBN) const
{
    for (int i = 0; i < soLuongBN; i++)
    {
        if (dsBenhNhan[i].getID() == id_bn)
        {
            return dsBenhNhan[i].getName();
        }
    }
    return "Khong tim thay";
}

void LichKham::hienThiDayDu(Doctor *dsBacSi, int soLuongBS,
                            Patient *dsBenhNhan, int soLuongBN) const
{
    cout << "\n=== THONG TIN CHI TIET LICH KHAM ===" << endl;
    cout << "Ma lich: " << MaLich << endl;
    cout << "Bac si: " << getTenBacSi(dsBacSi, soLuongBS)
         << " (ID: " << id_bs << ")" << endl;
    cout << "Benh nhan: " << getTenBenhNhan(dsBenhNhan, soLuongBN)
         << " (ID: " << id_bn << ")" << endl;
    cout << "Ngay kham: " << NgayKham << endl;
    cout << "Gio kham: " << GioKham << endl;
    cout << "Trang thai: " << trangThai.getTrangthai() << endl;
    cout << "Tien kham: " << fixed << setprecision(0) << tien << " VND" << endl;
}

bool LichKham::isValid(Doctor *dsBacSi, int soLuongBS,
                       Patient *dsBenhNhan, int soLuongBN) const
{
    // Kiểm tra bác sĩ tồn tại
    bool bsTonTai = false;
    for (int i = 0; i < soLuongBS; i++)
    {
        if (dsBacSi[i].getIDBS() == id_bs)
        {
            bsTonTai = true;
            break;
        }
    }

    // Kiểm tra bệnh nhân tồn tại
    bool bnTonTai = false;
    for (int i = 0; i < soLuongBN; i++)
    {
        if (dsBenhNhan[i].getID() == id_bn)
        {
            bnTonTai = true;
            break;
        }
    }

    return bsTonTai && bnTonTai;
}
void LichKham::timkiemLichKham(LichKham *ds, int soluong, const string &key)
{
    string keylower = key;
    transform(keylower.begin(), keylower.end(), keylower.begin(), ::tolower);

    bool found = false;
    for (int i = 0; i < soluong; i++)
    {
        string malich = ds[i].getidlk();
        transform(malich.begin(), malich.end(), malich.begin(), ::tolower);

        if (malich.find(keylower) != string::npos)
        {
            ds[i].hienthilk();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay lich kham nao!\n";
    }
}