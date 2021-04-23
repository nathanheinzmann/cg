#include <stdio.h>
#include <GL/glut.h>

void Triangle(char direction = 'r', float positionX = 0, float positionY = 0, float red = 0.4, float green = 0.7, float blue = 0.1)
{
  float baseSizeTriangle = 0.1;

  switch (direction)
  {
  case 'r':
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue);
    glVertex2f(0 + positionX, 0 + positionY);
    glVertex2f(0 + positionX, baseSizeTriangle + positionY);
    glVertex2f(baseSizeTriangle + positionX, (baseSizeTriangle / 2) + positionY);
    glEnd();
    break;
  case 'l':
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue);
    glVertex2f(0 + positionX, (baseSizeTriangle / 2) + positionY);
    glVertex2f(baseSizeTriangle + positionX, 0 + positionY);
    glVertex2f(baseSizeTriangle + positionX, baseSizeTriangle + positionY);
    glEnd();
    break;
  case 'u':
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue);
    glVertex2f(0 + positionX, 0 + positionY);
    glVertex2f(baseSizeTriangle + positionX, 0 + positionY);
    glVertex2f((baseSizeTriangle / 2) + positionX, baseSizeTriangle + positionY);
    glEnd();
    break;
  case 'd':
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue);
    glVertex2f(0 + positionX, baseSizeTriangle + positionY);
    glVertex2f(baseSizeTriangle + positionX, baseSizeTriangle + positionY);
    glVertex2f((baseSizeTriangle / 2) + positionX, 0 + positionY);
    glEnd();
    break;
  }
}
