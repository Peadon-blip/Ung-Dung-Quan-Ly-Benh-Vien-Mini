#include <iostream>
#include <string.h>
using namespace std;
#pragma once
class Patient
{
private:
    string id_bn;
    string tenBN;
    int gioitinh;
    string sdtbn;
    string cccd;
    int ngay, thang, nam;
    string diachi_to, diachi_phuong, diachi_tp, diachi_qg;

public:
    void them();
    void nhap();
    void hienthithongtinbn() const;
    bool Ktrasdt(const string &);
    bool Ktracccd(const string &);
    bool Ktrangaythangnamsinh(int, int, int);
    void write(const string &) const;
    static Patient read(const string &);
    string getName() const;
    void setTen(const string &);
    void setGT(const int &);
    int getgt() const;
    void setsdt(const string &);
    string getsdt() const;
    void setcccd(const string &);
    string getcccd() const;
    void setngay(const int &);
    int getngay() const;
    void setthang(const int &);
    int getthang() const;
    void setnam(const int &);
    int getnam() const;
    void setto(const string &);
    string getto() const;
    void setphuong(const string &);
    string getphuong() const;
    void settp1(const string &);
    string gettp1() const;
    void setqg(const string &);
    string getqg() const;
    void setID(const string &);
    string getID() const;
    string chuoi() const;
    static string getNextID(const string &fl);
    void xuatdstufile(const string &, const string &);
    // friend ostream()
};
