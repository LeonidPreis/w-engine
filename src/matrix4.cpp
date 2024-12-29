
#include "../include/matrix4.h"
#include "../include/vector4.h"
#include <iomanip>    
#include <iostream>

void Matrix4::Print(const int& precision = 6) const {
    std::cout << std::fixed << std::setprecision(precision) << "Matrix4[[ m11: " << m11 << " m12: " << m12 << " m13: " << m13 << " m14: " << m14 << " ]," << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "        [ m21: " << m21 << " m22: " << m22 << " m23: " << m23 << " m24: " << m24 << " ]," << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "        [ m31: " << m31 << " m32: " << m32 << " m33: " << m33 << " m34: " << m34 << " ]," << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "        [ m41: " << m41 << " m42: " << m42 << " m43: " << m43 << " m44: " << m44 << " ]]\n" << std::endl;
}

Matrix4  Matrix4::Clone() const {
    return Matrix4(
        m11, m12, m13, m14,
        m21, m22, m23, m24,
        m31, m32, m33, m34,
        m41, m42, m43, m44
    );
}

Matrix4 Matrix4::Transpose() const {
    return Matrix4(
        m11, m21, m31, m41,
        m12, m22, m32, m42,
        m13, m23, m33, m43,
        m14, m24, m34, m44
    );
}

float Matrix4::Determinant() const {
    const float m3344_3443 = m33 * m44 - m34 * m43;
    const float m3244_3442 = m32 * m44 - m34 * m42;
    const float m3243_3342 = m32 * m43 - m33 * m42;
    const float m3144_3441 = m31 * m44 - m34 * m41;
    const float m3143_3341 = m31 * m43 - m33 * m41;
    const float m3142_3241 = m31 * m42 - m32 * m41;

    return  m11 * (m22 * m3344_3443 - m23 * m3244_3442 + m24 * m3243_3342)-
            m12 * (m21 * m3344_3443 - m23 * m3144_3441 + m24 * m3143_3341)+
            m13 * (m21 * m3244_3442 - m22 * m3144_3441 + m24 * m3142_3241)-
            m14 * (m21 * m3243_3342 - m22 * m3143_3341 + m23 * m3142_3241);
}

Matrix4 Matrix4::MultiplyMatrix(const Matrix4& m) const {
    return Matrix4(
        m11 * m.m11 + m12 * m.m21 + m13 * m.m31 + m14 * m.m41,
        m11 * m.m12 + m12 * m.m22 + m13 * m.m32 + m14 * m.m42,
        m11 * m.m13 + m12 * m.m23 + m13 * m.m33 + m14 * m.m43,
        m11 * m.m14 + m12 * m.m24 + m13 * m.m34 + m14 * m.m44,
        m21 * m.m11 + m22 * m.m21 + m23 * m.m31 + m24 * m.m41,
        m21 * m.m12 + m22 * m.m22 + m23 * m.m32 + m24 * m.m42,
        m21 * m.m13 + m22 * m.m23 + m23 * m.m33 + m24 * m.m43,
        m21 * m.m14 + m22 * m.m24 + m23 * m.m34 + m24 * m.m44,
        m31 * m.m11 + m32 * m.m21 + m33 * m.m31 + m34 * m.m41,
        m31 * m.m12 + m32 * m.m22 + m33 * m.m32 + m34 * m.m42,
        m31 * m.m13 + m32 * m.m23 + m33 * m.m33 + m34 * m.m43,
        m31 * m.m14 + m32 * m.m24 + m33 * m.m34 + m34 * m.m44,
        m41 * m.m11 + m42 * m.m21 + m43 * m.m31 + m44 * m.m41,
        m41 * m.m12 + m42 * m.m22 + m43 * m.m32 + m44 * m.m42,
        m41 * m.m13 + m42 * m.m23 + m43 * m.m33 + m44 * m.m43,
        m41 * m.m14 + m42 * m.m24 + m43 * m.m34 + m44 * m.m44
    );
}

Vector4 Matrix4::MultiplyVector(const Vector4& v) const {
    return Vector4(
        m11 * v.x + m12 * v.y + m13 * v.z + m14 * v.w,
        m21 * v.x + m22 * v.y + m23 * v.z + m24 * v.w,
        m31 * v.x + m32 * v.y + m33 * v.z + m34 * v.w,
        m41 * v.x + m42 * v.y + m43 * v.z + m44 * v.w
    );
}

Matrix4 Matrix4::Scale(const float& scale) const {
    return Matrix4(
        m11 * scale, m12 * scale, m13 * scale, m14 * scale,
        m21 * scale, m22 * scale, m23 * scale, m24 * scale,
        m31 * scale, m32 * scale, m33 * scale, m34 * scale,
        m41 * scale, m42 * scale, m43 * scale, m44 * scale
    );
}

std::optional<Matrix4> Matrix4::Inverse() const {
    const float determinant = this->Determinant();

    if (determinant == 0) {
        return std::nullopt;
    }

    const float m3344_3443 = m33 * m44 - m34 * m43;
    const float m3244_3442 = m32 * m44 - m34 * m42;
    const float m3243_3342 = m32 * m43 - m33 * m42;
    const float m2344_2443 = m23 * m44 - m24 * m43;
    const float m2244_2442 = m22 * m44 - m24 * m42;
    const float m2243_2342 = m22 * m43 - m23 * m42;
    const float m2334_2443 = m23 * m34 - m24 * m43;
    const float m2234_2432 = m22 * m34 - m24 * m32;
    const float m2233_2332 = m22 * m33 - m23 * m32;
    const float m3144_3441 = m31 * m44 - m34 * m41;
    const float m3143_3341 = m31 * m43 - m33 * m41;
    const float m2144_2441 = m21 * m44 - m24 * m41;
    const float m2143_2341 = m21 * m43 - m23 * m41;
    const float m2334_2433 = m23 * m34 - m24 * m33;
    const float m2134_2431 = m21 * m34 - m24 * m31;
    const float m2133_2331 = m21 * m33 - m23 * m31;
    const float m3142_3241 = m31 * m42 - m32 * m41;
    const float m2142_2241 = m21 * m42 - m22 * m41;
    const float m2132_2231 = m21 * m32 - m22 * m31;
    const float d = 1.0 / determinant;

    return Matrix4(
        d * (m22 * m3344_3443 - m23 * m3244_3442 + m24 * m3243_3342),
       -d * (m12 * m3344_3443 - m13 * m3244_3442 + m14 * m3243_3342),
        d * (m12 * m2344_2443 - m13 * m2244_2442 + m14 * m2243_2342),
       -d * (m12 * m2334_2433 - m13 * m2234_2432 + m14 * m2233_2332),

       -d * (m21 * m3344_3443 - m23 * m3144_3441 + m24 * m3143_3341),
        d * (m11 * m3344_3443 - m13 * m3144_3441 + m14 * m3143_3341),
       -d * (m11 * m2344_2443 - m13 * m2144_2441 + m14 * m2143_2341),
        d * (m11 * m2334_2433 - m13 * m2134_2431 + m14 * m2133_2331),

        d * (m21 * m3244_3442 - m22 * m3144_3441 + m24 * m3142_3241),
       -d * (m11 * m3244_3442 - m12 * m3144_3441 + m14 * m3142_3241),
        d * (m11 * m2244_2442 - m12 * m2144_2441 + m14 * m2142_2241),
       -d * (m11 * m2234_2432 - m12 * m2134_2431 + m14 * m2132_2231),

       -d * (m21 * m3243_3342 - m22 * m3143_3341 + m23 * m3142_3241),
        d * (m11 * m3243_3342 - m12 * m3143_3341 + m13 * m3142_3241),
       -d * (m11 * m2243_2342 - m12 * m2143_2341 + m13 * m2142_2241),
        d * (m11 * m2233_2332 - m12 * m2133_2331 + m13 * m2132_2231)
    );
}

Matrix4 Matrix4::Degree(int degree) const {
    if (degree <= 0) {
        std::cout << "Degree must be greater than 0." << std::endl;
        return Matrix4();
    }

    if (degree == 1) {
        return *this;
    }

    Matrix4 result = this->MultiplyMatrix(*this);
    for (int i = 3; i <= degree; i++) {
        result = this->MultiplyMatrix(result);
    }
    return result;
}

Matrix4 Matrix4::Add(const Matrix4& m) const {
    return Matrix4(
        m11 + m.m11, m12 + m.m12, m13 + m.m13, m14 + m.m14,
        m21 + m.m21, m22 + m.m22, m23 + m.m23, m24 + m.m24,
        m31 + m.m31, m32 + m.m32, m33 + m.m33, m34 + m.m34,
        m41 + m.m41, m42 + m.m42, m43 + m.m43, m44 + m.m44
    );
}

Matrix4 Matrix4::Subtract(const Matrix4& m) const {
    return Matrix4(
        m11 - m.m11, m12 - m.m12, m13 - m.m13, m14 - m.m14,
        m21 - m.m21, m22 - m.m22, m23 - m.m23, m24 - m.m24,
        m31 - m.m31, m32 - m.m32, m33 - m.m33, m34 - m.m34,
        m41 - m.m41, m42 - m.m42, m43 - m.m43, m44 - m.m44
    );
}