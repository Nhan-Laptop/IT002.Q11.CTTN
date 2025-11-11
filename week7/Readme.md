# week7
## Bài 1 — Quản lý nhân viên (week7)

Mô tả
- Chương trình mẫu `bai1.cpp` minh họa cấu trúc lớp cho quản lý nhân viên bằng C++.
- Có lớp cơ sở trừu tượng `NhanVien` và ba lớp dẫn xuất:
  - `NhanVienVanPhong` (nhân viên văn phòng)
  - `NhanVienSanXuat` (nhân viên sản xuất)
  - `NhanVienQuanLy` (nhân viên quản lý)
- Mỗi lớp triển khai phương thức `tinhluong()` và `Xuat()` để tính lương và in thông tin.
- Chương trình chính khởi tạo 3 nhân viên mẫu, in lương của từng người, tổng lương công ty, và cho phép tìm nhân viên theo tên.

Yêu cầu
- Trình biên dịch C++ (ví dụ: g++).
- Chuẩn C++11/C++17 trở lên.

Biên dịch

```bash
g++ -std=c++17 -O2 bai1.cpp -o bai1
```

Chạy

```bash
./bai1
```

Khi chạy, chương trình sẽ in lương và thông tin của 3 nhân viên mẫu, rồi hỏi bạn nhập tên nhân viên cần tìm. Ví dụ nhập: `Nguyen Van A` để hiển thị thông tin của nhân viên đó.

Ví dụ đầu ra (cắt bớt, phụ thuộc vào cách định dạng `cout` trong chương trình):

```
Luong cua nhan vien 1: 200006
Ho ten: Nguyen Van A
Ngay sinh: 01/01/1990
Luong co ban: 5
So ngay lam viec: 1
Tro cap: 1

Luong cua nhan vien 2: 400007.5
Ho ten: Tran Thi B
Ngay sinh: 02/02/1992
Luong co ban: 6
So san pham: 2
Tro cap: 1.5

Luong cua nhan vien 3: 16
Ho ten: Le Van C
Ngay sinh: 03/03/1993
Luong co ban: 7
He so chuc vu: 2
Thuong: 2

Tong luong cong ty phai tra: 600029.5

Nhap ten nhan vien can tim: Nguyen Van A
Ho ten: Nguyen Van A
Ngay sinh: 01/01/1990
Luong co ban: 5
So ngay lam viec: 1
Tro cap: 1
```

Ghi chú
- Các giá trị trong `bai1.cpp` là ví dụ; bạn có thể thay đổi dữ liệu đầu vào hoặc mở rộng chương trình để đọc từ tệp/nhập từ bàn phím theo danh sách.
- Nếu muốn thay đổi định dạng (ví dụ: thêm đơn vị tiền tệ, làm tròn), chỉnh trong các phương thức `tinhluong()` và khi in ra `cout`.

Tác giả / License
- README này do người làm bài tạo. Bạn có thể dùng nó để đẩy repo lên Git.
- License: không chỉ định (thêm nếu cần).
