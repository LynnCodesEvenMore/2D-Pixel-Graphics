#include <GL/freeglut.h>
#include <stdio.h>


// Global Variables
const int WIDTH_WINDOW = 400;
const int HEIGHT_WINDOW = 400;
const int X_POS_WINDOW = 100;
const int Y_POS_WINDOW = 100;
const char* NAME_WINDOW = "Graphics Test";
const int FPS = 30;

GLubyte* PixelBuffer = new GLubyte[WIDTH_WINDOW * HEIGHT_WINDOW * 3];
int blue = 245;



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(WIDTH_WINDOW, HEIGHT_WINDOW, GL_RGB, GL_UNSIGNED_BYTE, PixelBuffer);
    glutSwapBuffers();
}


void makePixel(int x, int y, int r, int g, int b, GLubyte* pixels, int width, int height)
{
    if (0 <= x && x < width && 0 <= y && y < height) {
        int position = (x + y * width) * 3;
        pixels[position] = r;
        pixels[position + 1] = g;
        pixels[position + 2] = b;
    }
}

void drawBlue(int width, int height) {

    blue += 1;
    blue %= 256;

    // fill Pixel Buffer
    for(int x = 0; x < width; x++) {
    	for(int y = 0; y < height; y++) {
    		makePixel(x,y,0,0,blue,PixelBuffer, width, height);
    	}
    }
    return;
}

void special_keyboard_keys(int key, int x, int y)
{
     switch (key)
    {
       case GLUT_KEY_LEFT : printf("GLUT_KEY_LEFT %d\n",key);   break;
       case GLUT_KEY_RIGHT: printf("GLUT_KEY_RIGHT %d\n",key);  ;  break;
       case GLUT_KEY_UP   : printf("GLUT_KEY_UP %d\n",key);  ;  break;
       case GLUT_KEY_DOWN : printf("GLUT_KEY_DOWN %d\n",key);  ;  break;
    }

}

void normal_keyboard_keys(unsigned char key, int x, int y) {
	// ASCII codes for normal keys
	switch(key)
	{
	case 97: printf("KEY_LOWERCASE_A %d\n",key); break;
	case 100: printf("KEY_LOWERCASE_D %d\n",key); break;
	case 115: printf("KEY_LOWERCASE_S %d\n",key); break;
	case 119: printf("KEY_LOWERCASE_W %d\n",key); break;
	}
}

void timer(int t) {
	
	// Animation code
	drawBlue(WIDTH_WINDOW, HEIGHT_WINDOW);

	// Update display
	glutPostRedisplay();

	// Reset timer (one-shot timer!)
	glutTimerFunc( 1000/FPS, timer, 0);

}

void initializeWindow(int argc, char* argv[], int xPos, int yPos, int width, int height, const char* name) {
    // GLUT requires main context
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(width, height);
    glutInitWindowPosition(xPos, yPos);

    int MainWindow = glutCreateWindow(name);
    glClearColor(0.0, 0.0, 0.0, 0);
    return;
}

void registerCallbackHandlers() {
    glutDisplayFunc(display);
    glutSpecialFunc(special_keyboard_keys);
    glutKeyboardFunc(normal_keyboard_keys);
    glutTimerFunc( 1000/FPS , timer, 0);
    return;
}

int main(int argc, char *argv[])
{
    // Initialize Window
    initializeWindow(argc, argv, X_POS_WINDOW, Y_POS_WINDOW, WIDTH_WINDOW, HEIGHT_WINDOW, NAME_WINDOW);

    // register callback handlers for display, keyboard and timer for drawing frames
    registerCallbackHandlers();

    // Mainloop
    for(;;) {

    // timer will be called periodically for drawing frames


    // make changes visible
    glutMainLoopEvent();

    }


    return 0;
}

