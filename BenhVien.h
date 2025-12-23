// BenhVien.h
#pragma once
#include "QuanLyThongNhat.h"
#include "ThongKe.h"

class HeThongMenu
{
private:
    QuanLyThongNhat quanLy;
    ThongKe thongKe;

public:
    void chayChuongTrinh();

private:
    void menuChinh();
    void menuQuanLyBenhNhan();
    void menuQuanLyBacSi();
    void menuQuanLyLichKham();
    void menuThongKeBaoCao();
    void menuTimKiem();

    void timKiemBenhNhan();
    void timKiemBacSi();
    void timKiemLichKhamNangCao();
    void timKiemTheoNgay();
    void timKiemTheoTrangThai();
    void timKiemTheoChuyenKhoa();
    void timKiemThongMinh();
    void xemLichKhamCuaBenhNhan(const string &);
    void xemLichKhamCuaBacSi(const string &);
    void xuatBaoCaoThongKe(const string &);

    void xuatDanhSachBenhNhan();
    void xuatDanhSachBacSi();
    void datLichKhamMoi();
    void capNhatTrangThai();
    void timKiemLichKham();
    void themBenhNhanMoi();
    void themBacSiMoi();
};