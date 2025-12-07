//
// Created by jeann on 24/11/2025.
//

#include "StepGenerator.h"

StepGenerator::StepGenerator(): TimeSeriesGenerator() {};
StepGenerator::StepGenerator(int seed):TimeSeriesGenerator(seed) {
}

vector<double> StepGenerator::generateTimeSeries(int size) {
    vector<double> out;
    for (int i; i<size; i++) {
        double proba = rand()/RAND_MAX;
        if (proba < 0.5) {
            out.push_back(rand()/RAND_MAX*100);
        }
    }
    return out;
}

