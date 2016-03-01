//
// Created by Gannon Faul on 2/16/16.
//
/*
#include <iostream>


#include "Cluster.h"

namespace Clustering {

    typedef Point * PointPtr;

    // ************
    // CONSTRUCTORS
    // ************

    // Default Constructor
    Cluster::Cluster() {
        __size = 0;
        __points = NULL;
    }

    // *********
    // BIG THREE
    // *********

    // Copy Constructor
    Cluster::Cluster(const Cluster &clust) {
        if(&clust != this) {
            if (clust.__points != NULL) {
                __size = 0;

            } else {
                __size = 0;
                __points = NULL;
            }
        }
    }

    // Operator Overload=
    Cluster &Cluster::operator=(const Cluster &clust) {
        if
    }

    // Destructors
    Cluster::~Cluster() {

    }

    // ****************
    // MEMBER FUNCTIONS
    // ****************

    // Accessors and Mutators
    int getSize() const { // TODO add to the requirements

    }

    // Set functions: They allow calling c1.add(c2.remove(p));
    void add(const Point &) { // TODO add asc order to the requirements

    }

    const Point &remove(const Point &) {

    }

    bool contains(const Point &) {

    }


    // Overloaded operators

    // Members: Subscript
    const Point &operator[](unsigned int index) const {
        // notice: const
    }

    // Members: Compound assignment (Point argument)
    Cluster &operator+=(const Point &) {

    }

    Cluster &operator-=(const Point &) {

    }

    // Members: Compound assignment (Cluster argument)
    Cluster &operator+=(const Cluster &) {
        // union
    }

    Cluster &operator-=(const Cluster &) {
        // (asymmetric) difference
    }

    // *******
    // FRIENDS
    // *******

    // Friends: IO
    std::ostream &operator<<(std::ostream &, const Cluster &) {

    }

    std::istream &operator>>(std::istream &, Cluster &) {

    }

    // Friends: Comparison
    bool operator==(const Cluster &, const Cluster &) {

    }

    bool operator!=(const Cluster &, const Cluster &) {

    }

    // Friends: Arithmetic (Cluster and Point)
    const Cluster operator+(const Cluster &, const Point &) {

    }

    const Cluster operator-(const Cluster &, const Point &) {

    }

    // Friends: Arithmetic (two Clusters)
    const Cluster operator+(const Cluster &, const Cluster &) {
        // union
    }

    const Cluster operator-(const Cluster &, const Cluster &) {
        // (asymmetric) difference
    }

}
 */