#include<bits/stdc++.h>
using namespace std;

class SoPhuc{
private:
    double *thuc, *ao;
public:
    SoPhuc(double t = 0, double a = 0): thuc(new double(t)), ao(new double(a)) {}
    SoPhuc(const SoPhuc& sp): thuc(new double(*sp.thuc)), ao(new double(*sp.ao)) {}
    SoPhuc & operator+(const SoPhuc &sp){
        *thuc += *sp.thuc;
        *ao += *sp.ao;
        return *this;
    }
    SoPhuc & operator*(const SoPhuc &sp){
        double t = *thuc * *sp.thuc - *ao * *sp.ao;
        double a = *thuc * *sp.ao + *ao * *sp.thuc;
        *thuc = t;
        *ao = a;
        return *this;
    }
    SoPhuc &operator-(const SoPhuc &sp){
        *thuc -= *sp.thuc;
        *ao -= *sp.ao;
        return *this;
    }   
    SoPhuc &operator-(){
        *thuc = -(*thuc);
        *ao = -(*ao);
        return *this;
    }   
    SoPhuc &operator/(const SoPhuc &sp){
        double denom = (*sp.thuc) * (*sp.thuc) + (*sp.ao) * (*sp.ao);
        double t = (*thuc * *sp.thuc + *ao * *sp.ao) / denom;
        double a = (*ao * *sp.thuc - *thuc * *sp.ao) / denom;
        *thuc = t;
        *ao = a;
        return *this;
    }
    bool operator==(const SoPhuc &sp) const{
        return (*thuc == *sp.thuc) && (*ao == *sp.ao);
    }
    ~SoPhuc() {
        delete thuc;
        delete ao;
    }
    explicit operator double() const { return *thuc; }

    friend istream& operator>>(istream &is, SoPhuc &sp);
    friend ostream& operator<<(ostream &os, const SoPhuc &sp);
};
istream& operator>>(istream &is, SoPhuc &sp){
    double t, a;
    cout<<"Nhap phan thuc: ";
    is >> t;
    cout<<"Nhap phan ao: ";
    is >> a;
    *(sp.thuc) = t;
    *(sp.ao) = a;
    return is;
}

ostream& operator<<(ostream &os, const SoPhuc &sp){
    os << *(sp.thuc);
    if (*(sp.ao) >= 0) os << " + " << *(sp.ao) << "i";
    else os << " - " << -(*(sp.ao)) << "i";
    return os;
}

int main(){
    SoPhuc a(1,2), b(3,4);
    cout << "So phuc a: " << a << endl;
    cout << "So phuc b: " << b << endl;
    cout<< "a + b = " << (a + b) << endl;
    cout<< "a - b = " << (a - b) << endl;
    cout<< "a * b = " << (a * b) << endl;
    cout<< "a / b = " << (a / b) << endl;
}