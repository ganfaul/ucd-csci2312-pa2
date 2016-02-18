//
// Created by Gannon Faul on 2/16/16.
//

#include<iostream>
#include<cmath>

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
        for (int i = 0; i < dimensions; i++) {
            *__values = 0;
            __values++;
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
    // Big three: cpy ctor, overloaded operator=, dtor

    // Copy Constructos
    Point::Point(const Point &p) {
        __dim = p.getDims();
        __id = __idGen++;
        for (int i = 0; i < p.getDims(); i++) {
            __values[i] = p.getValue(i);
        }
    }

    // Operator Overload (Testing address)
    bool Point::Point &operator=(const Point &p) {
        __dim = p.getDims();

    }

    // Destructor
    Point::~Point() {

    }


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

// Functions
    double Point::distanceTo(const Point &p) const {

        double distance = 0;

        if(__dim != p.getDims()) {
            std::cout << "Points have different dimensions, cannot compute distance." << std::endl;
            return 0;
        }

        for (int i = 0; i < __dim; i++) {
            distance += pow((p.getValue(i) - __values[i]), 2);
        }
    }

// Overloaded operators

// Members
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
            return Point(*this) *= factor;
    }

    const Point Point::operator/(double divisor) const { // p3 = p2 / 2;
        return Point(*this) /= divisor;
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

    }

    const Point operator+(const Point &lhs, const Point &rhs) {
        Point p(lhs);
        return p += rhs;
    }

    const Point operator-(const Point &lhs, const Point &rhs) {

    }


    bool operator==(const Point &lhs, const Point &rhs) {

    }

    bool operator!=(const Point &lhs, const Point &rhs) {

    }


    bool operator<(const Point &lhs, const Point &rhs) {

    }

    bool operator>(const Point &lhs, const Point &rhs) {

    }

    bool operator<=(const Point &lhs, const Point &rhs) {

    }

    bool operator>=(const Point &lhs, const Point &rhs) {

    }


    std::ostream &operator<<(std::ostream &, const Point &) {

    }

    std::istream &operator>>(std::istream &, Point &) {

    }


}