#include "interpolation.h"

vector<double> Interpolation::linear(double xA, double yA, double xB, double yB) {
    vector<double> values;
    if (xA == xB) {
        values.push_back(yA);
        return values;
    }
    double k = (yB - yA) / (xB - xA);
    double b = yA;
    for (double i = xA; i <= xB; i++) {
        values.push_back(b);
        b += k;
    }
    return values;
}

vector<vector<double>> Interpolation::edge(double xA, double yA, double xB, double yB, double xC, double yC) {
    vector<double> ab = Interpolation::linear(yA, xA, yB, xB);
    vector<double> bc = Interpolation::linear(yB, xB, yC, xC);
    vector<double> ac = Interpolation::linear(yA, xA, yC, xC);
    ab.pop_back();
    ab.insert(ab.end(), bc.begin(), bc.end());
    return {ac, ab};
}
