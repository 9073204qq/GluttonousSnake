#include "GluttonousSnake.h"


static Draw* draw = 0;
static Board* board = 0;
static keyEvent* key_event = 0;
static Snake* snake = 0;


void timerProc(int id)
{

	glClearColor(0.96, 0.96, 0.863, 1.0);//000��ɫ,111��ɫ
	glClear(GL_COLOR_BUFFER_BIT);
	if (!snake->crashed)
	{	

		snake->move(board->board_XY, board);//������ƶ�Ҫ����board����
		draw->DrawSnake(snake->body);//���ƹ���Ҫ����������Ϣ
		draw->DrawFood(board->foodPos);//board����ʳ����ƹ���Ҫ���board�����Ϣ
		draw->DrawGrid();
		draw->DrawWall();
	}
	else
	{
		//draw->DrawSnake(snake->body);//���ƹ���Ҫ����������Ϣ
		//draw->DrawFood(board->foodPos);//board����ʳ����ƹ���Ҫ���board�����Ϣ
		draw->DrawGrid();
		draw->DrawWall();
		draw->gameOver();
	}

	glutSwapBuffers();
	glutTimerFunc(500, timerProc, 1);//��Ҫ�ں������ٵ���һ�Σ����ܱ�֤ѭ��  
}

void myReshape(int x, int y)
{
	draw->myReshape(x, y);
}
void myDisplay()
{
	draw->myDisplay();
}
void KeyDown(unsigned char key, int x, int y)
{
	key_event->KeyDown(key, x, y);
}
int main(int argc, char ** argv) {
	/*��ʼ��*/
	draw = new Draw;
	board = new Board;
	snake = new Snake;
	key_event = new keyEvent(snake);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);//˫���塢RGBģʽ
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Gluttonous Snake");//���ڱ���
	glShadeModel(GL_SMOOTH);//����Ϊ�⻬����ģʽ
							/*��������ʾ*/
	glutReshapeFunc(myReshape);//���ڴ�С�����ı�ʱ��ȡ����Ϊ
	glutDisplayFunc(myDisplay);//��ʾ����ͼ��
	glutTimerFunc(500, timerProc, 1);
	glutKeyboardFunc(KeyDown);
	//glutMouseFunc(mouse);
	//glutIdleFunc(myDisplay);
	glutMainLoop();//ѭ��

	delete draw;
	delete board;
	delete snake;
	delete key_event;
	return(0);
}

