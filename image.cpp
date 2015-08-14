#include "SimpleImage.h"

class YIQ {
public:
    YIQ(RGBColor p);
    float y, i, q;
};

YIQ::YIQ(RGBColor p) {
    y = (p.r*.299f + p.g*.587f + p.b*.114f);
    i = (p.r*.596f - p.g*.275f - p.b*.321f);
    q = (p.r*.212f - p.g*.523f + p.b*.311f);
}

//class RGB {
//public:
//	RGB(YIQ p);
//	float r, g, b;
//};

//RGB::RGB(YIQ p) {
// r = (p.y + p.i*.956f + p.q*.621f);
// g = (p.y - p.i*.272f - p.q*.647);
// b = (p.y - p.i*1.105f + p.q*1.702f);
//}

int main() {
    // Load images from file
    SimpleImage imgA("a.jpg");
    SimpleImage imgA2("a_2.jpg");
    SimpleImage imgB("b.jpg");
    //float y, i, q;
    // Initialize result image
    SimpleImage result(imgA.width(), imgA.height(), RGBColor(0, 0, 0));
    
    // Iterate over pixels and set color for result image
    for (int y = 0; y < imgA.height(); ++y) {
        for (int x = 0; x < imgA.width(); ++x) {
            RGBColor p1 = imgA(x, y);
            RGBColor p2 = imgA2(x,y);
            RGBColor q1 = imgB(x,y);
            RGBColor q2;
            
            YIQ p1p(p1);
            YIQ p2p(p2);
            
            q2.r = p1p.y;
            q2.g = p1p.i;
            q2.b = p1p.q;
            result.set(x, y, q2);
            
            //printf("RGB: %.2f %.2f %.2f - YIQ %.2f - %.2f - %.2f\n", p.r , p.g , p.b , pp.y, pp.i, pp.q);
        }
    }
    
    // Save result image to file
    result.save("./b_2.jpg");
    //system("pause");
    
    return 0;
}

