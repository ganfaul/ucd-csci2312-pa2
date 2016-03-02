//
// Created by Gannon Faul on 2/16/16.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Cluster.h"

namespace Clustering {

    LNode::LNode(const Point & p, LNodePtr n) : point(p), next(n){ }

    // *********************
    // FUNDAMENTAL FUNCTIONS
    // *********************
/*
    void Cluster::__del() {
        LNodePtr delPtr = __points;
        LNodePtr delHelp = nullptr;
        while(__size > 0) {
            if(__points) {
                delHelp = delPtr->next;
                delete delPtr;
                delPtr = delHelp;
            }
        }
        __points = nullptr;
    }

    void Cluster::__cpy(LNodePtr pts) {
        if (pts) {
            LNodePtr cpyPtr = nullptr;
            LNodePtr ptr = NULL;
            LNode *start = new LNode(pts->point, nullptr);
            cpyPtr = pts->next;
            __points = start;
            LNodePtr cpyHelp = __points;

            while(cpyPtr) {
                cpyHelp->next = new LNode(cpyPtr->point, nullptr);
                cpyHelp = cpyHelp->next;
                cpyPtr = cpyHelp->next;
            }

        }

    }

    bool Cluster::__in(const Point &p) const {

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
        if(&clust != this) {
            __size = clust.getSize();
            if (__size != 0) {
                __points = new LNode(clust.__points->point, nullptr);

                LNodePtr cpyPtr = __points;
                LNodePtr cpyHelp = cpyPtr;
                LNodePtr nullCheck = clust.__points->next;
                while (nullCheck) {
                    cpyPtr = new LNode(nullCheck->point, nullptr);
                    cpyHelp->next = cpyPtr;
                    cpyHelp = cpyPtr;
                    nullCheck = nullCheck->next;
                }
            } else {
                __points = nullptr;
            }
        }

    }

    // Operator Overload=
    Cluster &Cluster::operator=(const Cluster &clust) {
        if (this != &clust) {
            if(__points) {
                LNodePtr delPtr = __points;
                LNodePtr delHelp = delPtr->next;
                for (int i = 0; i < __size; i++) {
                    delete delPtr;
                    delPtr = delHelp;
                    if (delPtr->next) {
                        delHelp = delPtr->next;
                    }
                }
            }
            __points = nullptr;
            __size = 0;

            __size = clust.getSize();
            if (__size != 0) {
                __points = new LNode(clust.__points->point, nullptr);

                LNodePtr cpyPtr = __points;
                LNodePtr cpyHelp = cpyPtr;
                LNodePtr nullCheck = clust.__points->next;
                while (nullCheck) {
                    cpyPtr = new LNode(nullCheck->point, nullptr);
                    cpyHelp->next = cpyPtr;
                    cpyHelp = cpyPtr;
                    nullCheck = nullCheck->next;
                }
            } else {
                __points = nullptr;
            }

        }
    }

    // Destructors
    Cluster::~Cluster() {
        if(__points) {
            LNodePtr delPtr = __points;
            LNodePtr delHelp = delPtr->next;
            for (int i = 0; i < __size; i++) {
                delete delPtr;
                delPtr = delHelp;
                if (delPtr->next) {
                    delHelp = delPtr->next;
                }
            }
        }
        __points = nullptr;
        __size = 0;
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
        LNodePtr addPtr = __points;
        if (addPtr) {
            LNodePtr addHelp = addPtr->next;
            LNodePtr location = nullptr;
            if (addHelp) {
                if (p < addPtr->point) {
                    location = addPtr;
                }
                while (!location && addHelp) {
                    if (p > addHelp->point) {
                        addPtr = addHelp;
                    } else {
                        location = addHelp;
                    }
                    addHelp = addHelp->next;
                }
            } else {
                if (p < addPtr->point) {
                    location = addPtr;
                } else {
                    location = addHelp;
                }
            }
            addHelp = new LNode(p, location);
            addPtr->next = addHelp;
            __size++;
        } else {
            addPtr = new LNode(p, nullptr);
            __points = addPtr;
            __size = 1;
        }
        return;
    }

    const Point &Cluster::remove(const Point &p) {
        LNodePtr remPtr = __points;
        if(remPtr){
            if(remPtr->next) {
                LNodePtr remHelp = remPtr->next;
                if (remPtr->point == p) {
                    __points = remHelp;
                    __size--;
                    delete remPtr;
                    return p;
                } else {
                    while (remHelp) {
                        if(remHelp->point == p) {
                            remPtr->next = remHelp->next;
                            __size--;
                            delete remHelp;
                            return p;
                        }
                        remHelp = remHelp->next;
                    }
                }
            } else {
                if(remPtr->point == p) {
                    delete remPtr;
                    __size = 0;
                    __points = nullptr;
                    return p;
                }
            }
        }
        return p;
    }

    bool Cluster::contains(const Point &p) {
        LNodePtr crossCheck = __points;
        while(crossCheck) {
            if(p == crossCheck->point) {
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
        LNodePtr indexPtr = __points;
        while (index > 0) {
            indexPtr = indexPtr->next;
            index--;
        }
        return indexPtr->point;
    }

    // Members: Compound assignment (Point argument)
    Cluster &Cluster::operator+=(const Point &p) {
        if (!(this->contains(p))) {
            add(p);
        }
        return *this;
    }

    Cluster &Cluster::operator-=(const Point &p) {
        if (this->contains(p)) {
            remove(p);
        }
        return *this;
    }

    // Members: Compound assignment (Cluster argument)
    Cluster &Cluster::operator+=(const Cluster &c) {
        // union
        LNodePtr cPtr = c.__points;
        while (cPtr) {
            if (this->contains(cPtr->point)) {
                cPtr = cPtr->next;
            } else {
                add(cPtr->point);
                cPtr = cPtr->next;
            }
        }
        return *this;
    }

    Cluster &Cluster::operator-=(const Cluster &c) {
        // (asymmetric) difference
        LNodePtr cPtr = c.__points;
        while (cPtr) {
            if (this->contains(cPtr->point)) {
                remove(cPtr->point);
            }
            cPtr = cPtr->next;
        }
        return *this;
    }

    // *******
    // FRIENDS
    // *******

    // Friends: IO
    std::ostream &operator<<(std::ostream &out, const Cluster &c) {

    }

    std::istream &operator>>(std::istream &in, Cluster &c) {

    }

    // Friends: Comparison
    bool operator==(const Cluster &lhs, const Cluster &rhs) {
        if(lhs.getSize() == rhs.getSize()) {
            LNodePtr lhsPtr = lhs.__points;
            LNodePtr rhsPtr = rhs.__points;
            while (lhsPtr && rhsPtr) {
                if (lhsPtr->point != rhsPtr->point) {
                    return false;
                }
                lhsPtr = lhsPtr->next;
                rhsPtr = rhsPtr->next;
            }
            return true;
        }
        return false;
    }

    bool operator!=(const Cluster &lhs, const Cluster &rhs) {
        return !(lhs == rhs);
    }

    // Friends: Arithmetic (Cluster and Point)
    const Cluster operator+(const Cluster &lhs, const Point &rhs) {
        Cluster sum(lhs);
        sum += rhs;
        return sum;
    }

    const Cluster operator-(const Cluster &lhs, const Point &rhs) {
        Cluster difference(lhs);
        difference -= rhs;
        return difference;
    }

    // Friends: Arithmetic (two Clusters)
    const Cluster operator+(const Cluster &lhs, const Cluster &rhs) {
        // union
        Cluster sum(lhs);
        sum += rhs;
        return sum;
    }

    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) {
        // (asymmetric) difference
        Cluster difference(lhs);
        difference -= rhs;
        return difference;
    }


}
