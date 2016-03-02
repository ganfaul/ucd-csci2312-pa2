//
// Created by Gannon Faul on 2/16/16.
//

#include <iostream>
#include <string>
#include <sstream>
#include "Cluster.h"

using std::string;
using std::stringstream;

namespace Clustering {

    typedef Point * PointPtr;

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
        return *this;
    }

    // Destructors
    Cluster::~Cluster() {
        if(__points != nullptr) {
            LNodePtr delPtr = __points;
            LNodePtr delHelp = nullptr;
            for (int i = 0; i < __size; i++) {
                if (__points != nullptr) {
                   delHelp = delPtr->next;
                   delete delPtr;
                   delPtr = delHelp;

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
        LNodePtr addPtr = new LNode(p, nullptr);
        if (!__points) {
            __points = addPtr;
            __size++;
            return;
        } else if (!__points->next) {
            if(addPtr->point < __points->point){
                addPtr->next = __points;
                __points = addPtr;
                __size++;
                return;
            } else {
                __points->next = addPtr;
                __size++;
                return;
            }
        }
        LNodePtr addHelp = __points->next;
        LNodePtr holder = __points;
        if(addPtr->point < __points->point){
            __points = addPtr;
            addPtr->next = holder;
            __size++;
            return;
        } else if (addPtr->point < addHelp->point){
            holder->next = addPtr;
            addPtr->next = addHelp;
            __size++;
            return;
        }
        while (addHelp->next != nullptr) {
            if (addPtr->point < addHelp->point){
                holder = addPtr;
                addPtr->next = holder;
                __size++;
                return;
            }
            addHelp = addHelp->next;
            holder = holder->next;
        }
        addHelp->next = addPtr;
        __size++;
    }

    const Point &Cluster::remove(const Point &p) {
        LNodePtr remPtr = __points;
        if (__points->point != p) {
            LNodePtr remHelp = remPtr;
            remPtr = remPtr->next;

            for (int i = 0; i < __size; i++) {
                if (remPtr->point == p) {
                    if (remPtr->next == nullptr) {
                        remHelp->next = nullptr;
                        delete remPtr;
                        __size--;
                    } else {
                        remHelp->next = remPtr->next;
                    }
                }
                remPtr = remPtr->next;
                remHelp = remHelp->next;
            }
        } else {
            remPtr = __points;
            if (__size > 0) {
                __points = __points->next;
                --__size;
            }
            delete remPtr;
        }
        return p;
    }

    bool Cluster::contains(const Point &p) {
        LNodePtr containCheck = __points;
        bool contain = false;
        while (containCheck) {
            if(containCheck->point == p) {
                contain = true;
            }
            containCheck = containCheck->next;
        }
        return contain;
    }


    // Overloaded operators

    // Members: Subscript
    const Point &Cluster::operator[](unsigned int index) const {
        // notice: const
        LNodePtr indexPtr = __points;
        if(index != 0) {
            for (int i = 0; i < index; i++) {
                indexPtr = indexPtr->next;
            }
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
        LNodePtr outPtr = c.__points;
        while (outPtr) {
            out << outPtr->point;
            out << std::endl;
            outPtr = outPtr->next;
        }
        return out;
    }

    std::istream &operator>>(std::istream &in, Cluster &c) {
        return in;
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
