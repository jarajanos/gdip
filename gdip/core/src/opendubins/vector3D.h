/**
 * @file vector3D.h
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 04. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once 

#include "dmath.h"

namespace opendubins {

    class Vector3D {
    public:

        double dx; 
        double dy;
        double dz;

        Vector3D(double x, double y, double z) :
                dx(x), dy(y), dz(z) {
        }

        static Vector3D getInvalid(){
            return Vector3D(GDIP_NAN, GDIP_NAN, GDIP_NAN);
        }

        inline bool isValid() const{
            return (!std::isnan(dx)) && (!std::isnan(dy)) && (!std::isnan(dz));
        }

        inline Vector3D negate() const {
            return Vector3D(-dx, -dy, -dz);
        }

        inline double length() const {
            return std::sqrt(lengthSquared());
        }

        inline double lengthSquared() const {
            return dx * dx + dy * dy + dz * dz;
        }

        inline Vector3D normalize() const {
            double len = this->length();
            return Vector3D(dx / len, dy / len, dz / len);
        }

        inline double dotProduct(const Vector3D &vec) const {
            return dx * vec.dx + dy * vec.dy + dz * vec.dz;
        }

        inline Vector3D &operator*=(const double &mult) {
            dx *= mult;
            dy *= mult;
            dz *= mult;
            return *this;
        }

        inline Vector3D &operator+=(const Vector3D &rght) {
            dx += rght.dx;
            dy += rght.dy;
            dz += rght.dz;
            return *this;
        }
    };

    inline Vector3D operator+(const Vector3D &left, const Vector3D &right) {
        return Vector3D(left.dx + right.dx, left.dy + right.dy, left.dz + right.dz);
    }

    inline Vector3D operator*(const Vector3D &left, const double &right) {
        return Vector3D(left.dx * right, left.dy * right, left.dz * right);
    }

    inline Vector3D operator*(const double &left, const Vector3D &right) {
        return Vector3D(right.dx * left, right.dy * left, right.dz * left);
    }

}