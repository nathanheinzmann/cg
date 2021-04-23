#include <stdio.h>
#include <GL/glut.h>

void Grid(float ri, float rf)
{
  glBegin(GL_LINES);
  glColor3f(0, 0, 1);
  glVertex2f(ri, 0);
  glVertex2f(rf, 0);
  glVertex2f(0, ri);
  glVertex2f(0, rf);

  glColor3f(1, 1, 1);
  for (float i = ri; i < rf; i = i + 0.1)
  {
    glVertex2f(ri, i);
    glVertex2f(rf, i);
    glVertex2f(i, ri);
    glVertex2f(i, rf);
  }
  glEnd();
}
