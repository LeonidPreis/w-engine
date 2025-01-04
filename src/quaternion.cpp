#include "../include/quaternion.h"
#include "../include/vector4.h"
#include "../include/matrix4.h"

void Quaternion::Print(const int& precision = 6) const {
    std::cout << std::fixed << std::setprecision(precision) << "Quaternion[ w: " << w << " x: " << x << " y: " << y << " z: " << z << " ]\n" << std::endl;
}

Quaternion Quaternion::Clone() const {
    return Quaternion(w, x, y, z);
}

bool Quaternion::Equals(const Quaternion& q, const float& precision) const {
    return fabs(w - q.w) < precision && 
           fabs(x - q.x) < precision &&
           fabs(y - q.y) < precision && 
           fabs(z - q.z) < precision;
}

float Quaternion::Length() const {
    return sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::Normalize() const {
    const float length = this->Length();

    if (length == 0.0) return Quaternion();

    return Quaternion(w / length, x / length, y / length, z / length);
}

Quaternion& Quaternion::Conjugate(){
    x = -x, y = -y, z = -z;
    return *this;
}

Quaternion Quaternion::Inverse() const {
    const float lengthSquared = this->Length() * this->Length();
    return Quaternion(w / lengthSquared, -x / lengthSquared, -y / lengthSquared, -z / lengthSquared);
}

Quaternion Quaternion::Add(const Quaternion& q) const {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::Subtract(const Quaternion q) const {
    return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}

Quaternion Quaternion::Scale(const float& scale) const {
    return Quaternion(w * scale, x * scale, y * scale, z * scale);
}

Quaternion Quaternion::Multiply(const Quaternion& q) const {
    return Quaternion(
        w * q.w - x * q.x - y * q.y - z * q.z,
        w * q.x + x * q.w + y * q.z - z * q.y,
        w * q.y - x * q.z + y * q.w + z * q.x,
        w * q.z + x * q.y - y * q.x + z * q.w
    );
}

float Quaternion::Dot(const Quaternion& q) const {
    return w * q.w + x * q.x + y * q.y + z * q.z;
}

float Quaternion::Angle(const Quaternion& q, const bool& degrees) const {
    const float lengths = this->Length() * q.Length();

    if (lengths == 0) {
        return 0.0f;
    }

    const float angle = 2 * acos(abs(this->Dot(q) / lengths));

    if (degrees) {
        return angle * 57.295779513082320876;
    } else {
        return angle;
    }
}

float Quaternion::ToAngle() const {
    return 2 * acos(w);
}

Vector4 Quaternion::ToAxis() const {
    const float sinTheta = sin(this->ToAngle() / 2);
    return Vector4(x / sinTheta, y / sinTheta, z / sinTheta, 0.0f);
}

float Quaternion::ToRoll() const {
    return -atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y));
}

float Quaternion::ToPitch() const {
    return asin(2 * (w * y - z * x));
}

float Quaternion::ToYaw() const {
    return atan2(2 * (w * z + x * y), 1 - 2 * (y * y + z * z));
}

Matrix4 Quaternion::ToRotationMatrix() const {
    return Matrix4(
        1 - 2 * (y * y + z * z), 2 * (x * y + w * z),     2 * (x * z - w * y),     0,
        2 * (x * y - w * z),     1 - 2 * (x * x + z * z), 2 * (y * z + w * x),     0,
        2 * (x * z + w * y),     2 * (y * z - w * x),     1 - 2 * (x * x + y * y), 0,
        0,                       0,                       0,                       1
    );
}

Vector4 Quaternion::ApplyToVector(const Vector4& v) const {
    const Quaternion qVector = Quaternion(0, v.x, v.y, v.z);
    const Quaternion qInverse = this->Clone().Inverse();
    const Quaternion qResult = this->Multiply(qVector).Multiply(qInverse);
    return Vector4(qResult.x, qResult.y, qResult.z, 0.0f);
}

Quaternion Quaternion::Slerp(Quaternion& q, const float& t) const {
    if (t <= 0) { return *this; }
    if (t >= 1) { return q; }

    float cosTheta = this->Dot(q);

    if (cosTheta < 0) {
        q = q.Inverse();
        cosTheta = -cosTheta;
    }

    if (abs(cosTheta) >= 1) { return q; }

    const float theta = acos(cosTheta);
    const float sinTheta = sqrt(1 - cosTheta * cosTheta);

    if (abs(sinTheta) < 1e-3) {
        return Quaternion(
            0.5 * w + 0.5 * q.w,
            0.5 * x + 0.5 * q.x,
            0.5 * y + 0.5 * q.y,
            0.5 * z + 0.5 * q.z
        );
    }

    const float ratioA = sin((1 - t) * theta) / sinTheta;
    const float ratioB = sin(t * theta) / sinTheta;

    return Quaternion(
        ratioA * w + ratioB * q.w,
        ratioA * x + ratioB * q.x,
        ratioA * y + ratioB * q.y,
        ratioA * z + ratioB * q.z
    );
}

Quaternion Quaternion::FromAngleAxis(const float& angleRadians, const Vector4& axis) {
    const float sinTheta = sin(angleRadians / 2);
    return Quaternion(cos(angleRadians / 2), axis.x * sinTheta, axis.y * sinTheta, axis.z * sinTheta);
}

Quaternion Quaternion::FromRotationMatrix(const Matrix4& m) {
    const float xSign = std::signbit(m.m32 - m.m23) == false ? 1.0f : -1.0f;
    const float ySign = std::signbit(m.m13 - m.m31) == false ? 1.0f : -1.0f;
    const float zSign = std::signbit(m.m21 - m.m12) == false ? 1.0f : -1.0f;

    const float w = 0.5f * pow((m.m11 + m.m22 + m.m33 + 1), 2);
    const float x = 0.5f * pow((m.m11 - m.m22 - m.m33 + 1), 2) * xSign;
    const float y = 0.5f * pow((-m.m11 + m.m22 - m.m33 + 1), 2) * ySign;
    const float z = 0.5f * pow((-m.m11 - m.m22 + m.m33 + 1), 2) * zSign;
    return Quaternion(w, x, y, z);
}