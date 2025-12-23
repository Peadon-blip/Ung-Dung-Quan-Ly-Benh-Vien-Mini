// QuanLyThongNhat.h
#pragma once
#include "BenhNhan.h"
#include "BacSi.h"
#include "LichKham.h"
// #include "ThongKe.h" // Tạm bỏ vì circular dependency

class QuanLyThongNhat
{
private:
    Patient *dsBenhNhan;
    Doctor *dsBacSi;
    LichKham *dsLichKham;
    // ThongKe *thongKe; // Tạm bỏ

    int soLuongBN;
    int soLuongBS;
    int soLuongLK;
    int sucChuaBN;
    int sucChuaBS;
    int sucChuaLK;

public:
    QuanLyThongNhat();
    ~QuanLyThongNhat();

    // ===== QUẢN LÝ CHUNG =====
    void loadAllData();
    void saveAllData();

    // ===== TRA CỨU =====
    Doctor *timBacSi(const string &id);
    Patient *timBenhNhan(const string &id);
    LichKham *timLichKham(const string &maLich);

    // ===== GETTER =====
    Patient *getDSBenhNhan() { return dsBenhNhan; }
    Doctor *getDSBacSi() { return dsBacSi; }
    LichKham *getDSLichKham() { return dsLichKham; }
    int getSoLuongBN() const { return soLuongBN; }
    int getSoLuongBS() const { return soLuongBS; }
    int getSoLuongLK() const { return soLuongLK; }

    // ===== THÊM/XÓA CÓ KIỂM TRA =====
    bool themBenhNhan(const Patient &bn);
    bool themBacSi(const Doctor &bs);
    bool themLichKham(const LichKham &lk);

    bool xoaBenhNhan(const string &id);
    bool xoaBacSi(const string &id);
    bool xoaLichKham(const string &maLich);

    // ===== THỐNG KÊ TÍCH HỢP =====
    void thongKeLuotKhamNgay(const string &ngay);
    void thongKeBenhNhanThang(const string &thang);
    void thongKeDoanhThuThang(const string &thang);
    void thongKeTheoBacSi(const string &idBS);
    void thongKeTrangThai();
    void thongKeDoanhThuBacSi(const string &idBS);

    // ===== TIỆN ÍCH =====
    void hienThiLichKhamDayDu(); // Hiển thị đầy đủ thông tin
    bool kiemTraTrungLich(const string &idBS, const string &ngay, const string &gio);
    void capNhatTrangThai(const string &maLich, const string &trangThaiMoi);

private:
    void moRongDanhSachBN();
    void moRongDanhSachBS();
    void moRongDanhSachLK();
};