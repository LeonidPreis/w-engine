#ifndef MATRIX4_H
#define MATRIX_4H

class Vector4;

#include <iostream>

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
    void Print(const int& precision) const;

public:
    Matrix4 Clone() const;

public:
    Matrix4 Transpose() const;

public:
    float Determinant() const;

public:
    Matrix4 Scale(const float& scale) const;

public:
    Vector4 MultiplyVector4(const Vector4& v) const;

public:
    Matrix4 MultiplyMatrix(const Matrix4& m) const;

public:
    Vector4 MultiplyVector(const Vector4& v) const;

public:
    Matrix4 Inverse() const;

public:
    Matrix4 Degree(int degree) const;

public:
    Matrix4 Add(const Matrix4& m) const;

public:
    Matrix4 Subtract(const Matrix4& m) const;
};

#endif