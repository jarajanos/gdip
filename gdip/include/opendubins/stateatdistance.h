/**
 * @file stateatdistance.h
 * @author Petr Vana
 * @brief Auxiliary structure for returning informations about intersections.
 */

#pragma once

#include "state.h"

namespace opendubins {

    template <class T>
    struct StateAtDistance {

        T state;
        double distance;

        StateAtDistance() {
            state = T();
            distance = GDIP_NAN;
        }

        StateAtDistance(T state, double distance) {
            this->state = state;
            this->distance = distance;
        }

        bool isValid() const {
            return ! std::isnan(distance);
        }

    };

}
