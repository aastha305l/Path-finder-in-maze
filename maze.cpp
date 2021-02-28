//Name: Aastha Lamichhane
//File: maze.cpp

#include "maze.h"

int Cell::getR() { return this->r_; }
int Cell::getC() { return this->c_; }
void Cell::setR(int r) { this->r_ = r; }
void Cell::setC(int c) { this->c_ = c; }
Cell PunchedWall::getC0() { return this->c0_; }
Cell PunchedWall::getC1() { return this->c1_; }

bool Cell::operator==(const Cell c) const
{
    int r0 = this->r_;
    int c0 = this->c_;
    int r1 = c.r_;
    int c1 = c.c_;
    return ((r0 == r1) && (c0 == c1));
}

bool PunchedWall::operator==(const PunchedWall p0) const
{
    Cell c0 = this->c0_;
    Cell c1 = this->c1_;
    Cell d0 = p0.c0_;
    Cell d1 = p0.c1_;

    return ((c0.getR() == d0.getR()) && (c0.getC() == d0.getC())
        && (c1.getR() == d1.getR()) && (c1.getC() == d1.getC()))
        ? true : false;
}
