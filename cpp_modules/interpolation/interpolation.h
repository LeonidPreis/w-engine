#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
using namespace std;

class Interpolation {
    public:
    /**
     * @brief Calculates intermediate values ​​of a linear function between points A and B.
     * @note Time complexity: O(1).
     * @param xA coefficient x of point A. Must be less than xB.
     * @param yA coefficient y of point A. 
     * @param xB coefficient x of point B. 
     * @param yB coefficient y of point B. 
     * @return interpolated values. 
    */
    static vector<double> linear(double xA, double yA, double xB, double yB);
    public:
    /**
     * @brief Calculates the values ​​of the edges of the triangle between points A, B, C using three corresponding interpolations. X is a value dependent on Y.
     * @note Time complexity: O(1);
     * @param xA coefficient x of point A.
     * @param yA coefficient y of point A. 
     * @param xB coefficient x of point B. 
     * @param yB coefficient y of point B. 
     * @param xC coefficient x of point C. 
     * @param yC coefficient y of point C.
     * @return The vector of two vectors. First vector contains the interpolated values along the edge AC. Second vector contains the interpolated values along the edges AB and BC.
    */
    static vector<vector<double>> edge(double xA, double yA, double xB, double yB, double xC, double yC);
};
#endif