    //
// Created by jeann on 24/11/2025.
//

#ifndef TP2_CPP_GAUSSIANGENERATOR_H
#define TP2_CPP_GAUSSIANGENERATOR_H
#include "TimeSeriesGenerator.h"


class GaussianGenerator: public TimeSeriesGenerator{
private:
    double mean;
    double ecart_t;
public:
    GaussianGenerator();
    GaussianGenerator(int,float,float);
    vector<double> generateTimeSeries(int) override;
private:
    double boxMuller();
};


#endif //TP2_CPP_GAUSSIANGENERATOR_H