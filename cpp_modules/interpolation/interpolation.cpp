#include "interpolation.h"
#include <iostream>

std::vector<float> Interpolation::Linear(float xA, float yA, float xB, float yB, float step = 1) {
    std::vector<float> values;
    if (xA == xB) {
        values.push_back(yA);
        return values;
    }
    float k = (yB - yA) / (xB - xA);
    float b = yA;
    for (float i = xA; i <= xB; i += step) {
        values.push_back(b);
        b += k;
    }
    return values;
}

std::vector<std::vector<float>> Interpolation::Edge(float xA, float yA, float xB, float yB, float xC, float yC, float step = 1) {
    std::vector<float> ab = Interpolation::Linear(yA, xA, yB, xB, step);
    std::vector<float> bc = Interpolation::Linear(yB, xB, yC, xC, step);
    std::vector<float> ac = Interpolation::Linear(yA, xA, yC, xC, step);
    ab.pop_back();
    ab.insert(ab.end(), bc.begin(), bc.end());
    return {ac, ab};
}