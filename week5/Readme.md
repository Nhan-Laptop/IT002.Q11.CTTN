# Week5 

Ba chương trình dưới đây là các bài luyện tập OOP (Lập trình hướng đối tượng) bằng C++, giúp rèn kỹ năng xây dựng lớp, nạp chồng toán tử và quản lý bộ nhớ.

## 🧮 Bài 1 – Số phức (main1.cpp)

Mục tiêu:
Xây dựng lớp SoPhuc mô tả số phức 𝑧 = 𝑎 + 𝑏𝑖 với các phép toán cơ bản.

### Tính năng chính:

- Lưu trữ phần thực và phần ảo (dùng con trỏ double*).

- Nạp chồng các toán tử:

    - `+`, `-`, `*`, `/`, `==`

- Toán tử chuyển kiểu operator double() (trả về phần thực).

- Toán tử nhập/xuất >>, <<.

- Quản lý bộ nhớ thủ công (constructor, copy constructor, destructor).

Cách chạy:

`g++ -std=c++17 -O2 -o so_phuc main1.cpp && ./so_phuc`

Ví dụ đầu ra:

```go
So phuc a: 1 + 2i
So phuc b: 3 + 4i
a + b = 4 + 6i
a - b = -2 - 2i
a * b = -5 + 10i
a / b = 0.44 + 0.08i
```

## ➗ Bài 2 – Phân số (main2.cpp)

Mục tiêu:
Xây dựng lớp PhanSo và lớp dsPhanSo để quản lý danh sách phân số.

### Tính năng chính:

- Lớp `PhanSo`:

    -   Thuộc tính: tử số, mẫu số.

    -   Phép toán `+`, `-`, `>` để so sánh và tính tổng.

    -   Hàm nhập (`nhap`), xuất (`xuat`).

- Lớp dsPhanSo:

    - Quản lý mảng các phân số.

    - Nạp chồng `>>`, `<<` để nhập/xuất danh sách.

    - Hàm `TimMax()` tìm phân số lớn nhất.

    - Hàm `Tong()` tính tổng các phân số.

Cách chạy:

`g++ -std=c++17 -O2 -o phan_so main2.cpp && ./phan_so`

Ví dụ đầu ra:

```go
Nhap so luong phan so: 2
Nhap phan so thu 1:
Nhap tu so: 1
Nhap mau so: 2
Nhap phan so thu 2:
Nhap tu so: 2
Nhap mau so: 3
Phan so thu 1: 1/2
Phan so thu 2: 2/3
Phan so lon nhat: 2/3
Tong cac phan so: 7/6
```

## 🧩 Bài 3 – Ma trận (main4.cpp)

Mục tiêu:
Xây dựng lớp Matran để thao tác với ma trận 2 chiều.

### Tính năng chính:

- Nhập và xuất ma trận.

- Tạo ma trận ngẫu nhiên (`MatranRandom()`).

- Nạp chồng toán tử:

    - `+` (cộng hai ma trận cùng kích thước)

    - `*` (nhân hai ma trận hợp lệ)

- Quản lý bộ nhớ động cho mảng 2 chiều (int** data).

- Kiểm tra kích thước hợp lệ trước khi tính toán.

Cách chạy:

`g++ -std=c++17 -O2 -o matran main4.cpp && ./matran`

Ví dụ đầu ra:

```go
Nhap ma tran A:
Nhap so hang: 2
Nhap so cot: 2
Nhap phan tu [0][0]: 1
Nhap phan tu [0][1]: 2
Nhap phan tu [1][0]: 3
Nhap phan tu [1][1]: 4
Nhap ma tran B:
Nhap so hang: 2
Nhap so cot: 2
Nhap phan tu [0][0]: 5
Nhap phan tu [0][1]: 6
Nhap phan tu [1][0]: 7
Nhap phan tu [1][1]: 8
Ma tran A + B:
6 8
10 12
Ma tran A * B:
19 22
43 50
```