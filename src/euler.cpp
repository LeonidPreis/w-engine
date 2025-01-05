#include "../include/euler.h"
#include "../include/vector4.h"
#include "../include/matrix4.h"
#include "../include/quaternion.h"

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
    pitch = asinf(-rotationMatrix[3][1]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2f(rotationMatrix[3][2], rotationMatrix[3][3]);
        yaw = atan2f(rotationMatrix[2][1], rotationMatrix[1][1]);
    } else {
        roll = atan2f(-rotationMatrix[1][2], rotationMatrix[2][2]);
        yaw = 0;
    }
}

void Euler::ComputeXZY(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(rotationMatrix[3][2]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2f(-rotationMatrix[2][3], rotationMatrix[2][2]);
        yaw = atan2f(-rotationMatrix[3][1], rotationMatrix[1][1]);
    } else {
        roll = 0;
        yaw = atan2f(rotationMatrix[1][2], rotationMatrix[2][2]);
    }
}

void Euler::ComputeYXZ(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asinf(-rotationMatrix[1][3]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2f(rotationMatrix[2][3], rotationMatrix[3][3]);
        yaw = atan2f(rotationMatrix[1][2], rotationMatrix[1][1]);
    } else {
        roll = 0;
        yaw = atan2f(-rotationMatrix[2][1], rotationMatrix[2][2]);
    }
}

void Euler::ComputeYZX(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asin(rotationMatrix[1][3]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2f(-rotationMatrix[1][2], rotationMatrix[1][1]);
        yaw = atan2f(-rotationMatrix[3][1], rotationMatrix[3][2]);
    } else {
        roll = 0;
        yaw = atan2f(rotationMatrix[2][1], rotationMatrix[2][2]);
    }
}

void Euler::ComputeZXY(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asinf(rotationMatrix[3][1]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2f(-rotationMatrix[2][1], rotationMatrix[1][1]);
        yaw = atan2f(-rotationMatrix[3][2], rotationMatrix[3][3]);
    } else {
        roll = 0;
        yaw = atan2f(rotationMatrix[1][2], rotationMatrix[2][2]);
    }
}

void Euler::ComputeZYX(const float rotationMatrix[3][3], float& roll, float& pitch, float& yaw) {
    pitch = asinf(-rotationMatrix[3][1]);
    if (abs(pitch) < M_PI_2) {
        roll = atan2f(rotationMatrix[3][2], rotationMatrix[3][3]);
        yaw = atan2f(rotationMatrix[2][1], rotationMatrix[1][1]);
    } else {
        roll = atan2f(-rotationMatrix[1][2], rotationMatrix[2][2]);
        yaw = 0;
    }
}

Euler Euler::FromAngleAxis(const float& angleRadians, const Vector4& axis, const std::string& order) {
    Euler::Order ORDER = StringToOrder(order);

    const float cosTheta = cosf(angleRadians);
    const float sinTheta = sinf(angleRadians);

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

Euler Euler::FromRotationMatrix(const Matrix4& m) {
    const float roll = -atanf(m.m32 / m.m33);
    const float pitch = atanf(-m.m31 / sqrtf(powf(m.m32, 2) + powf(m.m33, 2)));
    const float yaw = atanf(m.m21 / m.m11);
    return Euler(roll, pitch, yaw);
}

Euler Euler::FromQuaternion(const Quaternion& q) {
    return Euler(
       -atan2f(2 * (q.w * q.x + q.y * q.z), 1 - 2 * (q.x * q.x + q.y * q.y)),
        asinf(2 * (q.w * q.y - q.z * q.x)),
        atan2f(2 * (q.w * q.z + q.x * q.y), 1 - 2 * (q.y * q.y + q.z * q.z))
    );
}

Vector4 Euler::ToRotationAxis() const {

}

Matrix4 Euler::RotateX() {
    const float c = cosf(this->roll);
    const float s = sinf(this->roll);
    return Matrix4(
        1, 0, 0, 0,
        0, c, s, 0,
        0,-s, c, 0,
        0, 0, 0, 1
    );
}

Matrix4 Euler::RotateY() {
    const float c = cosf(this->pitch);
    const float s = sinf(this->pitch);
    return Matrix4(
        c, 0,-s, 0,
        0, 1, 0, 0,
        s, 0, c, 0,
        0, 0, 0, 1
    );
}

Matrix4 Euler::RotateZ() {
    const float c = cosf(this->yaw);
    const float s = sinf(this->yaw);
    return Matrix4(
        c, s, 0, 0,
       -s, c, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    );
}

Matrix4 Euler::RotateXYZ() {
    const float cA = cosf(this->roll);
    const float sA = sinf(this->roll);
    const float cB = cosf(this->pitch);
    const float sB = sinf(this->pitch);
    const float cG = cosf(this->yaw);
    const float sG = sinf(this->yaw);

    switch (this->order) {
        case Order::XYZ:
            return Matrix4(
                cB*cG,          cB*sG,         -sB,    0,
                sA*sB*cG-cA*sG, cA*cG+sA*sB*sG, sA*cB, 0,
                sA*sG+cA*sB*cG, cA*sB*sG-sA*cG, cA*cB, 0,
                0,              0,              0,     1
            );
            break;
        case Order::XZY:
            return Matrix4(
                cB*cG,           sG,   -sB*cG,          0,
                sA*sB-cA*cB*sG,  cA*cG, cA*sB*sG+sA*cB, 0,
                sA*cB*sG+cA*sB, -sA*cG, cA*cB-sA*sB*sG, 0,
                0,               0,     0,              1
            );
            break;
        case Order::YXZ:
            return Matrix4(
                cB*cG-sA*sB*sG, sA*sB*cG+cB*cG, -cA*sB, 0,
               -cA*sG,          cA*cG,           sA,    0,
                sA*cB*sG+sB*cG, sB*sG-sA*cB*cG,  cA*cB, 0,
                0,              0,               0,     1
            );
            break;
        case Order::YZX:
            return Matrix4(
                cB*cG, cA*cB*sG+sA*sB, sA*cB*sG-cA*sB, 0,
                -sG,   cA*cG,          sA*cG,          0,
                sB*cG, cA*sB*sG-sA*cB, sA*sB*sG+cA*cB, 0,
                0,     0,              0,              1
            );
            break;
        case Order::ZXY:
            return Matrix4(
                sA*sB*sG+cB*cG, cA*sG, sA*cB*sG-sB*cG, 0,
                sA*sB*cG-cB*sG, cA*cG, sA*cB*cG+sB*sG, 0,
                sA*sB,         -sA,    cA*cB,          0,
                0,              0,     0,              1
            );
            break;
        case Order::ZYX:
            return Matrix4(
                cB*cG, cA*sG+sA*sB*cG, sA*sG-cA*sB*cG, 0,
               -cB*sG, cA*cG-sA*sB*sG, sA*cG+cA*sB*sG, 0,
                sB,   -sA*cB,          cA*cB,          0,
                0,     0,              0,              1
            );
            break;
    }
}