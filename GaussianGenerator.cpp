//
// Created by jeann on 24/11/2025.
//

#include "GaussianGenerator.h"
#include <cmath>;
using namespace std;

GaussianGenerator::GaussianGenerator(int _seed,float _mean, float _ecart_t):
TimeSeriesGenerator(_seed), mean(_mean), ecart_t(_ecart_t) {
}
GaussianGenerator::GaussianGenerator():
TimeSeriesGenerator(), mean(0), ecart_t(0) {
}

double GaussianGenerator::boxMuller() {
    double u1, u2, z;

    u1 =  (((double)rand() +1) / (RAND_MAX+2)) ;
    u2 =  (((double)rand() +1) / (RAND_MAX+2)) ;

    z = sqrt((-2.0 * log(u1)) * cos(2* numbers::pi*u2));

return mean + z * ecart_t;
}

vector<double> GaussianGenerator::generateTimeSeries(int size) {
    vector<double> out;
    for (int i=0; i<size; i++) {
        out.push_back(boxMuller());
    }
    return out;
}
