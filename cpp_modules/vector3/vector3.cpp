#include "vector3.h"

void Vector3::Print() {
    std::cout << "Vector3(x: " << x << " y: " << y << " z: " << z << ")" << std::endl;
}

Vector3 Vector3::Clone() const {
    return Vector3(x, y, z);
}

bool Vector3::Equals(const Vector3& vB) const {
    return x == vB.x && y == vB.y && z == vB.z;
}

Vector3& Vector3::Negate() {
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

float Vector3::Length() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3 Vector3::Normalize() {
    float length = this->Length();
    if (length == 0) {
        return Vector3(0.0f, 0.0f, 0.0f);
    } else {
        return Vector3(x /= length, y /= length, z /= length);
    }
}

Vector3 Vector3::Scale(const float& scale) const {
    return Vector3(x * scale, y * scale, z * scale);
}


Vector3 Vector3::Add(const Vector3& vB) {
    return  Vector3(x + vB.x, y + vB.y, z + vB.z);
}

Vector3 Vector3::Subtract(const Vector3& vB) {
    return Vector3(x - vB.x, y - vB.y, z - vB.z);
}

float Vector3::Dot(const Vector3& vB) {
    return x * vB.x + y * vB.y + z * vB.z;
}

Vector3 Vector3::Cross(const Vector3& vB) {
    return Vector3(
        y * vB.z - vB.y * z,
      -(z * vB.x - vB.z * x),
        x * vB.y - vB.x * y
    );
}

float Vector3::Project(const Vector3& vB) {
    float length = vB.Length();
    if (length == 0) {
        return 0.0f;
    } else {
        return this->Dot(vB) / length;
    }
}

float Vector3::Angle(const Vector3& vB, bool degrees) {
    const float lengths = this->Length() * vB.Length();
    if (lengths == 0) {
        return 0.0f;
    } else {
        const float angle = this->Dot(vB) / lengths;
        if (degrees) {
            return acos(angle) * radDeg;
        } else {
            return acos(angle);
        }
    }
}

Vector3 Vector3::Reflect(const Vector3& normal) {
    return this->Subtract(normal.Scale(2 * this->Dot(normal)));
}
