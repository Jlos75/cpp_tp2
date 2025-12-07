//
// Created by jeann on 02/12/2025.
//

#ifndef TP2_CPP_KNN_H
#define TP2_CPP_KNN_H
#include <string>
#include <vector>

#include "TimeSeriesDataset.h"
using namespace std;

class KNN {
private:
    int k;
    string similarity_measure;
public:
    KNN(int, string);
    double evaluate(TimeSeriesDataset& trainSet, TimeSeriesDataset& testSet, std::vector<int>& testLabels);



};


#endif //TP2_CPP_KNN_H