#include <stdio.h>
#include <GL/glut.h>

static int getLineSize(float x, float y)
{
  if (x > y)
  {
    return (x - y) * 10;
  }
  else
  {
    return (y - x) * 10;
  }
}

void generateSquare(float xPosition, float yPosition, float red = 0.3, float green = 0.1, float blue = 0.7)
{
  glBegin(GL_QUADS);
  glColor3f(red, green, blue);
  glVertex2f(0 + xPosition, 0.1 + yPosition);
  glVertex2f(0 + xPosition, 0 + yPosition);
  glVertex2f(0.1 + xPosition, 0 + yPosition);
  glVertex2f(0.1 + xPosition, 0.1 + yPosition);
  glEnd();
}

void LineGenerator(float from, float to, float baseAxis, char axis)
{
  float lineSize = getLineSize(from, to);

  float startPoint = from;
  float endPoint = to;
  if (to < from)
  {
    endPoint = from;
    startPoint = to;
  };

  while (startPoint <= endPoint)
  {
    if (axis == 'y' || axis == 'Y')
    {
      generateSquare(baseAxis, startPoint);
    }
    else
    {
      generateSquare(startPoint, baseAxis);
    }
    startPoint += 0.1;
  }
}
