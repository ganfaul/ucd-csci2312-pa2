//
// Created by Gannon Faul on 2/16/16.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Cluster.h"

namespace Clustering {

    LNode::LNode(const Point & p, LNodePtr n) : point(p), next(n){ }
/*
    // *********************
    // FUNDAMENTAL FUNCTIONS
    // *********************

    void Cluster::__del() {
        if (__size != 0 && __points != NULL) {
            if (!(__points->next)) {
                __size = 0;
                delete __points;
                return;
            }
            LNodePtr delPtr = __points;
            LNodePtr delHelp = NULL;
            while(delPtr) {
                if (delPtr->next) {
                    LNodePtr delHelp = delPtr->next;
                }
                delete delPtr;
                delPtr = delHelp;
            }
            __size = 0;
            return;
        } else {
            return;
        }
    }

    void Cluster::__cpy(LNodePtr pts) {
        if (pts != NULL) {
            LNodePtr cpyPtr = pts;
            LNodePtr
        }

    }

    bool __in(const Point &p) const {

    }
*/
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
        if (&clust != this) {
            if (clust.__points != nullptr) {
                __size = clust.__size;
                LNodePtr cpyPtr = clust.__points;
                __points = new LNode(cpyPtr->point, NULL);
                LNodePtr nextPtr = NULL;
                LNodePtr c = __points;
                while(cpyPtr->next) {
                    nextPtr = cpyPtr->next;
                    c->next = new LNode(nextPtr->point, NULL);
                    cpyPtr = nextPtr;
                }

            } else {
                __size = 0;
                __points = nullptr;
            }
        }
    }

    // Operator Overload=
    Cluster &Cluster::operator=(const Cluster &clust) {
        __points = clust.__points;
        __size = clust.__size;
    }

    // Destructors
    Cluster::~Cluster() {
        LNodePtr delPtr;
        while (__points) {
            delPtr = __points;
            __points = delPtr->next;
            delete delPtr;
        }
    }

    // ****************
    // MEMBER FUNCTIONS
    // ****************

    // Accessors and Mutators
    int Cluster::getSize() const {
        return __size;
    }

    // Set functions: They allow calling c1.add(c2.remove(p));
    void Cluster::add(const Point &p) {
        if (__size != 0) {
            if (!contains(p)) {
                LNodePtr newNodePtr = __points;
                LNodePtr nullCheck = nullptr;
                while (newNodePtr) {
                    if (p < newNodePtr->point) {
                        if (nullCheck) {
                            nullCheck->next = new LNode(p, newNodePtr);
                            __size++;
                            return;
                        } else {
                            __points = new LNode(p, newNodePtr);
                            __size++;
                            return;
                        }
                    }
                    nullCheck = newNodePtr;
                    newNodePtr = newNodePtr->next;
                }
            } else {
                return;
            }
        } else {
            __points = new LNode(p, nullptr);
            __size++;
            return;
        }
    }

    const Point &Cluster::remove(const Point &p) {

    }

    bool Cluster::contains(const Point &p) {
        LNodePtr crossCheck = __points;
        while(crossCheck) {
            if(p.getId() == crossCheck->point.getId()) {
                return true;
            }
            crossCheck = crossCheck->next;
        }
        return false;
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
*/

}
