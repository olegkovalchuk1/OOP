
#include "Matrix.h"
#include <sstream>
#include <cmath>

using namespace std;

void Matrix::allocateMemory()
{
    data = new int* [size];
    for (int i = 0; i < size; i++) {
        data[i] = new int[N];
        for (int j = 0; j < N; j++) {
            data[i][j] = 0;
        }
    }
}

void Matrix::freeMemory()
{
    if (data != nullptr) {
        for (int i = 0; i < size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

Matrix::Matrix()
{
    size = MAX_SIZE;
    count = 1;
    N = 1;
    allocateMemory();
}

Matrix::Matrix(int k, int n)
{
    size = MAX_SIZE;
    count = (k > 0 && k <= size) ? k : 1;
    N = (n > 0) ? n : 1;
    allocateMemory();
}

// Конструктор з літерного рядка (Формат: "Рядки Стовпці Ел1 Ел2...")
Matrix::Matrix(string s)
{
    size = MAX_SIZE;
    stringstream ss(s);
    int k, n;
    ss >> k >> n;
    count = (k > 0 && k <= size) ? k : 1;
    N = (n > 0) ? n : 1;
    allocateMemory();

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < N; j++) {
            if (!ss.eof()) {
                ss >> data[i][j];
            }
        }
    }
}

Matrix::Matrix(const Matrix& m)
{
    size = m.size;
    count = m.count;
    N = m.N;
    allocateMemory();
    for (int i = 0; i < count; i++)
        for (int j = 0; j < N; j++)
            data[i][j] = m.data[i][j];
}

Matrix::~Matrix()
{
    freeMemory();
}

int Matrix::Size() const { return size; }
int Matrix::getCount() const { return count; }
int Matrix::getN() const { return N; }

void Matrix::setElement(int r, int c, int value)
{
    if (r >= 0 && r < count && c >= 0 && c < N)
        data[r][c] = value;
}

int Matrix::getElement(int r, int c) const
{
    if (r >= 0 && r < count && c >= 0 && c < N)
        return data[r][c];
    return 0;
}

double Matrix::calculateNorm() const
{
    double sum = 0;
    for (int i = 0; i < count; i++)
        for (int j = 0; j < N; j++)
            sum += data[i][j] * data[i][j];
    return sqrt(sum);
}

Matrix& Matrix::operator = (const Matrix& m)
{
    if (this == &m) return *this;
    freeMemory();
    size = m.size;
    count = m.count;
    N = m.N;
    allocateMemory();
    for (int i = 0; i < count; i++)
        for (int j = 0; j < N; j++)
            data[i][j] = m.data[i][j];
    return *this;
}

int* Matrix::operator [] (int i)
{
    if (i < 0 || i >= count) throw out_of_range("Index out of range");
    return data[i];
}

Matrix::operator string () const
{
    stringstream ss;
    ss << "Size: " << count << "x" << N << " (Max: " << size << ")" << endl;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < N; j++) {
            ss << data[i][j] << "\t";
        }
        ss << endl;
    }
    return ss.str();
}

Matrix& Matrix::operator ++ ()
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < N; j++)
            data[i][j]++;
    return *this;
}

Matrix& Matrix::operator -- ()
{
    for (int i = 0; i < count; i++)
        for (int j = 0; j < N; j++)
            data[i][j]--;
    return *this;
}

Matrix Matrix::operator ++ (int)
{
    Matrix t(*this);
    ++(*this);
    return t;
}

Matrix Matrix::operator -- (int)
{
    Matrix t(*this);
    --(*this);
    return t;
}

// Дружні функції
Matrix operator - (const Matrix& l, const Matrix& r)
{
    if (l.count != r.count || l.N != r.N) {
        cout << "Matrices of different sizes!" << endl;
        return Matrix(l.count, l.N);
    }
    Matrix res(l.count, l.N);
    for (int i = 0; i < l.count; i++)
        for (int j = 0; j < l.N; j++)
            res.data[i][j] = l.data[i][j] - r.data[i][j];
    return res;
}

bool operator == (Matrix& l, Matrix& r)
{
    if (l.count != r.count || l.N != r.N) return false;
    for (int i = 0; i < l.count; i++)
        for (int j = 0; j < l.N; j++)
            if (l.data[i][j] != r.data[i][j]) return false;
    return true;
}

ostream& operator << (ostream& out, const Matrix& m)
{
    out << string(m);
    return out;
}

istream& operator >> (istream& in, Matrix& m)
{
    cout << "Enter number of rows (count <= " << MAX_SIZE << "): ";
    in >> m.count;
    if (m.count > MAX_SIZE) m.count = MAX_SIZE;

    cout << "Enter number of columns N: ";
    in >> m.N;

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < m.count; i++) {
        for (int j = 0; j < m.N; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            in >> m.data[i][j];
        }
    }
    return in;
}