/**
 * @file dubins3D.cpp
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 04. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "dubins3D.h"

namespace opendubins
{
  Dubins3D::Dubins3D() : radiusMin{GDIP_NAN}, maxPitch{GDIP_NAN}, minPitch{GDIP_NAN},
    length{std::numeric_limits<double>::max()} {

    }

  Dubins3D::~Dubins3D() { }

  bool Dubins3D::check() {
    return false;
  }

  State3D Dubins3D::getState(double len) const {
    State lonState{this->path.DubinsLon.getState(len)};

    double latLen{lonState.getPoint().getX()};
    State latState{this->path.DubinsLat.getState(latLen)};
    return State3D(latState.getPoint().getX(), 
                   latState.getPoint().getY(), 
                   lonState.getPoint().getY(), 
                   latState.getAngle(), 
                   lonState.getAngle());
  }
  
  StateAtDistance<State3D> Dubins3D::getClosestStateAndDistance(const Point &p) const {
    throw "Not implemented!";
    return StateAtDistance<State3D>();
  }

  std::ostream &operator<<(std::ostream &os, const Dubins3D &d) {
    os << "Dubins maneuver 3D, TODO";
    return os;
  }

} // namespace opendubins
