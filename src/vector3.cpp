#include "vector3.h"

void Vector3::Print() {
    std::cout << "Vector3(x: " << x << " y: " << y << " z: " << z << ")" << std::endl;
}

Vector3 Vector3::Clone() const {
    return Vector3(x, y, z);
}

bool Vector3::Equals(const Vector3& v) const {
    return x == v.x && y == v.y && z == v.z;
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


Vector3 Vector3::Add(const Vector3& v) {
    return  Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::Subtract(const Vector3& v) {
    return Vector3(x - v.x, y - v.y, z - v.z);
}

float Vector3::Dot(const Vector3& v) {
    return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::Cross(const Vector3& v) {
    return Vector3(
        y * v.z - v.y * z,
      -(z * v.x - v.z * x),
        x * v.y - v.x * y
    );
}

float Vector3::Project(const Vector3& v) {
    float length = v.Length();
    if (length == 0) {
        return 0.0f;
    } else {
        return this->Dot(v) / length;
    }
}

float Vector3::Angle(const Vector3& v, bool degrees) {
    const float lengths = this->Length() * v.Length();
    if (lengths == 0) {
        return 0.0f;
    } else {
        const float angle = this->Dot(v) / lengths;
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
