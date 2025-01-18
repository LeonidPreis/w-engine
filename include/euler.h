#ifndef EULER
#define EULER

#define _USE_MATH_DEFINES

class Vector4;
class Matrix4;
class Quaternion;

#include <set>
#include <cmath>
#include <string>
#include <iomanip> 
#include <iostream>
#include <stdexcept>


class Euler {
public: enum class Order { XYZ, XZY, YXZ, YZX, ZXY, ZYX };

public: float alpha, beta, gamma;
public: Order order;

public: Euler(float alpha = 0, float beta = 0, float gamma = 0, const std::string& order = "XYZ"):
    alpha(alpha), beta(beta), gamma(gamma), order(StringToOrder(order)) {}

public: static Order StringToOrder(const std::string& order);

public: static std::string OrderToString(Order order);

public: void Print(const int& precision) const;

public: static Euler XYZ(const Matrix4& rotationMatrix, float epsilon = 1e-6);

public: static Euler XZY(const Matrix4& rotationMatrix, float epsilon = 1e-6);

public: static Euler YXZ(const Matrix4& rotationMatrix, float epsilon = 1e-6);

public: static Euler YZX(const Matrix4& rotationMatrix, float epsilon = 1e-6);

public: static Euler ZXY(const Matrix4& rotationMatrix, float epsilon = 1e-6);

public: static Euler ZYX(const Matrix4& rotationMatrix, float epsilon = 1e-6);

public: static Euler FromAngleAxis(const float& angleRadians, const Vector4& axis, const std::string& order);

public: static Euler FromRotationMatrix(const Matrix4& m);

public: static Euler FromQuaternion(const Quaternion& q);

public: float ToRotationAngle() const;

public: Vector4 ToRotationAxis() const;

public: Quaternion ToQuaternion() const;

public: Matrix4 RotateX() const;

public: Matrix4 RotateY() const;

public: Matrix4 RotateZ() const;

public: Matrix4 RotateXYZ() const;

};

#endif
