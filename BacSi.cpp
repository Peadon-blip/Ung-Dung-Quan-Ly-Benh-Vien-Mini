#include "BacSi.h"
using namespace std;
int Doctor::next_ID = 10;
bool Doctor::Ktrasdt(const string &p)
{
    /// so dien thoai co 10 so
    /// luc dau bat dau co
    if (p.length() != 10)
        return false;
    if (p[0] != '0')
        return false;
    for (char c : p)
    {
        if (c < '0' || c > '9')
            return false;
    }
    return true;
}
void Doctor::nhapbs()
{
    cout << "Nhap ten bac si: ";
    getline(cin, tenBS);
    string tp;
    do
    {
        cout << "So dien thoai: ";
        getline(cin, tp);
        if (!Ktrasdt(tp))
        {
            cout << "So dien thoai khong hop le! Vui long nhap lai .... \n";
        }
    } while (!Ktrasdt(tp));
    sdt = tp;
    cout << "Nhap chuyen khoa: \n";
    cout << "1.Khoa tim mach\n2.Noi khoa\n3.Ngoai khoa\n4.Da lieu\n5.Tai mui hong\n";
    int ck = 0;
    do
    {
        cout << "Nhap lua chon chuyen khoa (1 - 5): ";
        getline(cin, tp);
        try
        {
            ck = stoi(tp);
        }
        catch (...) /// kiem tra bat loi
        {
            ck = 0;
        }
        if (ck < 1 || ck > 5)
            cout << "Lua chon khong hop le.Nhap lai\n";
    } while (ck < 1 || ck > 5);
    chuyenkhoa = ck;
    /// chuyen nganh khoa : khoa noi khoa ngoai khoa kham benh
}
string Doctor::write()
{
    stringstream s;
    s << id_BS << "|" << tenBS << "|" << sdt << "|" << chuyenkhoa << endl;
    return s.str();
}
/*Doctor Doctor::read(const string &p)
{
    stringstream s(p);
    string token;
    Doctor c;
    getline(s, c.tenBS, '|');
    getline(s, c.sdt, '|');
    string ck;
    getline(s, ck, '|');
    if (!ck.empty() && all_of(ck.begin(), ck.end(), ::isdigit))
    {
        c.chuyenkhoa = stoi(ck); // định dạng về kiểu int
    }
    else
        c.chuyenkhoa = 0; // gtri mac dinh
    return c;
}*/
Doctor Doctor::read(const string &p)
{
    stringstream s(p);
    Doctor c;
    string token;

    getline(s, token, '|');
    if (token.rfind("BS", 0) == 0) // Nếu token bắt đầu bằng "BS"
    {
        c.id_BS = token;
        getline(s, c.tenBS, '|');
    }
    else
    {
        // Không có ID -> tạo ID mới
        c.id_BS = "BS" + to_string(next_ID++);
        c.tenBS = token;
    }

    getline(s, c.sdt, '|');
    string ck;
    getline(s, ck, '|');
    if (!ck.empty() && all_of(ck.begin(), ck.end(), ::isdigit))
        c.chuyenkhoa = stoi(ck);
    else
        c.chuyenkhoa = 0;

    return c;
}

void Doctor::hienthithongtinbs()
{ // Phần tiêu đề bảng
    cout << "\n";
    cout << setfill(' ');
    cout << "| " << left << setw(8) << "ID BS"
         << "| " << setw(20) << "Ho ten Bac si"
         << "| " << setw(12) << "So dien thoai"
         << "| " << setw(15) << "Chuyen khoa" << " |\n";
    cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

    // Hiển thị thông tin bác sĩ hiện tại
    cout << "| " << left << setw(8) << id_BS
         << "| " << setw(20) << tenBS
         << "| " << setw(12) << sdt
         << "| " << setw(15);

    // Hiển thị chuyên khoa dạng chuỗi
    switch (chuyenkhoa)
    {
    case 1:
        cout << "Tim Mach";
        break;
    case 2:
        cout << "Noi Khoa";
        break;
    case 3:
        cout << "Ngoai Khoa";
        break;
    case 4:
        cout << "Da Lieu";
        break;
    case 5:
        cout << "Tai Mui Hong";
        break;
    case 6:
        cout << "Noi Tong Hop";
        break;
    default:
        cout << "Khong xac dinh";
        break;
    }
    cout << " |\n";
}

void Doctor::xuatdsbstufile(const string &inputFile, const string &outputFile)
{
    ifstream fin(inputFile);
    if (!fin.is_open())
    {
        cerr << " Không thể mở file " << inputFile << " để đọc.\n";
        return;
    }

    ofstream fout(outputFile);
    if (!fout.is_open())
    {
        cerr << "Không thể mở file " << outputFile << " để ghi.\n";
        return;
    }

    fout << setfill(' ');
    fout << "| " << left << setw(8) << "ID"
         << "| " << setw(25) << "Ten Bac Si"
         << "| " << setw(13) << "So Dien Thoai"
         << "| " << setw(15) << "Chuyen Khoa"
         << "|\n";
    fout << string(70, '-') << '\n';

    string line;
    while (getline(fin, line))
    {
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (line.empty())
            continue;
        Doctor bs = read(line);

        string ck;
        switch (bs.chuyenkhoa)
        {
        case 1:
            ck = "Tim Mach";
            break;
        case 2:
            ck = "Noi Khoa";
            break;
        case 3:
            ck = "Ngoai Khoa";
            break;
        case 4:
            ck = "Da Lieu";
            break;
        case 5:
            ck = "Tai Mui Hong";
            break;
        case 6:
            ck = "Noi Tong Hop";
            break;
        default:
            ck = "Khac";
            break;
        }

        fout << "| " << left << setw(8) << bs.id_BS
             << "| " << setw(25) << bs.tenBS
             << "| " << setw(13) << bs.sdt
             << "| " << setw(15) << ck << "|\n";
    }

    fout << string(70, '-') << '\n';
    fin.close();
    fout.close();

    // cout << " Đã xuất danh sách bác sĩ ra file: " << outputFile << endl;
}
string Doctor::getIDBS() const
{
    return id_BS;
}
string Doctor::getTenBS() const
{
    return tenBS;
}
string Doctor::getsdtbs() const
{
    return sdt;
}
int Doctor::getck() const
{
    return chuyenkhoa;
}
void Doctor::setIDBS(string i_d)
{
    id_BS = i_d;
}
void Doctor::settenbs(string ten)
{
    tenBS = ten;
}
void Doctor::setsdt(string sodt)
{
    sdt = sodt;
}
void Doctor::setck(int c_k)
{
    chuyenkhoa = c_k;
}
string Doctor::chuoibs() const
{
    stringstream ss;
    ss << id_BS << "|" << tenBS << "|" << chuyenkhoa << "|" << sdt << endl;
    return ss.str();
}