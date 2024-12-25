#include "../include/vector4.h"
#include "../include/matrix4.h"

void Vector4::Print() {
    std::cout << "Vector4(x: " << x << " y: " << y << " z: " << z << " w: " << w << ")" << std::endl;
}

Vector4 Vector4::Clone() const {
    return Vector4(x, y, z, w);
}

bool Vector4::Equals(const Vector4& v) const {
    return x == v.x && y == v.y && z == v.z && w == v.w;
}

Vector4& Vector4::Negate() {
    x = -x;
    y = -y;
    z = -z;
    w = -w;
    return *this;
}

float Vector4::Length() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

Vector4 Vector4::Normalize() const {
    float length = this->Length();
    if (length == 0) {
        return Vector4(0.0f, 0.0f, 0.0f, 0.0f);
    } else {
        return Vector4(x / length, y / length, z / length, w / length);
    }
}

Vector4 Vector4::Scale(const float& scale) const {
    return Vector4(x * scale, y * scale, z * scale, w * scale);
}

Vector4 Vector4::MultiplyMatrix(const Matrix4& m) const {
    return Vector4(
        x * m.m11 + y * m.m21 + z * m.m31 + w * m.m41,
        x * m.m12 + y * m.m22 + z * m.m32 + w * m.m42,
        x * m.m13 + y * m.m23 + z * m.m33 + w * m.m43,
        x * m.m14 + y * m.m24 + z * m.m34 + w * m.m44
    );
}

Vector4 Vector4::Add(const Vector4& v) const {
    return  Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4 Vector4::Subtract(const Vector4& v) const {
    return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
}

float Vector4::Dot(const Vector4& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vector4 Vector4::Cross(const Vector4& v) {
    return Vector4(
        y * v.z - v.y * z,
      -(z * v.x - v.z * x),
        x * v.y - v.x * y,
        0.0f
    );
}

float Vector4::Project(const Vector4& v) {
    float length = v.Length();
    if (length == 0) {
        return 0.0f;
    }
    return this->Dot(v) / length;
}

float Vector4::Angle(const Vector4& v, bool degrees) {
    const float lengths = this->Length() * v.Length();
    if (lengths == 0) {
        return 0.0f;
    }
    const float angle = this->Dot(v) / lengths;
    if (degrees) {
        return acos(angle) * radDeg;
    } else {
        return acos(angle);
    }
}

Vector4 Vector4::Reflect(const Vector4& normal) {
    return this->Subtract(normal.Scale(2 * this->Dot(normal)));
}