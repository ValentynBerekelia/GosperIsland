#include <iostream>
#include <windows.h>
#include "graphics.h"
#include <math.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
float angle_radians_p = 30 * 3.14 / 180.0;
float angle_radians_n = -30 * 3.14 / 180.0;
float lamda = (sqrt(3)) / (2 - sqrt(3));
void gosper(float startx, float starty, float endx, float endy, int iterations) {
	if (iterations == 0) {
		line(startx, starty, endx, endy);
		return;
	}
	float centerx = (startx + endx) / 2;
	float centery = (starty + endy) / 2;

	float y_n, y_p;
	float x_n, x_p;
	x_n = (centerx - startx) * cos(angle_radians_n) - (centery - starty) * sin(angle_radians_n) + startx;
	y_n = (centerx - startx) * sin(angle_radians_n) + (centery - starty) * cos(angle_radians_n) + starty;

	float x1, x2, x3, y1, y2, y3;

	x1 = (x_n * (1 + lamda) - startx) / lamda;
	y1 = (y_n * (1 + lamda) - starty) / lamda;

	x_p = (centerx - endx) * cos(angle_radians_n) - (centery - endy) * sin(angle_radians_n) + endx;
	y_p = (centerx - endx) * sin(angle_radians_n) + (centery - endy) * cos(angle_radians_n) + endy;

	x2 = (x_p * (1 + lamda) - endx) / lamda;
	y2 = (y_p * (1 + lamda) - endy) / lamda;


	gosper(startx, starty, x1, y1, iterations - 1);
	gosper(endx, endy, x2, y2, iterations - 1);
	gosper(x1, y1, x2, y2, iterations - 1);

}
int main() {
	srand(time(NULL));
#pragma comment(lib, "graphics.lib")
	initwindow(600, 600);
	setcolor(WHITE);
	int iter = 10;
	int startx, starty, endx, endy;
	startx = 200; endx = 300; starty = 200; endy = 200;
	gosper(startx, starty, endx, endy, iter);

	startx = 300; endx = 250; starty = 200; endy = 100;
	gosper(startx, starty, endx, endy, iter);
	startx = 250, starty = 100, endx = 200, endy = 200;
	gosper(startx, starty, endx, endy, iter);
	getchar();
	closegraph();
}