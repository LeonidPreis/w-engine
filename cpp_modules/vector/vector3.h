#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;
const float radDeg = 57.295779513082320876;

class Vector3 {
public:
    Vector3(float x = 0, float y = 0, float z = 0): x(x), y(y), z(z) {}

public:
    float x, y, z;

public:
    /**
     * @brief Outputs the vector value to the console.
    */
    void Print();

public:
    /**
     * @brief Clones the current vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Clone() const;

public:
    /**
     * @brief Checks the equality of vectors.
     * @return Boolean value.
    */
    bool Equals(const Vector3& vectorB) const;

public:
    /**
     * @brief Changes the signs of the x,y,z coefficients.
    */
    Vector3& Negate();

public:
    /**
     * @brief Calculates length of the vector.
     * @return Length value of the vector.
    */
    float Length() const;

public:
    /**
     * @brief Brings the vector to unit length if length not equal zero.
    */
    Vector3 Normalize();

public:
    /**
     * @brief Multiplies each vector coefficient by a scalar.
     * @param scale multiplier.
    */
    Vector3 Scale(const float& scale) const;

public:
    /**
     * @brief Adds vector B to the current vector.
     * @param vectorB second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Add(const Vector3& vectorB);

public:
    /**
     * @brief Subtracts vector B from the current vector.
     * @param vectorB second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Subtract(const Vector3& vectorB);

public:
    /**
     * @brief Calculates a dot product of two vectors.
     * @param vectorB second vector.
     * @return Dot product.
    */
    float Dot(const Vector3& vectorB);

public:
    /**
     * @brief Calculates a vector that is perpendicular to two source vectors.
     * @param vectorB second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Cross(const Vector3& vectorB);

public:
    /**
     * @brief Calculates the length of the projection of the current vector onto vector B.
     * @param vectorB second vector.
     * @return Length of the projection.
    */
    float Project(const Vector3& vectorB);

public:
    /**
     * @brief Calculates the angle between two vectors in radians or degrees.
     * @param vectorB second vector.
     * @param degrees taken into account when returning the value. Dafault - false (return value in radians).
     * @return Angle between vectors.
    */
    float Angle(const Vector3& vectorB, bool degrees = false);

public:
    /**
     * @brief Calculates the vector reflected relative to the normal.
     * @param normal vector of the normal. Must be normalized.
     * @return Reflected vector.
    */
    Vector3 Reflect(const Vector3& normal);
};

#endif