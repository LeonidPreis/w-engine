#include "../include/quaternion.h"

void Quaternion::Print(const int& precision = 6) const {
    std::cout << std::fixed << std::setprecision(precision) << "Quaternion[ w: " << w << " x: " << x << " y: " << y << " z: " << z << " ]\n" << std::endl;
}

Quaternion Quaternion::Clone() const {
    return Quaternion(w, x, y, z);
}

bool Quaternion::Equals(const Quaternion& q) const {
    return w == q.w && x == q.x && y == q.y && z == q.z;
}

float Quaternion::Length() const {
    return sqrt(w * w + x * x + y * y + z * z);
}


