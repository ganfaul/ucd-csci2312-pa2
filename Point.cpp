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
    Point::Point &operator=(const Point &) {

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
            std::cout << "Points have different dimensions, cannot compute distance." << endl;
            return 0;
        }

        for (int i = 0; i < __dim; i++) {
            distance += pow(())
        }
    }

// Overloaded operators

// Members
Point &operator*=(double); // p *= 6; p.operator*=(6);
Point &operator/=(double);
const Point operator*(double) const; // prevent (p1 * 2) = p2;
const Point operator/(double) const; // p3 = p2 / 2;

double &operator[](int index);

// Friends
friend Point &operator+=(Point &, const Point &);
friend Point &operator-=(Point &, const Point &);
friend const Point operator+(const Point &, const Point &);
friend const Point operator-(const Point &, const Point &);

friend bool operator==(const Point &, const Point &);
friend bool operator!=(const Point &, const Point &);

friend bool operator<(const Point &, const Point &);
friend bool operator>(const Point &, const Point &);
friend bool operator<=(const Point &, const Point &);
friend bool operator>=(const Point &, const Point &);

friend std::ostream &operator<<(std::ostream &, const Point &);
friend std::istream &operator>>(std::istream &, Point &);


}