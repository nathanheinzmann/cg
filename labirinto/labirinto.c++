#include <stdio.h>
#include <GL/glut.h>
#include "plano.h"

#define TAM_JANELA 100.0

int x_translacao, y_translacao, angulo_rotacao = 0;
float x_escala = 1, y_escala = 1;
int translacao = 0, rotacao = 0, escala = 0;

void Desenha()
{
  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  DesenhaPlano(TAM_JANELA, 1, 1, 0);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(x_translacao, y_translacao, 0);
  glScalef(x_escala, y_escala, 0.0);
  glRotatef(angulo_rotacao, 0, 0, 1);
  glPopMatrix();
  glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
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
    translacao = 1;
    escala = rotacao = 0;
  }
  if (key == 'e')
  {
    printf("escala OK\n");
    escala = 1;
    translacao = rotacao = 0;
  }
  if (key == 'r')
  {
    printf("rotacao OK\n");
    rotacao = 1;
    translacao = escala = 0;
  }
}

void TeclasEspeciais(int tecla, int x, int y)
{
  if (tecla == GLUT_KEY_UP)
  {
    printf("tecla up\n");
    if (translacao)
      y_translacao += 5;
    if (escala)
      y_escala += 0.1;
  }
  if (tecla == GLUT_KEY_DOWN)
  {
    printf("tecla down\n");
    if (translacao)
      y_translacao -= 5;
    if (escala)
      y_escala -= 0.1;
  }
  if (tecla == GLUT_KEY_LEFT)
  {
    printf("tecla left\n");
    if (translacao)
      x_translacao -= 5;
    if (rotacao)
      angulo_rotacao += 5;
    if (escala)
      x_escala -= 0.1;
  }
  if (tecla == GLUT_KEY_RIGHT)
  {
    printf("tecla right\n");
    if (translacao)
      x_translacao += 5;
    if (rotacao)
      angulo_rotacao -= 5;
    if (escala)
      x_escala += 0.1;
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

void Inicializa()
{
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-TAM_JANELA, TAM_JANELA, -TAM_JANELA, TAM_JANELA);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("Transformacoes Geometricas");
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutKeyboardFunc(Teclado);
  glutSpecialFunc(TeclasEspeciais);

  glutMouseFunc(GerenciaMouse);
  glutMotionFunc(MoveMouseBotaoPressionado);
  glutPassiveMotionFunc(MoveMouse);
  glutIdleFunc(SistemaOcioso);
  Inicializa();
  glutMainLoop();
  system("pause");
  return (0);
}
