//
// Created by jeann on 24/11/2025.
//

#ifndef TP2_CPP_STEPGENERATOR_H
#define TP2_CPP_STEPGENERATOR_H
#include "TimeSeriesGenerator.h"


class StepGenerator: public TimeSeriesGenerator {
public:
    StepGenerator();

    StepGenerator(int seed);
    vector<double> generateTimeSeries(int) override;


};


#endif //TP2_CPP_STEPGENERATOR_H