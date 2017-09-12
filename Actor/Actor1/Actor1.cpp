// Actor1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MovieActor.h"

Character int2charcter(int a);
int main()
{
	Date dateTemp;
	string sAcNum, SS;
	string sTemp;
	int iTemp, AcNum, iCharacter, month, movNum = 0;
	Character character;
	string name1, name2;
	dateTemp.setDay(0);
	dateTemp.setMonth(0);
	dateTemp.setYear(0);
	ifstream input1("MAList.txt");   //ifstream用于读txt文件
	while (!input1.is_open())
	{
		cout << "text is not exist!" << endl;
		return 0;
	}
	cout << "read data successful!" << endl;
	getline(input1, sAcNum);
	AcNum = stoi(sAcNum);
	void *raw = operator  new[](AcNum * sizeof(MovieActor));
	MovieActor *MaArray = static_cast<MovieActor *>(raw);
	for (size_t i = 0; i < AcNum; i++)
		new (&MaArray[i])MovieActor("defalt", Character::Comedy, dateTemp);
	string *strArr1 = new string[AcNum];
	for (size_t i = 0; i < AcNum; i++)
	{
		stringstream ss(SS);
		getline(input1, SS);
		ss << SS;		//将流SS1传给ss
		ss >> sTemp;  //将ss中的第一个数据传给sTemp
		strArr1[i] = sTemp;
		ss >> iTemp;
		iCharacter = iTemp;
		character = int2charcter(iCharacter);
		ss >> iTemp;
		dateTemp.setYear(iTemp);
		ss >> iTemp;
		dateTemp.setMonth(iTemp);
		ss >> iTemp;
		dateTemp.setDay(iTemp);
		MaArray[i].setCharacter(character);
		MaArray[i].setBirthday(dateTemp);
	}
	cout << endl;
	for (size_t i = 0; i < AcNum; i++)
		MaArray[i].setName(strArr1[i].c_str());
	cout << "Movie Actor List:" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < AcNum; i++)
		cout << MaArray[i] << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "input two correct name:" << endl;
	cin >> name1 >> name2;
	for (size_t i = 0; i < AcNum; i++)
	{
		for (size_t j = i + 1; j < AcNum; j++)
		{
			if ((strcmp(name1.c_str(), MaArray[i].getName()) == 0 && strcmp(name2.c_str(), MaArray[j].getName()) == 0))
			{
				if (MaArray[i].getCharacter() == MaArray[j].getCharacter()) cout << "same" << endl;
				else
				{
					cout << "not same:" << endl;
					cout << name1 << ":";
					switch (MaArray[i].getCharacter())
					{
					case Tragedy:
						cout << "Tragedy";
						break;
					case Comedy:
						cout << "Comedy";
						break;
					case WomanDressedLikeMan:
						cout << "WomanDressedLikeMan";
						break;
					case Juvenile:
						cout << "Juvenile";
						break;
					default:
						break;
					}
					cout << endl << name2 << ":";
					switch (MaArray[j].getCharacter())
					{
					case Tragedy:
						cout << "Tragedy";
						break;
					case Comedy:
						cout << "Comedy";
						break;
					case WomanDressedLikeMan:
						cout << "WomanDressedLikeMan";
						break;
					case Juvenile:
						cout << "Juvenile";
						break;
					default:
						break;
					}
					cout << endl;
				}
			}
		}
	}
	system("pause");
    return 0;
}
Character int2charcter(int a)
{
	switch (a)
	{
	case 0:
		return Character::Tragedy;
	case 1:
		return Character::Comedy;
	case 2:
		return Character::WomanDressedLikeMan;
	case 3:
		return Character::Juvenile;
	default:
		break;
	}
}

