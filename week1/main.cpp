#include<bits/stdc++.h>
using namespace std;

class Task1{ 

private: 
	void func (int i, int j = 0 ){
		cout << "So nguyen:" << i << " " << j << endl;
	}
	void func (float i = 0, float j = 0){
		cout << "So thuc:" << i << " " << j <<endl;
	}
public: 
	void displayed(){
		int i = 1, j = 2;
		float f = 1.5, g = 2.5;
		func(); func(i);
		func(f); func(i, j);
		func(f, g);
		cout<<endl;
	};

};

class Task2{
	private:
		int gcd(int a, int b) {
		    int res = min(a, b);
		    while (res > 1) {
		        if (a % res == 0 && b % res == 0)
		            break;
		        res--;
		    }
			return res;
		};
		void reduce(int &a, int &b){
			int tmp; 
			while(gcd(a,b)!=1){
				tmp = gcd (a,b);
				a = a/tmp;
				b = b/tmp;
			}
			
		}
		void tong(int a,int b,int c,int d){
			int tu = a * d + b * c ;
			int mau= d * b ;
			reduce(tu,mau);
			cout<<"tong: "<<tu <<"/" << mau <<endl;
		};
		void hieu(int a,int b, int c, int d){
			int tu = a * d - b * c ;
			cout<<"hieu: ";
			if ( tu < 0 ){
				cout<<'-';
				tu = -tu;
			}
			if ( tu == 0 ){
				cout<< 0 <<endl;
				return ; 
			}
			
			int mau= d * b ;
			reduce(tu,mau);
			cout<< tu << '/' << mau << endl;
			

			
		}
		void tich(int a, int b, int c, int d){
			int tu = a * c ;
			int mau = b * d;
			reduce(tu,mau);
			cout<<"tich: "<< tu <<"/"<<mau<<endl; 	
		}
		void thuong(int a,int b,int c,int d){
			swap(c,d);
			tich(a,b ,c ,d);
		}
		
		bool isLeap(int year) {

		    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
		}
		
		int daysInMonth(int month, int year) {

		    switch(month) {
		        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		            return 31;
		        case 4: case 6: case 9: case 11:
		            return 30;
		        case 2:
		            return isLeap(year) ? 29 : 28;
		        default:
		            return 0; 
		            
		    }
		}
		struct staff_info{
			string id;
			string name;
			string phong_ban;
			int luong_co_ban;
			int thuong;
			int thuc_lanh;

		    staff_info(string i, string n, string p, int lcb, int t)
		        : id(i), name(n), phong_ban(p), luong_co_ban(lcb), thuong(t) {
		        thuc_lanh = lcb + t;
		    }
			
		};
		struct student{
			string mssv;
			string ho_va_ten;
			float diem_toan;
			float diem_van;
			float diem_ly;
			float diem_hoa;
			
		};
	public: 
		void displayed_task1(){
			int a, b; 
			cout<<"nhap phan so tu a - mau b: ";
			cin >> a >> b; 
			if ( a == 0 ) {
				cout<< "ket qua: "<< 0 <<endl ;
				return; 
			}
			if ( b == 0 ){
				cout<<"ket qua: "<< "inf" << endl;
				return;
			}
			reduce(a,b);	
			
			if ( b == 1 ) cout<< a ;
			else cout<< a << '/' << b;
			cout<<endl; 
			
		}
		void displayed_task2(){
			int a, b,c, d ; 
			cout<<"nhap phan so tu a - mau b: ";
			cin >> a >> b ; 
			cout<<"nhap phan so tu c - mau d: ";
			cin >> c >> d ;
			if (b == 0 or d == 0 ){
				cout<< "inf"<< endl;
				return; 
			}
			int tmp  = a * d - b * c ;
			if ( tmp  > 0 ) cout << "phan so lon hon: "<< a << '/'<< b<<endl;
			else if (tmp < 0 ) cout << "phan so lon hon: "<< c << '/'<< d<<endl;
			else cout<<"2 phan so bang nhau"<<endl;
		};
		void displayed_task3(){
			int a, b,c, d ; 
			cout<<"a/b (+) c/d"<<endl;
			cout<<"nhap phan so tu a - mau b: ";
			cin >> a >> b ; 
			cout<<"nhap phan so tu c - mau d: ";
			cin >> c >> d ;
			if (b == 0 or d == 0 ){
				cout<< "inf"<< endl;
				return; 
			}
			if ( a == 0 ){
				if ( c == 0 ){
					cout<<"tong: "<< 0 <<endl;
					cout<<"hieu: "<< 0 <<endl;
					cout<<"tich: "<< 0 <<endl;
					cout<<"thuong: "<<"inf"<<endl;	 				  
					
				}else {
					cout<<"tong: "<< c << '/' << d <<endl;
					cout<<"hieu: -"<< c << '/' << 'd' <<endl;
					cout<<"tich: "<< 0 <<endl;
					cout<<"thuong: "<<0<<endl;	 				  
					
				}
			}
			else if ( a != 0 ){
				if ( c == 0 ){
					cout<<"tong: "<< a << '/' << d <<endl;
					cout<<"hieu: "<< a << '/' << 'd' <<endl;
					cout<<"tich: "<< 0 <<endl;
					cout<<"thuong: "<<"inf"<<endl;
					
				}
			}
			reduce(a,b);
			reduce(c,d);
			tong(a,b,c,d);
			tich(a,b,c,d);
			thuong(a,b,c,d);
			hieu(a,b,c,d);
			
			
			
		};
		
		void displayed_task4(){
			int d, m, y;
		    cout << "Nhap 3 thong so - ngay thang nam (dd-mm-yyyy): ";
		    cin >> d >> m >> y;
		
		    d++;

		    if (d > daysInMonth(m, y)) {
		        d = 1;
		        m++;
		        if (m > 12) {
		            m = 1;
		            y++;
		        }
		    }
		
		    cout << "Ngay ke tiep la: " << d << "-" << m << "-" << y << endl;
		}		
		void displayed_task5(vector<staff_info> company = {}) {
		    if (company.empty()) {
		        company = {
		            {"NV001", "Nguyen Van A", "IT",     8000000, 1500000},
		            {"NV002", "Tran Thi B",   "HR",     7000000, 1000000},
		            {"NV003", "Le Van C",     "Finance",6000000, 2000000},
		            {"NV004", "Pham Thi D",   "IT",     6000000, 1200000},
		            {"NV005", "Hoang Van E",  "HR",     9000000, 500000},
		            {"NV006", "Bui Thi F",    "Finance",6000000,  800000},
		            {"NV007", "Do Van G",     "IT",     5000000, 1300000}
		        };
		    }
			int tong= 0 ;
			for ( auto i : company) tong += i.thuc_lanh;
			cout<<"tong thuc lanh: "<< tong << endl;
			
			int min_luong = min_element(company.begin(), company.end(),
	        [](const staff_info &a, const staff_info &b){
	            return a.luong_co_ban < b.luong_co_ban;
	        })->luong_co_ban;	
	        
	        cout << "Nhan vien co luong co ban thap nhat: "<< endl;
		    for (auto &s : company) {
		        if (s.luong_co_ban == min_luong) {
		            cout << s.id << " - " << s.name << " - " << s.phong_ban 
		                 << " - " << s.luong_co_ban << " - " << s.thuong 
		                 << " - Thuc lanh: " << s.thuc_lanh << endl;
		        }
		    }
		    
		    int count = count_if(company.begin(), company.end(),
        	[](const staff_info &s){ return s.thuong >= 1200000; });
        	
	        cout << "So nhan vien co thuong >= 1.200.000: " << count << endl;
	        
	        sort(company.begin(), company.end(), [](const staff_info &a, const staff_info &b){
		        if (a.phong_ban != b.phong_ban) return a.phong_ban < b.phong_ban;
		        return a.id > b.id; 
		        
		    });
		    cout << "Danh sach nhan vien sau sap xep: "<<endl;
		    for (auto &s : company) {
		        cout << s.id << " - " << s.name << " - " << s.phong_ban 
		             << " - " << s.luong_co_ban << " - " << s.thuong 
		             << " - Thuc lanh: " << s.thuc_lanh << endl;
		    }
	        
	        
		
		}
		void displayed_task6(){
			student S;
	        cout << "Nhap MSSV: ";
	        cin >> S.mssv;
	        cin.ignore(); // b? ký t? xu?ng dòng còn l?i
	
	        cout << "Nhap ho va ten: ";
	        getline(cin, S.ho_va_ten);
	
	        cout << "Nhap diem Toan: ";
	        cin >> S.diem_toan;
	        cout << "Nhap diem Van: ";
	        cin >> S.diem_van;
	        cout << "Nhap diem Ly: ";
	        cin >> S.diem_ly;
	        cout << "Nhap diem Hoa: ";
	        cin >> S.diem_hoa;
			float diem_tb = (S.diem_toan + S.diem_van + S.diem_ly + S.diem_hoa) / 4.0;
        	cout << "Diem trung binh: " << fixed << setprecision(2) << diem_tb << endl;
		}
};



int main(){
	Task1 task1;
	task1.displayed();
	Task2 task2;
	task2.displayed_task1();
	task2.displayed_task2();
	task2.displayed_task3();
	task2.displayed_task4();
	task2.displayed_task5();
	task2.displayed_task6();
  	
	return 0 ;
}
