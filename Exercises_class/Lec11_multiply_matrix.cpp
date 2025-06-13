#include <iostream>
#include <stdexcept>  // For exception handling

template <typename T>
class Matrix {
private:
    int m_rows;      // Number of rows
    int m_cols;      // Number of columns
    T** m_matrix;    // 2D array to store matrix data

    // Helper function to initialize matrix memory
    void initializeMatrix() {
        m_matrix = new T*[m_rows];
        for (int i = 0; i < m_rows; ++i) {
            m_matrix[i] = new T[m_cols]();
        }
    }

public:
    // Constructor: Creates a matrix with specified dimensions
    Matrix(int rows, int cols) : m_rows(rows), m_cols(cols) {
        if (rows <= 0 || cols <= 0) {
            throw std::invalid_argument("Matrix dimensions must be positive");
        }
        initializeMatrix();
    }

    // Copy constructor: Creates a deep copy of another matrix
    Matrix(const Matrix& other) : m_rows(other.m_rows), m_cols(other.m_cols) {
        initializeMatrix();
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                m_matrix[i][j] = other.m_matrix[i][j];
            }
        }
    }

    // Destructor: Releases allocated memory
    ~Matrix() {
        for (int i = 0; i < m_rows; ++i) {
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }

    // Access element at specified position (with bounds checking)
    T& at(int row, int col) {
        if (row < 0 || row >= m_rows || col < 0 || col >= m_cols) {
            throw std::out_of_range("Matrix index out of bounds");
        }
        return m_matrix[row][col];
    }

    // Matrix multiplication operator overload
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        if (lhs.m_cols != rhs.m_rows) {
            throw std::invalid_argument(
                "Matrix dimensions incompatible for multiplication");
        }

        Matrix result(lhs.m_rows, rhs.m_cols);

        // Standard matrix multiplication algorithm
        for (int i = 0; i < lhs.m_rows; ++i) {
            for (int j = 0; j < rhs.m_cols; ++j) {
                T sum = 0;
                for (int k = 0; k < lhs.m_cols; ++k) {
                    sum += lhs.m_matrix[i][k] * rhs.m_matrix[k][j];
                }
                result.m_matrix[i][j] = sum;
            }
        }
        return result;
    }

    // Display matrix contents in a formatted way
    void display(const std::string& name = "Matrix") const {
        std::cout << "\n" << name << " (" << m_rows << "x" << m_cols << "):\n";
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                std::cout << m_matrix[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }

    // Function to fill matrix with user input
    void fillFromUser() {
        std::cout << "Enter matrix elements (" << m_rows << "x" << m_cols << "):\n";
        for (int i = 0; i < m_rows; ++i) {
            for (int j = 0; j < m_cols; ++j) {
                std::cout << "Element [" << i << "][" << j << "]: ";
                std::cin >> m_matrix[i][j];
            }
        }
    }
};

int main() {
    try {
        // Get matrix dimensions from user
        int rows1, cols1, rows2, cols2;
        std::cout << "Enter dimensions for first matrix (rows columns): ";
        std::cin >> rows1 >> cols1;
        
        std::cout << "Enter dimensions for second matrix (rows columns): ";
        std::cin >> rows2 >> cols2;

        // Create matrices
        Matrix<int> mat1(rows1, cols1);
        Matrix<int> mat2(rows2, cols2);

        // Get matrix elements from user
        mat1.fillFromUser();
        mat2.fillFromUser();

        // Display input matrices
        mat1.display("First Matrix");
        mat2.display("Second Matrix");

        // Perform matrix multiplication
        Matrix<int> result = mat1 * mat2;
        result.display("Resultant Matrix");

    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << "\n";
        return 1;
    }

    return 0;
}