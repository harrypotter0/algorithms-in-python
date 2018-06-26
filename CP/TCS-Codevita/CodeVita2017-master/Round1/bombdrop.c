#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct   // Point data type
{
    double x;
    double y;
}
Point;

typedef struct   // Line data type
{
    Point p1;
    Point p2;
}
Line;

// Emulate C++ constructors for structures
#define Point(x, y) ((Point) { x, y })
#define Line(p1, p2) ((Line) { p1, p2 })

// Distance between points
double pdistance(Point p1, Point p2)
{
    double dx, dy;

    dx = (p1.x - p2.x);
    dy = (p1.y - p2.y);

    return sqrt((dx * dx) + (dy * dy));
}

// Test point circle intersection
bool intersects(Point point, int x, int y, int r)
{
    return pdistance(point, Point(x, y)) <= r;
}

// Intersection distance, how much has the point penetrated into circle
double idistance(Point point, int x, int y, int r)
{
    return ((double) r) - pdistance(point, Point(x, y));
}

// Length of the line
double llength(Line line)
{
    return pdistance(line.p1, line.p2);
}

// Process a line, clears the area inside the circle, and returns the new length
double lprocess(Line line, int x, int y, int r)
{
    double distance;

    bool p1intersects;
    bool p2intersects;

    p1intersects = intersects(line.p1, x, y, r);
    p2intersects = intersects(line.p2, x, y, r);

    // If none of the points are in the circle, then return the length of the line
    if (!p1intersects && !p2intersects)
        return llength(line);

    // If both the points intersect, then the line is completely erased, 0 is the length
    if (p1intersects && p2intersects)
        return 0;

    // Compute the length of the line
    distance = llength(line);

    if (p1intersects)
        distance -= idistance(line.p1, x, y, r);

    else if (p2intersects)
        distance -= idistance(line.p2, x, y, r);

    return distance;
}

int main()
{
    int n, r, x, y, i, t1, t2, t3, t4;
    double count;

    scanf("%d\n%d\n%d %d", &n, &r, &x, &y);
    Line* lines = (Line*) malloc(sizeof(Line) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &t1, &t2, &t3, &t4);
        lines[i] = Line(Point(t1, t2), Point(t3, t4));
    }

    count = 0;

    for (i = 0; i < n; i++)
        count += lprocess(lines[i], x, y, r);

    printf("%.2lf\n", count);

    free (lines);
    return 0;
}
