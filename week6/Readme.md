# Bài tập tuần 6 — Quản lý Sinh viên và Nhân viên (C++)

Phiên bản: hoàn chỉnh mô tả và hướng dẫn sử dụng cho các script `bai1.cpp` và `bai2.cpp`.

## Mục tiêu
- `bai1.cpp`: Xây dựng lớp quản lý thông tin sinh viên cho hai hệ: Đại học và Cao đẳng; nhập một sinh viên hệ đại học và một sinh viên hệ cao đẳng, xuất thông tin và kiểm tra điều kiện tốt nghiệp theo quy tắc đề bài.
- `bai2.cpp`: Quản lý danh sách nhân viên của một công ty phần mềm gồm hai loại: Lập trình viên và Kiểm chứng viên; tính lương theo công thức khác nhau, in danh sách nhân viên và liệt kê những nhân viên có lương thấp hơn mức trung bình công ty.

## Nội dung file
- `bai1.cpp` — cài đặt các lớp: `SinhVien` (base), `SvDaiHoc`, `SvCaoDang`. Hỗ trợ nhập/xuất (operator>> / operator<<), sao chép an toàn (copy ctor, operator=), và hàm `XetTotNghiep()` để kiểm tra điều kiện tốt nghiệp.
- `bai2.cpp` — cài đặt các lớp: `NhanVien` (base), `LapTrinhVien`, `KiemChungVien`. Mỗi lớp có các trường thông tin cơ bản và phương thức nhập/xuất; lương được tính theo công thức:
  - Lương lập trình viên = lương cơ bản + số giờ overtime * 200000
  - Lương kiểm chứng viên = lương cơ bản + số lỗi * 50000
  Chương trình cho phép nhập danh sách, in danh sách và liệt kê nhân viên có lương < lương trung bình công ty.

## Yêu cầu môi trường
- Compiler C++ hỗ trợ C++11/14/17 (khuyến nghị `-std=c++17`).
- Hệ điều hành: Linux (thử nghiệm với g++).

## Hướng dẫn biên dịch
Mở terminal trong thư mục chứa các file (`/home/nhanlaptop/blog/IT002.Q11.CTTN/week6`) và chạy:

```bash
g++ -std=c++17 -Wall -Wextra -o bai1 bai1.cpp
g++ -std=c++17 -Wall -Wextra -o bai2 bai2.cpp
```

## Hướng dẫn chạy và ví dụ

### 1) Chạy `bai1` (sinh viên)

```bash
./bai1
```

Chương trình sẽ yêu cầu nhập lần lượt thông tin cho một sinh viên hệ đại học và một sinh viên hệ cao đẳng. Dòng lệnh tương tác điển hình:

- Nhập MSSV
- Nhập Họ và tên
- Nhập Địa chỉ
- Nhập Tổng số tín chỉ (số nguyên)
- Nhập Điểm trung bình (số nguyên trong code hiện tại)
- (với SV đại học) Nhập Tên luận văn
- (với SV đại học) Nhập Điểm luận văn
- (với SV cao đẳng) Nhập Điểm thi tốt nghiệp

Sau đó chương trình in ra thông tin 2 sinh viên và báo có đủ điều kiện tốt nghiệp hay không theo qui tắc:
- SV đại học: tổng tín chỉ >= 170, điểm trung bình >= 5, điểm luận văn >= 5
- SV cao đẳng: tổng tín chỉ >= 120, điểm trung bình >= 5, điểm thi tốt nghiệp >= 5

### 2) Chạy `bai2` (nhân viên)

```bash
./bai2
```

Chương trình sẽ:
1. Yêu cầu nhập số lượng lập trình viên, rồi nhập từng lập trình viên (Mã NV, Họ tên, Tuổi, SĐT, Email, Lương cơ bản, Số giờ overtime).
2. Yêu cầu nhập số lượng kiểm chứng viên, rồi nhập từng kiểm chứng viên (Mã NV, Họ tên, Tuổi, SĐT, Email, Lương cơ bản, Số lỗi phát hiện).
3. In danh sách lập trình viên và kiểm chứng viên.
4. Tính lương trung bình (tổng lương tất cả nhân viên / tổng số nhân viên) và in ra.
5. Liệt kê (riêng theo từng loại) các nhân viên có lương thấp hơn lương trung bình.

Ví dụ nhập rút gọn (tương tác):
- Số lập trình viên: 2
- Thông tin LTV1: ma NV01, ten A, luong cb 10000000, soGio 10 -> Luong = 10000000 + 10*200000
- Thông tin LTV2: ma NV02, ten B, luong cb 8000000, soGio 5
- Số kiểm chứng viên: 1
- Thông tin KCV1: ma NV10, ten C, luong cb 9000000, soLoi 20

Chương trình in lương trung bình và danh sách nhân viên có lương < lương trung bình.

## Định dạng nhập/xuất và lưu ý
- Cả hai chương trình hiện là interactive (nhập từ bàn phím, in ra màn hình).
- Vì có sự kết hợp giữa `getline()` và `operator>>`, một số vị trí trong code dùng `ignore()` để loại bỏ ký tự newline còn lại — khi thêm tính năng hoặc chỉnh sửa, hãy cẩn thận với việc này.

## Thiết kế nhanh (tóm tắt lớp)
- `bai1.cpp`:
  - `SinhVien`: quản lý MSSV, họ tên, địa chỉ, tổng số tín chỉ, điểm trung bình (hiện dùng con trỏ và `new/delete`).
  - `SvDaiHoc`: thêm `tenluanvan`, `diemluanvan`, có `XetTotNghiep()` riêng.
  - `SvCaoDang`: thêm `diemthitotnghiep`, có `XetTotNghiep()` riêng.

- `bai2.cpp`:
  - `NhanVien`: mã, họ tên, tuổi, sđt, email, lương cơ bản.
  - `LapTrinhVien`: thêm số giờ overtime, tính `Luong = luongcoban + soGio*200000`.
  - `KiemChungVien`: thêm số lỗi phát hiện, tính `Luong = luongcoban + soLoi*50000`.

Hiện tại code sử dụng nhiều con trỏ thô (`new/delete`). Đây là một cách làm nhưng không an toàn bằng sử dụng kiểu giá trị (`std::string`, `int`) hoặc smart pointers.

## Vấn đề đã biết & đề xuất cải tiến
- Rủi ro: quản lý bộ nhớ thủ công (cần đảm bảo copy ctor, operator=, destructor luôn nhất quán để tránh rò rỉ hoặc double-delete).
- Khuyến nghị cải tiến:
  1. Thay thế các con trỏ chuỗi bằng thành viên `std::string` (loại bỏ `new/delete`).
  2. Lưu lương và các số là kiểu giá trị (`int`/`double`) thay vì con trỏ.
  3. Thêm kiểm tra input (validate số âm, chuỗi rỗng,...).
  4. Tách chức năng nhập/xuất ra helper để dễ unit-test.
  5. Thêm chức năng lưu/đọc file (CSV) cho dữ liệu nhân viên/sinh viên.

## Thực thi kiểm thử nhanh
- Để kiểm thử nhanh, biên dịch rồi chạy theo các bước ở phần "Hướng dẫn chạy" và nhập 1–3 bản ghi để kiểm tra các tính toán (tổng lương, lương trung bình, điều kiện tốt nghiệp).


---

