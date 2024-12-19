# class Vector3
The `Vector3` class is intended for working with three-dimensional vectors in the context of 3D graphics.
## Constructor
```cpp
Vector3(float x = 0, float y = 0, float z = 0)
```
## Content
- [Methods](#methods)
  - [`Print`](#Print)
  - [`Clone`](#Clone)
  - [`Equals`](#Equals)
  - [`Negate`](#Negate)
  - [`Length`](#Length)
  - [`Normalize`](#Normalize)
  - [`Scale`](#Scale)
  - [`Add`](#Add)
  - [`Subtract`](#Subtract)
  - [`Dot`](#Dot)
  - [`Cross`](#Cross)
  - [`Project`](#Project)
  - [`Angle`](#Angle)
  - [`Reflect`](#Reflect)
---

## Methods
### `Print`
##### Declaration
```cpp
public void Vector3::Print();
```
##### Description 
An instance method for conveniently outputting a vector to the console.

---
### `Clone`
##### Declaration
```cpp
public Vector3 Vector3::Clone() const;
```
##### Description
An instance method for copying a vector.

---
### `Equals`
##### Declaration
```cpp
public bool Vector3::Equals(const Vector3& vectorB) const;
```
##### Description 
An instance method checking equality of coefficients of two vectors.
##### Returns
 - `bool` - true if values are equal.

---
### `Nagate`
##### Declaration 
```cpp
public Vector3& Vector3::Negate();
```
##### Description 
This method replaces the sign of each element with the opposite sign. This is a **mutable** operation that modifies the current vector.

---
### `Length`
##### Declaration
```cpp
public float Vector3::Length() const;
```
##### Description 
An instance method that returns length of a vector. 
##### Returns
`float` - length of the vector.
##### Usage
```cpp
Vector3 vector = Vector3(3.0, -4.0, 12.0);
float length = vector.Length()
std::cout << length << std::endl;
// output: 
// 13.0
```
##### Mathematical description
The length of a three-dimensional vector is defined as:
```math
\left| \overline{a} \right|=\sqrt{a_x^2+a_y^2+a_z^2}.
```
For example, there is a vector $\overline{a}\left\langle 3,-4,12 \right\rangle$, then its length is calculated will be:
```math
\left| \overline{a} \right|=\sqrt{3^2+(-4)^2+12^2}=\sqrt{169}=13.
```

---
### `Normalize`
##### Declaration
```cpp
public Vector3 Vector3::Normalize();
```
##### Description 
An instance method that brings a vector to unit length. This is a *mutable* operation that modifies the current vector.
##### Returns
- `Vector3` - a vector of unit length.
> If length of the vector is zero, return Vector3(0.0, 0.0, 0.0).
##### Usage
```cpp
Vector3 vector = Vector3(3.0, -4.0, 12.0).Normalize();
vector.Print();
// output:
// Vector3(0.230769, -0.307692, 0.923076)
```
##### Mathematical description
Normalizing a vector is dividing each of the coefficients of the vector by its length.
For example, there is a vector $\overline{a}\left\langle 3,-4,12 \right\rangle$ with length equal 13. Then normalized vector a will be $\overline{a}=\left\langle\frac{3}{13},\frac{-4}{13},\frac{12}{13}\right\rangle=\left\langle 0.\overline{230769},-0.\overline{307692},0.\overline{923076}\right\rangle$.

---
### `Scale`
##### Declaration
```cpp
public Vector3 Vector3::Scale(const float& scale);
```
##### Description 
Scales **`this`** vector by the given scalar.
##### Parameters
- `scale` — scalar multiplier.
##### Returns
- `Vector3` - scaled vector.
##### Usage
```cpp
Vector3 vector = Vector3(3.0, -4.0, 12.0).Scale(2.5);
vector.Print();
// output 
// Vector3(7.5, -10.0, 30.0)
```
##### Mathematical description
To multiply any vector by a number, simply multiply each coefficient of the vector by that number as in next formula $\lambda\cdot\overline{a} = \left\langle\lambda a_x, \lambda a_y, \lambda a_z\right\rangle$.
For example, there is a vector $\overline{a}\left\langle 3,-4,12 \right\rangle$ with scale 2.5. Then scaled vector will be $2.5\cdot\overline{a}=\left\langle3\cdot2.5,-4\cdot2.5,12\cdot2.5\right\rangle=\left\langle7.5, -10, 30\right\rangle$.

---
### `Add`
##### Declaration
```cpp
public Vector3 Vector3::Add(const Vector3& vectorB);
```
##### Description 
Adds `vector B` to **`this`** vector.
##### Parameters
- `vectorB` — second vector.
##### Returns
- `Vector3` - sum of the vectors.

---
##### Usage
```cpp
Vector3 vectorA = Vector3(3.0, -4.0, 12.0);
Vector3 vectorB = Vector3(-12.0, 0.0, -16.0);
Vector3 vectorC = vectorA.Add(vectorB);
vectorC.Print();
// output
// Vector3(-9.0, -4.0, -4.0)
```
##### Mathematical description
To add two vectors to each other, it is sufficient to add each coordinate of the first vector to the corresponding coordinate of the second vector. 
```math
\overline{a}+\overline{b} = \left\langle a_x+b_x, a_y+b_y, a_z+b_z\right\rangle
```
For example there are two vectors $\overline{a}\left\langle 3,-4,12 \right\rangle$ and $\overline{b}\left\langle-12,0,16 \right\rangle$ then sum of the vectors will be:
```math
\overline{c} = \overline{a}+\overline{b} = \left\langle3+(-12), -4+0, 12+(-16)\right\rangle=\left\langle-9,-4,-4\right\rangle.
```

Important properties of the vector subtraction:
- **commutativity** $\overline{a}+\overline{b}=\overline{b}+\overline{a}$.
- **associativity** $(\overline{a}+\overline{b})+\overline{c} = \overline{a}+(\overline{b}+\overline{c})$.
- **additivity (linearity)** $\lambda(\overline{a}+\overline{b})=\lambda\overline{a}+\lambda\overline{b}$.
- existence of **opposite vector** $\overline{a}+(-\overline{a})=\overline{0}$.

---
### `Subtract`
##### Declaration
```cpp
public Vector3 Vector3::Subtract(const Vector3& vectorB);
```
##### Description 
This method subtracts **`this`** vector from `vector B`.
##### Parameters
- `vectorB` — second vector.
##### Returns
- `Vector3` - difference between two vectors.
##### Usage
```cpp
Vector3 vectorA = Vector3(3.0, -4.0, 12.0);
Vector3 vectorB = Vector3(-12.0, 0.0, -16.0);
Vector3 vectorC = vectorA.Subtract(vectorB);
vectorC.Print();
// output
// Vector3(15.0, -4.0, 28.0)
```
##### Mathematical description
To subtract two vectors from each other, simply subtract each coordinate of the first vector from the corresponding coordinate of the second vector as in next formula:
```math
\overline{a}-\overline{b} = \left\langle a_x-b_x, a_y-b_y, a_z-b_z\right\rangle.
```
For example there are two vectors $\overline{a}\left\langle 3,-4,12 \right\rangle$ and $\overline{b}\left\langle-12,0,16 \right\rangle$ then differance of the vectors will be:
```math
\overline{c} = \overline{a}+\overline{b} = \left\langle 3-(-12), -4-0, 12-(-16)\right\rangle=\left\langle15,-4,28\right\rangle.
```
> Important! Subtraction is non-associative operation $\overline{a}-\overline{b}\neq\overline{b}-\overline{a}$.

---
### `Dot`
##### Declaration
```cpp
public float Vector3::Dot(const Vector3& vectorB);
```
##### Description 
This method returns the dot product of two vectors. Used to determine the angle between vectors in algorithms for culling backfaces.
##### Parameters
- `vectorB` — second vector.
##### Returns
- `float` - dot product of two vecctors.
##### Usage
```cpp
Vector3 vectorA = Vector3(3.0, -4.0, 12.0);
Vector3 vectorB = Vector3(-12.0, 0.0, -16.0);
Vector3 dot = vectorA.Dot(vectorB);
std::cout << dot << std::endl;
// output
// -228
```
##### Mathematical description
The result of the dot product of two vectors is a **scalar value** - the product of the lengths of the vectors by the cosine of the angle between them $(\overline{a},\overline{b})=\left| \overline{a} \right|\cdot\left| \overline{b} \right|\cdot cos \angle (\overline{a};\overline{b})$. Basically, as mentioned above, this scalar is required to determine the angle between two vectors or to calculate the projection of one vector onto another. 

Important properties of the dot product:
- **commutativity** $(\overline{a},\overline{b})=(\overline{b},\overline{a})$.
- **distributivity** with respect to the addition operation $(\overline{a}+\overline{b},\overline{c})=(\overline{a}, \overline{c})+(\overline{b},\overline{c})$ and $(\overline{c},\overline{a}+\overline{b})=(\overline{c}, \overline{a})+(\overline{c},\overline{b})$.
- **associativity** with respect to multiplication by a number $((\lambda\overline{a},\overline{b})=\lambda(\overline{a},\overline{b})=(\overline{a},\lambda\overline{b})$.
- **non-associativity** with respect to multiplication by a vector $(\overline{a},\overline{b})\cdot\overline{c}\neq\overline{a}\cdot(\overline{b},\overline{c})$.
- **orthogonality**: two vectors (**non zero-length**) are perpendicular only if their dot product is zero. $\overline{a}\bot \overline{b}$ if $(\overline{a},\overline{b}) = 0$.

For example you have to calculate the dot product of two vectors $\overline{a}\left( 3,-4,12 \right)$ and $\overline{b}\left(-12,0,-16 \right)$. 
This can be calculated as the sum of products of coefficients for the **n-dimensional vector** as $(\overline{a},\overline{b}) = \sum_{k=1}^{n}\overline{a}_n\overline{b}_n = a_1b_1+a_2b_b+a_3b_3+\cdots +a_nb_n$.
In this case the dot product is equal to $(\overline{a},\overline{b})=3\cdot(-12)+(-4)\cdot0+12\cdot16=-228$.

---
### `Cross`
##### Declaration
```cpp
public Vector3 Vector3::Cross(const Vector3& vectorB);
```
##### Description 
This method calculates a vector in three-dimensional Euclidean space that is perpendicular to both source vectors. The length of the vector is numerically equal to the area of the parallelogram formed by the two original vectors. The returned vector has the same direction as the z-axis in the *right coordinate system*.
> In case of cross product between two collinear vectors (or if one of the vectors is zero), it returns a zero vector.
##### Parameters
- `vectorB` — second vector.
##### Returns
- `Vector3` - vector that is perpendicular to both source vectors.
##### Usage
```cpp
Vector3 vectorA = Vector3(3.0, -4.0, 12.0);
Vector3 vectorB = Vector3(-12.0, 0.0, -16.0);
Vector3 cross = vectorA.Cross(vectorB);
cross.Print();
// output
// Vector3(64.0, -96.0, -48.0)
```
#####  Mathematical description
The cross product $\left[ \overline{a}\times\overline{b} \right]$ of two noncollinear vectors in a given order is the vector $\overline{N}=\left[ \overline{a}\times\overline{b} \right]$ whose length is numerically equal to the area of the parallelogram built on these vectors.
The vector $\overline{N}$ is orthogonal to vectors $\overline{a}$ and $\overline{b}$ and directed so that the basis $(\overline{a}, \overline{b},\overline{N})$ forms the right coordinate system. 
If we multiply the same two vectors in reverse order, we get the opposite direction of the normal $-\overline{N}=\left[ \overline{b}\times\overline{a} \right]$. In geometry, we can similarly define the **length** of the cross product of vectors as the product of their lengths by the sine of the angle between them $\left| \overline{N} \right|=\left| \overline{a} \right|\cdot\left|\overline{b} \right|\cdot sin \angle (\overline{a};\overline{b})$.

Important properties of cross product:
- The cross product of a vector by itself yields a **zero vector** $\left[ \overline{a}\times\overline{a} \right]=\overline{0}$.
- **non-commutativity** (order of multiplication of vectors matters) $\left[ \overline{a}\times\overline{b} \right]=-\left[ \overline{b}\times\overline{a} \right]$.
- **associativity** (constants can be freely carried outside the vector product) $\left[\lambda\overline{a}\times\overline{b} \right]=\lambda\left[\overline{a}\times\overline{b} \right]$ and $\left[\overline{a}\times\lambda\overline{b} \right]=\lambda\left[\overline{a}\times\overline{b} \right]$.
- **distributivity** of vectors (brackets open as with numbers) $\left[(\overline{a}+\overline{b})\times\overline{c}) \right]=\left[\overline{a}\times\overline{c}\right]+\left[\overline{b}\times\overline{c}\right]$ and $\left[\overline{a}\times(\overline{b}+\overline{c})\right]=\left[\overline{a}\times\overline{b}\right]+\left[\overline{a}\times\overline{c}\right]$.

In the case when two vectors are given by coordinates in an orthonormalized basis, the cross product is computed as a determinant in the first row of which the unit orthos $\overline{i}$ $\overline{j}$ and $\overline{k}$ and the second and third rows contain the vectors $\overline{a}$ and $\overline{b}$, respectively.
```math
\left[\overline{a}\times\overline{b} \right] =
\begin{vmatrix}
\textbf i & \textbf j & \textbf k \\
a_x & a_y & a_z \\
b_x & b_y & b_z
\end{vmatrix} = i(a_yb_z-b_ya_z)-j(a_xb_z-b_xa_z)+k(a_xb_y-b_xa_y)
```

For example you have to calculate the cross product of two vectors $\overline{a}\left\langle 3,-4,12 \right\rangle$ and $\overline{b}\left\langle-12,0,-16 \right\rangle$.
```math
\left[\overline{a}\times\overline{b} \right] =
\begin{vmatrix}
\textbf i & \textbf j & \textbf k \\
3 & -4 & 12 \\
-12 & 0 & -16
\end{vmatrix} = i((-4)\cdot(-16)-0\cdot12))-j(3\cdot(-16)-(-12)\cdot12)+k(3\cdot0-(-12)\cdot(-4))
```
```math
\left[\overline{a}\times\overline{b} \right]=\left\langle 64,-96,-48 \right\rangle
```

---
### `Project`
##### Declaration
```cpp
float Vector3::Project(const Vector3& vectorB);
```
##### Description 
This method projects the **`this`** vector onto `vector B`. Returns the length of the projection.
##### Parameters
- `vectorB` — second vector.
##### Returns
- `float` - length of the projection.
> If one of the vectors has zero-length returns 0.
##### Usage
```cpp
Vector3 vectorA = Vector3(3.0, -4.0, 12.0);
Vector3 vectorB = Vector3(-12.0, 0.0, -16.0);
Vector3 projection = vectorA.Project(vectorB);
std::cout << projection << std::endl;
// output
// -11.4
```
##### Mathematical description
To find the length of the projection of vector a onto vector b you must divide the scalar product of the vectors by the length of vector.

```math
Projection_{\overline{b}}\overline{a}=\frac{(\overline{a},\overline{b})}{\left| \overline{b} \right|}
```

For example you have to calculate the length of the projection $\overline{a}\left\langle 3,-4,12 \right\rangle$ onto $\overline{b}\left\langle-12,0,-16 \right\rangle$.

```math
Projection_{\overline{b}}\overline{a}=\frac{a_xb_x+a_yb_y+a_zb_z}{\sqrt{b_x^2+b_y^2+b_z^2}}
```
```math
Projection_{\overline{b}}\overline{a}=\frac{3\cdot (-12)+(-4)\cdot0+12\cdot(-16)}{\sqrt{(-12)^2+0^2+(-16)^2}}=\frac{-228}{20}=-11.4
```

---
### `Angle`
##### Declaration
```cpp
public float Vector3::Angle(const Vector3& vectorB, bool degrees);
```
##### Description 
This method returns the value of the angle between two vectors. By default, the angle is returned in **radians**.
##### Parameters
- `vectorB` — second vector.
- `degrees` — default is false (result in radians).
##### Returns
- `float` - angle between the vectors in radians or degrees.
> If one of the vectors has zero-length returns 0.
##### Usage
```cpp
Vector3 vectorA = Vector3(3.0, -4.0, 12.0);
Vector3 vectorB = Vector3(-12.0, 0.0, -16.0);
Vector3 angleAB = vectorA.Angle(vectorB);
std::cout << angleAB << std::endl;
// output
// 2.64022 radians or 151.27346 degrees
```
##### Mathematical description
To find the angle between vectors you must divide the dot product of the vectors by the lengths of the vectors.
```math
cos\alpha = \frac{(\overline{a},\overline{b})}{\left| \overline{a} \right|\cdot\left| \overline{b} \right|}
```
For example you have two vectors $\overline{a}\left\langle 3,-4,12 \right\rangle$ and $\overline{b}\left\langle-12,0,-16 \right\rangle$. Then angle will be:
```math
cos\alpha=\frac{a_xb_x+a_yb_y+a_zb_z}{\sqrt{a_x^2+a_y^2+a_z^2}\cdot\sqrt{b_x^2+b_y^2+b_z^2}}
```
```math
cos\alpha = \frac{3\cdot (-12)+(-4)\cdot0+12\cdot(-16)}{\sqrt{3^2+(-4)^2+12^2}\cdot\sqrt{(-12)^2+0^2+(-16)^2}}=\frac{-228}{260}=-\frac{57}{65}
```
```math
\alpha=cos^{-1}(-\frac{57}{65})\cdot(\frac{180}{\pi})\cong151.2734^{\circ}
```

---
### `Reflect`
##### Declaration
```cpp
public Vector3 Vector3::Reflect(const Vector3& normal);
```
##### Description 
This method reflects **`this`** vector relative to the `normal` vector. The normal must be **normalized** beforehand.
##### Parameters
- `normal` — vector of the normal. Must be normalized before using.
##### Returns
- `Vector3` - reflected vector.
##### Usage
```cpp
Vector3 normal = Vector3(0.0, 25.0, 0.0).normalize();
Vector3 direction = Vector3(-30.0, -15.0, 0.0).reflect(normal);
Vector3 reflection = direction.Reflect(normal);
reflection.Rrint();
// output
// Vector3(x: -30 y: 15 z: 0)
```

##### Mathematical description
Sometimes in rendering tasks (especially in ray tracing) it is necessary to reflect a vector from a plane or polygon defined by a normal. If there is a normal vector $\overline{N}$ and a direction vector $\overline{d}$ (our original ray), then the reflected vector $\overline{r}$ can be calculated as:
```math
\overline{r}=\overline{d}-2\cdot(\overline{d},\overline{N})\cdot\overline{N}

```
For example, there is a direction vector $\overline{d}\left\langle -30,-15,0 \right\rangle$ and a normal $\overline{N}\left\langle 0,25,0 \right\rangle$. Then the reflected vector $\overline{r}$ will be equal to:
```math
\overline{r}=\overline{d}-2\cdot(\overline{d},\overline{N})\cdot\overline{N}
```

```math
2\cdot(\overline{d},\overline{N})=2\cdot(0\cdot(-30)+1\cdot(-15)+0\cdot(10))=-30
```

```math
-30\cdot\overline{N} = \left\langle 0,-30,0 \right\rangle
```

```math
\overline{r}=\left\langle -30-0,-15-(-30),0-0 \right\rangle=\left\langle -30,15,0 \right\rangle
```

---