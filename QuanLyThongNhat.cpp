// QuanLyThongNhat.cpp
#include "QuanLyThongNhat.h"
#include <fstream>
#include <sstream>
#include <iomanip>

QuanLyThongNhat::QuanLyThongNhat()
{
    sucChuaBN = 10;
    sucChuaBS = 10;
    sucChuaLK = 10;

    dsBenhNhan = new Patient[sucChuaBN];
    dsBacSi = new Doctor[sucChuaBS];
    dsLichKham = new LichKham[sucChuaLK];

    soLuongBN = 0;
    soLuongBS = 0;
    soLuongLK = 0;

    loadAllData();
}

QuanLyThongNhat::~QuanLyThongNhat()
{
    saveAllData();
    delete[] dsBenhNhan;
    delete[] dsBacSi;
    delete[] dsLichKham;
}

void QuanLyThongNhat::loadAllData()
{
    // Load bệnh nhân
    ifstream finBN("BenhNhan.txt");
    if (finBN.is_open())
    {
        string line;
        while (getline(finBN, line))
        {
            if (line.empty())
                continue;
            if (soLuongBN >= sucChuaBN)
                moRongDanhSachBN();
            dsBenhNhan[soLuongBN++] = Patient::read(line);
        }
        finBN.close();
    }

    // Load bác sĩ
    ifstream finBS("BacSi.txt");
    if (finBS.is_open())
    {
        string line;
        while (getline(finBS, line))
        {
            if (line.empty())
                continue;
            if (soLuongBS >= sucChuaBS)
                moRongDanhSachBS();
            dsBacSi[soLuongBS++] = Doctor::read(line);
        }
        finBS.close();
    }

    // Load lịch khám
    ifstream finLK("LichKham.txt");
    if (finLK.is_open())
    {
        string line;
        while (getline(finLK, line))
        {
            if (line.empty())
                continue;
            if (soLuongLK >= sucChuaLK)
                moRongDanhSachLK();
            dsLichKham[soLuongLK++] = LichKham::read(line);
        }
        finLK.close();
    }
}

void QuanLyThongNhat::saveAllData()
{
    // Lưu bệnh nhân
    ofstream foutBN("BenhNhan.txt");
    if (foutBN.is_open())
    {
        for (int i = 0; i < soLuongBN; i++)
        {
            foutBN << dsBenhNhan[i].chuoi() << endl;
        }
        foutBN.close();
    }

    // Lưu bác sĩ
    ofstream foutBS("BacSi.txt");
    if (foutBS.is_open())
    {
        for (int i = 0; i < soLuongBS; i++)
        {
            foutBS << dsBacSi[i].write();
        }
        foutBS.close();
    }

    // Lưu lịch khám
    ofstream foutLK("LichKham.txt");
    if (foutLK.is_open())
    {
        for (int i = 0; i < soLuongLK; i++)
        {
            foutLK << dsLichKham[i].write();
        }
        foutLK.close();
    }
}

Doctor *QuanLyThongNhat::timBacSi(const string &id)
{
    for (int i = 0; i < soLuongBS; i++)
    {
        if (dsBacSi[i].getIDBS() == id)
        {
            return &dsBacSi[i];
        }
    }
    return nullptr;
}

Patient *QuanLyThongNhat::timBenhNhan(const string &id)
{
    for (int i = 0; i < soLuongBN; i++)
    {
        if (dsBenhNhan[i].getID() == id)
        {
            return &dsBenhNhan[i];
        }
    }
    return nullptr;
}

LichKham *QuanLyThongNhat::timLichKham(const string &maLich)
{
    for (int i = 0; i < soLuongLK; i++)
    {
        if (dsLichKham[i].getidlk() == maLich)
        {
            return &dsLichKham[i];
        }
    }
    return nullptr;
}

bool QuanLyThongNhat::themLichKham(const LichKham &lk)
{
    // Kiểm tra trùng lịch
    if (kiemTraTrungLich(lk.getIDBS(), lk.getday(), lk.gettime()))
    {
        return false;
    }

    // Kiểm tra bác sĩ tồn tại
    if (!timBacSi(lk.getIDBS()))
    {
        return false;
    }

    // Kiểm tra bệnh nhân tồn tại
    if (!timBenhNhan(lk.getIDBN()))
    {
        return false;
    }

    if (soLuongLK >= sucChuaLK)
    {
        moRongDanhSachLK();
    }

    dsLichKham[soLuongLK++] = lk;
    return true;
}

bool QuanLyThongNhat::kiemTraTrungLich(const string &idBS, const string &ngay, const string &gio)
{
    for (int i = 0; i < soLuongLK; i++)
    {
        if (dsLichKham[i].getIDBS() == idBS &&
            dsLichKham[i].getday() == ngay &&
            dsLichKham[i].gettime() == gio)
        {
            return true;
        }
    }
    return false;
}

void QuanLyThongNhat::hienThiLichKhamDayDu()
{
    if (soLuongLK == 0)
    {
        cout << "\nKhong co lich kham nao!\n";
        return;
    }

    cout << "\n======================================== DANH SACH LICH KHAM ========================================\n";
    cout << left << setw(10) << "Ma Lich"
         << setw(12) << "ID BS"
         << setw(20) << "Ten Bac Si"
         << setw(12) << "ID BN"
         << setw(20) << "Ten Benh Nhan"
         << setw(15) << "Ngay Kham"
         << setw(10) << "Gio"
         << setw(15) << "Trang Thai"
         << setw(12) << "Tien Kham" << endl;
    cout << string(130, '=') << endl;

    for (int i = 0; i < soLuongLK; i++)
    {
        LichKham &lk = dsLichKham[i];
        Doctor *bs = timBacSi(lk.getIDBS());
        Patient *bn = timBenhNhan(lk.getIDBN());

        string tenBS = bs ? bs->getTenBS() : "Khong tim thay";
        string tenBN = bn ? bn->getName() : "Khong tim thay";

        cout << left << setw(10) << lk.getidlk()
             << setw(12) << lk.getIDBS()
             << setw(20) << (tenBS.length() > 18 ? tenBS.substr(0, 15) + "..." : tenBS)
             << setw(12) << lk.getIDBN()
             << setw(20) << (tenBN.length() > 18 ? tenBN.substr(0, 15) + "..." : tenBN)
             << setw(15) << lk.getday()
             << setw(10) << lk.gettime()
             << setw(15) << lk.trangThai.getTrangthai()
             << setw(12) << fixed << setprecision(0) << lk.getTien() << " VND" << endl;
    }
    cout << string(130, '=') << endl;
}

// Các hàm thống kê tích hợp
void QuanLyThongNhat::thongKeLuotKhamNgay(const string &ngay)
{
    int dem = 0;
    for (int i = 0; i < soLuongLK; i++)
    {
        if (dsLichKham[i].getday() == ngay)
        {
            dem++;
        }
    }
    cout << "\nSo luot kham ngay " << ngay << ": " << dem << endl;
}

void QuanLyThongNhat::thongKeTrangThai()
{
    int hoanthanh = 0, dangcho = 0, dahuy = 0;
    for (int i = 0; i < soLuongLK; i++)
    {
        string tt = dsLichKham[i].trangThai.getTrangthai();
        if (tt == "Hoan thanh")
            hoanthanh++;
        else if (tt == "Dang cho")
            dangcho++;
        else if (tt == "Da huy")
            dahuy++;
    }

    cout << "\n=== THONG KE TRANG THAI LICH KHAM ===" << endl;
    cout << "Hoan thanh: " << hoanthanh << endl;
    cout << "Dang cho: " << dangcho << endl;
    cout << "Da huy: " << dahuy << endl;
    cout << "Tong cong: " << soLuongLK << endl;
}

using namespace std;

// Thêm các hàm mở rộng mảng
void QuanLyThongNhat::moRongDanhSachBN()
{
    int newSize = sucChuaBN * 2;
    Patient *newArr = new Patient[newSize];
    for (int i = 0; i < soLuongBN; i++)
    {
        newArr[i] = dsBenhNhan[i];
    }
    delete[] dsBenhNhan;
    dsBenhNhan = newArr;
    sucChuaBN = newSize;
}

void QuanLyThongNhat::moRongDanhSachBS()
{
    int newSize = sucChuaBS * 2;
    Doctor *newArr = new Doctor[newSize];
    for (int i = 0; i < soLuongBS; i++)
    {
        newArr[i] = dsBacSi[i];
    }
    delete[] dsBacSi;
    dsBacSi = newArr;
    sucChuaBS = newSize;
}

void QuanLyThongNhat::moRongDanhSachLK()
{
    int newSize = sucChuaLK * 2;
    LichKham *newArr = new LichKham[newSize];
    for (int i = 0; i < soLuongLK; i++)
    {
        newArr[i] = dsLichKham[i];
    }
    delete[] dsLichKham;
    dsLichKham = newArr;
    sucChuaLK = newSize;
}

// Thêm các hàm thêm/xóa
bool QuanLyThongNhat::themBenhNhan(const Patient &bn)
{
    if (soLuongBN >= sucChuaBN)
    {
        moRongDanhSachBN();
    }
    dsBenhNhan[soLuongBN++] = bn;
    return true;
}

bool QuanLyThongNhat::themBacSi(const Doctor &bs)
{
    if (soLuongBS >= sucChuaBS)
    {
        moRongDanhSachBS();
    }
    dsBacSi[soLuongBS++] = bs;
    return true;
}

bool QuanLyThongNhat::xoaBenhNhan(const string &id)
{
    for (int i = 0; i < soLuongBN; i++)
    {
        if (dsBenhNhan[i].getID() == id)
        {
            // Dịch các phần tử phía sau lên
            for (int j = i; j < soLuongBN - 1; j++)
            {
                dsBenhNhan[j] = dsBenhNhan[j + 1];
            }
            soLuongBN--;
            return true;
        }
    }
    return false;
}

bool QuanLyThongNhat::xoaBacSi(const string &id)
{
    for (int i = 0; i < soLuongBS; i++)
    {
        if (dsBacSi[i].getIDBS() == id)
        {
            for (int j = i; j < soLuongBS - 1; j++)
            {
                dsBacSi[j] = dsBacSi[j + 1];
            }
            soLuongBS--;
            return true;
        }
    }
    return false;
}

bool QuanLyThongNhat::xoaLichKham(const string &maLich)
{
    for (int i = 0; i < soLuongLK; i++)
    {
        if (dsLichKham[i].getidlk() == maLich)
        {
            for (int j = i; j < soLuongLK - 1; j++)
            {
                dsLichKham[j] = dsLichKham[j + 1];
            }
            soLuongLK--;
            return true;
        }
    }
    return false;
}

void QuanLyThongNhat::capNhatTrangThai(const string &maLich, const string &trangThaiMoi)
{
    LichKham *lk = timLichKham(maLich);
    if (lk)
    {
        lk->trangThai.setTrangthai(trangThaiMoi);
    }
}

// Thêm các hàm thống kê còn thiếu
void QuanLyThongNhat::thongKeBenhNhanThang(const string &thang)
{
    int dem = 0;
    for (int i = 0; i < soLuongLK; i++)
    {
        string ngay = dsLichKham[i].getday();
        // Tìm tháng trong chuỗi dd/mm/yyyy
        size_t pos = ngay.find('/');
        if (pos != string::npos)
        {
            string thangTrongNgay = ngay.substr(pos + 1, 2);
            if (thangTrongNgay == thang)
            {
                dem++;
            }
        }
    }
    cout << "\nSo benh nhan trong thang " << thang << ": " << dem << endl;
}

void QuanLyThongNhat::thongKeDoanhThuThang(const string &thang)
{
    double tongTien = 0;
    int dem = 0;
    for (int i = 0; i < soLuongLK; i++)
    {
        string ngay = dsLichKham[i].getday();
        size_t pos = ngay.find('/');
        if (pos != string::npos)
        {
            string thangTrongNgay = ngay.substr(pos + 1, 2);
            if (thangTrongNgay == thang && dsLichKham[i].trangThai.getTrangthai() == "Hoan thanh")
            {
                tongTien += dsLichKham[i].getTien();
                dem++;
            }
        }
    }
    cout << "\nDoanh thu thang " << thang << ": "
         << fixed << setprecision(0) << tongTien << " VND (" << dem << " luot kham)" << endl;
}

void QuanLyThongNhat::thongKeTheoBacSi(const string &idBS)
{
    int dem = 0;
    for (int i = 0; i < soLuongLK; i++)
    {
        if (dsLichKham[i].getIDBS() == idBS)
        {
            dem++;
        }
    }
    Doctor *bs = timBacSi(idBS);
    string tenBS = bs ? bs->getTenBS() : "Khong tim thay";
    cout << "\nBac si " << tenBS << " (ID: " << idBS << ") da kham: " << dem << " luot" << endl;
}

void QuanLyThongNhat::thongKeDoanhThuBacSi(const string &idBS)
{
    double tongTien = 0;
    int dem = 0;
    for (int i = 0; i < soLuongLK; i++)
    {
        if (dsLichKham[i].getIDBS() == idBS &&
            dsLichKham[i].trangThai.getTrangthai() == "Hoan thanh")
        {
            tongTien += dsLichKham[i].getTien();
            dem++;
        }
    }
    Doctor *bs = timBacSi(idBS);
    string tenBS = bs ? bs->getTenBS() : "Khong tim thay";
    cout << "\nDoanh thu cua bac si " << tenBS << " (ID: " << idBS << "): "
         << fixed << setprecision(0) << tongTien << " VND (" << dem << " luot kham)" << endl;
}