#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>

int angle;
float horizontalMove;
float verticalMove;

// Collider
float posisiX[2] = {0, 10};
float posisiY[2] = {0, 10};




void ColliderPersegi(){ // Collider bentuk kotak
    glPushMatrix();
    glBegin(GL_POLYGON);
	glColor3f(0.063, 0.91, 0.176);
	glVertex2f(posisiX[0], posisiY[0]);
	glVertex2f(posisiX[1], posisiY[0]);
	glVertex2f(posisiX[1], posisiY[1]);
	glVertex2f(posisiX[0], posisiY[1]);
	glEnd();
    glPopMatrix();
}

// Menggambar segitiga dengan titik putar berada di tengah object
void SegitigaView(){
    glRotatef(angle,0,0,1);
    glBegin(GL_POLYGON);
    glColor3f(1, 0.91, 0.176);
    glVertex2f(-2,-2);
    glVertex2f(0,2);
    glVertex2f(2,-2);
    glEnd();
}

void SegitigaObject(){
    // Memasang collider pada object
    ColliderPersegi();

    glPushMatrix();
    glTranslatef(horizontalMove, verticalMove,0); // Mengendalikan posisi segitiganya
    glTranslatef(5,5,0); // Menengahkan view
    SegitigaView(); // Memanggil view
    glPopMatrix();
}

// Fungsi untuk mengendalikan object
void characterController(int data)
{
    // Jika menekan tombol panah kiri
    if(GetAsyncKeyState(VK_LEFT)){
        if (posisiX[0] >= 0){
            posisiX[0] -= 0.1f;
            posisiX[1] -= 0.1f;
            horizontalMove-=0.1f;
        }
    // Jika menekan tombol panah kanan
    } else if(GetAsyncKeyState(VK_RIGHT)){
        if (posisiX[1] <= 50){
            posisiX[0] += 0.1f;
            posisiX[1] += 0.1f;
            horizontalMove+=0.1f;
        }
    }

    // Jika menekan tombol panah atas
    if(GetAsyncKeyState(VK_UP)){
        if (posisiY[1] <= 50){
            posisiY[0] += 0.1f;
            posisiY[1] += 0.1f;
            verticalMove+=0.1f;
        }
    // Jika menekan tombol panah bawah
    } else if (GetAsyncKeyState(VK_DOWN)){
        if (posisiY[0] >= 0){
            posisiY[0] -= 0.1f;
            posisiY[1] -= 0.1f;
            verticalMove-=0.1f;
        }
    }

    glutPostRedisplay();
	glutTimerFunc(1,characterController,0);
}

void keyboard(unsigned char key, int x, int y)
{
    if(key==100 || key==68){ // Tombol d atau D
        angle--;
    }
    if(key==97 || key==65){ // Tombol a atau A
        angle++;
    }
}

void displayMe(void) {
	glClearColor(1,1,1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// Memanggil object segitiga
    SegitigaObject();

	glFlush();
	glutSwapBuffers();
}

void myinit() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0); //membersihkan windows
	glColor3f(0.0, 0.0, 0.0); //spesifikasi warna
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Windows");
	gluOrtho2D(0, 50, 0, 50);
	glutDisplayFunc(displayMe);
	glutTimerFunc(1,characterController,0);
	glutKeyboardFunc(keyboard);
	myinit();
	glutMainLoop();
	return 0;
}
