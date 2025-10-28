#include<bits/stdc++.h>
using namespace std;

class NhanVien{
protected:
    string *maNV, *hoTen, *tuoi, *Sodienthoai, *email;
public:
    int32_t *luongcoban;
    NhanVien():maNV(nullptr), hoTen(nullptr), tuoi(nullptr),
         Sodienthoai(nullptr), email(nullptr), luongcoban(nullptr){};
    NhanVien(string &ma, string &ten, string &age,
         string &sdt, string &mail, int32_t &luong){
        maNV = new string(ma);
        hoTen = new string(ten);
        tuoi = new string(age);
        Sodienthoai = new string(sdt);
        email = new string(mail);
        luongcoban = new int32_t(luong);
    }
    NhanVien(const NhanVien &nv){
        maNV = new string(*(nv.maNV));
        hoTen = new string(*(nv.hoTen));
        tuoi = new string(*(nv.tuoi));
        Sodienthoai = new string(*(nv.Sodienthoai));
        email = new string(*(nv.email));
        luongcoban = new int32_t(*(nv.luongcoban));
    }
    ~NhanVien(){
        delete maNV;
        delete hoTen;
        delete tuoi;
        delete Sodienthoai;
        delete email;
        delete luongcoban;
    }
    NhanVien &operator=(const NhanVien &nv){
        if(this != &nv){
            delete maNV;
            delete hoTen;
            delete tuoi;
            delete Sodienthoai;
            delete email;
            delete luongcoban;

            maNV = new string(*(nv.maNV));
            hoTen = new string(*(nv.hoTen));
            tuoi = new string(*(nv.tuoi));
            Sodienthoai = new string(*(nv.Sodienthoai));
            email = new string(*(nv.email));
            luongcoban = new int32_t(*(nv.luongcoban));
        }
        return *this;
    }

    friend istream& operator>>(istream &is, NhanVien &nv){
        is.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Nhap thong tin nhan vien:\n";
        string ma, ten, age, sdt, mail;
        int32_t luong;
        cout<<"Ma NV: ";
        getline(is, ma);
        cout<<"Ho ten: ";
        getline(is, ten);
        cout<<"Tuoi: ";
        getline(is, age);
        cout<<"So dien thoai: ";
        getline(is, sdt);
        cout<<"Email: ";
        getline(is, mail);
        cout<<"Luong co ban: ";
        is >> luong;

        is.ignore(numeric_limits<streamsize>::max(), '\n');
        nv.maNV = new string(ma);
        nv.hoTen = new string(ten);
        nv.tuoi = new string(age);
        nv.Sodienthoai = new string(sdt);
        nv.email = new string(mail);
        nv.luongcoban = new int32_t(luong);
        return is;
    }
    friend ostream& operator<<(ostream &os, const NhanVien &nv){
        os << "Ma NV: " << *(nv.maNV) << "\n";
        os << "Ho ten: " << *(nv.hoTen) << "\n";
        os << "Tuoi: " << *(nv.tuoi) << "\n";
        os << "So dien thoai: " << *(nv.Sodienthoai) << "\n";
        os << "Email: " << *(nv.email) << "\n";
        os << "Luong co ban: " << *(nv.luongcoban) << "\n";
        return os;
    }
};

class LapTrinhVien: public NhanVien{
private:
    int32_t *soGioOverTime;
public:
    int32_t *Luong;
    LapTrinhVien():NhanVien(), soGioOverTime(nullptr),Luong(nullptr){}
    LapTrinhVien(string &ma, string &ten, string &age,
         string &sdt, string &mail, int32_t &luong, int32_t &soGio):
         NhanVien(ma, ten, age, sdt, mail, luong){
        soGioOverTime = new int32_t(soGio);
        Luong = new int32_t(luong + (*soGioOverTime)*200000);
    }
    LapTrinhVien(const LapTrinhVien &ltv):NhanVien(ltv){
        soGioOverTime = new int32_t(*(ltv.soGioOverTime));
        Luong = new int32_t(*(ltv.Luong));
    }
    ~LapTrinhVien(){
        delete soGioOverTime;
        delete Luong;
    }
    LapTrinhVien &operator=(const LapTrinhVien &ltv){
        if(this != &ltv){
            delete soGioOverTime;
            delete Luong;

            NhanVien::operator=(ltv);
            soGioOverTime = new int32_t(*(ltv.soGioOverTime));
            Luong = new int32_t(*(ltv.Luong));
        }
        return *this;
    }

    friend istream& operator>>(istream &is, LapTrinhVien &ltv){
        cout<<" Nhap thong tin lap trinh vien:\n";
        is >> static_cast<NhanVien&>(ltv);

        cout<<"So gio over time: ";
        int32_t soGio;
        is >> soGio;
        is.ignore(numeric_limits<streamsize>::max(), '\n');

        delete ltv.soGioOverTime;
        ltv.soGioOverTime = new int32_t(soGio);

        delete ltv.Luong;
        ltv.Luong = new int32_t(*(ltv.luongcoban) + (*ltv.soGioOverTime) * 200000);

        return is;
    }
    friend ostream& operator<<(ostream &os, const LapTrinhVien &ltv){
        os << static_cast<const NhanVien&>(ltv);
        os << "So gio over time: " << *(ltv.soGioOverTime) << "\n";
        os << "Luong: " << *(ltv.Luong) << "\n";
        return os;
    }

};

class KiemChungVien: public NhanVien{
private:
    int32_t *soLoiphatHienDuoc;
public:
    int32_t *Luong;
    KiemChungVien():NhanVien(), soLoiphatHienDuoc(nullptr), Luong(nullptr){}
    KiemChungVien(string &ma, string &ten, string &age,
         string &sdt, string &mail, int32_t &luong, int32_t &soLoi):
         NhanVien(ma, ten, age, sdt, mail, luong){
        soLoiphatHienDuoc = new int32_t(soLoi);
        Luong = new int32_t(luong + (*soLoiphatHienDuoc)*50000);
    }
    KiemChungVien(const KiemChungVien &kcv):NhanVien(kcv){
        soLoiphatHienDuoc = new int32_t(*(kcv.soLoiphatHienDuoc));  
        Luong = new int32_t(*(kcv.Luong));
    }
    ~KiemChungVien(){
        delete soLoiphatHienDuoc;
        delete Luong;
    }
    KiemChungVien &operator=(const KiemChungVien &kcv){
        if(this != &kcv){
            delete soLoiphatHienDuoc;
            delete Luong;
            NhanVien::operator=(kcv);
            soLoiphatHienDuoc = new int32_t(*(kcv.soLoiphatHienDuoc));  
            Luong = new int32_t(*(kcv.Luong));
        }
        return *this;   
    }
    friend istream& operator>>(istream &is, KiemChungVien &kcv){
        cout<<"Nhap thong tin kiem chung vien:\n";
        is >> static_cast<NhanVien&>(kcv);

        cout<<"So loi phat hien duoc: ";
        int32_t soLoi;
        is >> soLoi;
        is.ignore(numeric_limits<streamsize>::max(), '\n');

        delete kcv.soLoiphatHienDuoc;
        kcv.soLoiphatHienDuoc = new int32_t(soLoi);

        delete kcv.Luong;
        kcv.Luong = new int32_t(*(kcv.luongcoban) + (*kcv.soLoiphatHienDuoc) * 50000);

        return is;
    }
    friend ostream& operator<<(ostream &os, const KiemChungVien &kcv){
        os << static_cast<const NhanVien&>(kcv);
        os << "So loi phat hien duoc: " << *(kcv.soLoiphatHienDuoc) << "\n";
        os << "Luong: " << *(kcv.Luong) << "\n";
        return os;
    }   

};


int main(){
    vector<LapTrinhVien> dsLTV;
    vector<KiemChungVien> dsKCV;
    
    int n;
    cout<<"So luong lap trinh vien: ";
    cin>>n;
    for(int i=0; i<n; i++){
        LapTrinhVien ltv;
        cin >> ltv;
        dsLTV.push_back(ltv);
    }
    cout<<"So luong kiem chung vien: ";
    cin>>n;
    for(int i=0; i<n; i++){
        KiemChungVien kcv;
        cin >> kcv;
        dsKCV.push_back(kcv);
    }
    cout<<"---Danh sach lap trinh vien---\n";
    for(const auto &ltv : dsLTV){
        cout << ltv;
        cout << "-----------------------\n";
    }
    cout<<"---Danh sach kiem chung vien---\n";
    for(const auto &kcv : dsKCV){
        cout << kcv;
        cout << "-----------------------\n";
    }
    int32_t tongLuongLTV = 0;
    for(const auto &ltv : dsLTV){
        tongLuongLTV += *(ltv.Luong);   
    }
    int32_t tongLuongKCV = 0;
    for(const auto &kcv : dsKCV){
        tongLuongKCV += *(kcv.Luong);   
    }
    double luongTrungBinh = double(tongLuongLTV + tongLuongKCV) / (dsLTV.size() + dsKCV.size());
    cout << "Luong trung binh cua cong ty: " << luongTrungBinh << "\n";
    n = 0 ;
    for(const auto &ltv : dsLTV){
        if(*(ltv.Luong) < luongTrungBinh){
            n++;
        }
    }
    if (n){
        for(const auto &ltv : dsLTV){
            if(*(ltv.Luong) < luongTrungBinh){
                cout << ltv;
                cout << "-----------------------\n";
            }
        }
    } else {
        cout << "Khong co lap trinh vien nao co luong duoi trung binh.\n";
    }
    n= 0;
    for(const auto &kcv : dsKCV){
        if(*(kcv.Luong) < luongTrungBinh){  
            n++;
        }
    }
    if (n){
        cout << "---Danh sach kiem chung vien co luong duoi trung binh---\n";
        for(const auto &kcv : dsKCV){
            if(*(kcv.Luong) < luongTrungBinh){  
                cout << kcv;
                cout << "-----------------------\n";
            }
        }
        return 0;
    } else {
        cout << "Khong co kiem chung vien nao co luong duoi trung binh.\n";
    }
    return 0;
}