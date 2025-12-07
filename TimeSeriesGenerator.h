//
// Created by jeann on 24/11/2025.
//

#ifndef TP2_CPP_TIMESERIESGENERATOR_H
#define TP2_CPP_TIMESERIESGENERATOR_H
#include <functional>
using namespace std;

class TimeSeriesGenerator {
private:
    int seed;
public:
    TimeSeriesGenerator();
    TimeSeriesGenerator(int);
    virtual vector<double> generateTimeSeries(int)=0;
    static void printTimeSeries(const vector<double>);

};



#endif //TP2_CPP_TIMESERIESGENERATOR_H
