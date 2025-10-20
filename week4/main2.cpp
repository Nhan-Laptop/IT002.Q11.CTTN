#include<bits/stdc++.h>
using namespace std;


class PhanSo{
private:
    int tu;
    int mau;
public:
    PhanSo(int t = 0, int m = 1): tu(t), mau(m) {}
    ~PhanSo() {}
    friend ostream& operator<<(ostream& os, const PhanSo& ps);
    friend istream& operator>>(istream& is, PhanSo& ps);
    bool operator > (const PhanSo &other) {
        return (tu * other.mau) > (other.tu * mau);
    }
    bool isprime() {
        if (tu <= 1) return false;
        for (int i = 2; i <= sqrt(tu); i++) {
            if (tu % i == 0) return false;
        }
        return true;
    }
};
ostream & operator << (ostream &o, const PhanSo &ps){
return o << ps.tu << "/" << ps.mau;
}
istream & operator >> (istream &i, PhanSo &ps){
    cout << "Nhap tu so: ";
    i >> ps.tu;
    cout << "Nhap mau so: ";
    i >> ps.mau;
    return i;
}


class arrPhanSo{
private: 
    PhanSo *p;
    int n;
public:
    arrPhanSo(int size = 0){
        n = size;
        if (n > 0) {
            p = new PhanSo[n];
        } else {
            p = nullptr;
        }
    }
    ~arrPhanSo(){
        delete[] p;
    }
    void Nhap(){
        cout<<"Nhap so phan tu cua mang phan so: ";
        cin>>n;
        if (p != nullptr) {
            delete[] p;
            p = nullptr;
        }
        p = new PhanSo[n];
        for(int i = 0; i < n; i++){
            cout<<"Nhap phan so thu "<<i+1<<": ";
            cin>>p[i];
        }
    }

    void Xuat(){
        cout<<"Cac phan so trong mang la: \n";
        for(int i = 0; i < n; i++){
            cout<<"Phan so "<<i+1<<": "; 
            cout<<p[i]<<endl;
        }
        cout<<endl;
    }
    void arrPhanSoRandom(){
        if (p != nullptr) {
            delete[] p;
            p = nullptr;
        }
        p = new PhanSo[n];
        srand(time(0));
        for(int i = 0; i < n; i++){
            int tu = rand() ;  
            int mau = rand() ; 
            p[i] = PhanSo(tu, mau);
        }
    }
    void findMaxPhanSo(){
        if (n == 0) {
            cout << "Mang rong!" << endl;
            return;
        }
        PhanSo maxPS = p[0];
        for(int i = 1; i < n; i++){
            // So sanh phan so voi nhau bang cross multiplication
            if (p[i] > maxPS) {
                maxPS = p[i];
            }
        }
        cout << "Phan so lon nhat trong mang la: " << maxPS << endl;
    }
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) return false;
        }
        return true;
    }
    void CountTunguyento(){
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].isprime()) {
                count++;
            }
        }
        cout << "So luong tu so nguyen to trong mang la: " << count << endl;
    }
    void arrPhanSoSort(){
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if( (p[i] > p[j])){
                    swap(p[i], p[j]);
                }
            }
        }
        cout<<"Mang phan so sau khi sap xep la: \n";
        Xuat();
    }

};

int main(){
    arrPhanSo a;
    a.Nhap();
    a.Xuat();
    a.findMaxPhanSo();
    a.CountTunguyento();
    a.arrPhanSoSort();

    return 0;
}