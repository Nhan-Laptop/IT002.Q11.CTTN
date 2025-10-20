#include<bits/stdc++.h>
using namespace std;

class DaThuc{
    int *bac;
    int *heso;
public:
    DaThuc(int b=0){
        bac = new int(b);
        heso = new int[b+1];
    }
    ~DaThuc(){
        delete[] heso;
        delete bac;
    }
    
    DaThuc operator+(DaThuc &b){
        DaThuc temp(*bac);
        for(int i=0;i<=*bac;i++){
            int heSoA = (i<=*bac)?heso[i]:0;
            int heSoB = (i<=*(b.bac))?b.heso[i]:0;
            temp.heso[i] = heSoA + heSoB;
        }
        return temp;
    }
    DaThuc operator-(DaThuc &b){
        DaThuc temp(*bac);
        for(int i=0;i<=*bac;i++){
            int heSoA = (i<=*bac)?heso[i]:0;
            int heSoB = (i<=*(b.bac))?b.heso[i]:0;
            temp.heso[i] = heSoA - heSoB;
        }
        return temp;
    }
    friend ostream &operator <<(ostream &os, const DaThuc &dt);
    friend istream &operator >>(istream &is, const DaThuc &dt);
};
ostream &operator <<(ostream &os,const DaThuc &dt){
    for(int i = *dt.bac;i>=0;i--){
        if (dt.heso[i]!=0){
            if (i!=0){
                os<<dt.heso[i]<<"x^"<<i<<" + ";
            }else{
                os<<dt.heso[i];
            }
        }
    }
    return os;
}
istream &operator >>(istream &is,const DaThuc &dt){
    for(int i=0;i<=*dt.bac;i++){
        cout<<"He so bac "<<i<<": ";
        is>>dt.heso[i];
    }
    return is;
}


int main(){
    cout<< "Nhap bac da thuc : "<<endl;
    int n;
    cin>>n;
    DaThuc a(n), b(n);
    cout<<"Nhap da thuc a: "<<endl;
    cin >> a;
    cout<<"Nhap da thuc b: "<<endl;
    cin >> b;
    DaThuc c = a + b;
    cout<<"Tong da thuc c = a + b: ";
    cout << c;
    cout<<endl;
    DaThuc d = a - b;
    cout<<"Hieu da thuc d = a - b: ";
    cout << d;
    cout<<endl;
    return 0;
}
