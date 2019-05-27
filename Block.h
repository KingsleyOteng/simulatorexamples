/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Block.h
 * Author: Kwadwo Oteng-Amoako
 *
 * Created on April 29, 2019, 7:30am
 */
#pragma once
#ifndef BLOCK_H
#define BLOCK_H
#include <string>
#include <numeric>
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>


//using namespace std

class Block {
public:
    Block();
    Block(const Block& orig);
    Block(int a, int b);
    virtual ~Block();
    
    static double means;
    static double stdevs; 
    static double valued;
    static double samplingerrorrate;
    static int minimumRuns;
    static int simulatorMode;
    static std::vector<double> sampleCohort;
    
    
    

    //setters
    void setMean();
    

    void setStdDev();
    
    
    void setNumRuns();
    
    
    void setSimulationType(int simulatorRuns);
    
    
    void setSampleCohort(std::vector<double> sample);
   
    
    //getters
    double getMean();
   
    
    double getStdDev();
    
    
    double getSampleMean(std::vector<double> sample);
    
    
    double getSampleStdDev(std::vector<double> sample);
   
    
    double getSampleStdDev2(std::vector<double> sample);
    
    
    int getNumRuns();
    
    
    int getSimulationType();
    
    
    void start();
    
    
    static std::string newHashSignet;
    std::vector<Block> blockChain;
    
    
    

    
   
   

    
private:
    std::string message;
    long timeStamp;
    int nonce;
    
    
    /**
     *
     */
    
    

};

#endif /* BLOCK_H */

