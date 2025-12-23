#include <bits/stdc++.h>
using namespace std;
#pragma once
class Doctor
{
private:
    string id_BS; /// 011
    string tenBS;
    int chuyenkhoa;
    string sdt;
    string PLV;
    static int next_ID;

public:
    Doctor()
    {
        next_ID++;
        ostringstream s;
        s << setw(3) << " " << setfill('0') << next_ID;
        id_BS = s.str();
    };
    string getIDBS() const;
    string getTenBS() const;
    string getsdtbs() const;
    int getck() const;

    void setIDBS(string);
    void settenbs(string);
    void setsdt(string);
    void setck(int);

    void nhapbs();
    bool Ktrasdt(const string &);
    void hienthithongtinbs();
    void xuatdsbstufile(const string &, const string &);
    string write();
    static Doctor read(const string &);
    string chuoibs() const;
};