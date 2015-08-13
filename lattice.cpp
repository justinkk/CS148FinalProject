/**
 * This program should draw a simple 10x10x10 cubic lattice of points. Insert the appropriate code below.
 */

#include "vdb.h"

int main() {
    for(int x = 0; x < 10; x++) {
        for(int y = 0; y < 10; y++) {
            for(int z = 0; z < 10; z++) {
                vdb_point(x,y,z);
            }
        }
    }
    return 0;
}