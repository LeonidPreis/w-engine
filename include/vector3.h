#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

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
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Print
    */
    void Print();

public:
    /**
     * @brief Clones the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Clone
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
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Equals
     * @param v second vector.
     * @return Boolean value.
    */
    bool Equals(const Vector3& v) const;

public:
    /**
     * @brief Changes the signs of the x,y,z coefficients. Mutable operation.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Negate
    */
    Vector3& Negate();

public:
    /**
     * @brief Calculates length of the vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Length
     * @return Length value of the vector.
    */
    float Length() const;

public:
    /**
     * @brief Brings the vector to unit length if length not equal zero.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Normalize
    */
    Vector3 Normalize();

public:
    /**
     * @brief Multiplies each vector coefficient by a scalar.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Scale
     * @param scale multiplier.
     * @return New scaled vector.
    */
    Vector3 Scale(const float& scale) const;

public:
    /**
     * @brief Adds vector B to the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Add
     * @param v second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Add(const Vector3& v);

public:
    /**
     * @brief Subtracts vector B from the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Subtract
     * @param v second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Subtract(const Vector3& v);

public:
    /**
     * @brief Calculates a dot product of two vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Dot
     * @param v second vector.
     * @return Dot product.
    */
    float Dot(const Vector3& v);

public:
    /**
     * @brief Calculates a vector that is perpendicular to two source vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Cross
     * @param v second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector3 Cross(const Vector3& v);

public:
    /**
     * @brief Calculates the length of the projection of the current vector onto vector B.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Project
     * @param v second vector.
     * @return Length of the projections.
    */
    float Project(const Vector3& v);

public:
    /**
     * @brief Calculates the angle between two vectors in radians or degrees.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Angle
     * @param v second vector.
     * @param degrees taken into account when returning the value. Dafault - false (return value in radians).
     * @return Angle between vectors.
    */
    float Angle(const Vector3& v, bool degrees = false);

public:
    /**
     * @brief Calculates the vector reflected relative to the normal.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector3#Reflect
     * @param normal vector of the normal. Must be normalized.
     * @return Reflected vector.
    */
    Vector3 Reflect(const Vector3& normal);
};

#endif