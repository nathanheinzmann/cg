#include <stdio.h>
#include <GL/glut.h>

void Desenha(void)
{
  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glColor3f(1, 0, 0);
  glVertex3f(-0.5, -0.5, 0);
  glVertex3f(0.0, 0.5, 0);
  glVertex3f(0.5, -0.5, 0);
  glEnd();

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

  glutInitWindowSize(300, 300);

  glutInitWindowPosition(10, 10);

  glutCreateWindow("1o Exemplo");

  glutDisplayFunc(Desenha);

  glutMainLoop();

  system("pause");

  return (0);
}
