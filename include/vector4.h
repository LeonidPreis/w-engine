#ifndef VECTOR4_H
#define VECTOR4_H

class Matrix4;

#include <cmath>
#include <iostream>

constexpr float radDeg = 57.295779513082320876;

class Vector4 {
public:
    Vector4(float x = 0, float y = 0, float z = 0, float w = 0): x(x), y(y), z(z), w(w) {}

public:
    float x, y, z, w;

public:
    /**
     * @brief Outputs the vector value to the console.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Print
    */
    void Print();

public:
    /**
     * @brief Clones the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Clone
     * 
     * @return New vector. 
    */
    Vector4 Clone() const;

public:
    /**
     * @brief Checks the equality of vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Equals
     * 
     * @param v second vector.
     * @return Boolean value.
    */
    bool Equals(const Vector4& v) const;

public:
    /**
     * @brief Changes the signs of the x,y,z coefficients.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Negate
    */
    Vector4& Negate();

public:
    /**
     * @brief Calculates length of the vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Length
     * @return Length value of the vector.
    */
    float Length() const;

public:
    /**
     * @brief Brings the vector to unit length if length not equal zero.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Normalize
    */
    Vector4 Normalize() const;

public:
    /**
     * @brief Multiplies each vector coefficient by a scalar.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Scale
     * @param scale multiplier.
     * @return New vector. Operation is non-mutable.
    */
    Vector4 Scale(const float& scale) const;

public:
    /**
     * @brief Multiplyes current vector by matrix.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#MultiplyMatrix
     * @param m matrix 4x4.
     * @return New row-vector.
    */
    Vector4 MultiplyMatrix(const Matrix4& m) const;

public:
    /**
     * @brief Adds second vector to the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Add
     * @param v second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector4 Add(const Vector4& v) const;

public:
    /**
     * @brief Subtracts second vector from the current vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Subtract
     * @param v second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector4 Subtract(const Vector4& v) const;

public:
    /**
     * @brief Calculates a dot product of two vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Dot
     * @param v second vector.
     * @return Dot product.
    */
    float Dot(const Vector4& v) const;

public:
    /**
     * @brief Calculates a vector that is perpendicular to two source vectors.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Cross
     * @param v second vector.
     * @return New vector. Operation is non-mutable.
    */
    Vector4 Cross(const Vector4& v);

public:
    /**
     * @brief Calculates the length of the projection of the current vector onto second vector.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Project
     * @param v second vector.
     * @return Length of the projection.
    */
    float Project(const Vector4& v);

public:
    /**
     * @brief Calculates the angle between two vectors in radians or degrees.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Angle
     * @param v second vector.
     * @param degrees taken into account when returning the value. Dafault - false (return value in radians).
     * @return Angle between vectors.
    */
    float Angle(const Vector4& v, bool degrees = false);

public:
    /**
     * @brief Calculates the vector reflected relative to the normal.
     * 
     * Documentation:
     * 
     * https://github.com/LeonidPreis/w-engine/wiki/Vector4#Reflect
     * @param normal vector of the normal. Must be normalized.
     * @return Reflected vector.
    */
    Vector4 Reflect(const Vector4& normal);
};

#endif