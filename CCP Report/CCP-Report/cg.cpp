#include <windows.h>
#include <GL/GL.h>
#include <GL/glut.h>

// Initial position and visibility flag for flames
int dotX = 210;
int dotY = 100;
bool flamesVisible = false;

// Color constants for different parts of the rocket
GLfloat bodyColor[] = { 0.8f, 0.8f, 0.8f };  
GLfloat noseColor[] = { 0.8f, 0.8f, 0.8f };  
GLfloat finColor[] = { 0.6f, 0.6f, 0.6f };   
GLfloat engineColor[] = { 0.4f, 0.4f, 0.4f }; 

void myInit() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(10.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void drawGround() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    glVertex2i(0, 50);
    glVertex2i(640, 50);
    glVertex2i(640, 0);
    glVertex2i(0, 0);
    glEnd();
}

void drawAntennaTowers() {
    // Left antenna tower
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2i(10, 50);
    glVertex2i(30, 50);
    glVertex2i(30, 200);
    glVertex2i(10, 200);
    glEnd();

    // Right antenna tower
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2i(610, 50);
    glVertex2i(630, 50);
    glVertex2i(630, 200);
    glVertex2i(610, 200);
    glEnd();
}

void drawRocketAndLand(int x, int y) {
    // Rocket body
    glColor3fv(bodyColor);
    glBegin(GL_POLYGON);
    glVertex2i(x + 50, y);
    glVertex2i(x + 100, y);
    glVertex2i(x + 100, y + 300);
    glVertex2i(x + 50, y + 300);
    glEnd();

    // Rocket nose
    glColor3fv(noseColor);
    glBegin(GL_TRIANGLES);
    glVertex2i(x + 50, y + 300);
    glVertex2i(x + 100, y + 300);
    glVertex2i(x + 75, y + 350);
    glEnd();

    // Rocket fins
    glColor3fv(finColor);
    glBegin(GL_TRIANGLES);
    // Left fin
    glVertex2i(x + 50, y + 200);
    glVertex2i(x + 30, y + 150);
    glVertex2i(x + 50, y + 150);

    // Right fin
    glVertex2i(x + 100, y + 200);
    glVertex2i(x + 120, y + 150);
    glVertex2i(x + 100, y + 150);

    // Bottom left fin
    glVertex2i(x + 50, y);
    glVertex2i(x + 30, y - 50);
    glVertex2i(x + 50, y - 50);

    // Bottom right fin
    glVertex2i(x + 100, y);
    glVertex2i(x + 120, y - 50);
    glVertex2i(x + 100, y - 50);
    glEnd();

    // Rocket engine
    glColor3fv(engineColor);
    glBegin(GL_POLYGON);
    glVertex2i(x + 60, y - 50);
    glVertex2i(x + 90, y - 50);
    glVertex2i(x + 90, y);
    glVertex2i(x + 60, y);
    glEnd();

    // Rocket flames
    if (flamesVisible) {
        glColor3f(1.0f, 0.5f, 0.0f);
        glBegin(GL_TRIANGLES);
        glVertex2i(x + 75, y - 50);
        glVertex2i(x + 60, y - 100);
        glVertex2i(x + 90, y - 100);
        glEnd();
    }
}

void menu(int option) {
    switch (option) {
    case 1:
        bodyColor[0] = 1.0f; bodyColor[1] = 0.0f; bodyColor[2] = 0.0f;
        break;
    case 2:
        noseColor[0] = 0.0f; noseColor[1] = 1.0f; noseColor[2] = 0.0f;
        break;
    case 3:
        finColor[0] = 0.0f; finColor[1] = 0.0f; finColor[2] = 1.0f;
        break;
    case 4:
        engineColor[0] = 1.0f; engineColor[1] = 1.0f; engineColor[2] = 0.0f;
        break;
    case 5:
        exit(0);
    default:
        break;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    drawGround();
    drawAntennaTowers();
    drawRocketAndLand(dotX, dotY);
    glFlush();
}

void createMenu() {
    int colorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Body - Red", 1);
    glutAddMenuEntry("Nose - Green", 2);
    glutAddMenuEntry("Fins - Blue", 3);
    glutAddMenuEntry("Engine - Yellow", 4);
    int mainMenu = glutCreateMenu(menu);
    glutAddSubMenu("Change Color", colorMenu);
    glutAddMenuEntry("Exit", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void handleSpecialKeys(int key, int x, int y) {
    if (flamesVisible) {
        glClear(GL_COLOR_BUFFER_BIT);
        if (key == GLUT_KEY_UP) {
            dotY += 5;
        }
        else if (key == GLUT_KEY_DOWN && dotY > 100) {
            dotY -= 5;
        }
        drawGround();
        drawAntennaTowers();
        drawRocketAndLand(dotX, dotY);
        glFlush();
    }
}

void handleKeys(unsigned char key, int x, int y) {
    if (key == 'p' || key == 'P') {
        flamesVisible = !flamesVisible;
        glClear(GL_COLOR_BUFFER_BIT);
        drawGround();
        drawAntennaTowers();
        drawRocketAndLand(dotX, dotY);
        glFlush();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawGround();
    drawAntennaTowers();
    drawRocketAndLand(dotX, dotY);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rocket Animation");
    myInit();
    createMenu();
    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeys);
    glutKeyboardFunc(handleKeys);
    glutMainLoop();
    return 0;
}
