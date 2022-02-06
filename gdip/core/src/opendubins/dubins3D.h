/**
 * @file dubins3D.h
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 04. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include "dubins.h"
#include "state3D.h"

namespace opendubins
{
  struct Dubins3DPath {
    Dubins DubinsLat;
    Dubins DubinsLon;
    
    bool isValid{false};
  };

  class Dubins3D : public Path<State3D> {

    public:
        State3D start;
        State3D end;

        double radiusMin;

        double minPitch;
        double maxPitch;
        
        Dubins3DPath path;

        double length;

        // default constructor
        Dubins3D();

        // classical Dubins maneuver
        Dubins3D(const State3D& from, const State3D& to, const double minRadius, const double minPitch, const double maxPitch);

        ~Dubins3D() override;

        bool check();

        State3D getState(double len) const override;

        inline double getLength() const {
            return length;
        }

        inline double getMinRadius() const {
            return radiusMin;
        }

        inline double getMinPitch() const {
            return minPitch;
        }

        inline double getMaxPitch() const {
            return maxPitch;
        }

        /**
         * Find the closest state to point p on the path according to the euclidean metric.
         * It return Intersection (state and distance).
         */
        StateAtDistance<State3D> getClosestStateAndDistance(const Point &p) const override;

    private:
        // create standard Dubins maneuver
        void init(const State3D & from, const State3D & to);

        Dubins3DPath tryToConstruct(double horRadius);
    };

    std::ostream &operator<<(std::ostream &os, const Dubins3D &d);
  
} // namespace opendubins
