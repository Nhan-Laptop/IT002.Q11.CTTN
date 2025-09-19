from fractions import Fraction

class Task1: 
    """
    Viết chương trình cho phép nhập một dãy phân số. Cài
    đặt hàm tính tổng các phân số và tìm phân số lớn nhất
    
    """
    def __init__(self):
        print("Nhập dãy phân số (cách nhau bởi dấu cách, ví dụ: 1/2 3/4 5/6): ")
        self.fractions = input().split()
        self.fractions = [self.parse_fraction(frac) for frac in self.fractions]
    def sum_fractions(self):
        from fractions import Fraction
        total = sum(Fraction(num, den) for num, den in self.fractions)
        return total
    def max_fraction(self):
        from fractions import Fraction
        max_frac = max(Fraction(num, den) for num, den in self.fractions)
        return max_frac
    def parse_fraction(self, frac_str):
        num, den = map(int, frac_str.split('/'))
        return (num, den)
    def run(self):
        total = self.sum_fractions()
        max_frac = self.max_fraction()
        print(f"Tổng các phân số: {total}")
        print(f"Phân số lớn nhất: {max_frac}")
class Task2:
    """
    Viết chương trình nhập vào 2 ma trận. Tính tổng, hiệu,
    tích hai ma trận đã nhập và in kết quả ra màn hình
    """
    def __init__(self):
        self.matrix1 = self.input_matrix("Nhập ma trận 1:")
        self.matrix2 = self.input_matrix("Nhập ma trận 2:")
    def input_matrix(self, prompt):
        print(prompt)
        rows = int(input("Nhập số hàng: "))
        cols = int(input("Nhập số cột: "))
        matrix = []
        for i in range(rows):
            row = list(map(int, input(f"Nhập hàng {i + 1} (các phần tử cách nhau bởi dấu cách): ").split()))
            matrix.append(row)
        return matrix
    def add_matrices(self):
        return [[self.matrix1[i][j] + self.matrix2[i][j] for j in range(len(self.matrix1[0]))] for i in range(len(self.matrix1))]
    def subtract_matrices(self):
        return [[self.matrix1[i][j] - self.matrix2[i][j] for j in range(len(self.matrix1[0]))] for i in range(len(self.matrix1))]
    def multiply_matrices(self):
        result = [[0 for _ in range(len(self.matrix2[0]))] for _ in range(len(self.matrix1))]
        for i in range(len(self.matrix1)):
            for j in range(len(self.matrix2[0])):
                for k in range(len(self.matrix2)):
                    result[i][j] += self.matrix1[i][k] * self.matrix2[k][j]
        return result
    def print_matrix(self, matrix, title):
        print(title)
        for row in matrix:
            print(" ".join(map(str, row)))
    def run(self):
        sum_matrix = self.add_matrices()
        diff_matrix = self.subtract_matrices()
        prod_matrix = self.multiply_matrices()
        self.print_matrix(sum_matrix, "Tổng hai ma trận:")
        self.print_matrix(diff_matrix, "Hiệu hai ma trận:")
        self.print_matrix(prod_matrix, "Tích hai ma trận:")
class Task3: 
    """
    Viết chương trình cho phép người dùng:
    - Nhập vào thông tin của một học sinh gồm: mã học sinh
        (chuỗi), họ tên, giới tính, điểm toán, điểm lý, điểm hóa.
    - Tính điểm trung bình và xuất thông tin chi tiết của học
        sinh ra màn hình.
    """
    def __init__(self):
        
        self.student = self.input_student_info()
        self.average_score = self.calculate_average()
    def input_student_info(self):
        print("Nhập thông tin học sinh:")
        student_id = input("Mã học sinh: ")
        name = input("Họ tên: ")
        gender = input("Giới tính: ")
        math_score = float(input("Điểm toán: "))
        physics_score = float(input("Điểm lý: "))
        chemistry_score = float(input("Điểm hóa: "))
    def calculate_average(self):
        return (self.student['math_score'] + self.student['physics_score'] + self.student['chemistry_score']) / 3
    def display_student_info(self):
        print("Thông tin học sinh:")
        print(f"Mã học sinh: {self.student['student_id']}")
        print(f"Họ tên: {self.student['name']}")
        print(f"Giới tính: {self.student['gender']}")
        print(f"Điểm toán: {self.student['math_score']}")
        print(f"Điểm lý: {self.student['physics_score']}")
        print(f"Điểm hóa: {self.student['chemistry_score']}")
        print(f"Điểm trung bình: {self.average_score}")
    def run(self):
        self.display_student_info()

if __name__ == "__main__":
    task = Task1()
    task.run()
    task2 = Task2()
    task2.run()
    task3 = Task3()
    task3.run()