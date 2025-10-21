#include<bits/stdc++.h>
using namespace std;

class Matran{
private:
    int rows, cols;
    int **data;
public:
    Matran(int r = 0, int c = 0): rows(r), cols(c){
        data = new int*[rows];
        for(int i = 0; i < rows; i++){
            data[i] = new int[cols];
        }
    }
    ~Matran(){
        for(int i = 0; i < rows; i++){
            delete[] data[i];
        }
        delete[] data;
    }
    void MatranRandom(){
        srand(time(0));
        rows = rand() % 5 + 1;
        cols = rand() % 5 + 1;
        data = new int*[rows];
        for(int i = 0; i < rows; i++){
            data[i] = new int[cols];
            for(int j = 0; j < cols; j++){
                data[i][j] = rand() % 10;
            }
        }

    }

    Matran operator+(const Matran &other) const {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Matrices must have the same dimensions for addition.");
        }
        Matran result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    Matran operator*(const Matran &other) const {
        if (cols != other.rows) {
            throw invalid_argument("Incompatible matrix dimensions for multiplication.");
        }
        Matran result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    friend ostream& operator<<(ostream &os, const Matran &m);
    friend istream& operator>>(istream &is, Matran &m);

};

ostream& operator<<(ostream &os, const Matran &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream &is, Matran &m) {
    cout << "Nhap so hang: ";
    is >> m.rows;
    cout << "Nhap so cot: ";
    is >> m.cols;
    for (int i = 0; i < m.rows; i++) {
        delete[] m.data[i];
    }
    delete[] m.data;
    m.data = new int*[m.rows];
    for (int i = 0; i < m.rows; i++) {
        m.data[i] = new int[m.cols];
        for (int j = 0; j < m.cols; j++) {
            cout<<"Nhap phan tu ["<<i<<"]["<<j<<"]: ";
            is >> m.data[i][j];
        }
    }
    return is;
}

int main(){
    Matran A, B;
    cout<<"Nhap ma tran A:"<<endl;
    cin >> A;
    cout<<"Nhap ma tran B:"<<endl;
    cin >> B;
    try {
        Matran C = A + B;
        cout << "Ma tran A + B:\n" << C << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    try {
        Matran D = A * B;
        cout << "Ma tran A * B:\n" << D << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }
    return 0;
}