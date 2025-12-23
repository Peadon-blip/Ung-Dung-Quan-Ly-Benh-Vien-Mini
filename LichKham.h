#pragma once
#include <bits/stdc++.h>
#include "BenhNhan.h"
#include "BacSi.h"
// #include "PhongKham.h"
#include "TrangThai.h"
using namespace std;
class LichKham
{
private:
    double tien;

public:
    string MaLich;
    string id_bn;
    string id_bs;
    int MaPhongKham;
    string Phongkham;
    string NgayKham;
    string GioKham;
    string note;
    static int next_id;
    Patient BenhNhan;
    Doctor BacSi;
    TrangThai trangThai;

public:
    LichKham();
    //  LichKham(int, int, int, int, const string &, const string &);
    LichKham(string ma, string idBN, string idBS, string ngay, string gio);
    string getIDBN() const;
    string getIDBS() const;
    void setIDBN(const string &id);
    void setIDBS(const string &id);
    void nhap();
    void hienthilk() const;
    /*int layMalich() const;
    int layMaBN() const;
    int layMaPhong() const;
    string layNgayKham() const;
    string LayGioKham() const;

    string ghiDong() const;
    static LichKham docDong(const string &);*/
    string write() const;
    static LichKham read(const string &); /// doc tu file

    string getidlk() const;
    string getday() const;
    string gettime() const;

    void setid(const string &);
    void setday(const string &);
    void settime(const string &);

    Patient &getBN();
    Doctor &getDT();

    void setBN(const Patient &);
    void setDT(const Doctor &);
    // void hienthithongtinlk();
    // void hienthilk();
    bool ktratrunglich(const LichKham *, int) const;
    void capnhatTrangThai();
    void timkiemLichKham(LichKham *, int, const string &);
    static void sapxepLichTheoNgay(LichKham *, int);
    // void xoalich(LichKham *, int &, const string &);
    static void thongkeLich(LichKham *, int);
    // void ghifileLichKham(LichKham *, int, const string &);
    static string taoMaTuDong(int stt); // sinh mã tự động
    double getTien() const;
    void setTien(double t);
    static double tinhTienTheoChuyenKhoa(int chuyenKhoa);
    // Thêm phương thức mới
    string getTenBacSi(Doctor *dsBacSi, int soLuongBS) const;
    string getTenBenhNhan(Patient *dsBenhNhan, int soLuongBN) const;
    void hienThiDayDu(Doctor *dsBacSi, int soLuongBS,
                      Patient *dsBenhNhan, int soLuongBN) const;

    // Validation
    bool isValid(Doctor *dsBacSi, int soLuongBS,
                 Patient *dsBenhNhan, int soLuongBN) const;
};
void xoalich(LichKham *, int &, const string &);
void ghifileLichKham(LichKham *, int, const string &);