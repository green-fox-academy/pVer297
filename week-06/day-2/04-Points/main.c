#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
*/

typedef struct
{
    float x;
    float y;
} point_t;

double getDist(point_t p1, point_t p2)
{
    return sqrt((pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}

int main()
{
    point_t point1 = {400, 600};
    point_t point2 = {100, 325};

    printf("First point is %.1f, %.1f\n", point1.x, point1.y);
    printf("Second point is %.1f, %.1f\n", point2.x, point2.y);
    printf("Distance between them is %lf\n", getDist(point1, point2));

    return 0;
}