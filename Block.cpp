/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Block.cpp
 * Author: Kwadwo Oteng-Amoako
 * 
 * Created on April 26, 2019, 12:59 PM
 */

#include "Block.h"
#include <string>
#include <stdlib.h>
#include <numeric>
#include <map> 
#include <math.h> /* sqrt */
#include <iostream> /* endl, cout */ 

//constructors
Block::Block() {
}

Block::Block(const Block& orig) {
}

Block::Block(int a, int b) {
}

// authored methods
void setMean(double adjMean){                             //set the  sample mean for the simulator
    Block::means = adjMean;
}
void setStdDev(double adjStdDev){                         //set the sample standard deviation for the simulator
    Block::stdevs = adjStdDev;
}
void setNumRuns(int simulatorRuns){                       //set the minimum number of simulator runs
    Block::minimumRuns = simulatorRuns;
}
void setSimulationType(int simulatorType){        //set the simulator type
    Block::simulatorMode = simulatorType;
}
void setSampleCohort(std::vector<double> sample){         //set the cohort
    Block::sampleCohort = sample;
}

double Block::getMean(){                                    //return a double for the sample mean
    return  Block::means;
}
double Block::getStdDev(){                                  //return a double for the standard deviation
    return  Block::stdevs;
}
int Block::getNumRuns(){                                    //return an integer for minimum number of runs
    return  Block::minimumRuns;
}
int Block::getSimulationType(){                     //return a string for the simulator type    
    return  Block::simulatorMode;
}
double Block::getSampleMean(std::vector<double> sample){
    double samplemean = 0x0;
    double samplestddev = 0x0;
    
    auto lambda = [&](double a, double b)
        {return a + b / sample.size();};
        
    return   std::accumulate(sample.begin(), sample.end(), 0.0, lambda);
    
   
}

double Block::getSampleStdDev(std::vector<double> sample){
    double accumulator = 0x0;
    double sum = std::accumulate(std::begin(sample), std::end(sample), 0.0);
    double meaned = sum / sample.size();
    
    std::for_each (std::begin(sample), std::end(sample), [&](const double d) { accumulator += (d - meaned ) * (d - meaned);});
    return sqrt(accumulator / (sample.size() - 1));
}

double Block::getSampleStdDev2(std::vector<double> sample){
    double accumulator = 0x0;
    double samplemean = 0x0;
    double samplestddev = 0x0;
    
    auto lambda = [&](double a, double b)
        {return a + b / sample.size();};
        
    double meaned =   std::accumulate(sample.begin(), sample.end(), 0.0, lambda);
    std::for_each (std::begin(sample), std::end(sample), [&](const double d) { accumulator += (d - meaned ) * (d - meaned);});
    return sqrt(accumulator / (sample.size() - 1));
   
}



void Block::start()
{
    double value = 0.0;
    std::vector<double> cohort = this->sampleCohort;
    std::vector<double> sampledresult;
    
    switch(this->simulatorMode) {
        case 0 : //bootstrap mode
            for (int rounding = 0 ; rounding <= this->minimumRuns ; rounding++)
                {
                    
                    int point_sample = rand() % (cohort.size()  + 1);
                    
                    //value = value + sampleCohort[point_sample];
                    sampledresult[rounding] = sampleCohort[point_sample];
                }
                
            break;
            
        default :
            
            std::cout << "model unknown" << std::endl;
            break;
    }        
    
    // generate the value as the mean of the sum of sample runs; (\sum_{i=0}^N x_i) / N
    this->valued = this->getSampleMean(sampledresult);
    
    // generate the error rate of the sample; (\sum_{i=0}^N x_i) / N^0.5
    this->samplingerrorrate = this->getSampleStdDev(sampledresult) / this->minimumRuns;
    
};

//destructors
Block::~Block() {
}



