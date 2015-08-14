/**
    This program is supposed to draw all points with integer coordinates within a radius 10
    sphere when the vdb viewer is running.

    Make sure your build system can find vdb.h. The simple but inelegant way to ensure this is
    to simply copy vdb.h from your copy of vdb into this directory.
*/

#include "vdb.h"

int main() {
  int r = 10;
  for (int x = -r; x <= r; x++) {
    for (int y = -r; y <= r; y++) {
      for (int z = -r; z <= r; z++) {
        if ( x * x + y * y + z * z < r * r) {
          vdb_point(x, y, z);
        }
      }
    }
  }
  return 0;
}
