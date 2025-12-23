// ThongKe.cpp
#include "ThongKe.h"
#include <iomanip>
#include <iostream>

void ThongKe::Thongkeluotkhamtrongngay(LichKham *ds, int soLuong, const string &ngay)
{
    int dem = 0;
    for (int i = 0; i < soLuong; i++)
    {
        if (ds[i].getday() == ngay)
        {
            dem++;
        }
    }
    cout << "\nSo luot kham trong ngay " << ngay << ": " << dem << endl;
}

void ThongKe::ThongkeTrangThai(LichKham *ds, int soLuong)
{
    int hoanthanh = 0, dangcho = 0, dahuy = 0;
    for (int i = 0; i < soLuong; i++)
    {
        string tt = ds[i].trangThai.getTrangthai();
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
    cout << "Tong so: " << soLuong << endl;
}

// Giữ nguyên các hàm khác nhưng thêm tham số ds và soLuong
void ThongKe::Thongkesobenhnhantrongthang(LichKham *ds, int soLuong, const string &thang)
{
    int dem = 0;
    for (int i = 0; i < soLuong; i++)
    {
        string ngay = ds[i].getday();
        if (ngay.find("/" + thang + "/") != string::npos)
        {
            dem++;
        }
    }
    cout << "\nSo benh nhan trong thang " << thang << ": " << dem << endl;
}

void ThongKe::Tongdoanhthuthang(LichKham *ds, int soLuong, const string &thang)
{
    double tongTien = 0;
    int count = 0;

    for (int i = 0; i < soLuong; i++)
    {
        string ngay = ds[i].getday();
        if (ngay.find("/" + thang + "/") != string::npos)
        {
            if (ds[i].trangThai.getTrangthai() == "Hoan thanh")
            {
                tongTien += ds[i].getTien();
                count++;
            }
        }
    }

    cout << "\nTong doanh thu thang " << thang << ": "
         << fixed << setprecision(0) << tongTien << " VND ("
         << count << " luot kham hoan thanh)" << endl;
 }
    // void ThongKe::Thongkebacsikham(LichKham *ds, int soLuong, const string &maBaSi)
    // {
    //     int dem = 0;
    //     for (int i = 0; i < soLuong; i++)
    //     {
    //         // Giả sử có hàm getMaBacSi() hoặc thuộc tính tương tự
    //         if (ds[i].getMaBacSi() == maBaSi) // Thay bằng phương thức thực tế của bạn
    //         {
    //             dem++;
    //         }
    //     }
    //     cout << "\nSo luot kham cua bac si " << maBaSi << ": " << dem << endl;
    // }

    // void ThongKe::ThongkedoanhthutheoBacSi(LichKham *ds, int soLuong, const string &maBaSi)
    // {
    //     double tongTien = 0;
    //     int count = 0;

    //     for (int i = 0; i < soLuong; i++)
    //     {
    //         // Kiểm tra bác sĩ và trạng thái hoàn thành
    //         if (ds[i].getMaBacSi() == maBaSi && ds[i].trangThai.getTrangthai() == "Hoan thanh")
    //         {
    //             tongTien += ds[i].getTien();
    //             count++;
    //         }
    //     }

    //     cout << "\nDoanh thu cua bac si " << maBaSi << ": "
    //          << fixed << setprecision(0) << tongTien << " VND ("
    //          << count << " luot kham hoan thanh)" << endl;
    // }

    void ThongKe::Thongkebacsikham(LichKham * ds, int soLuong, const string &maBaSi)
    {
        int dem = 0;
        for (int i = 0; i < soLuong; i++)
        {
            if (ds[i].getIDBS() == maBaSi) // Sửa getIDBS() thay vì getmabacSi
            {
                dem++;
            }
        }
        cout << "\nBac si " << maBaSi << " da kham: " << dem << " luot" << endl;
    }

    void ThongKe::ThongkedoanhthutheoBacSi(LichKham * ds, int soLuong, const string &maBaSi)
    {
        double tongTien = 0;
        int count = 0;

        for (int i = 0; i < soLuong; i++)
        {
            if (ds[i].getIDBS() == maBaSi && ds[i].trangThai.getTrangthai() == "Hoan thanh")
            {
                tongTien += ds[i].getTien();
                count++;
            }
        }

        cout << "\nDoanh thu cua bac si " << maBaSi << ": "
             << fixed << setprecision(0) << tongTien << " VND ("
             << count << " luot kham hoan thanh)" << endl;
    }