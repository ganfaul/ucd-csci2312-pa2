//
// Created by Gannon Faul on 2/16/16.
//

#include<iostream>
#include<cmath>
#include<sstream>

using std::sqrt;
using std::pow;
using std::string;
using std::stringstream;
using std::stod;


#include"Point.h"
namespace Clustering {

    // Initialize ID Generator to 0
    unsigned int Point::__idGen = 0;

    // ************
    // CONSTRUCTORS
    // ************

    // Default Constructor
    Point::Point(int dimensions) {
        __dim = dimensions;
        __id = __idGen++;
        __values = new double[__dim];
        for (int i = 0; i < dimensions; i++) {
            __values[i] = 0.0;
        }
    }

    // Constructor with initial values
    Point::Point(int dimensions, double *values) {
        __dim = dimensions;
        __id = __idGen++;
        for (int i = 0; i < dimensions; i++) {
            __values[i] = values[i];
        }
    }


    // *********
    // BIG THREE
    // *********

    // Copy Constructor
    Point::Point(const Point &p) {

        if (&p != this) {
            __dim = p.__dim;
            __id = p.__id;
            __values = new double[__dim];
            for (int i = 0; i < p.getDims(); i++) {
                __values[i] = p.getValue(i);
            }
        }
    }

    // Operator Overload=
    Point &Point::operator=(const Point &p) {
        if (&p != this) {
            for (int i = 0; i < p.getDims(); i++) {
                __values[i] = p.getValue(i);
            }
            return *this;
        } else {
            return *this;
        }
    }

    // Destructor
    Point::~Point() {
        if (__values != NULL) {
            delete[] __values;
        }
        __values = NULL;
    }

    // ****************
    // MEMBER FUNCTIONS
    // ****************

    // Accessors & mutators
    int Point::getId() const {
        return __id;
    }

    int Point::getDims() const {
        return __dim;
    }

    void Point::setValue(int index, double newValue) {
        __values[index] = newValue;
    }

    double Point::getValue(int index) const {
        return __values[index];
    }

    // Distance Function
    double Point::distanceTo(const Point &p) const {

        double distance = 0.0;

        if(__dim != p.getDims()) {
            std::cout << "Points have different dimensions, cannot compute distance." << std::endl;
            return 0;
        } else {
            for (int i = 0; i < __dim; i++) {
                distance += pow((p.getValue(i) - __values[i]), 2);
            }

            distance = sqrt(distance);
            return distance;
        }
    }


    // Overloaded operators

    //Members
    Point &Point::operator*=(double factor) { // p *= 6; p.operator*=(6);
        for(int i = 0; i < __dim; i++) {
            __values[i] *= factor;
        }
        return *this;
    }

    Point &Point::operator/=(double divisor) {
        if(divisor != 0) {
            for (int i = 0; i < __dim; i++) {
                __values[i] /= divisor;
            }
        }
        return *this;
    }

    const Point Point::operator*(double factor) const { // prevent (p1 * 2) = p2;
        Point p(*this);
        p *= factor;
        return p;
    }

    const Point Point::operator/(double divisor) const { // p3 = p2 / 2;
        Point p(*this);
        p /=divisor;
        return p;
    }

    double &Point::operator[](int index) {
        return __values[index];
    }

    // Friends
    Point &operator+=(Point &lhs, const Point &rhs) {
        if (&lhs == &rhs) {
            return lhs *= 2;
        } else if (lhs.__dim == rhs.__dim) {
            for (int i = 0; i < lhs.__dim; i++)
                lhs.__values[i] += rhs.__values[i];
        }
        return lhs;
    }

    Point &operator-=(Point &lhs, const Point &rhs) {
        if (&lhs == &rhs) {
            return lhs /= 2;
        } else if (lhs.__dim == rhs.__dim) {
            for (int i = 0; i < lhs.__dim; i++)
                lhs.__values[i] -= rhs.__values[i];
        }
        return lhs;
    }

    const Point operator+(const Point &lhs, const Point &rhs) {
        Point p(lhs);
        p += rhs;
        return p;
    }

    const Point operator-(const Point &lhs, const Point &rhs) {
        Point p(lhs);
        p -= rhs;
        return p;
    }


    bool operator==(const Point &lhs, const Point &rhs) {
        if (lhs.getId() == rhs.getId()) {
            if (lhs.getDims() == rhs.getDims()) {
                for (int i = 0; i < lhs.getDims(); i++) {
                    if (lhs.getValue(i) != rhs.getValue(i)) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    bool operator!=(const Point &lhs, const Point &rhs) {
        return !(lhs == rhs);
    }


    bool operator<(const Point &lhs, const Point &rhs) {
        if (lhs != rhs) {
            if(lhs.getDims() == rhs.getDims()) {
                for (int i = 0; i < lhs.getDims(); i++) {
                    if(lhs.getValue(i) != rhs.getValue(i)) {
                        return (lhs.getValue(i) < rhs.getValue(i));
                    }
                }
            }
        }
        return false;
    }

    bool operator>(const Point &lhs, const Point &rhs) {
        return (rhs < lhs);
    }

    bool operator<=(const Point &lhs, const Point &rhs) {
        if (lhs < rhs) {
            return true;
        } else if(&lhs != &rhs) {
            if (lhs.getDims() == rhs.getDims()) {
                for (int i = 0; i < lhs.getDims(); i++) {
                    if(lhs.getValue(i) != rhs.getValue(i)) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        return true;
    }

    bool operator>=(const Point &lhs, const Point &rhs) {
        return (rhs <= lhs);
    }

    std::ostream &operator<<(std::ostream &out, const Point &p) {
        out << p.getValue(0);
        for (int i = 1; i < p.getDims(); i++) {
            out << ", " << p.getValue(i);
        }
        return out;
    }

    std::istream &operator>>(std::istream &in, Point &p) {
        int i = 0;
        string content;
        string characters;
        double value;
        while(getline(in, content)) {
            stringstream contentIn(content);
            while (getline(contentIn, characters, ',')){
                value = stod(characters);
                p.setValue(i++, value);

            }
        }
        return in;
    }


}