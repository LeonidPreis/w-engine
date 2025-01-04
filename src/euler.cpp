#include "../include/euler.h"
#include "../include/vector4.h"

Euler::Order Euler::StringToOrder(const std::string& order) {
    if (order == "XYZ" || order == "xyz") return Order::XYZ;
    if (order == "XZY" || order == "xzy") return Order::XZY;
    if (order == "YXZ" || order == "yxz") return Order::YXZ;
    if (order == "YZX" || order == "yzx") return Order::YZX;
    if (order == "ZXY" || order == "zxy") return Order::ZXY;
    if (order == "ZYX" || order == "zyx") return Order::ZYX;
    throw std::invalid_argument("Invalid rotation order: " + order + ".\nValid options are: XYZ, XZY, YXZ, YZX, ZXY, ZYX or xyz, xzy, yxz, yzx, zxy, zyx.");
}

void Euler::ComputeXYZ(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(-rotationMatrix[3][1]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2(rotationMatrix[3][2], rotationMatrix[3][3]);
        yaw = atan2(rotationMatrix[2][1], rotationMatrix[1][1]);
    } else {
        roll = atan2(-rotationMatrix[1][2], rotationMatrix[2][2]);
        yaw = 0;
    }
}

void Euler::ComputeXZY(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(rotationMatrix[3][2]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2(-rotationMatrix[2][3], rotationMatrix[2][2]);
        yaw = atan2(-rotationMatrix[3][1], rotationMatrix[1][1]);
    } else {
        roll = 0;
        yaw = atan2(rotationMatrix[1][2], rotationMatrix[2][2]);
    }
}

void Euler::ComputeYXZ(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(-rotationMatrix[1][3]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2(rotationMatrix[2][3], rotationMatrix[3][3]);
        yaw = atan2(rotationMatrix[1][2], rotationMatrix[1][1]);
    } else {
        roll = 0;
        yaw = atan2(-rotationMatrix[2][1], rotationMatrix[2][2]);
    }
}

void Euler::ComputeYZX(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(rotationMatrix[1][3]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2(-rotationMatrix[1][2], rotationMatrix[1][1]);
        yaw = atan2(-rotationMatrix[3][1], rotationMatrix[3][2]);
    } else {
        roll = 0;
        yaw = atan2(rotationMatrix[2][1], rotationMatrix[2][2]);
    }
}

void Euler::ComputeZXY(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(rotationMatrix[3][1]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2(-rotationMatrix[2][1], rotationMatrix[1][1]);
        yaw = atan2(-rotationMatrix[3][2], rotationMatrix[3][3]);
    } else {
        roll = 0;
        yaw = atan2(rotationMatrix[1][2], rotationMatrix[2][2]);
    }
}

void Euler::ComputeZYX(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(-rotationMatrix[3][1]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2(rotationMatrix[3][2], rotationMatrix[3][3]);
        yaw = atan2(rotationMatrix[2][1], rotationMatrix[1][1]);
    } else {
        roll = atan2(-rotationMatrix[1][2], rotationMatrix[2][2]);
        yaw = 0;
    }
}

Euler Euler::FromAngleAxis(const float& angleRadians, const Vector4& axis, const std::string& order) {
    Euler::Order ORDER = StringToOrder(order);
    
    const float cosTheta = cos(angleRadians);
    const float sinTheta = sin(angleRadians);

    const float rotationMatrix[3][3] = {
        cosTheta + axis.x * axis.x * (1.0f - cosTheta), axis.x * axis.y * (1.0f - cosTheta) - axis.z * sinTheta, axis.x * axis.z * (1.0f - cosTheta) + axis.y * sinTheta,
        axis.y * axis.x * (1.0f - cosTheta) + axis.z * sinTheta, cosTheta + axis.y * axis.y * (1.0f - cosTheta), axis.y * axis.z * (1.0f - cosTheta) - axis.x * sinTheta,
        axis.z * axis.x * (1.0f - cosTheta) - axis.y * sinTheta, axis.z * axis.y * (1.0f - cosTheta) + axis.x * sinTheta, cosTheta + axis.z * axis.z * (1.0f - cosTheta)
    };

    float roll, pitch, yaw;

    switch(ORDER) {
        case Order::XYZ:
            Euler::ComputeXYZ(rotationMatrix, roll, pitch, yaw);
            break;
        case Order::XZY:
            Euler::ComputeXZY(rotationMatrix, roll, pitch, yaw);
            break;
        case Order::YXZ:
            Euler::ComputeYXZ(rotationMatrix, roll, pitch, yaw);
            break;
        case Order::YZX:
            Euler::ComputeYZX(rotationMatrix, roll, pitch, yaw);
            break;
        case Order::ZXY:
            Euler::ComputeZXY(rotationMatrix, roll, pitch, yaw);
            break;
        case Order::ZYX:
            Euler::ComputeZYX(rotationMatrix, roll, pitch, yaw);
            break;
        default:
            throw std::invalid_argument("Invalid rotation order: " + order + ".\nValid options are: XYZ, XZY, YXZ, YZX, ZXY, ZYX or xyz, xzy, yxz, yzx, zxy, zyx.");
    }
}
