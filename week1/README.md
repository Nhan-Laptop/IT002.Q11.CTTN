# 📘 Hướng dẫn thực hiện các Task – Lập trình Hướng đối tượng

Chương trình đã được cài đặt trong 2 lớp chính: Task1 và Task2, với các hàm displayed() và displayed_taskX() tương ứng từng bài tập.

## ⚙️ Cách chạy chương trình

Compile chương trình:

```py
g++ main.cpp -o run

```

Chạy chương trình:
```py
./run
```
## 📝 Task 1 – Nạp chồng hàm func
Hàm cài đặt
```py
void func (int i, int j = 0){
    cout << "So nguyen: " << i << " " << j << endl;
}
void func (float i = 0, float j = 0){
    cout << "So thuc: " << i << " " << j << endl;
}
```
Khi gọi:
```py
int i = 1, j = 2;
float f = 1.5, g = 2.5;
func();       // gọi hàm float mặc định
func(i);      // gọi hàm int
func(f);      // gọi hàm float
func(i, j);   // gọi hàm int
func(f, g);   // gọi hàm float
```

Kết quả xuất ra:
```py
So thuc: 0 0
So nguyen: 1 0
So thuc: 1.5 0
So nguyen: 1 2
So thuc: 1.5 2.5
```
## 📝 Task 2 – Làm việc với phân số
### a. Rút gọn phân số

Hàm: `displayed_task1()`

Nhập: tử số a, mẫu số b

Xuất: phân số tối giản hoặc 0 / inf nếu đặc biệt.

Ví dụ:

Nhap phan so tu a - mau b: 6 9
ket qua: 2/3

### b. So sánh 2 phân số

Hàm: displayed_task2()

Nhập: a/b, c/d

Xuất: phân số lớn hơn hoặc thông báo bằng nhau.

Ví dụ:

Nhap phan so tu a - mau b: 1 2
Nhap phan so tu c - mau d: 3 4
phan so lon hon: 3/4

### c. Tổng, hiệu, tích, thương 2 phân số

Hàm: displayed_task3()

Nhập: a/b, c/d

Xuất: kết quả 4 phép toán trên phân số.

Ví dụ:
```py
Nhap phan so tu a - mau b: 1 2
Nhap phan so tu c - mau d: 1 3
tong: 5/6
tich: 1/6
thuong: 3/2
hieu: 1/6
```

### d. Ngày kế tiếp

Hàm: displayed_task4()

Nhập: ngày-tháng-năm (dd mm yyyy)

Xuất: ngày hôm sau, có xét năm nhuận.

Ví dụ:

Nhap 3 thong so - ngay thang nam (dd-mm-yyyy): 28 2 2024
Ngay ke tiep la: 29-2-2024

## 📝 Task 3 – Quản lý nhân viên

Hàm: displayed_task5()

Dữ liệu: được tạo mặc định gồm nhiều nhân viên (ID, tên, phòng ban, lương, thưởng).

Xuất ra:

Tổng thực lãnh của toàn bộ nhân viên

Danh sách nhân viên có lương cơ bản thấp nhất

Số nhân viên có thưởng ≥ 1.200.000

Danh sách nhân viên sắp xếp theo:

Phòng ban tăng dần

Nếu trùng phòng ban → sắp xếp ID giảm dần

Ví dụ:

```py
tong thuc lanh: 48500000
Nhan vien co luong co ban thap nhat:
NV007 - Do Van G - IT - 5000000 - 1300000 - Thuc lanh: 6300000
So nhan vien co thuong >= 1.200.000: 4
Danh sach nhan vien sau sap xep:
NV003 - Le Van C - Finance - 6000000 - 2000000 - Thuc lanh: 8000000
NV006 - Bui Thi F - Finance - 6000000 - 800000 - Thuc lanh: 6800000
```

## 📝 Task 4 – Quản lý sinh viên

Hàm: displayed_task6()

Nhập: MSSV, họ tên, điểm Toán, Văn, Lý, Hóa

Xuất: điểm trung bình (TB), xếp loại.

Ví dụ:
```py
Nhap MSSV: 22520001
Nhap ho va ten: Nguyen Van A
Nhap diem Toan: 7.5
Nhap diem Van: 8
Nhap diem Ly: 6.5
Nhap diem Hoa: 7

Diem trung binh: 7.25
Xep loai: Kha
```
## ✅ Tổng kết

Task1.displayed() → minh họa nạp chồng hàm

Task2.displayed_task1() → rút gọn phân số

Task2.displayed_task2() → so sánh phân số

Task2.displayed_task3() → tính toán 2 phân số

Task2.displayed_task4() → tìm ngày kế tiếp

Task2.displayed_task5() → quản lý nhân viên

Task2.displayed_task6() → quản lý sinh viên