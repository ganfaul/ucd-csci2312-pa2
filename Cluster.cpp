//
// Created by Gannon Faul on 2/16/16.
//
/*
#include <iostream>
#include <string>
#include <sstream>
#include "Cluster.h"

namespace Clustering {

    LNode::LNode(const Point & p, LNodePtr n):point(p) {
        point = p;
        n = next;
    }

    // ************
    // CONSTRUCTORS
    // ************

    // Default Constructor
    Cluster::Cluster() {
        __size = 0;
        __points = nullptr;
    }

    // *********
    // BIG THREE
    // *********

    // Copy Constructor
    Cluster::Cluster(const Cluster &clust) {
        if(&clust != this) {
            if (clust.__points != nullptr) {
                __size = 0;

            } else {
                __size = 0;
                __points = nullptr;
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
    int Cluster::getSize() const { // TODO add to the requirements
        return __size;
    }

    // Set functions: They allow calling c1.add(c2.remove(p));
    void Cluster::add(const Point &p) { // TODO add asc order to the requirements

    }

    const Point &Cluster::remove(const Point &p) {

    }

    bool Cluster::contains(const Point &p) {

    }


    // Overloaded operators

    // Members: Subscript
    const Point &Cluster::operator[](unsigned int index) const {
        // notice: const
    }

    // Members: Compound assignment (Point argument)
    Cluster &Cluster::operator+=(const Point &) {

    }

    Cluster &Cluster::operator-=(const Point &) {

    }

    // Members: Compound assignment (Cluster argument)
    Cluster &Cluster::operator+=(const Cluster &) {
        // union
    }

    Cluster &Cluster::operator-=(const Cluster &) {
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