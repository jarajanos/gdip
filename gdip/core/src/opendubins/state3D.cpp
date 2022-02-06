/**
 * @file state3D.cpp
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 04. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "state3D.h"

namespace opendubins {

    State3D::State3D() {
        this->point = Point3D(0, 0, 0);
        this->heading = GDIP_NAN;
        this->pitch = GDIP_NAN;
    }

    State3D::State3D(Point3D point, double heading, double pitch) {
        this->point = point;
        this->heading = heading;
        this->pitch = pitch;
    }

    State3D::State3D(double x, double y, double z, double heading, double pitch) {
        this->point = Point3D(x, y, z);
        this->heading = heading;
        this->pitch = pitch;
    }

    void State3D::random(double interval) {
        this->point = Point3D(myRandom() * interval, myRandom() * interval, myRandom() * interval);
        this->heading = myRandom() * 2 * M_PI;
        this->pitch = myRandom() * 2 * M_PI;
    }

    std::ostream &operator<<(std::ostream &os, const State3D &pos) {
        Point3D p = pos.getPoint();
        os << "(" << p.x << ", " << p.y << ", " << p.z << ", " << pos.getHeading() << ", " << pos.getPitch() << ")";
        return os;
    }

}
