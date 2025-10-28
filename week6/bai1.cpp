#include<bits/stdc++.h> 
using namespace std;

class SinhVien{
protected:
    string *MSSV, *hovaten, *diachi;
    int *tongsotinchi, *diemtrungbinh;
public: 
    SinhVien (string const &M, string const &H, string const &D, int T, int DTB) {
        MSSV = new string(M);
        hovaten = new string(H);
        diachi = new string(D);
        tongsotinchi = new int(T);
        diemtrungbinh = new int(DTB);
    }
    SinhVien (){
        MSSV =nullptr;
        hovaten = nullptr;
        diachi = nullptr;
        tongsotinchi = nullptr;
        diemtrungbinh = nullptr;
    }
    ~SinhVien(){
        delete MSSV;
        delete hovaten;
        delete diachi;
        delete tongsotinchi;
        delete diemtrungbinh;
    }
    SinhVien (const SinhVien &sv){
        MSSV = new string(*(sv.MSSV));
        hovaten = new string(*(sv.hovaten));
        diachi = new string(*(sv.diachi));
        tongsotinchi = new int(*(sv.tongsotinchi));
        diemtrungbinh = new int(*(sv.diemtrungbinh));
    }
    SinhVien &operator=(const SinhVien &sv){
        if(this != &sv){
            delete MSSV;
            delete hovaten;
            delete diachi;
            delete tongsotinchi;
            delete diemtrungbinh;
            MSSV = new string(*(sv.MSSV));
            hovaten = new string(*(sv.hovaten));
            diachi = new string(*(sv.diachi));
            tongsotinchi = new int(*(sv.tongsotinchi));
            diemtrungbinh = new int(*(sv.diemtrungbinh));
        }
        return *this;
    }
    friend istream& operator >>(istream &is, SinhVien &sv);
    friend ostream& operator <<(ostream &os,const SinhVien &sv);
};
istream& operator >>(istream &is, SinhVien &sv){
    string M, H, D;
    int T, DTB;
    cout<<"Nhap MSSV: ";
    getline(is, M);
    cout<<"Nhap Ho va Ten: ";
    getline(is, H);
    cout<<"Nhap Dia Chi: ";
    getline(is, D);
    cout<<"Nhap Tong So Tin Chi: ";
    is >> T;
    cout<<"Nhap Diem Trung Binh: ";
    is >> DTB;

    delete sv.MSSV;
    delete sv.hovaten;
    delete sv.diachi;
    delete sv.tongsotinchi;
    delete sv.diemtrungbinh;
    sv.MSSV = new string(M);
    sv.hovaten = new string(H);
    sv.diachi = new string(D);
    sv.tongsotinchi = new int(T);
    sv.diemtrungbinh = new int(DTB);
    return is;
}
ostream& operator <<(ostream &os, const SinhVien &sv){
    cout<<"MSSV: "; os<<*(sv.MSSV)<<endl;
    cout<<"Ho va Ten: "; os<<*(sv.hovaten)<<endl;
    cout<<"Dia Chi: "; os<<*(sv.diachi)<<endl;
    cout<<"Tong So Tin Chi: "; os<<*(sv.tongsotinchi)<<endl;
    cout<<"Diem Trung Binh: "; os<<*(sv.diemtrungbinh)<<endl;
    return os;
}   
class SvDaiHoc: public SinhVien{
private:
    string *tenluanvan;
    int *diemluanvan;
public:
    SvDaiHoc (string const &M, string const &H, string const &D, int T, int DTB, string const &TLV, int DLV)
    :SinhVien(M, H, D, T, DTB) {
        tenluanvan = new string(TLV);
        diemluanvan = new int(DLV);
    }
    SvDaiHoc (){
        tenluanvan = nullptr;
        diemluanvan = nullptr;
    }
    ~SvDaiHoc(){
        delete tenluanvan;
        delete diemluanvan;
    }
    SvDaiHoc (const SvDaiHoc &svdh):SinhVien(svdh){
        tenluanvan = new string(*(svdh.tenluanvan));
        diemluanvan = new int(*(svdh.diemluanvan));
    }
    SvDaiHoc &operator=(const SvDaiHoc &svdh){
        if(this != &svdh){
            SinhVien::operator=(svdh);
            delete tenluanvan;
            delete diemluanvan;
            tenluanvan = new string(*(svdh.tenluanvan));
            diemluanvan = new int(*(svdh.diemluanvan));
        }
        return *this;
    }
    void XetTotNghiep(){
        if ( *this->diemluanvan >= 5 and *this->tongsotinchi >=170
                and *this->diemtrungbinh >= 5 ){
                    cout<<"Sinh Vien Du Dieu Kien Tot Nghiep"<<endl;
                }
        else{
            cout<<"Sinh Vien Khong Du Dieu Kien Tot Nghiep"<<endl;
        }
    }
    friend istream& operator >>(istream &is, SvDaiHoc &svdh);
    friend ostream& operator <<(ostream &os,const SvDaiHoc &svdh);
};
istream& operator >>(istream &is, SvDaiHoc &svdh){
    is >> (SinhVien&)svdh;
    string TLV;
    int DLV;
    is.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"Nhap Ten Luan Van: ";

    getline(is, TLV);
    cout<<"Nhap Diem Luan Van: ";
    is >> DLV;
    is.ignore(numeric_limits<streamsize>::max(), '\n');

    char n;
    delete svdh.tenluanvan;
    delete svdh.diemluanvan;
    svdh.tenluanvan = new string(TLV);
    svdh.diemluanvan = new int(DLV);
    return is;
}
ostream& operator <<(ostream &os, const SvDaiHoc &svdh){
    os << (const SinhVien&)svdh;
    cout<<"Ten Luan Van: "; os<<*(svdh.tenluanvan)<<endl;
    cout<<"Diem Luan Van: "; os<<*(svdh.diemluanvan)<<endl;
    return os;
}
class SvCaoDang: public SinhVien{
private:
    int *diemthitotnghiep;
public:
    SvCaoDang (string const &M, string const &H, string const &D, int T, int DTB, int DTTN)
    :SinhVien(M, H, D, T, DTB) {
        diemthitotnghiep = new int(DTTN);
    }
    SvCaoDang (){
        diemthitotnghiep = nullptr;
    }   
    ~SvCaoDang(){
        delete diemthitotnghiep;
    }
    SvCaoDang (const SvCaoDang &svcd):SinhVien(svcd){
        diemthitotnghiep = new int(*(svcd.diemthitotnghiep));
    }
    SvCaoDang &operator=(const SvCaoDang &svcd){
        if(this != &svcd){
            SinhVien::operator=(svcd);
            delete diemthitotnghiep;
            diemthitotnghiep = new int(*(svcd.diemthitotnghiep));
        }
        return *this;
    }
    void XetTotNghiep(){
        if ( *this->diemthitotnghiep >= 5 and *this->tongsotinchi >=120
                and *this->diemtrungbinh >= 5 ){
                    cout<<"Sinh Vien Du Dieu Kien Tot Nghiep"<<endl;
                }
        else{
            cout<<"Sinh Vien Khong Du Dieu Kien Tot Nghiep"<<endl;
        }
    }
    friend istream& operator >>(istream &is, SvCaoDang &svcd);
    friend ostream& operator <<(ostream &os,const SvCaoDang &svcd);
};
istream& operator >>(istream &is, SvCaoDang &svcd){
    is >> (SinhVien&)svcd;
    int DTTN;
    cout<<"Nhap Diem Thi Tot Nghiep: ";
    is >> DTTN;
    delete svcd.diemthitotnghiep;
    svcd.diemthitotnghiep = new int(DTTN);
    return is;
}
ostream& operator <<(ostream &os, const SvCaoDang &svcd){
    os << (const SinhVien&)svcd;
    cout<<"Diem Thi Tot Nghiep: "; os<<*(svcd.diemthitotnghiep)<<endl;
    return os;
}
int main(){
    SvDaiHoc svdh;
    cin >> svdh;
    cout << svdh;
    svdh.XetTotNghiep();
    SvCaoDang svcd;
    cin >> svcd;
    cout << svcd;
    svcd.XetTotNghiep();
    return 0;
}