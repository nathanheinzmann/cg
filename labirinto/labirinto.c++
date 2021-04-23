#include <stdio.h>
#include <GL/glut.h>
#include "plano.h"

int x_translacao, y_translacao, angulo_rotacao = 0;
float x_escala = 1, y_escala = 1;
int translacao = 0, rotacao = 0, escala = 0;

float x = 0, y = 0, referencia = 2;
float rf = referencia / 2;
float ri = -rf;

float trianglePositionY, trianglePositionX = 0;

void Lines()
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

void Labirint()
{
  float x[] = {-1, -0.8, -0.9, 0.3, 0.8};
  float y[] = {0, -0.2, 0.9, -0.3, 0.3};

  int i = 0;
  glBegin(GL_QUADS);
  glColor3f(0, 0.2, 0.5);
  for (i = 0; i < 5; i++)
  {
    glVertex2f(0 + x[i], 0.1 + y[i]);
    glVertex2f(0 + x[i], 0 + y[i]);
    glVertex2f(0.1 + x[i], 0 + y[i]);
    glVertex2f(0.1 + x[i], 0.1 + y[i]);
  }
  glEnd();
}

void Triangulo()
{
  // float x = {-1, -0.8, -0.9, 0.3, 0.8};
  // float y = {0, -0.2, 0.9, -0.3, 0.3};

  int baseSizeTriangle = 0.1;
  glBegin(GL_TRIANGLES);
  glColor3f(0.4, 0.5, 0.1);
  glVertex3f(-1 + trianglePositionX, 0 + trianglePositionY, 0);
  glVertex3f(-1 + trianglePositionX, 0.1 + trianglePositionY, 0);
  glVertex3f(-0.9 + trianglePositionX, 0.05 + trianglePositionY, 0);
  glEnd();
}

void Teclado(unsigned char key, int x, int y)
{
  if (key == 27)
  {
    exit(0);
  }
  if (key == 't')
  {
    printf("translacao OK\n");
  }
  if (key == 'e')
  {
    printf("escala OK\n");
  }
  if (key == 'r')
  {
    printf("rotacao OK\n");
  }
}

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

void GerenciaMouse(int botao, int estado, int x, int y)
{
}

void MoveMouseBotaoPressionado(int x, int y)
{
}

void MoveMouse(int x, int y)
{
}

void SistemaOcioso(void)
{
}

void Desenha()
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  Lines();
  Labirint();

  Triangulo();

  glFlush();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(700, 700);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Transformacoes Geometricas");
  glutDisplayFunc(Desenha);
  glutKeyboardFunc(Teclado);
  glutSpecialFunc(TeclasEspeciais);
  glutMouseFunc(GerenciaMouse);
  glutMotionFunc(MoveMouseBotaoPressionado);
  glutPassiveMotionFunc(MoveMouse);
  glutIdleFunc(SistemaOcioso);
  glutMainLoop();
  system("pause");
  return (0);
}
