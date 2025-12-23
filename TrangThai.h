#ifndef TRANGTHAI_H
#define TRANGTHAI_H
#include <bits/stdc++.h>
using namespace std;

class TrangThai
{
private:
    string trangthai; // VD: "Hoan thanh", "Da huy", "Dang cho"
public:
    TrangThai();
    void nhap();
    void hienthithongtin() const;
    void setTrangthai(const string &tt);
    string getTrangthai() const;

    friend ostream &operator<<(ostream &out, const TrangThai &tt);
    friend istream &operator>>(istream &in, TrangThai &tt);
};
#endif
