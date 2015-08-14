/**
 * This program draws a picture of Karel the Robot using gdb.
 * Colors taken from  http://xkcd.com/color/rgb/
 */

#include "vdb.h"
#include <math.h>       /* fabs */

int main() {

  //Draw Karel's body
  vdb_color(94.f/255.f, 129.f/255.f, 157.f/255.f); //Make Karel greyish blue
  vdb_triangle(1.0f, 5.0f, 0.0f, //upper-left triangle
               -2.0f, 5.0f, 0.0f,
               1.0f, 1.0f, 0.0f);
  vdb_triangle(-3.0f, 0.0f, 0.0f, //lower-right triangle
               -3.0f, 4.0f, 0.0f,
               0.0f, 0.0f, 0.0f);
  //connect big triangles
  vdb_triangle(-2.0f, 5.0f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f); 
  vdb_triangle(-2.0f, 5.0f, 0.0f,  -3.0f, 4.0f, 0.0,  0.0f, 0.0f, 0.0f); 

  //Face, mounth, and legs
  vdb_color(2.f/255.f, 0.f/255.f, 53.f/255.f); //Lines on Karel are midnight blue
  vdb_line(-2.1f, 1.4f, -0.1f,  -0.8f, 1.4f, -0.1f); //mouth
  vdb_line(-2.1f, 1.8f, -0.1f,  -2.1f, 4.0f, -0.1f); //right
  vdb_line(-0.1f, 1.8f, -0.1f,  -0.1f, 4.0f, -0.1f); //left
  vdb_line(-0.1f, 4.0f, -0.1f,  -2.1f, 4.0f, -0.1f); //top
  vdb_line(-0.1f, 1.8f, -0.1f,  -2.1f, 1.8f, -0.1f); //bottom

  vdb_line(-1.0f, 0.0f, 0.0f,  -1.0f, -0.8f, 0.0f); //Bottom leg
  vdb_line(-1.8f, -0.8f, 0.0f,  -1.0f, -0.8f, 0.0f);

  vdb_line(1.0f, 2.0f, 0.0f,  1.8f, 2.0f, 0.0f); //Left leg
  vdb_line(1.8f, 2.0f, 0.0f,  1.8f, 1.2f, 0.0f);

  //Background
  vdb_color(255.f/255.f, 255.f/255.f, 228.f/255.f); //Background off-white
  float size = 20.f;
  vdb_triangle(-size, size, 5.0f,  size, size, 5.0,  -size, -size, 5.0f); //5.0f is behind Karel
  vdb_triangle(size, size, 5.0f,  size, -size, 5.0,  -size, -size, 5.0f); 

  return 0;
}