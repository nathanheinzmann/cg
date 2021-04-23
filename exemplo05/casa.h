float Modulo (float n) {
	return n < 0 ? ( n * (-1) ) : (n); 
}

float Distancia (float p1, float p2) {
	if ( (p1 >= 0.00) && (p2 >= 0.00) || (p1 < 0.00) && (p2 < 0.00) ) return ( Modulo (p2 - p1) );
	else return ( (Modulo (p1) + Modulo (p2)) );
}

void DesenhaCasa (float x_p1, float y_p1, float altura, int quadro) {
	float x_p2, y_p2, x_base;
	x_p2 = x_p1 + altura;
	y_p2 = y_p1 + altura;
	
	if ( quadro ) {
		glColor3f (1.0f, 0.0f, 0.0f);
		glBegin (GL_LINE_LOOP); // quadro
			glVertex2f (x_p1, y_p1);
			glVertex2f (x_p1, y_p2);
			glVertex2f (x_p2, y_p2);
			glVertex2f (x_p2, y_p1);
		glEnd ();
	}
	
	glColor3f (0.0f, 0.0f, 1.0f);
	x_base = Distancia (x_p1, x_p2) / 10;
	glBegin (GL_QUADS); // base
		glVertex2f ( (x_p1 + x_base), y_p1);
		glVertex2f ( (x_p1 + x_base), (y_p2 - (altura / 2.5)) );
		glVertex2f ( (x_p2 - x_base), (y_p2 - (altura / 2.5)) );
		glVertex2f ( (x_p2 - x_base), y_p1);
	glEnd ();
	
	glColor3f (1.0f, 5.0f, 0.0f);
	x_base = Distancia (x_p1, x_p2) / 2;
	glBegin (GL_TRIANGLES); // telhado
		glVertex2f (x_p1, (y_p2 - (altura / 2.5)) );
		glVertex2f ( (x_p1 + x_base), y_p2);
		glVertex2f (x_p2, (y_p2 - (altura / 2.5)) );
	glEnd ();
	
	glColor3f(1.0f, 1.0f, 1.0f);
	x_base = Distancia(x_p1, x_p2) / 6;
	glBegin (GL_QUADS); // porta e janela
		glVertex2f ( (x_p1 + x_base), y_p1);
		glVertex2f ( (x_p1 + x_base), (y_p2 - (altura / 2.0)) );
		glVertex2f ( (x_p1 + (2 * x_base) ), (y_p2 - (altura / 2.0)) );
		glVertex2f ( (x_p1 + (2 * x_base) ), y_p1);
		glVertex2f ( (x_p1 + (2.7 * x_base) ), (y_p1 + (altura / 4.0)) );
		glVertex2f ( (x_p1 + (2.7 * x_base) ), (y_p2 - (altura / 2.0)) ); 
		glVertex2f ( (x_p1 + (4.7 * x_base) ), (y_p2 - (altura / 2.0)) );
		glVertex2f ( (x_p1 + (4.7 * x_base) ), (y_p1 + (altura / 4.0)) );
	glEnd ();
	
	glColor3f (0.0f, 0.0f, 1.0f);
	glBegin (GL_LINES); // "linhas" da janela
		glVertex2f ( (x_p1 + (2.7 * x_base) ), (y_p1 + (altura / 2.7)) );
		glVertex2f ( (x_p1 + (4.7 * x_base) ), (y_p1 + (altura / 2.7)) );
		glVertex2f ( (x_p1 + (3.7 * x_base) ), (y_p1 + (altura / 4.0)) );
		glVertex2f ( (x_p1 + (3.7 * x_base) ), (y_p2 - (altura / 2.0)) );
	glEnd ();
}

