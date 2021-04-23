#include <stdio.h>
#include <GL/glut.h>

float x = 0, y = 0, referencia = 2;
float rf = referencia / 2;
float ri = -rf;

void Background()
{
  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Points()
{
  glPointSize(10);
  glBegin(GL_POINTS);
  glColor3f(1, 0, 0);
  glVertex2f(0.0, 0.0);
  glVertex2f(ri, 0.0);
  glVertex2f(rf, 0.0);
  glVertex2f(0.0, ri);
  glVertex2f(0.0, rf);
  glEnd();
}

void Lines()
{
  glBegin(GL_LINES);
  glColor3f(0, 0, 1);
  glVertex2f(ri, 0);
  glVertex2f(rf, 0);
  glVertex2f(0, ri);
  glVertex2f(0, rf);

  glColor3f(0, 0, 0);
  for (float i = ri; i < rf; i = i + 0.1)
  {
    glVertex2f(ri, i);
    glVertex2f(rf, i);
    glVertex2f(i, ri);
    glVertex2f(i, rf);
  }
  glEnd();
}

void Triangle()
{
  glBegin(GL_TRIANGLES);
  glColor3f(0, 0, 1);
  glVertex3f(-0.95, 0.25, 0);
  glVertex3f(-0.65, 0.75, 0);
  glVertex3f(-0.35, 0.25, 0);
  glEnd();
}

void Quads()
{
  glBegin(GL_QUADS);
  glVertex3f(-0.25, 0.75, 0);
  glVertex3f(-0.25, 0.25, 0);
  glVertex3f(0.25, 0.25, 0);
  glVertex3f(0.25, 0.75, 0);
  glEnd();
}

void Polygon()
{
  glBegin(GL_POLYGON);
  glVertex3f(0.55, 0.75, 0);
  glVertex3f(0.42, 0.68, 0);
  glVertex3f(0.35, 0.55, 0);
  glVertex3f(0.4, 0.32, 0);
  glVertex3f(0.55, 0.25, 0);
  glVertex3f(0.9, 0.27, 0);
  glVertex3f(0.95, 0.50, 0);
  glVertex3f(0.90, 0.75, 0);
  glEnd();
}

void QuadsArray()
{
  float proportion = 2;
  float yPosition = 0.35;
  float xPosition = 0.1;

  glBegin(GL_QUAD_STRIP);

  glColor3f(0, 0, 1);
  glVertex2f((0.1 * proportion) + xPosition, (-0.4 * proportion) + yPosition);
  glVertex2f((0.1 * proportion) + xPosition, (-0.5 * proportion) + yPosition);
  glVertex2f((0.2 * proportion) + xPosition, (-0.4 * proportion) + yPosition);
  glVertex2f((0.2 * proportion) + xPosition, (-0.5 * proportion) + yPosition);
  glVertex2f((0.3 * proportion) + xPosition, (-0.38 * proportion) + yPosition);
  glVertex2f((0.3 * proportion) + xPosition, (-0.52 * proportion) + yPosition);
  glVertex2f((0.4 * proportion) + xPosition, (-0.4 * proportion) + yPosition);
  glVertex2f((0.4 * proportion) + xPosition, (-0.5 * proportion) + yPosition);

  glEnd();
}

void TriangleFlower()
{
  float proportion = 3;
  float xPosition = 1.4;
  float yPosition = 0.87;

  glBegin(GL_TRIANGLE_FAN);

  glColor3f(0, 0, 1);
  glVertex2f((-0.5 * proportion) + xPosition, (-0.5 * proportion) + yPosition);
  glVertex2f((-0.55 * proportion) + xPosition, (-0.4 * proportion) + yPosition);
  glVertex2f((-0.57 * proportion) + xPosition, (-0.53 * proportion) + yPosition);
  glVertex2f((-0.47 * proportion) + xPosition, (-0.54 * proportion) + yPosition);
  glVertex2f((-0.4 * proportion) + xPosition, (-0.5 * proportion) + yPosition);
  glVertex2f((-0.45 * proportion) + xPosition, (-0.4 * proportion) + yPosition);

  glEnd();
}

void TrianlgeStrip()
{
  float proportion = 1.3;
  float xPosition = -0.33;
  float yPosition = -0.45;
  glBegin(GL_TRIANGLE_STRIP);

  glColor3f(0, 0, 1);
  glVertex2f((-0.5 * proportion) + xPosition, 0 + yPosition);
  glVertex2f((-0.4 * proportion) + xPosition, (-0.1 * proportion) + yPosition);
  glVertex2f((-0.3 * proportion) + xPosition, 0 + yPosition);
  glVertex2f((-0.2 * proportion) + xPosition, (-0.1 * proportion) + yPosition);
  glVertex2f((-0.1 * proportion) + xPosition, 0 + yPosition);
  glVertex2f(0 + xPosition, (-0.1 * proportion) + yPosition);

  glEnd();
}

void Primitivas()
{
  Lines();
  Points();
  Triangle();
  Quads();
  Polygon();
  TriangleFlower();
  TrianlgeStrip();
  QuadsArray();
}

void Desenha(void)
{
  Background();

  Primitivas();

  glFlush();
}

void Teclado(void) {}

void Inicializa(void)
{
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(800, 800);

  glutInitWindowPosition(200, 120);

  glutCreateWindow("3o Exemplo");

  glutDisplayFunc(Desenha);

  glutMainLoop();

  system("pause");

  return (0);
}
