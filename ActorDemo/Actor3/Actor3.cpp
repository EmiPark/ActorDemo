// Actor3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Dubber.h"
Character int2charcter(int a);
int main()
{
	Date dateTemp;
	string sAcNum, sDuNum, SS1, SS2;
	string sTemp;
	int month, chaNum = 0, movNum = 0;
	int iTemp, AcNum, DuNum, MovNum, iCharacter, iMovNum, chooseCha; 
	//iMovNum是获取txt中数据用的，MovNum用于设置第三问的阈值，movNum用于记录有多少人大于这个阈值
	Character character;
	string name1, name2, name3, name4;
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
		stringstream ss(SS1);
		getline(input1, SS1);
		ss << SS1;		//将流SS1传给ss
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
		stringstream ss(SS2);
		getline(input2, SS2);
		ss << SS2;
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
	cout << "first question:" << endl;
	cout << "input birth month to select actor：" << endl;
	cin >> month;
	cout << "actor information:" << endl;
	for (size_t i = 0; i < AcNum; i++)
		if (MaArray[i].getBirthday().getMonth() == month) cout << MaArray[i] << " "; 
	cout << endl<<endl;
	cout << "second question:" << endl;
	cout << "input character which needed to account actor's number：" << endl;
	cout << "1 means Tragedy,2 means Comedy,3 means WomanDressedLikeMan,4 means Juvenile" << endl;
	cin >> chooseCha;
	for (size_t i = 0; i < AcNum; i++)
		if (MaArray[i].getCharacter() == chooseCha - 1) chaNum++;
	cout << "this actor's number:" << chaNum << endl << endl;
	cout << "third question:" << endl;
	cout << "input movie number as threshold:" << endl;
	cin >> MovNum;
	cout << "people who's movie number is not greater than " << MovNum << ":" << endl;
	for (size_t i = 0; i < DuNum; i++)
	{
		if (VecDu[i].getNum()>MovNum) movNum++;
		else
			cout << VecDu[i] << endl;
	}
	cout << "the number that dubber who's movie number greater than " << MovNum << " is:" << movNum << endl;
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


