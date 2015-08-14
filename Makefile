CC=g++
CFLAGS=-Wall

all: image sphere unit_oct karel

image: image.cpp stb.cpp SimpleImage.cpp SimpleImage.h stb_image.h stb_image_write.h
	$(CC) $(CFLAGS) image.cpp stb.cpp SimpleImage.cpp -o image

sphere: sphere.cpp
	$(CC) $(CFLAGS) sphere.cpp -o sphere

unit_oct: unit_oct.cpp
	$(CC) $(CFLAGS) unit_oct.cpp -o unit_oct

karel: karel.cpp
	$(CC) $(CFLAGS) karel.cpp -o karel

clean:
	rm image sphere unit_oct
