//
// Created by jeann on 24/11/2025.
//

#include "SinWaveGenerator.h"
#include <cmath>
SinWaveGenerator::SinWaveGenerator(): TimeSeriesGenerator() {};
SinWaveGenerator::SinWaveGenerator(int _seed,double _A,double _w,double _phi):
TimeSeriesGenerator(_seed), amplitude(_A), freq(_w), ph_init(_phi){

}

vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    vector<double> out;
    for (int i; i<size; i++) {
        out.push_back(amplitude*sin(freq*i+ph_init));
    }
    return out;
}
