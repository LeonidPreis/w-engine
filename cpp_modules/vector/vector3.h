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
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
    */
    void Print();

public:
    /**
     * @brief Clones the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * 
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Clone() const;

public:
    /**
     * @brief Checks the equality of vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * 
     * @return Boolean value.
    */
    bool Equals(const Vector3& vectorB) const;

public:
    /**
     * @brief Changes the signs of the x,y,z coefficients.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
    */
    Vector3& Negate();

public:
    /**
     * @brief Calculates length of the vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @return Length value of the vector.
    */
    float Length() const;

public:
    /**
     * @brief Brings the vector to unit length if length not equal zero.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
    */
    Vector3 Normalize();

public:
    /**
     * @brief Multiplies each vector coefficient by a scalar.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param scale multiplier.
    */
    Vector3 Scale(const float& scale) const;

public:
    /**
     * @brief Adds vector B to the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param vectorB second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Add(const Vector3& vectorB);

public:
    /**
     * @brief Subtracts vector B from the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param vectorB second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Subtract(const Vector3& vectorB);

public:
    /**
     * @brief Calculates a dot product of two vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param vectorB second vector.
     * @return Dot product.
    */
    float Dot(const Vector3& vectorB);

public:
    /**
     * @brief Calculates a vector that is perpendicular to two source vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param vectorB second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Cross(const Vector3& vectorB);

public:
    /**
     * @brief Calculates the length of the projection of the current vector onto vector B.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param vectorB second vector.
     * @return Length of the projection.
    */
    float Project(const Vector3& vectorB);

public:
    /**
     * @brief Calculates the angle between two vectors in radians or degrees.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param vectorB second vector.
     * @param degrees taken into account when returning the value. Dafault - false (return value in radians).
     * @return Angle between vectors.
    */
    float Angle(const Vector3& vectorB, bool degrees = false);

public:
    /**
     * @brief Calculates the vector reflected relative to the normal.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/blob/main/cpp_modules/vector/vector3.md
     * @param normal vector of the normal. Must be normalized.
     * @return Reflected vector.
    */
    Vector3 Reflect(const Vector3& normal);
};

#endif