#include <stdio.h>

#define XMAX 100
#define YMAX 90

typedef struct point {
    int x;
    int y;
} point;

typedef struct rectangle {
    point pt1;
    point pt2;
} rect;

point makepoint(int x, int y) {
    point temp;

    temp.x = x;
    temp.y = y;
    return temp;
}

point addpoint(point p1, point p2) {

    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

int ptinrect(point p, rect r) { 
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}



int main() {

    point maxpt = { 320, 200 };
    point pt;

    printf("%d, %d", pt.x, pt.y);

    rect screen;
    point middle;
    point makepoint(int, int);
    
    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) / 2);

    point origin, *pp;

    pp = &origin;
    printf("origin is (%d, %d)\n", pp->x, pp->y);

    return 0;
}

