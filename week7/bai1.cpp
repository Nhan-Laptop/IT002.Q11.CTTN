#include <bits/stdc++.h>
using namespace std;


class NhanVien{
protected: 
    string hoten;
    string ngaysinh;
    double luongcoban;
public:
    NhanVien(string &hoten, string &ngaysinh,
                double &luongcoban): hoten(hoten), ngaysinh(ngaysinh), luongcoban(luongcoban) {};
    NhanVien(): hoten(""), ngaysinh(""), luongcoban(0) {};
    virtual double tinhluong() = 0;
    virtual void Xuat(){
        cout << "Ho ten: " << hoten << endl;
        cout << "Ngay sinh: " << ngaysinh << endl;
        cout << "Luong co ban: " << luongcoban << endl;
    }
    string getName(){
        return hoten;
    }
};


class NhanVienSanXuat: public NhanVien{
protected:
    int sosanpham;
    double trocap;
public:
    NhanVienSanXuat(string &hoten, string &ngaysinh,
                double &luongcoban, int &sosanpham, double &trocap)
                : NhanVien(hoten, ngaysinh, luongcoban), sosanpham(sosanpham), trocap(trocap) {};
    NhanVienSanXuat(): NhanVien(), sosanpham(0), trocap(0) {};
    double tinhluong(){
        return luongcoban + sosanpham*200000 + trocap;
    }
    void Xuat(){
        NhanVien::Xuat();
        cout << "So san pham: " << sosanpham << endl;
        cout << "Tro cap: " << trocap << endl;
    }
};

class NhanVienVanPhong: public NhanVien{
protected:
    int songaylamviec;
    double trocap;
public:
    NhanVienVanPhong(string &hoten, string &ngaysinh,
                double &luongcoban, int &songaylamviec, double &trocap)
                : NhanVien(hoten, ngaysinh, luongcoban), songaylamviec(songaylamviec), trocap(trocap) {};
    NhanVienVanPhong(): NhanVien(), songaylamviec(0), trocap(0) {};
    double tinhluong(){
        return luongcoban + songaylamviec*200000 + trocap;
    }
    void Xuat(){
        NhanVien::Xuat();
        cout << "So ngay lam viec: " << songaylamviec << endl;
        cout << "Tro cap: " << trocap << endl;
    }
};
class NhanVienQuanLy: public NhanVien{
protected:
    double hesochucvu;
    double thuong;
public:
    NhanVienQuanLy(string &hoten, string &ngaysinh,
                double &luongcoban, double &hesochucvu, double &thuong)
                : NhanVien(hoten, ngaysinh, luongcoban), hesochucvu(hesochucvu), thuong(thuong) {};
    NhanVienQuanLy(): NhanVien(), hesochucvu(0), thuong(0) {};
    double tinhluong(){
        return luongcoban * hesochucvu + thuong;
    }
    void Xuat(){
        NhanVien::Xuat();
        cout << "He so chuc vu: " << hesochucvu << endl;
        cout << "Thuong: " << thuong << endl;
    }
};

int main (){
    NhanVien *a[3];

    string name1 = "Nguyen Van A";
    string dob1 = "01/01/1990";
    double basic_salary1 = 5;
    int working_days1 = 1;
    double allowance1 = 1;
    a[0] = new NhanVienVanPhong(name1, dob1, basic_salary1, working_days1, allowance1);
    cout << "Luong cua nhan vien 1: " << a[0]->tinhluong() << endl;
    a[0]->Xuat();

    string name2 = "Tran Thi B";
    string dob2 = "02/02/1992";
    double basic_salary2 = 6;
    int products2 = 2;
    double allowance2 = 1.5;
    a[1] = new NhanVienSanXuat(name2, dob2, basic_salary2, products2, allowance2);
    cout << "Luong cua nhan vien 2: " << a[1]->tinhluong() << endl;
    a[1]->Xuat();

    string name3 = "Le Van C";
    string dob3 = "03/03/1993";
    double basic_salary3 = 7;
    double position_coefficient3 = 2;
    double bonus3 = 2;
    a[2] = new NhanVienQuanLy(name3, dob3, basic_salary3, position_coefficient3, bonus3);
    cout << "Luong cua nhan vien 3: " << a[2]->tinhluong() << endl;
    a[2]->Xuat();


    double TongLuong = 0;
    for (int i = 0; i < 3; i++){
        TongLuong += a[i]->tinhluong();
    }
    cout << "Tong luong cong ty phai tra: " << TongLuong << endl;

    string Ten ;
    cout<<"Nhap ten nhan vien can tim: ";
    getline(cin, Ten);

    for (int i = 0; i < 3; i++){
        if (a[i]->getName() == Ten){
            a[i]->Xuat();
        }
    }

    return 0;

    
}
