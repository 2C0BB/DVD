#include <cstdlib>
#include <time.h>

#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

class Dvd {
	public:
		Dvd(int _vel) {
			width = 128;
			height = 76;
			x = rand()%(SCREEN_WIDTH-width + 1);
			y = rand()%(SCREEN_HEIGHT-height + 1);

			x_vel = _vel;
			y_vel = _vel;

			colour = RED;
		}

		void random_colour() {

			int min = 100;
			int max = 255;

			unsigned char r;
			unsigned char g;
			unsigned char b;

			r = rand()%((max - min) + 1) + min;
			g = rand()%((max - min) + 1) + min;
			b = rand()%((max - min) + 1) + min;

			colour = {r, g, b, 255};
		}

		void update() {
			x += x_vel;
			y += y_vel;

			if (x < 0 || x+width >= SCREEN_WIDTH) {
				x_vel *= -1;
				random_colour();
			}

			if (y < 0 || y+height >= SCREEN_HEIGHT) {
				y_vel *= -1;
				random_colour();
			}
		}

		void draw() {
			DrawRectangle(x, y, width, height, colour);
		}

	private:
		int x;
		int y;
		int x_vel;
		int y_vel;
		int width;
		int height;
		Color colour;
};



int main(void)
{

	srand((unsigned int)time(0));

	Dvd the_dvd(2);

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "DVD");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {

		the_dvd.update();

		BeginDrawing();
        	ClearBackground(BLACK);
			the_dvd.draw();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}