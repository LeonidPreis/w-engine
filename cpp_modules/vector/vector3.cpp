#include "vector3.h"


void Vector3::Print() {
    cout << "Vector3(x: " << x << " y: " << y << " z: " << z << ")" << endl;
}

Vector3 Vector3::Clone() const {
    return Vector3(x, y, z);
}

bool Vector3::Equals(const Vector3& vectorB) const {
    return x == vectorB.x && y == vectorB.y && z == vectorB.z;
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


Vector3 Vector3::Add(const Vector3& vectorB) {
    return  Vector3(x + vectorB.x, y + vectorB.y, z + vectorB.z);
}

Vector3 Vector3::Subtract(const Vector3& vectorB) {
    return Vector3(x - vectorB.x, y - vectorB.y, z - vectorB.z);
}

float Vector3::Dot(const Vector3& vectorB) {
    return x * vectorB.x + y * vectorB.y + z * vectorB.z;
}

Vector3 Vector3::Cross(const Vector3& vectorB) {
    return Vector3(
        y * vectorB.z - vectorB.y * z,
        z * vectorB.x - vectorB.z * x,
        x * vectorB.y - vectorB.x * y
    );
}

float Vector3::Project(const Vector3& vectorB) {
    float length = vectorB.Length();
    if (length == 0) {
        return 0.0f;
    } else {
        return this->Dot(vectorB) / length;
    }
}

float Vector3::Angle(const Vector3& vectorB, bool degrees) {
    const float lengths = this->Length() * vectorB.Length();
    if (lengths == 0) {
        return 0.0f;
    } else {
        const float angle = this->Dot(vectorB) / lengths;
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


int main() {
    cout << "Reflection" << endl;

    // Vector3 normal = Vector3(0.0, 20.0, 0.0).normalize();
    // Vector3 vector = Vector3(-30.0, -15.0, 0.0);
    // Vector3 reflection = vector.reflect(normal);
    // reflection.print();

    cin.get();
    return 0;
}