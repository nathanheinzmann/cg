#include <stdio.h>
#include <GL/glut.h>

void TeclasEspeciais(int tecla, int x, int y)
{
  if (tecla == GLUT_KEY_UP)
  {
    printf("tecla up\n");
  }
  if (tecla == GLUT_KEY_DOWN)
  {
    printf("tecla down\n");
  }
  if (tecla == GLUT_KEY_LEFT)
  {
    printf("tecla left\n");
  }
  if (tecla == GLUT_KEY_RIGHT)
  {
    printf("tecla right\n");
  }
  glutPostRedisplay();
}
