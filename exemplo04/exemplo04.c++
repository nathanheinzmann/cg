#include <stdio.h>
#include <GL/glut.h>

float x = 0, y = 0, referencia = 2;
float rf = referencia / 2;
float ri = -rf;

float houseHeight = 3;
float houseWidth = 4.2;
float sideHouseWidth = 1;

float doorHeight = 2;
float doorWidth = 0.8;
float doorBorderHeight = doorHeight + 0.15;
float doorBorderWidth = doorWidth + 0.15;

float frontalWindowHeight = 0.8;
float frontalWindowWidth = 0.8;
float windowBorderHeight = frontalWindowHeight + 0.15;
float windowBorderWidth = frontalWindowWidth + 0.15;

float sizeWindowHeight = 0.8;
float sizeWindowWidth = 0.5;
float sizeWindowAngle = 0.5;

float halfRoofHeight = houseWidth;
float halfRoofWidth = houseWidth;

void Background()
{
  glClearColor(1, 1, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Porta()
{
  float proportion = 0.1;
  float xPosition = 0.05;
  float yPosition = 0.05 * proportion;

  glBegin(GL_QUADS);

  glColor3f(0.8, 0.4, 0.06);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (doorHeight * proportion) + yPosition);
  glVertex2f((doorWidth * proportion) + xPosition, (doorHeight * proportion) + yPosition);
  glVertex2f((doorWidth * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void ParedeFrente()
{
  float proportion = 0.1;
  float xPosition = 0;
  float yPosition = 0;

  glBegin(GL_QUADS);

  glColor3f(0.5, 0.8, 0.2);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (houseHeight * proportion) + yPosition);
  glVertex2f((houseWidth * proportion) + xPosition, (houseHeight * proportion) + yPosition);
  glVertex2f((houseWidth * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void ParedeLateral()
{
  float proportion = 0.1;
  float xPosition = 0;
  float yPosition = 0;

  glBegin(GL_QUADS);

  glColor3f(0.8, 0.8, 0.4);
  glVertex2f((houseWidth * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((houseWidth * proportion) + xPosition, (houseHeight * proportion) + yPosition);
  glVertex2f(((houseWidth + sideHouseWidth) * proportion) + xPosition, (houseHeight * proportion) + yPosition);
  glVertex2f(((houseWidth + sideHouseWidth) * proportion) + xPosition, (1 * proportion) + yPosition);

  glEnd();
}

void JanelaFrontal(float x = 0.2, float y = 0.15)
{
  float proportion = 0.1;
  float xPosition = x;
  float yPosition = y;

  glBegin(GL_QUADS);

  glColor3f(0.8, 0.4, 0.06);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (frontalWindowHeight * proportion) + yPosition);
  glVertex2f((frontalWindowWidth * proportion) + xPosition, (frontalWindowHeight * proportion) + yPosition);
  glVertex2f((frontalWindowWidth * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void JanelaLateral()
{
  float proportion = 0.1;
  float xPosition = 0.025;
  float yPosition = 0.15;

  glBegin(GL_QUADS);

  glColor3f(0.8, 0.4, 0.06);
  glVertex2f((houseWidth * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((houseWidth * proportion) + xPosition, (sizeWindowHeight * proportion) + yPosition);
  glVertex2f(((houseWidth + sizeWindowWidth) * proportion) + xPosition, ((sizeWindowHeight + sizeWindowAngle) * proportion) + yPosition);
  glVertex2f(((houseWidth + sizeWindowWidth) * proportion) + xPosition, ((0 + sizeWindowAngle) * proportion) + yPosition);

  glEnd();
}

void Vaso() {}

void Planta() {}

void Teto()
{
  float proportion = 0.1;
  float xPosition = ((houseWidth + sideHouseWidth) / 2) * proportion;
  float yPosition = houseHeight * proportion;

  glBegin(GL_POLYGON);

  glColor3f(0, 0, 0);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((-halfRoofWidth * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((-halfRoofWidth * 1 / 3 * proportion) + xPosition, ((halfRoofHeight * 2 / 5) * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (halfRoofHeight * proportion) + yPosition);
  glVertex2f((halfRoofWidth * 1 / 3 * proportion) + xPosition, ((halfRoofHeight * 2 / 5) * proportion) + yPosition);
  glVertex2f((halfRoofWidth * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void BordaPorta()
{
  float proportion = 0.1;
  float xPosition = 0.42 * proportion;
  float yPosition = 0;

  glBegin(GL_QUADS);

  glColor3f(1, 1, 1);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (doorBorderHeight * proportion) + yPosition);
  glVertex2f((doorBorderWidth * proportion) + xPosition, (doorBorderHeight * proportion) + yPosition);
  glVertex2f((doorBorderWidth * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void BordaJanela()
{
  float proportion = 0.1;
  float xPosition = 1.9 * proportion;
  float yPosition = 1.45 * proportion;

  glBegin(GL_QUADS);

  glColor3f(1, 1, 1);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (windowBorderHeight * proportion) + yPosition);
  glVertex2f((windowBorderWidth * 2 * proportion) + xPosition, (windowBorderHeight * proportion) + yPosition);
  glVertex2f((windowBorderWidth * 2 * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void TetoDireito()
{
  float proportion = 0.1;
  float xPosition = 0.05;
  float yPosition = 0;

  glBegin(GL_QUADS);

  glColor3f(0.8, 0.4, 0.06);
  glVertex2f((0 * proportion) + xPosition, (0 * proportion) + yPosition);
  glVertex2f((0 * proportion) + xPosition, (doorHeight * proportion) + yPosition);
  glVertex2f((doorWidth * proportion) + xPosition, (doorHeight * proportion) + yPosition);
  glVertex2f((doorWidth * proportion) + xPosition, (0 * proportion) + yPosition);

  glEnd();
}

void Desenha(void)
{
  Background();
  ParedeFrente();
  ParedeLateral();
  BordaPorta();
  Porta();
  BordaJanela();
  JanelaFrontal();
  JanelaFrontal(0.29);
  JanelaLateral();
  Teto();
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

  glutInitWindowSize(600, 600);

  glutInitWindowPosition(2590, 10);

  glutCreateWindow("3o Exemplo");

  glutDisplayFunc(Desenha);

  glutMainLoop();

  system("pause");

  return (0);
}
