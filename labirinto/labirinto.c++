#include <stdio.h>
#include <GL/glut.h>
#include "plano.h"
#include "grid.h"
#include "lineGenerator.h"
#include "triangle.h"

int x_translacao, y_translacao, angulo_rotacao = 0;
float x_escala = 1, y_escala = 1;
int translacao = 0, rotacao = 0, escala = 0;

float x = 0, y = 0, referencia = 2;
float rf = referencia / 2;
float ri = -rf;

float trianglePositionY = 0;
float trianglePositionX = -1;
char triangleDirection = 'r';

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
    trianglePositionY += 0.1;
    triangleDirection = 'u';
    printf("tecla up\n");
  }
  if (tecla == GLUT_KEY_DOWN)
  {
    trianglePositionY -= 0.1;
    triangleDirection = 'd';
    printf("tecla down\n");
  }
  if (tecla == GLUT_KEY_LEFT)
  {
    trianglePositionX -= 0.1;
    triangleDirection = 'l';
    printf("tecla left\n");
  }
  if (tecla == GLUT_KEY_RIGHT)
  {
    trianglePositionX += 0.1;
    triangleDirection = 'r';
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

void Labirinto()
{
  LineGenerator(-1, -0.4, 0, 'x');
  LineGenerator(0, 0.2, -0.4, 'y');
  LineGenerator(-0.4, -0.1, 0.2, 'x');
  LineGenerator(0.2, -0.4, -0.1, 'y');
  LineGenerator(-0.1, -0.8, -0.4, 'x');
  LineGenerator(-0.4, -0.8, -0.8, 'y');
  LineGenerator(-0.8, 0.2, -0.8, 'x');
  LineGenerator(-0.8, 0.5, 0.2, 'y');
  LineGenerator(0.2, 1, 0.5, 'x');
}

void Desenha()
{
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  Grid(ri, rf);
  Labirinto();

  Triangle(triangleDirection, trianglePositionX, trianglePositionY);

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
