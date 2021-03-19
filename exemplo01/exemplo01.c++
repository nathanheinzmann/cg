#include <stdio.h>
#include <GL/glut.h>

void Desenha(void)
{
}

void Teclado(void)
{
}

void Inicializa(void)
{
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
