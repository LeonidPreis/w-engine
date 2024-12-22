#include "vector4.h"

void Vector4::Print() {
    std::cout << "Vector4(x: " << x << " y: " << y << " z: " << z << " w: " << w << ")" << std::endl;
}

Vector4 Vector4::Clone() const {
    return Vector4(x, y, z, w);
}

bool Vector4::Equals(const Vector4& vB) const {
    return x == vB.x && y == vB.y && z == vB.z && w == vB.w;
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

Vector4 Vector4::Add(const Vector4& vB) const {
    return  Vector4(x + vB.x, y + vB.y, z + vB.z, w + vB.w);
}

Vector4 Vector4::Subtract(const Vector4& vB) const {
    return Vector4(x - vB.x, y - vB.y, z - vB.z, w - vB.w);
}

float Vector4::Dot(const Vector4& vB) const {
    return x * vB.x + y * vB.y + z * vB.z + w * vB.w;
}

Vector4 Vector4::Cross(const Vector4& vB) {
    return Vector4(
        y * vB.z - vB.y * z,
      -(z * vB.x - vB.z * x),
        x * vB.y - vB.x * y,
        0.0f
    );
}

float Vector4::Project(const Vector4& vB) {
    float length = vB.Length();
    if (length == 0) {
        return 0.0f;
    }
    return this->Dot(vB) / length;
}

float Vector4::Angle(const Vector4& vB, bool degrees) {
    const float lengths = this->Length() * vB.Length();
    if (lengths == 0) {
        return 0.0f;
    }
    const float angle = this->Dot(vB) / lengths;
    if (degrees) {
        return acos(angle) * radDeg;
    } else {
        return acos(angle);
    }
}

Vector4 Vector4::Reflect(const Vector4& normal) {
    return this->Subtract(normal.Scale(2 * this->Dot(normal)));
}