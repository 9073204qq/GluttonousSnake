#include"keyEvent.h"


void keyEvent::KeyDown(unsigned char key, int x, int y)
{
	snk->dirCheck();//��ⲻ���ߵķ���
	//���ݰ���ֵ�趨����
	if (key == 'w')
	{
		if ( snk->up != snk->direction_nallow)
		snk->direction = snk->up;
	}
	if (key == 'a')
	{
		if (snk->left != snk->direction_nallow)
		snk->direction = snk->left;
	}
	if (key == 's')
	{
		if (snk->down != snk->direction_nallow)
		snk->direction = snk->down;
	}
	if (key == 'd')
	{
		if (snk->right != snk->direction_nallow)
		snk->direction = snk->right;
	}
}
