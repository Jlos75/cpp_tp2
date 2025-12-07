//
// Created by jeann on 02/12/2025.
//

#include "KNN.h"#include <vector>
#include <algorithm>
#include <stdexcept>
#include "TimeSeriesDataset.h"
#include <string>
using namespace std;

KNN::KNN(int k, string sm): k(k),similarity_measure(sm) {
}

double KNN::evaluate(TimeSeriesDataset& trainSet, TimeSeriesDataset& testSet, vector<int>& testLabels) {
    int correct=0;
    double accuracy = 0.0;
    if (similarity_measure == "euclidean_distance") {
        for (size_t i = 0; i < testSet.numberOfSamples; i++) {
            vector<pair<double, int>> distances;
            vector<double> testSeries = testSet.getTimeSeries(i);
            for (size_t j = 0; j < trainSet.numberOfSamples; j++) {
                vector<double> trainSeries = trainSet.getTimeSeries(j);
                double dist = trainSet.euclidean_distance(testSeries, trainSeries);
                distances.push_back({ dist, trainSet.getLabel(j) });
            }
            sort(distances.begin(), distances.end());
            vector<int> votes;
            for (int n = 0; n < k; n++) {
                votes.push_back(distances[n].second);
            }
            int predictedLabel = *max_element(votes.begin(), votes.end(),
                [&votes](int a, int b) {
                    return count(votes.begin(), votes.end(), a) < count(votes.begin(), votes.end(), b);
                });
            if (predictedLabel == testLabels[i]) {
                correct++;
            }
        }
    } else if (similarity_measure == "dtw") {
        for (size_t i = 0; i < testSet.numberOfSamples; i++) {
            vector<pair<double, int>> distances;
            vector<double> testSeries = testSet.getTimeSeries(i);
            for (size_t j = 0; j < trainSet.numberOfSamples; j++) {
                vector<double> trainSeries = trainSet.getTimeSeries(j);
                double dist = trainSet.dtw(testSeries, trainSeries);
                distances.push_back({ dist, trainSet.getLabel(j) });
            }
            sort(distances.begin(), distances.end());
            vector<int> votes;
            for (int n = 0; n < k; n++) {
                votes.push_back(distances[n].second);
            }
            int predictedLabel = *max_element(votes.begin(), votes.end(),
                [&votes](int a, int b) {
                    return count(votes.begin(), votes.end(), a) < count(votes.begin(), votes.end(), b);
                });
            if (predictedLabel == testLabels[i]) {
                correct++;
            }
        }
    } else {
        throw invalid_argument("Unsupported similarity measure");
    }

    accuracy = static_cast<double>(correct) / testSet.numberOfSamples;
    return accuracy;
}