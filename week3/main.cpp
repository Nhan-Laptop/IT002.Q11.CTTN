#include<bits/stdc++.h>
using namespace std;

class Circle{
    private: 
        float P,S;

    public:
        Circle(float radius){
            P = 2*3.14*radius;
            S = 3.14*radius*radius;
        }

        float getPerimeter(){
            return P;
        }

        float getArea(){
            return S;
        }
};
class Distance{
    private: 
        float x1, y1, x2, y2;

    public:
        Distance(float x1, float y1, float x2, float y2){
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        float getDistance(){
            return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        }
};

class cArray{
    private: 
        vector<int> arr;
        int size;
        int x; 
    public:
        cArray(int size, long int minVal = -25062006,long int maxVal = 25062006,int x = NULL){
            this->size = size;
            arr.resize(size);
            for(int i=0; i<size; i++){
                arr[i] = rand()%(maxVal - minVal + 1) + minVal;
            }
            if (x != NULL){
                this->x = x;
            }
        }
        void display(){
            cout<<"Mảng: ";
            for(int i=0; i<size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        int getMin(){
            return *min_element(arr.begin(), arr.end());
        }
        void frequency(){
            if (x == NULL){
                cout<<"Chưa nhập phần tử x để kiểm tra tần số xuất hiện trong mảng.\n";
                return;
            }
            map<int, int> freqMap;
            for(int i=0; i<size; i++){
                freqMap[arr[i]]++;
            }
            cout<<"Tần số xuất hiện của "<<x<<" trong mảng:\n"<<freqMap[x]<<endl;
        }
        bool check_dec(){
            for(int i=0; i<size-1; i++){
                if (arr[i] < arr[i+1]){
                    return false;
                }
            }
            return true;
        }
        void sort_asc(){
            sort(arr.begin(), arr.end());
        }
};
class cHocSinh{
    private: 
        string MSSV1,MSSV2;
        string ten1, ten2;
        int gioitinh1, gioitinh2;
        int tuoi1, tuoi2;
        float diemtrungbinh1, diemtrungbinh2;
        public:
        cHocSinh(string MSSV1, string ten1, int gioitinh1, int tuoi1, float diemtrungbinh1,
                 string MSSV2, string ten2, int gioitinh2, int tuoi2, float diemtrungbinh2){
            this->MSSV1 = MSSV1;
            this->ten1 = ten1;
            this->gioitinh1 = gioitinh1;
            this->tuoi1 = tuoi1;
            this->diemtrungbinh1 = diemtrungbinh1;

            this->MSSV2 = MSSV2;
            this->ten2 = ten2;
            this->gioitinh2 = gioitinh2;
            this->tuoi2 = tuoi2;
            this->diemtrungbinh2 = diemtrungbinh2;
        }
        void Displayed(){
            if (diemtrungbinh1 > diemtrungbinh2){
                cout<<"Học sinh có điểm trung bình cao hơn là:\n";
                cout<<"MSSV: "<<MSSV1<<endl;
                cout<<"Họ và tên: "<<ten1<<endl;
                cout<<"Giới tính: "<<(gioitinh1 == 1 ? "Nam" : "Nữ")<<endl;
                cout<<"Tuổi: "<<tuoi1<<endl;
                cout<<"Điểm trung bình: "<<diemtrungbinh1<<endl;
            } else if (diemtrungbinh1 < diemtrungbinh2){
                cout<<"Học sinh có điểm trung bình cao hơn là:\n";
                cout<<"MSSV: "<<MSSV2<<endl;
                cout<<"Họ và tên: "<<ten2<<endl;
                cout<<"Giới tính: "<<(gioitinh2 == 1 ? "Nam" : "Nữ")<<endl;
                cout<<"Tuổi: "<<tuoi2<<endl;
                cout<<"Điểm trung bình: "<<diemtrungbinh2<<endl;
            } else{
                cout<<"Hai học sinh có điểm trung bình bằng nhau.\n";
            }

            if (tuoi1 > tuoi2){
                cout<<"Học sinh lớn tuổi hơn là:\n";
                cout<<"MSSV: "<<MSSV1<<endl;
                cout<<"Họ và tên: "<<ten1<<endl;
                cout<<"Giới tính: "<<(gioitinh1 == 1 ? "Nam" : "Nữ")<<endl;
                cout<<"Tuổi: "<<tuoi1<<endl;
                cout<<"Điểm trung bình: "<<diemtrungbinh1<<endl;
            } else if (tuoi1 < tuoi2){
                cout<<"Học sinh lớn tuổi hơn là:\n";
                cout<<"MSSV: "<<MSSV2<<endl;
                cout<<"Họ và tên: "<<ten2<<endl;
                cout<<"Giới tính: "<<(gioitinh2 == 1 ? "Nam" : "Nữ")<<endl;
                cout<<"Tuổi: "<<tuoi2<<endl;
                cout<<"Điểm trung bình: "<<diemtrungbinh2<<endl;
            } else{
                cout<<"Hai học sinh bằng tuổi nhau.\n";
            }   
        }
   
    
};
class Sophuc{
    private:
        float a, b; 
        
    public:
        
        Sophuc(int  a = 0, int b = 0){
            cout<<"Nhập phần thực và phần ảo của số phức:\n";
            cin>>a>>b;
            this->a = a;
            this->b = b;
        }
        Sophuc operator+(const Sophuc& other){
            return Sophuc(a + other.a, b + other.b);
        }
        Sophuc operator-(const Sophuc& other){
            return Sophuc(a - other.a, b - other.b);
        }
        Sophuc operator*(const Sophuc& other){
            return Sophuc(a * other.a - b * other.b, a * other.b + b * other.a);
        }
        void display(){
            if (b >= 0){
                cout<<a<<" + "<<b<<"i"<<endl;
            } else{
                cout<<a<<" - "<<-b<<"i"<<endl;
            }
        }
        void Thaydoi(float a, float b){
            this->a = a;
            this->b = b;
        }
        pair<float, float> getSoPhuc(){
            return make_pair(a, b);
        }
        void cong(Sophuc& other){
            a += other.a;
            b += other.b;
            cout<<"Sau khi cộng, số phức là: ";
            display();
        }

};
int main(){
    float radius;
    cout<<"Bán kính đường tròn: ";
    cin>>radius;

    Circle circle(radius);
    cout<<"Chu Kì của đường tròn: "<<circle.getPerimeter()<<endl;
    cout<<"Diện tích của đường tròn: "<<circle.getArea()<<endl;

    float x1, y1, x2, y2;
    cout<<"Toạ độ điểm 1 (x1, y1): ";
    cin>>x1>>y1;
    cout<<"Toạ độ điểm 2 (x2, y2): ";
    cin>>x2>>y2;
    Distance distance(x1, y1, x2, y2);
    cout<<"Khoảng cách giữa 2 điểm: "<<distance.getDistance()<<endl;

    int size, x;
    cout<<"Kích thước mảng: ";
    cin>>size;
    cout<<"Phần tử x để kiểm tra tần số xuất hiện trong mảng: ";
    cin>>x;

    cArray arr(size);
    arr.display();
    cout<<"Giá trị nhỏ nhất trong mảng: "<<arr.getMin()<<endl;
    arr.frequency();
    if (arr.check_dec()){
        cout<<"Mảng là mảng giảm.\n";
    }else{
        cout<<"Mảng không phải là mảng giảm.\n";
    }
    arr.sort_asc();
    cout<<"Mảng sau khi sắp xếp tăng dần:\n";
    arr.display();

    string MSSV1, ten1;
    int gioitinh1, tuoi1;
    float diemtrungbinh1;
    cout<<"Nhập thông tin học sinh 1:\n";
    cout<<"MSSV: ";
    cin>>MSSV1;
    cout<<"Họ và tên: ";
    cin.ignore();
    getline(cin, ten1);
    cout<<"Giới tính (1: Nam, 0: Nữ): ";
    cin>>gioitinh1;
    cout<<"Tuổi: ";
    cin>>tuoi1;
    cout<<"Điểm trung bình: ";
    cin>>diemtrungbinh1;
    
    string MSSV2, ten2;
    int gioitinh2, tuoi2;
    float diemtrungbinh2;
    cout<<"Nhập thông tin học sinh 2:\n";
    cout<<"MSSV: ";
    cin>>MSSV2;
    cout<<"Họ và tên: ";
    cin.ignore();
    getline(cin, ten2);
    cout<<"Giới tính (1: Nam, 0: Nữ): ";
    cin>>gioitinh2;
    cout<<"Tuổi: ";
    cin>>tuoi2;
    cout<<"Điểm trung bình: ";
    cin>>diemtrungbinh2;
    cHocSinh hs(MSSV1, ten1, gioitinh1, tuoi1, diemtrungbinh1,
                MSSV2, ten2, gioitinh2, tuoi2, diemtrungbinh2);
    hs.Displayed();

    Sophuc sp1, sp2;
    cout<<"Nhập số phức thứ nhất:\n";
    Sophuc spA;
    cout<<"Nhập số phức thứ hai:\n";
    Sophuc spB;
    Sophuc spC = spA + spB;
    cout<<"Kết quả phép cộng:\n";
    spC.display();
    Sophuc spD = spA - spB;
    cout<<"Kết quả phép trừ:\n";
    spD.display();
    Sophuc spE = spA * spB;
    cout<<"Kết quả phép nhân:\n";
    spE.display();
    


    return 0;
}