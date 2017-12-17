//-*-c++-*------------------------------------------------------------
//
// File name : bioStochasticGradient.h
// Author :    Michel Bierlaire
// Date :      Mon Jul  3 20:21:37 2017
//
//--------------------------------------------------------------------

#ifndef bioStochasticGradient_h
#define bioStochasticGradient_h

#include <vector>
#include "patError.h"
#include "patVariables.h"
#include "patIteratorErr.h"

class bioStochasticGradientFunction ;

class bioFunctionAndDerivatives ;

class bioStochasticGradient {
 public:
  bioStochasticGradient(bioStochasticGradientFunction* f, patError*& err) ;
  void init(patVariables x0, patError*& err) ;
  void run(patError*& err) ;
  patVariables getSolution() const ;
  patVariables getSolution() ;
 private:
  void onePass(patError*& err) ;
  void updateIterate(patVariables& gradient) ;
 private:
  bioStochasticGradientFunction* theFunction ;
  patVariables currentIterate ;
  vector<patVariables> listOfGradients ;
  patReal stepSize ;
  patReal stepSizeFactor ;
  patULong numberOfPasses ;
};
#endif