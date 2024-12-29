#ifndef QUATERNION
#define QUATERNION

class Vector4;
class Matrix4;

#include <iomanip>    
#include <iostream>
#include <cmath>

class Quaternion {
public:
    Quaternion(float w = 0.0f, float x = 0.0f, float y = 0.0f, float z = 0.0f): w(w), x(x), y(y), z(z) {}

public: float w, x, y, z;

public: void Print(const int& precision) const;

public: Quaternion Clone() const;

public: bool Equals(const Quaternion& q) const;

public: float Length() const;

public: Quaternion Normalize() const;

public: Quaternion Conjugate() const;

public: Quaternion Inverse() const;

public: Quaternion Add(const Quaternion& q) const;

public: Quaternion Subtract(const Quaternion q) const;

public: Quaternion Scale(const float& scale) const;

public: Quaternion Multiply(const Quaternion& q) const;

public: float Dot(const Quaternion& q) const;

public: float Angle(const Quaternion& q) const;


};


#endif