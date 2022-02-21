/**
 * @file dubinsmaneuver3D.cpp
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief Based on https://github.com/comrob/Dubins3D.jl/blob/master/src/dubinsmaneuver3d.jl
 * @version 1.0
 * @date 04. 02. 2022
 * 
 */

#include "dubins3D.h"

namespace opendubins
{
  Dubins3D::Dubins3D(const State3D& from, const State3D& to, const double minRadius, const double minPitch, const double maxPitch) {
    this->radiusMin = minRadius;
    this->minPitch = minPitch;
    this->maxPitch = maxPitch;
    
    this->start = from;
    this->end = to;

    this->length = std::numeric_limits<double>::max();
    
    init(from, to);
  } 

  void Dubins3D::init(const State3D & from, const State3D & to) {
    double dz{to.point.getZ() - from.point.getZ()};

    double mult{1.0};

    Dubins3DPath trial{tryToConstruct(radiusMin * mult)};

    while (!trial.isValid && mult <= 1024) {
      mult *= 2;
      trial = tryToConstruct(radiusMin * mult);
    }

    if (!trial.isValid) {
      return; // no manuever exists
    }

    // local optimalization
    double step{0.1};
    while (std::abs(step) > EPS) {
      double mult2{mult + step};
      mult2 = std::max(mult2, 1.0);

      Dubins3DPath trial2{tryToConstruct(radiusMin * mult2)};
      if (trial2.isValid) {
        if (trial2.DubinsLon.getLength() < trial.DubinsLon.getLength()) {
          mult = mult2;
          trial = std::move(trial2);
          step = step * 2;
          continue;
        }
      }
      step = step * -0.1;
    }

    this->length = trial.DubinsLon.getLength();
    this->path = std::move(trial);
  }

  Dubins3DPath Dubins3D::tryToConstruct(double horRadius) {
    Dubins3DPath retVal;

    State from2D {this->start.point.getX(), this->start.point.getY(), this->start.getHeading()};
    State to2D {this->end.point.getX(), this->end.point.getY(), this->end.getHeading()};
    retVal.DubinsLat = Dubins(from2D, to2D, horRadius);

    // horizontal axis
    State from3D {0, this->start.point.getZ(), this->start.getPitch()};
    State to3D {retVal.DubinsLat.getLength(), this->end.point.getZ(), this->end.getPitch()};

    // check eligibility
    double vertCurve{std::sqrt(1 / POW(this->radiusMin) - 1 / POW(horRadius))};
    if (vertCurve < EPS) {
      return retVal;
    }

    double vertRadius{1 / vertCurve};
    retVal.DubinsLon = Dubins(from3D, to3D, vertRadius);

    if (retVal.DubinsLon.getType() == DType::RLR) {
      return retVal;
    }

    if (retVal.DubinsLon.getType() == DType::RSL || retVal.DubinsLon.getType() == DType::RSR) {
      if (this->start.getPitch() - retVal.DubinsLon.getLen1() < this->minPitch) {
        return retVal;
      }
    } else {
      if (this->start.getPitch() + retVal.DubinsLon.getLen1() > this->maxPitch) {
        return retVal;
      }
    }
    
    retVal.isValid = true;
    return retVal;
  }

} // namespace opendubins
