#ifndef QUATERNION
#define QUATERNION

class Vector4;
class Matrix4;

#include <iomanip>    
#include <iostream>
#include <cmath>

//constexpr float radDeg = 57.295779513082320876;

class Quaternion {
public: Quaternion(float w = 0.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f): w(w), x(x), y(y), z(z) {}

public: float w, x, y, z;

public: void Print(const int& precision) const;

public: Quaternion Clone() const;

public: bool Equals(const Quaternion& q, const float& precision = 1e-6) const;

public: float Length() const;

public: Quaternion Normalize() const;

public: Quaternion& Conjugate();

public: Quaternion Inverse() const;

public: Quaternion Add(const Quaternion& q) const;

public: Quaternion Subtract(const Quaternion q) const;

public: Quaternion Scale(const float& scale) const;

public: Quaternion Multiply(const Quaternion& q) const;

public: float Dot(const Quaternion& q) const;

public: float Angle(const Quaternion& q, const bool& degrees = false) const;

public: float ToAngle() const;

public: Vector4 ToAxis() const;

public: float ToRoll() const;

public: float ToPitch() const;

public: float ToYaw() const;

public: Matrix4 ToRotationMatrix() const;

public: Vector4 ApplyToVector(const Vector4& v) const;

public: Quaternion Slerp(Quaternion& q, const float& t) const;

public: static Quaternion FromAngleAxis(const float& angleRadians, const Vector4& axis);

public: static Quaternion FromRotationMatrix(const Matrix4& m);

};


#endif