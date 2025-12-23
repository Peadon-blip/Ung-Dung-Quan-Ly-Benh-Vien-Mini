// ThongKe.h
#pragma once
#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "LichKham.h"
using namespace std;

// Lớp ThongKe độc lập, không phụ thuộc vào QuanLyThongNhat
class ThongKe
{
public:
    ThongKe() {}

    // Các hàm thống kê nhận tham số là mảng
    static void Thongkeluotkhamtrongngay(LichKham *ds, int soLuong, const string &ngay);
    static void Thongkesobenhnhantrongthang(LichKham *ds, int soLuong, const string &thang);
    static void Tongdoanhthuthang(LichKham *ds, int soLuong, const string &thang);
    static void Thongkebacsikham(LichKham *ds, int soLuong, const string &maBaSi);
    static void ThongkeTrangThai(LichKham *ds, int soLuong);
    static void ThongkedoanhthutheoBacSi(LichKham *ds, int soLuong, const string &maBaSi);
};