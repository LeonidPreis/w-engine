#ifndef MATRIX4_H
#define MATRIX_4H

class Vector4;

#include <iostream>
#include <optional>

class Matrix4 {
public: 
    Matrix4(
        float m11 = 1.0f, float m12 = 0.0f, float m13 = 0.0f, float m14 = 0.0f,
        float m21 = 0.0f, float m22 = 1.0f, float m23 = 0.0f, float m24 = 0.0f,
        float m31 = 0.0f, float m32 = 0.0f, float m33 = 1.0f, float m34 = 0.0f,
        float m41 = 0.0f, float m42 = 0.0f, float m43 = 0.0f, float m44 = 1.0f
    ): 
    m11(m11), m12(m12), m13(m13), m14(m14),
    m21(m21), m22(m22), m23(m23), m24(m24),
    m31(m31), m32(m32), m33(m33), m34(m34),
    m41(m41), m42(m42), m43(m43), m44(m44) {}

public:
    float m11, m12, m13, m14;
    float m21, m22, m23, m24;
    float m31, m32, m33, m34;
    float m41, m42, m43, m44;

public:
    /**
     * @brief Outputs the matrix to the console
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Print
    */
    void Print(const int& precision) const;

public:
    /**
     * @brief Clones the current matrix
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Clone
     * 
     * @return New Matrix.
    */
    Matrix4 Clone() const;

public:
    /**
     * @brief Changes rows and columns of the matrix.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Transpose
     * 
     * @return New transposed matrix.
    */
    Matrix4 Transpose() const;

public:
    /**
     * @brief Computes the determinant of the matrix.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Determinant
     * 
     * @return Scalar value of determinant.
    */
    float Determinant() const;

public:
    /**
     * @brief Scales current matrix by a scalar value.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Scale
     * 
     * @param scale multiplyer.
     * @return New scaled matrix.
    */
    Matrix4 Scale(const float& scale) const;

public:
    /**
     * @brief Multiplies current matrix by column-vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#MultiplyVector
     * 
     * @param v vector to multiply. 
     * @return New column-vector.
    */
    Vector4 MultiplyVector(const Vector4& v) const;

public:
    /**
     * @brief Calculates product of two matrices.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#MultiplyMatrix
     * 
     * @param m matrix to multiply.
     * @return product of f the matrices.
    */
    Matrix4 MultiplyMatrix(const Matrix4& m) const;

public:
    /**
     * @brief Calculates the inverse matrix.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Inverse
     * 
     * @return New inversed matrix or nullopt when determinant is equal zero.
    */
    std::optional<Matrix4> Inverse() const;

public:
    /**
     * @brief Multiplies current matrix by itself degree times.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Degree
     * 
     * @param degree amount of the multiplications.
     * @return New matrix.
    */
    Matrix4 Degree(int degree) const;

public:
    /**
     * Adds second matrix to the current matrix.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Add
     * 
     * @param m second matrix.
     * @return Summ of the matrices.
    */
    Matrix4 Add(const Matrix4& m) const;

public:
    /**
     * @brief Subtracts second matrix from the current matrix.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Matrix4#Subtract
     * 
     * @param m second matrix.
     * @return Differance of the matrices.
    */
    Matrix4 Subtract(const Matrix4& m) const;
};

#endif