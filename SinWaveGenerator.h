//
// Created by jeann on 24/11/2025.
//

#ifndef TP2_CPP_SINWAVEGENERATOR_H
#define TP2_CPP_SINWAVEGENERATOR_H
#include "TimeSeriesGenerator.h"


class SinWaveGenerator:public TimeSeriesGenerator{
private:
    double amplitude;
    double freq;
    double ph_init;
public:
    SinWaveGenerator();

    SinWaveGenerator(int,double,double,double);

    vector<double> generateTimeSeries(int) override;

};


#endif //TP2_CPP_SINWAVEGENERATOR_H