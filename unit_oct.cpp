/**
 * This program is supposed to draw densely sampled points within a regular octahedron centered
 * at the origin with its vertices 1 unit length from the origin. One half of the octahedron is red, the other half
 * is blue, and there is a thin layer of blue points in the middle. There are a couple of subtle bugs that you should
 * fix.  Look at loop variables, the types involved in the operations, and boolean conditions for the branches.
 */

#include "vdb.h"
#include <math.h>       /* fabs */

// This isn't relevant for this assignment, but note that by simply changing this inside function
// we can use the corrected version of the rest of this program to draw *any*
// shape defined in the [-1,1] cube.
bool inside(float x, float y, float z) {
  // An octahedron is simply a 3-ball using the L_1 norm
  return fabs(x) + fabs(y) + fabs(z) <= 1.0f;
}


int main() {
  int steps = 50;
  for (int i = 0; i <= steps; ++i) {
    for (int j = 0; j <= steps; ++j) {
      for (int k = 0; k <= steps; ++k) {
        // Iteration variables are in [0,50], we want points from -1 to 1
        // So multiply by 2/50, subtract 1
        float x = (1.0f * i / steps) * 2.0f - 1.0f;
        float y = (1.0f * j / steps) * 2.0f - 1.0f;
        float z = (1.0f * k / steps) * 2.0f - 1.0f;
        if ( inside(x, y, z) ) {
          if (x == 0 || y == 0 || z == 0) {
            vdb_color(31.f/255.f, 119.f/255.f, 180.f/255.f);   // planes of axes should be nice blue
          } else if (x > 0) {
            vdb_color(214.f/255.f, 39.f/255.f, 40.f/255.f);   // right half should be nice red
          } else {
            vdb_color(44.f/255.f, 160.f/255.f, 44.f/255.f);   // left half should be nice green
          }
          vdb_point(x, y, z);
        }
      }
    }
  }
  return 0;
}

/**************** ORIGINAL *********************
int main() {
  int steps = 50;
  for (int i = 0; i <= steps; ++i) {
    for (int j = 0; j <= steps; ++j) {
      for (int k = 0; k <= steps; ++k) {
        // Iteration variables are in [0,50], we want points from -1 to 1
        // So multiply by 2/50, subtract 1
        float x = (i / steps) * 2.0f - 1.0f;
        float y = (j / steps) * 2.0f - 1.0f;
        float z = (i / steps) * 2.0f - 1.0f;
        if ( inside(x, y, z) ) {
          if (x == 0 && y == 0 && z == 0) {
            vdb_color(31.f/255.f, 119.f/255.f, 180.f/255.f);   // planes of axes should be nice blue
          } else if (x > 0) {
            vdb_color(214.f/255.f, 39.f/255.f, 40.f/255.f);   // right half should be nice red
          } else {
            vdb_color(44.f/255.f, 160.f/255.f, 44.f/255.f);   // left half should be nice green
          }
          vdb_point(x, y, z);
        }
      }
    }
  }
  return 0;
}
***************************************************/
