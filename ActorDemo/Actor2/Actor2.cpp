// Actor2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Dubber.h"
Character int2charcter(int a);
int main()
{
	string sDuNum, sTemp, name1, name2;
	int DuNum, iTemp, iCharacter, iMovNum,month;
	Character character;
	Date dateTemp;
	string SS;
	ifstream input2("DuList.txt");
	while (!input2.is_open())
	{
		cout << "text is not exist!" << endl;
		return 0;
	}
	cout << "read data successful!" << endl;
	getline(input2, sDuNum);
	DuNum = stoi(sDuNum);
	vector<Dubber> VecDu;
	VecDu.reserve(1);
	for (size_t i = 0; i < DuNum; i++)
	{
		Dubber d("defult", Character::Comedy, dateTemp, 0);
		VecDu.push_back(d);
	}
	string *strArr2 = new string[DuNum];
	for (size_t i = 0; i < DuNum; i++)
	{
		stringstream ss(SS);
		getline(input2, SS);
		ss << SS;
		ss >> sTemp;
		strArr2[i] = sTemp;
		ss >> iTemp;
		iCharacter = iTemp;
		character = int2charcter(iCharacter);
		ss >> iTemp;
		dateTemp.setYear(iTemp);
		ss >> iTemp;
		dateTemp.setMonth(iTemp);
		ss >> iTemp;
		dateTemp.setDay(iTemp);
		ss >> iTemp;
		iMovNum = iTemp;
		VecDu[i].setCharacter(character);
		VecDu[i].setBirthday(dateTemp);
		VecDu[i].setNum(iMovNum);
	}
	for (size_t i = 0; i < DuNum; i++)
		VecDu[i].setName(strArr2[i].c_str());
	cout << "Dubber List:" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	for (size_t i = 0; i < DuNum; i++)
		cout << VecDu[i] << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "input two correct name:" << endl;
	cin >> name1 >> name2;
	for (size_t i = 0; i < DuNum; i++)
	{
		for (size_t j = i + 1; j < DuNum; j++)
		{
			if ((strcmp(name1.c_str(), VecDu[i].getName()) == 0 && strcmp(name2.c_str(), VecDu[j].getName()) == 0))
			{
				if (VecDu[i].getNum() == VecDu[j].getNum()) cout << "same" << endl;
				else
				{
					cout << "not same:" << endl;
					cout << name1 << ":" << VecDu[i].getNum() << endl;
					cout << name2 << ":" << VecDu[j].getNum() << endl;
				}
			}
		}
	}
	cout << "input birth month to select actor：" << endl;
	cin >> month;
	cout << "actor information：" << endl;
	for (size_t i = 0; i < DuNum; i++)
		if (VecDu[i].getBirthday().getMonth() == month) cout << VecDu[i] << " ";  //输出emun
	cout << endl;
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

