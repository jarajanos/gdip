/**
 * @file path.h
 * @author Petr Vana
 * @brief Path is an abstract class for Line and Arc which are basic segments in Dubins maneuver.
 */


#pragma once

#include "state.h"
#include "stateatdistance.h"

namespace opendubins {

    template <class T>
    class Path {
    public:
        Path() {
        }

        virtual ~Path() {
        }

    public:
        virtual double getLength() const = 0;

        virtual T getState(double len) const = 0;

        virtual T getStart() const {
            return getState(0);
        }

        virtual T getEnd() const {
            return getState(getLength());
        }

        /**
         * Get the closest state to point p on the path according to the Euclidean metric.
         * It invokes function getClosestIntersection(const Point &p) and return only state.
         */
        virtual T getClosestState(const Point &p) const {
            return getClosestStateAndDistance(p).state;
        }

        /**
         * Find the closest state to point p on the path according to the euclidean metric.
         * It return Intersection (state and distance).
         */
        virtual StateAtDistance<T> getClosestStateAndDistance(const Point &p) const = 0;
    };

}
