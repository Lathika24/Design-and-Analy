#include <stdio.h>
#include <stdlib.h>

// Structure to represent a point (x, y)
struct Point {
    int x, y;
};

// Function to find orientation of triplet (p, q, r).
// The function returns:
// 0 -> p, q, r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Function to perform Graham's scan and print convex hull
void convexHull(struct Point points[], int n) {
    // There must be at least 3 points for convex hull
    if (n < 3) return;

    // Initialize result
    int hull[n], hull_size = 0;

    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[l].x)
            l = i;
    }

    // Start from the leftmost point, keep moving counterclockwise
    // until we reach the start point again
    int p = l, q;
    do {
        // Add current point to result
        hull[hull_size++] = p;

        // Search for a point 'q' such that orientation(p, x, q) is
        // counterclockwise for all points 'x'. The idea is to keep
        // track of the next point in the convex hull in the search.
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        // Set p as q for the next iteration
        p = q;
    } while (p != l); // While we don't come back to the first point

    // Print result
    printf("Convex Hull Points:\n");
    for (int i = 0; i < hull_size; i++) {
        printf("(%d, %d)\n", points[hull[i]].x, points[hull[i]].y);
    }
}

// Driver program to test above functions
int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    struct Point points[n];
    printf("Enter the points (x, y):\n");
    for (int i = 0; i < n; i++) {
        printf("Point %d: ", i + 1);
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);
    return 0;
}

Recurrence Relation: T(n) = 2T(n/2) + O(n log n)

O(nlogn)