#ifndef EULER
#define EULER

class Vector4;

#include <string>
#include <iostream>
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>
#include <set>

class Euler {
public: enum class Order { XYZ, XZY, YXZ, YZX, ZXY, ZYX };

public: float roll, pitch, yaw;
public: Order order;

public: Euler(float roll = 0, float pitch = 0, float yaw = 0, const std::string& order = "XYZ"):
    roll(roll), pitch(pitch), yaw(yaw), order(StringToOrder(order)) {}

private: static Order StringToOrder(const std::string& order);

private: static void ComputeXYZ(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw);

private: static void ComputeXZY(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw);

private: static void ComputeYXZ(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw);

private: static void ComputeYZX(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw);

private: static void ComputeZXY(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw);

private: static void ComputeZYX(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw);

public: static Euler FromAngleAxis(const float& angleRadians, const Vector4& axis, const std::string& order);

};

#endif
