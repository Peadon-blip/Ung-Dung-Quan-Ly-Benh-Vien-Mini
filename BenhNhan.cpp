#include "BenhNhan.h"
#include <bits/stdc++.h>
#include <filesystem>
bool Patient::Ktrasdt(const string &p)
{
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
bool Patient::Ktracccd(const string &cid)
{
    if (cid.length() != 12)
        return false;
    for (char pid : cid)
    {
        if (pid < '0' || pid > '9')
            return false;
    }
    return true;
}
bool Patient::Ktrangaythangnamsinh(int ngay, int thang, int nam)
{
    if (thang < 1 || thang > 12)
        return false;
    if (ngay < 1 || ngay > 31)
        return false;
    /// CÁC THÁNG CÓ 30 NGÀY
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
    {
        return ngay <= 30;
    }
    bool namnhuan = (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    if (thang == 2)
    {
        return ngay <= (namnhuan ? 29 : 28);
    }
    return true;
}

void Patient::write(const string &fl) const
{
    cout << "Dang mo file" << filesystem ::absolute(fl) << endl;
    /// p.write("BenhNhan.txt");
    ofstream fout(fl, ios::app);
    if (!fout.is_open())
    {
        cerr << " file 0 mo duoc " << fl << "de ghi\n";
        perror("Ly do");
        return;
        /// return *this;
    }
    // fout << id_bn << "|" << tenBN << "|" << gioitinh << "|" << sdtbn << "|" << cccd << "|" << ngay << "|" << thang << "|" << nam << "|" << diachi_to << "|" << diachi_phuong << "|" << diachi_tp << "|" << diachi_qg << endl;
    fout << chuoi() << endl;
    fout.close();
    /// return *this;
}

// Patient Patient::read(const string &s)
// {
//     Patient p;
//     stringstream ss(s);
//     string tp;

//     try
//     {
//         // ĐẾM SỐ TRƯỜNG
//         int fieldCount = 0;
//         string temp = s;
//         size_t pos = 0;
//         while ((pos = temp.find('|', pos)) != string::npos) {
//             fieldCount++;
//             pos++;
//         }

//         if (fieldCount < 11) {
//             cerr << "Du lieu thieu truong: " << s << endl;
//             return p; // Trả về patient rỗng
//         }

//         getline(ss, p.id_bn, '|');
//         getline(ss, p.tenBN, '|');

//         getline(ss, tp, '|');
//         p.gioitinh = tp.empty() ? 0 : stoi(tp);

//         getline(ss, p.sdtbn, '|');
//         getline(ss, p.cccd, '|');

//         getline(ss, tp, '|');
//         p.ngay = tp.empty() ? 0 : stoi(tp);

//         getline(ss, tp, '|');
//         p.thang = tp.empty() ? 0 : stoi(tp);

//         getline(ss, tp, '|');
//         p.nam = tp.empty() ? 0 : stoi(tp);

//         getline(ss, p.diachi_to, '|');
//         getline(ss, p.diachi_phuong, '|');
//         getline(ss, p.diachi_tp, '|');
//         getline(ss, p.diachi_qg, '|');

//         cout << "Doc thanh cong: " << p.tenBN << " - ID: " << p.id_bn << endl;
//     }
//     catch (const exception &e)
//     {
//         cerr << "Loi nghiem trong khi doc benh nhan: " << s << endl;
//         cerr << "Loi: " << e.what() << endl;
//         // Trả về patient rỗng
//         p = Patient();
//     }

//     return p;
// }
// Patient Patient::read(const string &s)
// {
//     Patient p;
//     stringstream ss(s);
//     string tp;

//     try
//     {
//         getline(ss, p.id_bn, '|');
//         getline(ss, p.tenBN, '|');

//         getline(ss, tp, '|');
//         p.gioitinh = tp.empty() ? 0 : stoi(tp);

//         getline(ss, p.sdtbn, '|');
//         getline(ss, p.cccd, '|');

//         getline(ss, tp, '|');
//         p.ngay = tp.empty() ? 0 : stoi(tp);

//         getline(ss, tp, '|');
//         p.thang = tp.empty() ? 0 : stoi(tp);

//         getline(ss, tp, '|');
//         p.nam = tp.empty() ? 0 : stoi(tp);

//         getline(ss, p.diachi_to, '|');
//         getline(ss, p.diachi_phuong, '|');
//         getline(ss, p.diachi_tp, '|');
//         getline(ss, p.diachi_qg, '|');

//         // Debug
//         // cout << "Doc duoc benh nhan: " << p.tenBN << " - ID: " << p.id_bn << endl;
//     }
//     catch (const exception &e)
//     {
//         cerr << "Loi khi doc benh nhan tu chuoi: " << s << endl;
//         cerr << "Loi: " << e.what() << endl;
//     }

//     return p;
// }
// Patient Patient::read(const string &s)
// {
//     Patient p;
//     // p.read("BenhNhan.txt");
//     //  s << p.tenBN << "|" << gioitinh << "|" << sdtbn << "|" << cccd << "|" << ngay << "|" << thang << "|" << nam << "|" << diachi_to << "|" << diachi_phuong << "|" << diachi_tp << "|" << diachi_qg << endl;
//     stringstream ss(s);
//     string tp;
//     getline(ss, p.id_bn, '|');
//     getline(ss, p.tenBN, '|');
//     getline(ss, tp, '|');
//     p.gioitinh = tp.empty() ? 0 : stoi(tp); // định dạng chuyển kiểu int -> string để sử dụng getline
//     getline(ss, p.sdtbn, '|');
//     getline(ss, p.cccd, '|');
//     getline(ss, tp, '|');
//     p.ngay = tp.empty() ? 0 : stoi(tp);
//     getline(ss, tp, '|');
//     p.thang = tp.empty() ? 0 : stoi(tp);
//     getline(ss, tp, '|');
//     p.nam = tp.empty() ? 0 : stoi(tp);
//     getline(ss, p.diachi_to, '|');
//     getline(ss, p.diachi_phuong, '|');
//     getline(ss, p.diachi_tp, '|');
//     getline(ss, p.diachi_qg);

//     return p;
// }
Patient Patient::read(const string &s)
{
    Patient p;

    // Xóa các ký tự đặc biệt
    string cleaned = s;
    cleaned.erase(remove(cleaned.begin(), cleaned.end(), '\r'), cleaned.end());
    cleaned.erase(remove(cleaned.begin(), cleaned.end(), '\n'), cleaned.end());

    // Kiểm tra số lượng trường
    int fieldCount = 0;
    for (char c : cleaned)
    {
        if (c == '|')
            fieldCount++;
    }

    if (fieldCount < 11)
    {
        cerr << "Canh bao: Du lieu thieu truong! Chi co " << fieldCount
             << " truong (can 11). Chuoi: "
             << (cleaned.length() > 50 ? cleaned.substr(0, 50) + "..." : cleaned) << endl;
    }

    stringstream ss(cleaned);
    string tp;

    try
    {
        getline(ss, p.id_bn, '|');
        getline(ss, p.tenBN, '|');

        getline(ss, tp, '|');
        p.gioitinh = (tp.empty() || !isdigit(tp[0])) ? 0 : stoi(tp);

        getline(ss, p.sdtbn, '|');
        getline(ss, p.cccd, '|');

        getline(ss, tp, '|');
        p.ngay = (tp.empty() || !isdigit(tp[0])) ? 0 : stoi(tp);

        getline(ss, tp, '|');
        p.thang = (tp.empty() || !isdigit(tp[0])) ? 0 : stoi(tp);

        getline(ss, tp, '|');
        p.nam = (tp.empty() || !isdigit(tp[0])) ? 0 : stoi(tp);

        getline(ss, p.diachi_to, '|');
        getline(ss, p.diachi_phuong, '|');
        getline(ss, p.diachi_tp, '|');

        // Đọc trường cuối cùng (quốc gia) - KHÔNG dùng delimiter
        getline(ss, p.diachi_qg);

        /// cout << "Doc thanh cong: " << p.id_bn << " - " << p.tenBN << endl;
    }
    catch (const exception &e)
    {
        cerr << "Loi khi doc: " << e.what() << " - Chuoi: "
             << (cleaned.length() > 50 ? cleaned.substr(0, 50) + "..." : cleaned) << endl;
    }
    return p;
}
string Patient::chuoi() const
{
    stringstream ss;
    ss << id_bn << "|" << tenBN << "|" << gioitinh << "|" << sdtbn << "|" << cccd << "|" << ngay << "|" << thang << "|" << nam << "|" << diachi_to << "|" << diachi_phuong << "|" << diachi_tp << "|" << diachi_qg;
    return ss.str();
}
string Patient::getName() const
{
    return tenBN;
}
void Patient::setID(const string &id)
{
    id_bn = id;
}
string Patient::getID() const
{
    return id_bn;
}

void Patient::nhap()
{
    cout << "Ten benh nhan: ";
    getline(cin, tenBN);
    cout << "Chon gioi tinh:\n";
    cout << "1. Nam\n";
    cout << "2. Nu\n";
    cout << "Nhap lua chon (1 hoac 2): ";
    cin >> gioitinh;
    cout << "Gioi tinh: ";
    switch (gioitinh)
    {
    case 1:
        cout << "Nam" << endl;
        break;
    case 2:
        cout << "Nu" << endl;
        break;
    default:
        cout << "0 hop le" << endl;
    }
    do
    {
        cout << "Nhap so dien thoai: ";
        cin >> sdtbn;
        if (!Ktrasdt(sdtbn))
        {
            cout << "So dien thoai khong hop le!\nVui long nhap lai...." << endl;
        }
    } while (!Ktrasdt(sdtbn));
    do
    {
        cout << "Can cuoc cong dan: ";
        cin >> cccd;
        if (!Ktracccd(cccd))
        {
            cout << "Can cuoc cong dan khong hop le!\nVui long nhap lai...." << endl;
        }
    } while (!Ktracccd(cccd));
    do
    {
        cout << "- Ngay: ";
        cin >> ngay;
        cout << "- Thang: ";
        cin >> thang;
        cout << "- Nam: ";
        cin >> nam;
        if (!Ktrangaythangnamsinh(ngay, thang, nam))
        {
            cout << "Ngay - thang - nam sinh khong hop le!\nVui long nhap lai.... " << endl;
        }
    } while (!Ktrangaythangnamsinh(ngay, thang, nam));
    cin.ignore();
    cout << "Nhap to: ";
    getline(cin, diachi_to);
    cout << "Nhap phuong: ";
    getline(cin, diachi_phuong);
    cout << "Nhap thanh pho: ";
    getline(cin, diachi_tp);
    cout << "Nhap quoc gia: ";
    getline(cin, diachi_qg);
}
void Patient::hienthithongtinbn() const
{
    cout << setfill(' ');
    cout << "|" << left << setw(20) << "Ten BN"
         << "|" << setw(13) << "SDT"
         << "|" << setw(8) << "Gioi tinh"
         << "|" << setw(14) << "CCCD"
         << "|" << setw(12) << "Ngay Sinh"
         << "|" << setw(5) << "To"
         << "|" << setw(13) << "Phuong"
         << "|" << setw(12) << "Thanh Pho"
         << "|" << setw(10) << "Quoc gia" << "|\n";
    cout << "________________________________________";
    string gt = (gioitinh == 1 ? "Nam" : (gioitinh == 0 ? "Nu" : "Khac"));
    string ngaySinh = to_string(ngay) + "/" + to_string(thang) + "/" + to_string(nam);
    cout << "| " << left << setw(20) << tenBN
         << "| " << setw(13) << sdtbn
         << "| " << setw(8) << gioitinh
         << "| " << setw(14) << cccd
         << "| " << setw(12) << ngaySinh
         << "| " << setw(5) << diachi_to
         << "| " << setw(13) << diachi_phuong
         << "| " << setw(12) << diachi_tp
         << "| " << setw(10) << diachi_qg << "|\n";
}
// void Patient::xuatdstufile(const string &fl, const string &out)
// {
//     ifstream fin(fl);
//     if (!fin.is_open())
//     {
//         cerr << "Khong the mo file " << fl << " de doc\n";
//         return;
//     }

//     ofstream fout(out, ios::trunc);
//     if (!fout.is_open())
//     {
//         cerr << "Khong the mo file " << out << " de ghi.\n";
//         fin.close();
//         return;
//     }

//     // Định dạng header bảng
//     fout << setfill(' ');
//     fout << "| " << left << setw(20) << "Ten BN"
//          << "| " << setw(13) << "SDT"
//          << "| " << setw(8) << "Gioi tinh"
//          << "| " << setw(14) << "CCCD"
//          << "| " << setw(12) << "Ngay Sinh"
//          << "| " << setw(5) << "To"
//          << "| " << setw(13) << "Phuong"
//          << "| " << setw(12) << "Thanh Pho"
//          << "| " << setw(10) << "Quoc gia" << "|\n";
//     fout << string(150, '-') << "\n";

//     string line;
//     int count = 0;

//     while (getline(fin, line))
//     {
//         if (line.empty())
//             continue;

//         cout << "Dang doc dong: " << line << endl; // Debug

//         try
//         {
//             Patient p = read(line);
//             string gt = (p.gioitinh == 1 ? "Nam" : (p.gioitinh == 2 ? "Nu" : "Khac"));
//             string ngaySinh = to_string(p.ngay) + "/" + to_string(p.thang) + "/" + to_string(p.nam);

//             fout << "| " << left << setw(20) << p.tenBN
//                  << "| " << setw(13) << p.sdtbn
//                  << "| " << setw(8) << gt
//                  << "| " << setw(14) << p.cccd
//                  << "| " << setw(12) << ngaySinh
//                  << "| " << setw(5) << p.diachi_to
//                  << "| " << setw(13) << p.diachi_phuong
//                  << "| " << setw(12) << p.diachi_tp
//                  << "| " << setw(10) << p.diachi_qg << "|\n";
//             count++;
//         }
//         catch (const exception &e)
//         {
//             cerr << "Loi khi doc dong: " << line << " - " << e.what() << endl;
//         }
//     }

//     fout << string(150, '-') << '\n';
//     fin.close();
//     fout.close();

//     cout << "Da xuat " << count << " benh nhan sang file: " << out << endl;
// }
// void Patient::xuatdstufile(const string &fl, const string &out)
// {
//     ifstream fin(fl);
//     if (!fin.is_open())
//     {
//         cerr << "0 the mo file " << fl << "de ghi";
//         return;
//     }
//     ofstream fout(out);
//     {
//         if (!fout.is_open())
//         {
//             cerr << " 0 the mo file " << out << "de ghi.\n";
//             return;
//         }
//     }
//     fout << setfill(' ');
//     fout << "| " << left << setw(20) << "Ten BN"
//          << "| " << setw(13) << "SDT"
//          << "| " << setw(8) << "Gioi tinh"
//          << "| " << setw(14) << "CCCD"
//          << "| " << setw(12) << "Ngay Sinh"
//          << "| " << setw(5) << "To"
//          << "| " << setw(13) << "Phuong"
//          << "| " << setw(12) << "Thanh Pho"
//          << "| " << setw(10) << "Quoc gia" << "|\n";
//     fout << string(150, '-') << "\n";

//     string l;
//     while (getline(fin, l))
//     {
//         if (l.empty())
//             continue; // bo qua dong trong
//         Patient p = read(l);
//         string gt = (p.gioitinh == 1 ? "Nam" : (p.gioitinh == 2 ? "Nu" : "Khac"));
//         string ngaySinh = to_string(p.ngay) + "/" + to_string(p.thang) + "/" + to_string(p.nam);

//         fout << "| " << left << setw(20) << p.tenBN
//              << "| " << setw(13) << p.sdtbn
//              << "| " << setw(8) << gt
//              << "| " << setw(14) << p.cccd
//              << "| " << setw(12) << ngaySinh
//              << "| " << setw(5) << p.diachi_to
//              << "| " << setw(13) << p.diachi_phuong
//              << "| " << setw(12) << p.diachi_tp
//              << "| " << setw(10) << p.diachi_qg << "|\n";
//     }
//     fout << string(150, '-') << '\n';
//     fin.close();
//     fout.close();
//     /// cleanfile("BenhNhan.txt");
// }
void Patient::xuatdstufile(const string &fl, const string &out)
{
    ifstream fin(fl);
    if (!fin.is_open())
    {
        cerr << "Khong the mo file " << fl << " de doc\n";
        return;
    }

    // ĐỌC TOÀN BỘ NỘI DUNG FILE VÀO MỘT CHUỖI
    stringstream buffer;
    buffer << fin.rdbuf();
    string allData = buffer.str();
    fin.close();

    cout << "Tong du lieu doc duoc: " << allData.length() << " ky tu\n";
    cout << "Du lieu mau (100 ky tu dau): "
         << (allData.length() > 100 ? allData.substr(0, 100) + "..." : allData) << endl;

    ofstream fout(out, ios::trunc);
    if (!fout.is_open())
    {
        cerr << "Khong the mo file " << out << " de ghi.\n";
        return;
    }

    // Định dạng header bảng
    fout << setfill(' ');
    fout << "| " << left << setw(20) << "Ten BN"
         << "| " << setw(13) << "SDT"
         << "| " << setw(8) << "Gioi tinh"
         << "| " << setw(14) << "CCCD"
         << "| " << setw(12) << "Ngay Sinh"
         << "| " << setw(5) << "To"
         << "| " << setw(13) << "Phuong"
         << "| " << setw(12) << "Thanh Pho"
         << "| " << setw(10) << "Quoc gia" << "|\n";
    fout << string(150, '-') << "\n";

    // PHÂN TÍCH DỮ LIỆU - TÁCH THEO ID BỆNH NHÂN "BN"
    size_t pos = 0;
    int count = 0;

    while (pos < allData.length())
    {
        // Tìm bắt đầu của bản ghi tiếp theo (bắt đầu bằng "BN")
        size_t startPos = allData.find("BN", pos);
        if (startPos == string::npos)
            break;

        // Tìm bắt đầu của bản ghi tiếp theo sau đó (hoặc kết thúc chuỗi)
        size_t nextStart = allData.find("BN", startPos + 2);

        string record;
        if (nextStart != string::npos)
        {
            // Cắt từ vị trí hiện tại đến trước "BN" tiếp theo
            record = allData.substr(startPos, nextStart - startPos);
            pos = nextStart;
        }
        else
        {
            // Đây là bản ghi cuối cùng
            record = allData.substr(startPos);
            pos = allData.length();
        }

        // Xóa khoảng trắng và ký tự xuống dòng nếu có
        record.erase(remove(record.begin(), record.end(), '\r'), record.end());
        record.erase(remove(record.begin(), record.end(), '\n'), record.end());

        if (record.empty())
            continue;

        cout << "Xu ly ban ghi " << (count + 1) << ": "
             << (record.length() > 60 ? record.substr(0, 60) + "..." : record) << endl;

        try
        {
            Patient p = read(record);

            // Kiểm tra dữ liệu hợp lệ
            if (p.tenBN.empty() && p.id_bn.empty())
            {
                cerr << "Bo qua ban ghi khong hop le: " << record << endl;
                continue;
            }

            string gt;
            switch (p.gioitinh)
            {
            case 1:
                gt = "Nam";
                break;
            case 2:
                gt = "Nu";
                break;
            default:
                gt = "Khac";
                break;
            }

            string ngaySinh;
            if (p.ngay > 0 && p.thang > 0 && p.nam > 0)
            {
                ngaySinh = to_string(p.ngay) + "/" + to_string(p.thang) + "/" + to_string(p.nam);
            }
            else
            {
                ngaySinh = "KXD";
            }

            // Xuất dữ liệu
            fout << "| " << left << setw(20) << (p.tenBN.empty() ? "KXD" : p.tenBN)
                 << "| " << setw(13) << (p.sdtbn.empty() ? "KXD" : p.sdtbn)
                 << "| " << setw(8) << gt
                 << "| " << setw(14) << (p.cccd.empty() ? "KXD" : p.cccd)
                 << "| " << setw(12) << ngaySinh
                 << "| " << setw(5) << (p.diachi_to.empty() ? "KXD" : p.diachi_to)
                 << "| " << setw(13) << (p.diachi_phuong.empty() ? "KXD" : p.diachi_phuong)
                 << "| " << setw(12) << (p.diachi_tp.empty() ? "KXD" : p.diachi_tp)
                 << "| " << setw(10) << (p.diachi_qg.empty() ? "KXD" : p.diachi_qg) << "|\n";
            count++;
        }
        catch (const exception &e)
        {
            cerr << "Loi khi xu ly ban ghi: " << record << endl;
            cerr << "Loi: " << e.what() << endl;
            continue;
        }
    }

    fout << string(150, '-') << '\n';
    fout.close();

    cout << "Da xuat " << count << " benh nhan sang file: " << out << endl;
}
// }
// void Patient::xuatdstufile(const string &fl, const string &out)
// {
//     ifstream fin(fl);
//     if (!fin.is_open())
//     {
//         cerr << "Khong the mo file " << fl << " de doc\n";
//         return;
//     }

//     ofstream fout(out, ios::trunc);
//     if (!fout.is_open())
//     {
//         cerr << "Khong the mo file " << out << " de ghi.\n";
//         fin.close();
//         return;
//     }

//     // Định dạng header bảng
//     fout << setfill(' ');
//     fout << "| " << left << setw(20) << "Ten BN"
//          << "| " << setw(13) << "SDT"
//          << "| " << setw(8) << "Gioi tinh"
//          << "| " << setw(14) << "CCCD"
//          << "| " << setw(12) << "Ngay Sinh"
//          << "| " << setw(5) << "To"
//          << "| " << setw(13) << "Phuong"
//          << "| " << setw(12) << "Thanh Pho"
//          << "| " << setw(10) << "Quoc gia" << "|\n";
//     fout << string(100, '-') << "\n";

//     string line;
//     int count = 0;

//     while (getline(fin, line))
//     {
//         if (line.empty())
//             continue;

//         cout << "Dang doc dong: " << line << endl; // Debug

//         try
//         {
//             Patient p = read(line);

//                         if (p.tenBN.empty())
//             {
//                 cerr << "Du lieu benh nhan khong hop le, bo qua dong: " << line << endl;
//                 continue;
//             }

//             string gt;
//             switch (p.gioitinh)
//             {
//             case 1:
//                 gt = "Nam";
//                 break;
//             case 2:
//                 gt = "Nu";
//                 break;
//             default:
//                 gt = "Khac";
//                 break;
//             }

//             string ngaySinh;
//             if (p.ngay > 0 && p.thang > 0 && p.nam > 0)
//             {
//                 ngaySinh = to_string(p.ngay) + "/" + to_string(p.thang) + "/" + to_string(p.nam);
//             }
//             else
//             {
//                 ngaySinh = "Khong xac dinh";
//             }

//             // XUẤT DỮ LIỆU VỚI KIỂM TRA RỖNG
//             fout << "| " << left << setw(20) << (p.tenBN.empty() ? "KXD" : p.tenBN)
//                  << "| " << setw(13) << (p.sdtbn.empty() ? "KXD" : p.sdtbn)
//                  << "| " << setw(8) << gt
//                  << "| " << setw(14) << (p.cccd.empty() ? "KXD" : p.cccd)
//                  << "| " << setw(12) << ngaySinh
//                  << "| " << setw(5) << (p.diachi_to.empty() ? "KXD" : p.diachi_to)
//                  << "| " << setw(13) << (p.diachi_phuong.empty() ? "KXD" : p.diachi_phuong)
//                  << "| " << setw(12) << (p.diachi_tp.empty() ? "KXD" : p.diachi_tp)
//                  << "| " << setw(10) << (p.diachi_qg.empty() ? "KXD" : p.diachi_qg) << "|\n";
//             count++;
//         }
//         catch (const exception &e)
//         {
//             cerr << "Loi khi doc dong: " << line << " - " << e.what() << endl;
//             // TIẾP TỤC XỬ LÝ CÁC DÒNG TIẾP THEO THAY VÌ DỪNG LẠI
//             continue;
//         }
//     }

//     fout << string(100, '-') << '\n';
//     fin.close();
//     fout.close();

//     cout << "Da xuat " << count << " benh nhan sang file: " << out << endl;
// }
void Patient::setTen(const string &ten)
{
    tenBN = ten;
}
void Patient::setGT(const int &gt)
{
    gioitinh = gt;
}
void Patient::setsdt(const string &sdt)
{
    sdtbn = sdt;
}
void Patient::setcccd(const string &cc)
{
    cccd = cc;
}
void Patient::setngay(const int &n)
{
    ngay = n;
}
void Patient::setthang(const int &t)
{
    thang = t;
}
void Patient::setnam(const int &na)
{
    nam = na;
}
void Patient::setto(const string &to)
{
    diachi_to = to;
}
void Patient::setphuong(const string &phuong)
{
    diachi_phuong = phuong;
}
void Patient::settp1(const string &tp)
{
    diachi_tp = tp;
}
void Patient::setqg(const string &qg)
{
    diachi_qg = qg;
}
int Patient::getgt() const
{
    return gioitinh;
}
string Patient::getcccd() const
{
    return cccd;
}
int Patient::getngay() const
{
    return ngay;
}
int Patient::getthang() const
{
    return thang;
}
int Patient::getnam() const
{
    return nam;
}
string Patient::getto() const
{
    return diachi_to;
}
string Patient::getphuong() const
{
    return diachi_phuong;
}
string Patient::gettp1() const
{
    return diachi_tp;
}
string Patient ::getqg() const
{
    return diachi_qg;
}
string Patient ::getsdt() const
{
    return sdtbn;
}