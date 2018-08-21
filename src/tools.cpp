#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
                                
  VectorXd rmse(4);
  rmse << 0,0,0,0;

  // check that the inputs are of correct size. 
  if (estimations.size() != ground_truth.size()) {
    cout << "Size of estimation != size of ground truth" << endl;
    return rmse;
  } 
  if (estimations.size() == 0) {
    cout << "Estimations size is 0" << endl;
    return rmse;
  }

  for (unsigned int i = 0; i < estimations.size(); i++) {
    VectorXd res = estimations[i] - ground_truth[i];
    res = res.array()*res.array();
    rmse += res;
  }
  
  rmse = rmse/estimations.size();
  rmse = rmse.array().sqrt();
 
  return rmse;
}