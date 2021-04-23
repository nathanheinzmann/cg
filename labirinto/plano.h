#include <stdio.h>
#include <GL/glut.h>

void DesenhaPlano(float h, int pontos, int rotulos, int corbranca)
{
  int i;
  float x, y, rxy, intervalo = h / 10.0;
  char r[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  if (corbranca)
    glColor3f(1.0f, 1.0f, 1.0f);
  else
    glColor3f(0.0f, 0.0f, 0.0f);

  // tra�a o plano cartesiano **** OPERA��ES COM LINHA *******************
  glBegin(GL_LINES);
  glVertex2f(-h, 0.0);
  glVertex2f(h, 0.0);
  glVertex2f(0.0, -h);
  glVertex2f(0.0, h);
  glEnd();

  if (pontos)
  {
    // tra�a os pontos nos plano ********************************
    glBegin(GL_LINES);
    for (y = -h, x = -h; y <= (h + 0.1); y += intervalo, x += intervalo)
    {
      glVertex2f(-(intervalo / 20), y);
      glVertex2f((intervalo / 20), y);
      glVertex2f(x, -(intervalo / 20));
      glVertex2f(x, (intervalo / 20));
    }
    glEnd();

    if (rotulos)
    {
      rxy = 0.0;
      for (i = 0; i < 10; i++)
      {
        rxy += intervalo;
        glRasterPos2f(-((intervalo * 4) / 20), rxy);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, r[i]);
        glRasterPos2f(-((intervalo * 4) / 20), -rxy);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, r[i]);
        glRasterPos2f(rxy, -((intervalo * 3.5) / 10));
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, r[i]);
        glRasterPos2f(-rxy, -((intervalo * 3.5) / 10));
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, r[i]);
      }
    }
  }
}
