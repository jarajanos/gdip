/**
 * @file state3D.h
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 04. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include "point3d.h"

namespace opendubins {
  class State3D final {
    public:
      Point3D point;
      double heading;
      double pitch;

      State3D();

      State3D(Point3D, double, double);

      State3D(double, double, double, double, double);

      inline void set(double x, double y, double z, double heading, double pitch) {
          this->point.x = x;
          this->point.y = y;
          this->point.z = z;
          this->heading = heading;
          this->pitch = pitch;
      }

      void random(double);

      inline bool invalid() {
          return std::isnan(heading) && std::isnan(pitch);
      }

      static State3D getInvalid() {
          return State3D(Point3D::getInvalid(), GDIP_NAN, GDIP_NAN);
      }

      inline bool isValid() const {
          return (!std::isnan(heading)) && (!std::isnan(pitch)) && point.isValid();
      }

      inline Point3D getPoint() const { return point; }

      inline double getHeading() const { return heading; }

      inline double getPitch() const { return pitch; }

      inline double squared_distance(const State3D &p) const {
          return point.distanceSquared(p.point);
      }

      inline State3D reverse() const{
        State3D st = *this;
        st.heading = angleToLeft(0, heading + M_PI);
        return st;
      }
  };

  std::ostream &operator<<(std::ostream &os, const State3D &d);
}