#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;


int FindQ(Point);
int SameQuadrants(Point, Point);

int FindQ(Point p)
{
    if (p.x > 0 && p.y > 0)
        return 1;
    else if (p.x < 0 && p.y > 0)
        return 2;
    else if (p.x > 0 && p.y < 0)
        return 3;
    else if (p.x < 0 && p.y < 0)
        return 4;
    else
        return 0;
}

int SameQuadrants (Point p1, Point p2)
{
    if (FindQ(p1) == FindQ(p2))
        return 1;
    return 0;
}

int main()
{
    Point p1 = {1,1}, p2 = {-1, 1}, p3 = {-1, -1}, p4 = {1, -1}, p5 = {0, 5};

    printf("\nPoint p1 lies in Quadrant %d", FindQ(p1));
    printf("\nPoint p2 lies in Quadrant %d", FindQ(p2));
    printf("\nPoint p3 lies in Quadrant %d", FindQ(p3));
    printf("\nPoint p4 lies in Quadrant %d", FindQ(p4));
    printf("\nPoint p5 lies in Quadrant %d\n", FindQ(p5));
}