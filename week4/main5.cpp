#include<bits/stdc++.h>
using namespace std;

class cBook{
    string *masach, *tensach;
    int *namxuatban, *tongsotrang;
public:
    cBook(string m= "2452000", string t= "C++ Programming", int n= 2020, int s= 300):
        masach(new string(m)), tensach(new string(t)), namxuatban(new int(n)), tongsotrang(new int(s)){}
    ~cBook(){
        delete masach;
        delete tensach;
        delete namxuatban;
        delete tongsotrang;
    }
    void UpdateInfo(string m, string t, int n, int s){
        *(this->masach) = m;
        *(this->tensach) = t;
        *(this->namxuatban) = n;
        *(this->tongsotrang) = s;

    }
    bool operator>(const cBook &book){
        return *(this->namxuatban) > *(book.namxuatban);
    }
    friend istream &operator>>(istream &is, cBook &book);
    friend ostream &operator<<(ostream &os, cBook &book);
};  
istream &operator>>(istream &is, cBook &book){
    cout << "Nhap ma sach: ";    is >> *(book.masach);   ;
    cout << "Nhap ten sach: ";   is >> *(book.tensach);
    cout << "Nhap nam xuat ban: ";   is >> *(book.namxuatban);
    cout << "Nhap tong so trang: ";  is >> *(book.tongsotrang);
    return is;
}
ostream &operator<<(ostream &os, cBook &book){
    os << "Ma sach: " << *(book.masach) << endl;
    os << "Ten sach: " << *(book.tensach) << endl;
    os << "Nam xuat ban: " << *(book.namxuatban) << endl;
    os << "Tong so trang: " << *(book.tongsotrang) << endl;
    return os;
}


class cListBook{
    cBook *dsBook;
    int *soluong;
public:
    cListBook():dsBook(nullptr), soluong(new int(0)){}
    cListBook(const cListBook &list,const int n){
        dsBook = new cBook(*(list.dsBook));
        soluong = new int(n);
    }
    cListBook(const int n):
        dsBook(new cBook[n]), soluong(new int(n)){}
    ~cListBook(){
        delete[] dsBook;
        delete soluong;
    }
    void cListBooknamxuatbanmoinhat(){
        cBook result = this->dsBook[0];
        for(int i=1; i<*(this->soluong); i++){
            if(this->dsBook[i] > result){
                result = this->dsBook[i];
            }
        }
        cout << "Sach co nam xuat ban moi nhat la:\n";
        cout << result;
    }
    friend istream &operator>>(istream &is, cListBook &list);
    friend ostream &operator<<(ostream &os, cListBook &list);
};
istream &operator>>(istream &is, cListBook &list){
    int n;
    cout << "Nhap so luong sach: ";    is >> n;
    delete[] list.dsBook;
    delete list.soluong;
    list.dsBook = new cBook[n];
    list.soluong = new int(n);

    for(int i=0; i<n; i++){
        cout << "Nhap thong tin sach thu " << i+1 << ":\n";
        is >> list.dsBook[i];
    }
    return is;
}
ostream &operator<<(ostream &os, cListBook &list){
    os << "Danh sach sach:\n";
    for(int i=0; i<*(list.soluong); i++){
        os << "Thong tin sach thu " << i+1 << ":\n";
        os << list.dsBook[i];
    }
    return os;
}

int main(){
    cListBook list;
    cin >> list;
    cout << list;
    list.cListBooknamxuatbanmoinhat();
    return 0;
}