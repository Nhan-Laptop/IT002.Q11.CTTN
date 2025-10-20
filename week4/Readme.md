# WEEK4
## Mô tả

Bộ bài tập OOP C++ gồm 5 bài nhỏ để luyện lớp, đối tượng và thao tác dữ liệu.

- Bài 1: Mảng số nguyên một chiều (cArray)

- Bài 2: Mảng phân số (arrPhanSo)

- Bài 3: (chưa có file)

- Bài 4: Đa thức một biến (DaThuc)

- Bài 5: Quản lý sách thư viện (cBook, cListBook)

## Cấu trúc thư mục
```
.
├─ main.cpp      # Bài 1
├─ main2.cpp     # Bài 2
├─ main4.cpp     # Bài 4
└─  main5.cpp     # Bài 5
```

## Biên dịch và chạy

Sử dụng g++ (C++17):

### Bài 1
'g++ -std=c++17 -O2 -Wall -Wextra -o bt1 main.cpp && ./bt1'

### Bài 2
'g++ -std=c++17 -O2 -Wall -Wextra -o bt2 main2.cpp && ./bt2'

### Bài 4
'g++ -std=c++17 -O2 -Wall -Wextra -o bt4 main4.cpp && ./bt4'

### Bài 5
'g++ -std=c++17 -O2 -Wall -Wextra -o bt5 main5.cpp && ./bt5'


> Trên Windows (MinGW), chạy btX.exe.

## Yêu cầu từng bài (tóm tắt)
### Bài 1 – cArray (mảng số nguyên)

- Nhập mảng n phần tử

- Xuất mảng

- Tạo mảng ngẫu nhiên

- Đếm số lần xuất hiện của một giá trị

- Kiểm tra tăng dần

- Tìm phần tử lẻ nhỏ nhất

- Sắp xếp tăng dần

### Bài 2 – arrPhanSo (mảng phân số)

- Nhập danh sách phân số

- Xuất danh sách

- Tạo ngẫu nhiên

- Tìm phân số lớn nhất (so sánh theo giá trị thực)

- Đếm xem có bao nhiêu phân số tối giản

- Sắp xếp tăng dần theo giá trị

### Bài 4 – DaThuc (đa thức một biến)

- Khởi tạo đa thức bậc n (có thể 0)

- Nhập hệ số

- Tính giá trị P(x) tại x cho trước

- Xuất đa thức (định dạng đẹp)

- Cộng hai đa thức

### Bài 5 – cBook, cListBook (quản lý sách)

- Lớp cBook: Mã sách, Tên sách, Năm xuất bản, Tổng số trang
 
    - Thiết lập / cập nhật thông tin

    - Nhập/Xuất một cuốn sách

- Lớp cListBook: danh sách nhiều sách

    - Nhập danh sách

    - Xuất danh sách

    - Liệt kê sách có số trang > k

    - Sách được xuất bản gần đây nhất

Cách nhập liệu (gợi ý)

- Khi chương trình hỏi số lượng → nhập số nguyên dương.

- Khi nhập chuỗi (mã/ten sách) → nhập cả dòng.

- Với đa thức → nhập bậc trước, sau đó là các hệ số từ bậc cao đến thấp (tuỳ chương trình in hướng dẫn).

