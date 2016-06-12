#include"Board.h"


Board::Board()
{
	//��ʼ��boardά����λ�þ���
	for (int _i_cnt = 0; _i_cnt < boardSize*2; _i_cnt++)
	{
		board_XY.push_back(vector<int>( 0));
		for (int _j_cnt = 0; _j_cnt < boardSize*2; _j_cnt++)
		{
			board_XY[_i_cnt].push_back(0);
		}
	}
	//����ĳ�ʼλ���ǹ̶��ģ��Դ����޸������λ�þ���
	board_XY.at(boardSize / 2).at(boardSize / 2) = 1;
	board_XY.at(boardSize / 2-1).at(boardSize / 2) = 1;
	//����ʳ��
	foodPos = createFood();
}


//��λ�þ����������ѡֵΪ0�����꣬���������꣬����������
strucPos Board::createFood()
{
	int x = myRandom(2, boardSize*2-1 );
	vector<int> tmp;
	int cnt = 1;
	for (auto it = board_XY.at(x).begin()+1; it != board_XY.at(x).end()-2; it++)
	{	
		cnt++;
		if (*it == 0)
			tmp.push_back(cnt-1);
	}
	int y = myRandom(0, tmp.size()-1);
	y = tmp.at(y);
	strucPos pos(x-boardSize, y-boardSize+1);
	
	return pos;
}



int Board::myRandom(int begin, int end)
{
	std::default_random_engine generator(time(NULL));
	std::uniform_int_distribution<int> dis(begin, end);
	auto dice = std::bind(dis, generator);
	return dice();
}


