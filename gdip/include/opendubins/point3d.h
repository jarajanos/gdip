/**
 * @file point3d.h
 * @author Jaroslav Janos (janosjar@fel.cvut.cz)
 * @brief 
 * @version 1.0
 * @date 04. 02. 2022
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include "vector3D.h"

namespace opendubins {
    class Point3D {
    public:

        double x;
        double y;
        double z;

        Point3D() {
            x = 0;
            y = 0;
            z = 0;
        }

        Point3D(double x, double y, double z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        inline double getX() const {
            return x;
        }

        inline double getY() const {
            return y;
        }

        inline double getZ() const {
            return z;
        }

        static Point3D getInvalid(){
            return Point3D(GDIP_NAN, GDIP_NAN, GDIP_NAN);
        }

        inline bool isValid() const{
            return (!std::isnan(x)) && (!std::isnan(y)) && (!std::isnan(z));
        }

        inline Vector3D operator-(const Point3D &r) const {
            return Vector3D(x - r.x, y - r.y, z - r.z);
        }

        inline Point3D operator+(const Vector3D &right) const {
            return Point3D(x + right.dx, y + right.dy, z + right.dz);
        }

        inline Point3D operator-(const Vector3D &right) const {
            return Point3D(x - right.dx, y - right.dy, z - right.dz);
        }

        inline Point3D &operator+=(const Vector3D &rhs) {
            this->x += rhs.dx;
            this->y += rhs.dy;
            this->z += rhs.dz;
            return *this;
        }

        inline Point3D &operator+=(const Point3D &rhs) {
            this->x += rhs.x;
            this->y += rhs.y;
            this->z += rhs.z;
            return *this;
        }

        inline Point3D &operator-=(const Vector3D &rhs) {
            this->x -= rhs.dx;
            this->y -= rhs.dy;
            this->z -= rhs.dz;
            return *this;
        }

        inline Point3D &operator-=(const Point3D &rhs) {
            this->x -= rhs.x;
            this->y -= rhs.y;
            this->z -= rhs.z;
            return *this;
        }

        inline Point3D operator+(const Point3D &right) const {
            return Point3D(x + right.x, y + right.y, z + right.z);
        }

        inline Point3D operator/(const double div) const {
            if (div != 0)
                return Point3D(x / div, y / div, z / div);
            else
                return Point3D();
        }

        inline double distance(const Point3D &to) const {
            return (*this - to).length();
        }

        inline double distanceSquared(const Point3D &to) const {
            return (*this - to).lengthSquared();
        }

        inline Point3D interpolate(const Point3D &p, double &alpha) const {
            double beta = 1 - alpha;
            return Point3D(beta * x + alpha * p.x, beta * y + alpha * p.y, beta * z + alpha * p.z);
        }

        inline bool operator==(const Point3D &b) const {
            return (x == b.x) && (y == b.y) && (z == b.z);
        }

        inline size_t hash() const {
            auto h1 = std::hash<double>()(x);
            auto h2 = std::hash<double>()(y);
            auto h3 = std::hash<double>()(z);
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };

    inline std::ostream &operator<<(std::ostream &os, const Point3D &d) {
        os << "Point: (" << d.x << ", " << d.y  << ", " << d.z << ")";
        return os;
    }
}
