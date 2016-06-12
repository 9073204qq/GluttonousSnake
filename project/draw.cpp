#include"draw.h"

void Draw::DrawString(void *font, const char s[], float x, float y)
{
	glColor3f(0, 0, 0);
	unsigned int i;
	glRasterPos2f(x, y);
	for (i = 0; i < strlen(s); i++)
	{
		glutBitmapCharacter(font, s[i]);
	}
}

void Draw::DrawGrid()
{
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);

	float row = boardSize * 10 + 10;
	float column = -boardSize * 10 - 10;
	for (int i = 0; i < boardSize * 2 + 1; i++)
	{
		row -= 10;              column += 10;

		glVertex2f(-boardSize * 10, row);			glVertex2f(boardSize * 10, row);

		glVertex2f(column, -boardSize * 10);			glVertex2f(column, boardSize * 10);
	}
	glEnd();
}

void Draw::DrawSnake(vector<strucPos>  &  body)
{

	for (auto it = body.begin(); it != body.end(); it++)
	{
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);

		glVertex2f(it->x * 10 - 10, it->y * 10);     // ����
		glVertex2f(it->x * 10, it->y * 10);     // ����
		glVertex2f(it->x * 10, it->y * 10 - 10);     // ����
		glVertex2f(it->x * 10 - 10, it->y * 10 - 10);     // ����
		glEnd();
	}
}

void Draw::DrawFood(strucPos foodpos)
{


	glBegin(GL_QUADS);
	glColor3f(0.96, 0.6, 0.5);

	glVertex2f(foodpos.x * 10 - 10, foodpos.y * 10);     // ����
	glVertex2f(foodpos.x * 10, foodpos.y * 10);     // ����
	glVertex2f(foodpos.x * 10, foodpos.y * 10 - 10);     // ����
	glVertex2f(foodpos.x * 10 - 10, foodpos.y * 10 - 10);     // ����
	glEnd();
}

void Draw::DrawWall()
{


		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(-boardSize * 10+10*cnt, -boardSize * 10+10);     // ����
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, -boardSize * 10 + 10 );     // ����
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, -boardSize * 10   );     // ����
			glVertex2f(-boardSize * 10 + 10 * cnt, - boardSize * 10 );     // ����
			glEnd();
		}
		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(-boardSize * 10 + 10 * cnt, boardSize * 10 );     // ����
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, boardSize * 10 );     // ����
			glVertex2f(-boardSize * 10 + 10 + 10 * cnt, boardSize * 10-10);     // ����
			glVertex2f(-boardSize * 10 + 10 * cnt, boardSize * 10-10);     // ����
			glEnd();
		}

		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(-boardSize * 10 , -boardSize * 10 + 10 + 10 * cnt);     // ����
			glVertex2f(-boardSize * 10 + 10 , -boardSize * 10 + 10 + 10 * cnt);     // ����
			glVertex2f(-boardSize * 10 + 10 , -boardSize * 10 + 10 * cnt);     // ����
			glVertex2f(-boardSize * 10 , -boardSize * 10 + 10 * cnt);     // ����
			glEnd();
		}
	
		for (int cnt = 0; cnt < boardSize * 2; cnt++)
		{
			glBegin(GL_QUADS);
			glColor3f(0.7, 0.6, 0.5);

			glVertex2f(boardSize * 10-10, -boardSize * 10 + 10 + 10 * cnt);     // ����
			glVertex2f(boardSize * 10 , -boardSize * 10 + 10 + 10 * cnt);     // ����
			glVertex2f(boardSize * 10 , -boardSize * 10 + 10 * cnt);     // ����
			glVertex2f(boardSize * 10-10, -boardSize * 10 + 10 * cnt);     // ����
			glEnd();
		}

	

}

void Draw::gameOver()
{
	DrawString(GLUT_BITMAP_TIMES_ROMAN_24, "Game Over!", -50, 0);
}

void  Draw::myReshape(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;
	// ��ֹ��0����
	if (0 == h)
	{
		h = 1;
	}
	glViewport(0, 0, w, h);// �����ӿ�Ϊ���ڵĴ�С
	glMatrixMode(GL_PROJECTION);// ��ͶӰ����Ӧ�����ľ������
	glLoadIdentity();//�任����λ
	aspectRatio = (GLfloat)w / (GLfloat)h; // ���㴰�ڵ��ݺ�ȣ����رȣ�
	// ����ü����򣨸��ݴ��ڵ��ݺ�ȣ���ʹ����ͶӰ��
	if (w <= h) {// �� < ��
		glOrtho(-boardSize * 10, boardSize * 10, -boardSize * 10 / aspectRatio, boardSize * 10 / aspectRatio, 1.0, -1.0);
	}
	else {// �� > ��
		glOrtho(-boardSize * 10 * aspectRatio, boardSize * 10 * aspectRatio, -boardSize * 10, boardSize * 10, 1.0, -1.0);
	}
	glMatrixMode(GL_MODELVIEW);// ѡ��ģ����ͼ���󣬲���������ϵͳ
	glLoadIdentity();
}

void Draw::myDisplay(void) {

	glClearColor(0.96, 0.96, 0.863, 1.0);//000��ɫ,111��ɫ
	glClear(GL_COLOR_BUFFER_BIT);
	//DrawGrid();
	//DrawSquare(0,0);
	glutSwapBuffers();
}