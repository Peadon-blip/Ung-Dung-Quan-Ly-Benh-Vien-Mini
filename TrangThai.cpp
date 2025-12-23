#include "TrangThai.h"

TrangThai::TrangThai()
{
    trangthai = "Dang cho"; // mặc định
}

void TrangThai::nhap()
{
    cout << "Nhap trang thai (Hoan thanh / Da huy / Dang cho): ";
    getline(cin, trangthai);
}

void TrangThai::hienthithongtin() const
{
    cout << trangthai;
}

void TrangThai::setTrangthai(const string &tt)
{
    trangthai = tt;
}

string TrangThai::getTrangthai() const
{
    return trangthai;
}

ostream &operator<<(ostream &out, const TrangThai &tt)
{
    out << tt.trangthai;
    return out;
}

istream &operator>>(istream &in, TrangThai &tt)
{
    getline(in, tt.trangthai);
    return in;
}
