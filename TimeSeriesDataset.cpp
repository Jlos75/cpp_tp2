//
// Created by jeann on 24/11/2025.
//

#include "TimeSeriesDataset.h"
#include <math.h>
#include <stdexcept>
using namespace std;

TimeSeriesDataset::TimeSeriesDataset(bool znorm=false, bool train=false)
            : znormalize(znorm), isTrain(train) {}
TimeSeriesDataset::TimeSeriesDataset(bool _znormalize, bool _isTrain, vector<double> _data, vector<int> _labels,
    int _maxLength, int _numberOfSamples):
    znormalize(_znormalize),isTrain(_isTrain),data(_data),
    maxLength(_maxLength), numberOfSamples(_numberOfSamples){
}

double TimeSeriesDataset::euclidean_distance(const vector<double> xs, const vector<double> ys) {
    double sum = 0;
    for (int i=0; i<size(xs); i++ ) {
        sum += (xs[i] - ys[i])*(xs[i] - ys[i]);
    }
    return sqrt(sum);
}

double TimeSeriesDataset::dtw(const vector<double> xs, const vector<double> ys) {
    int L = size(xs);
    //matrice L+1*L+1
    vector<std::vector<double>> D(L + 1, vector<double>(L + 1, numeric_limits<double>::infinity()));
    D[0][0] = 0.0;
    double d = 0;
    for (int i=0; i<L; i++ ) {
        for (int j=0; j<L; j++ ) {
            d += (xs[i] - ys[i])*(xs[i] - ys[i]);
            double min_prev = std::min( D[i - 1][j] ,min( D[i][j - 1], D[i - 1][j - 1]));
            D[i][j]= d+ min_prev;
        }
    }
    return sqrt(D[L][L]);
}
std::vector<double> TimeSeriesDataset::getTimeSeries(int index) {
    if (index < 0 || index >= numberOfSamples) {
        throw std::out_of_range("Index out of range");
    }
    size_t seriesLength = data.size() / numberOfSamples;
    return std::vector<double>(data.begin() + index * seriesLength, data.begin() + (index + 1) * seriesLength);
}

int TimeSeriesDataset::getLabel(int index) {
    if (index < 0 || index >= numberOfSamples) {
        throw std::out_of_range("Index out of range");
    }
    return labels[index];
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    data.insert(data.end(), series.begin(), series.end());
    labels.push_back(label);
    numberOfSamples++;
}