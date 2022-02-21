/**
 * @file hellodubins3D.cpp
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 08. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

#include "opendubins/dubins3D.h"

int main(int argc, char *argv[]) {
  std::cout << "Hello Dubins, 3D maneuver\n";
  opendubins::State3D a{1,1,0,3,-0.3};
  opendubins::State3D b{0,0,1,0,-0.3};

  opendubins::Dubins3D path(a, b, 0.1, -0.1, 0.1);
  double part{path.length / 500};
  for (int i{0}; i <= 500; ++i) {
    opendubins::State3D temp{path.getState(i * part)};
    std::cout << temp << '\n';
  }
  std::cout << path;

  return 0;
}