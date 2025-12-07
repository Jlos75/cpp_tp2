//
// Created by jeann on 24/11/2025.
//

#include "TimeSeriesGenerator.h"

#include <iostream>
using namespace std;

TimeSeriesGenerator::TimeSeriesGenerator():seed(0) {
}

TimeSeriesGenerator::TimeSeriesGenerator(int _seed):seed(_seed) {

}

void TimeSeriesGenerator::printTimeSeries(const vector<double> doubles) {
    cout<< "Time Serie";
    for (double d:doubles) {
        cout<< d;
    }
}
