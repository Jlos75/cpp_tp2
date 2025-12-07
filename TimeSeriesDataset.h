//
// Created by jeann on 24/11/2025.
//

#ifndef TP2_CPP_TIMESERIESDATASET_H
#define TP2_CPP_TIMESERIESDATASET_H
#include <vector>
using namespace std;

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;
    vector<double> data;
    vector<int> labels;
    int maxLength;
    int numberOfSamples;
public:
    TimeSeriesDataset(bool znorm, bool train);
    TimeSeriesDataset(bool,bool ,vector<double> ,vector<int> ,int ,int );
    double euclidean_distance(const vector<double>,const vector<double>);
    double dtw(const vector<double>,const vector<double>);
    vector<double> getTimeSeries(int index);

    int getLabel(int index);

    void addTimeSeries(const std::vector<double> &series, int label);

    friend class KNN;
};




#endif //TP2_CPP_TIMESERIESDATASET_H
