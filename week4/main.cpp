#include<bits/stdc++.h>
using namespace std;

class cArray{
private:
    int *p;
    int n;
public:
    cArray(int size = 0){
        n = size;
        if (n > 0) {
            p = new int[n];
        } else {
            p = nullptr;
        }
    }

    ~cArray(){
        delete[] p;
    }
    void Nhap(){
        cout<<"Nhap so phan tu cua mang: ";
        cin>>n;
        if (p != nullptr) {
            delete[] p;
        }
        p = new int[n];
        for(int i = 0; i < n; i++){
            cout<<"Nhap phan tu thu "<<i+1<<": ";
            cin>>p[i];
        }
    }
    void Xuat(){
        cout<<"Cac phan tu trong mang la: ";
        for(int i = 0; i < n; i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    void cArrayRandom(){
        if (p != nullptr) {
            delete[] p;
        }
        p = new int[n];
        srand(time(0));
        for(int i = 0; i < n; i++){
            p[i] = rand();  
        }
    }
    void cArrayFrequency(){
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            freq[p[i]]++;
        }
        cout<<"Tan suat xuat hien cua cac phan tu trong mang:\n";
        for(const auto& pair : freq){
            cout<<"Phan tu "<<pair.first<<" xuat hien "<<pair.second<<" lan\n";
        }
    }
    void checkIncreasing(){
        bool isIncreasing = true;
        for(int i = 1; i < n; i++){
            if(p[i] < p[i-1]){
                isIncreasing = false;
                break;
            }
        }
        if(isIncreasing){
            cout<<"Mang la tang dan."<<endl;
        } else {
            cout<<"Mang khong phai la tang dan."<<endl;
        }
    }
    void findMinOdd(){
        int minOdd = INT_MAX;
        for(int i = 0; i < n; i++){
            if(p[i] % 2 != 0 && p[i] < minOdd){
                minOdd = p[i];
            }
        }
        if(minOdd != INT_MAX){
            cout<<"Phan tu le nho nhat trong mang la: "<<minOdd<<endl;
        } else {
            cout<<"Khong co phan tu le trong mang."<<endl;
        }
    }
    void SortArray(){
        sort(p, p + n);
    }

};

int main(){
    cArray arr;
    arr.Nhap();
    arr.Xuat();
    arr.cArrayFrequency();
    arr.checkIncreasing();
    arr.findMinOdd();
    arr.SortArray();
    arr.Xuat();
    arr.cArrayRandom();
    arr.Xuat();
    return 0;

}