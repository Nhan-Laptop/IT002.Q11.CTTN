#include<bits/stdc++.h>
using namespace std;

class PhanSo{
private:
    int tuso, mauso;
public:
    PhanSo(int tu = 0, int mau = 1): tuso(tu), mauso(mau) {}
    PhanSo (const PhanSo& ps): tuso(ps.tuso), mauso(ps.mauso) {}
    int LayTu() const { return tuso; }
    int LayMau() const { return mauso; }
    void GanTu(int tu) { tuso = tu; }
    void GanMau(int mau) { mauso = mau; }
    void nhap(){
        cout<<"Nhap tu so: ";
        cin>>tuso;
        cout<<"Nhap mau so: ";
        cin>>mauso;
    }
    void xuat() const {
        cout<<tuso<<"/"<<mauso;
    }
    bool operator>(const PhanSo &ps) const{
        return (tuso * ps.mauso) > (ps.tuso * mauso);
    }
    PhanSo operator+(const PhanSo &ps) const{
        PhanSo temp;
        temp.tuso = tuso * ps.mauso + ps.tuso * mauso;
        temp.mauso = mauso * ps.mauso;
        return temp;
    }
    PhanSo operator-(const PhanSo &ps) const{
        PhanSo temp;
        temp.tuso = tuso * ps.mauso - ps.tuso * mauso;
        temp.mauso = mauso * ps.mauso;
        return temp;
    }
};

class dsPhanSo{
private: 
    PhanSo *ds;
    int n;
public:
    dsPhanSo(int size = 0): n(size), ds((size==0)?nullptr:new PhanSo[size]) {}
    ~dsPhanSo(){
        delete[] ds;
    }
    friend istream& operator>>(istream &is, dsPhanSo &dsp);
    friend ostream& operator<<(ostream &os, const dsPhanSo &dsp);

    PhanSo TimMax() const {
        PhanSo max = ds[0];
        for(int i = 1; i < n; i++){
            if(ds[i] > max){
                max = ds[i];
            }
        }
        return max;
    }
    PhanSo Tong() const {
        PhanSo sum;
        for(int i = 0; i < n; i++){
            sum = sum + ds[i];
        }
        return sum;
    }
};
istream& operator>>(istream &is, dsPhanSo &dsp){
    cout<<"Nhap so luong phan so: ";
    is >> dsp.n;
    delete[] dsp.ds;
    dsp.ds = new PhanSo[dsp.n];
    for(int i = 0; i < dsp.n; i++){
        cout<<"Nhap phan so thu "<<i+1<<":"<<endl;
        dsp.ds[i].nhap();
    }
    return is;
}
ostream& operator<<(ostream &os, const dsPhanSo &dsp){
    for(int i = 0; i < dsp.n; i++){
        os<<"Phan so thu "<<i+1<<": ";
        dsp.ds[i].xuat();
        os<<endl;
    }
    return os;
}
int main(){
    dsPhanSo dsp;
    cin >> dsp;
    cout << dsp;
    PhanSo max = dsp.TimMax();
    cout << "Phan so lon nhat: ";
    max.xuat();
    cout << endl;
    PhanSo sum = dsp.Tong();
    cout << "Tong cac phan so: ";
    sum.xuat();
    cout << endl;
}