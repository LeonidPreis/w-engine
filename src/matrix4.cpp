
#include "../include/matrix4.h"
#include "../include/vector4.h"
#include <iomanip>    
#include <iostream>

void Matrix4::Print(const int& precision = 6) const {
    std::cout << std::fixed << std::setprecision(precision) << "Matrix4[[ m11: " << m11 << " m12: " << m12 << " m13: " << m13 << " m14: " << m14 << " ],\n" << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "        [ m21: " << m21 << " m22: " << m22 << " m23: " << m23 << " m24: " << m24 << " ],\n" << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "        [ m31: " << m31 << " m32: " << m32 << " m33: " << m33 << " m34: " << m34 << " ],\n" << std::endl;
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
        m11, m12, m13, m14,
        m21, m22, m23, m24,
        m31, m32, m33, m34,
        m41, m42, m43, m44
    );
}

float Matrix4::Determinant() const {
    const float m3142 = m31 * m42, m3143 = m31 * m43, m3144 = m31 * m44;
    const float m3241 = m32 * m41, m3243 = m32 * m43, m3244 = m32 * m44;
    const float m3341 = m33 * m41, m3342 = m33 * m42, m3344 = m33 * m44;
    const float m3441 = m34 * m41, m3442 = m34 * m42, m3443 = m34 * m43;

    return  m11 * (m22 * (m3344 - m3443) - m23 * (m3244 - m3442) + m24 * (m3243 - m3342))-
            m12 * (m21 * (m3344 - m3443) - m23 * (m3144 - m3441) + m24 * (m3143 - m3341))+
            m13 * (m21 * (m3244 - m3442) - m22 * (m3144 - m3441) + m24 * (m3142 - m3241))-
            m14 * (m21 * (m3243 - m3342) - m22 * (m3143 - m3341) + m23 * (m3142 - m3241));
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

Matrix4 Matrix4::Inverse() const {
    const float determinant = this->Determinant();

    if (determinant != 0) {
        const float d = 1.0 / determinant;
        const float m2132 = m21 * m32, m2133 = m21 * m33, m2134 = m21 * m34, m2142 = m21 * m42, m2143 = m21 * m43, m2144 = m21 * m44;
        const float m2231 = m22 * m31, m2233 = m22 * m33, m2234 = m22 * m34, m2241 = m22 * m41, m2243 = m22 * m43, m2244 = m22 * m44;
        const float m2331 = m23 * m31, m2332 = m23 * m32, m2334 = m23 * m34, m2341 = m23 * m41, m2342 = m23 * m42, m2344 = m23 * m44;
        const float m2431 = m24 * m31, m2432 = m24 * m32, m2433 = m24 * m33, m2441 = m24 * m41, m2442 = m24 * m42, m2443 = m24 * m43;
        const float m3142 = m31 * m42, m3143 = m31 * m43, m3144 = m31 * m44, m3241 = m32 * m41, m3243 = m32 * m43, m3244 = m32 * m44;
        const float m3341 = m33 * m41, m3342 = m33 * m42, m3344 = m33 * m44, m3441 = m34 * m41, m3442 = m34 * m42, m3443 = m34 * m43;

        return Matrix4(
            d * (m44 * (m11 * (m2233 - m2332) - m12 * (m2133 - m2331) + m13 * (m2132 - m2231))),
            d * (m34 * (m11 * (m2243 - m2342) - m12 * (m2143 - m2341) + m13 * (m2142 - m2241))),
            d * (m24 * (m11 * (m3243 - m3342) - m12 * (m3143 - m3341) + m13 * (m3142 - m3241))),
            d * (m14 * (m21 * (m3243 - m3342) - m22 * (m3143 - m3341) + m23 * (m3142 - m3241))),
            d * (m43 * (m11 * (m2234 - m2432) - m12 * (m2134 - m2431) + m14 * (m2132 - m2231))),
            d * (m33 * (m11 * (m2244 - m2442) - m12 * (m2144 - m2441) + m14 * (m2142 - m2241))),
            d * (m23 * (m11 * (m3244 - m3442) - m12 * (m3144 - m3441) + m14 * (m3142 - m3241))),
            d * (m13 * (m21 * (m3244 - m3442) - m22 * (m3144 - m3441) + m24 * (m3142 - m3241))),
            d * (m42 * (m11 * (m2334 - m2433) - m13 * (m2134 - m2431) + m14 * (m2133 - m2331))),
            d * (m32 * (m11 * (m2344 - m2443) - m13 * (m2144 - m2441) + m14 * (m2143 - m2341))),
            d * (m22 * (m11 * (m3344 - m3443) - m13 * (m3144 - m3441) + m14 * (m3143 - m3341))),
            d * (m12 * (m21 * (m3344 - m3443) - m23 * (m3144 - m3441) + m24 * (m3143 - m3341))),
            d * (m41 * (m12 * (m2334 - m2433) - m13 * (m2234 - m2432) + m14 * (m2233 - m2332))),
            d * (m31 * (m12 * (m2344 - m2443) - m13 * (m2244 - m2442) + m14 * (m2243 - m2342))),
            d * (m21 * (m12 * (m3344 - m3443) - m13 * (m3244 - m3442) + m14 * (m3243 - m3342))),
            d * (m11 * (m22 * (m3344 - m3443) - m23 * (m3244 - m3442) + m24 * (m3243 - m3342)))
        );
    } else {
        return Matrix4();
    }
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