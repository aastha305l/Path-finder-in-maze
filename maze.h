//Name:Aastha Lamichhane
//File: maze.h

#ifndef MAZE_H
#define MAZE_H

class Cell
{
  public:
    Cell(int r, int c)
        : r_(r), c_(c)
    {};
    int getR();
    int getC();
    void setR(int r);
    void setC(int c);
    bool operator==(const Cell) const;
  private:
    int r_ , c_;
};


class PunchedWall
{
  public:
    PunchedWall(Cell c0, Cell c1)
        : c0_(c0), c1_(c1)
    {}
    Cell getC0();
    Cell getC1();
    bool operator==(const PunchedWall) const;
  private:
    Cell c0_, c1_;
};


#endif
