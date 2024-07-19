#include"Management.h"

//���캯��
UsersManagement::UsersManagement()
{
	this->m_Index = 0;
	this->m_Error = 0;
}


void UsersManagement::showMenu()
{
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                   ��ӭʹ��ͼ�����ϵͳ                     ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***           1.���ͼ��                2.�黹ͼ��             ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           3.ͼ�鶪ʧ                4.�鿴����ͼ��         ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           5.����ͼ��                6.�û�ע��             ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           7.����Ա��Ȩ              8.������֪             ***" << endl;
	cout << "                          ******************************************************************" << endl;
}

//�û�ע��
void UsersManagement::addUser()
{
	//��ʾע�����
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         �û�ע��                           ***" << endl;
	cout << "                          ******************************************************************" << endl;

	//�������֤��
	cout << "���������֤���룺" << endl;
	string idCard;
	cin >> idCard;

	//�ж�  18   0~9  idCard[17]   ->A  Z

	for (int i = 0; i < 17; i++)
	{
		if (idCard.size() != 18 || idCard[i] > '9' || idCard[i] < '0' || (idCard[17] > 'Z' && idCard[17] < 'A') || (idCard[17] < '0' && idCard[17]>'9'))
		{
			cout << "������˺Ų����Ϲ淶��" << endl;
			system("pause");
			return;
		}
	}



	//��������
	string mima1;
	string mima2;
	cout << "���������룺" << endl;
	cin >> mima1;
	cout << "���ٴ��������룺" << endl;
	cin >> mima2;

	//�ȶ�����
	if (mima1 != mima2)
	{
		cout << "��������������벻ƥ�䣡" << endl;
		cout << "�����½��뱾ҳ��<<лл>>" << endl;
		system("pause");
		system("cls");
		return;
	}

	//���ļ�

	ifstream ifs;
	ifs.open("�û�ע����Ϣ.txt", ios::out);

	if (!ifs.is_open())
	{
		cout << "�ļ�·���������⣡" << endl;
		system("pause");
		return;
	}
	else
	{
		//��������
		string userData;
		while (ifs >> userData)
		{
			int pos = -1;
			int start = 0;
			while (1)
			{

				pos = userData.find(",", start);
				if (pos == -1)
				{
					break;
				}
				else
				{
					string target = userData.substr(start, pos - start);

					if (target == idCard)
					{
						cout << "�˺��Ѿ����ڣ����޷��ٽ���ע�ᡷ" << endl;
						system("pause");
						system("cls");
						return;
					}
				}

				//���ý�ȡ����ʼ��
				start = pos + 1;
			}

		}

	}

	//ע��ɹ���  ��������ӵ��ļ���
	ofstream ofs;
	ofs.open("�û�ע����Ϣ.txt", ios::in | ios::app);
	//��ʧ��
	if (!ofs.is_open())
	{
		cout << "�ļ�·���������⣡" << endl;
		system("pause");
		return;
	}

	//�ɹ�
	ofs << idCard << "," << mima1 << ",";

	//�ر��ļ�
	ofs.close();

	cout << "��ע��ɹ���" << endl;
	system("pause");




}

//������֪
void UsersManagement::borrowBookNotice()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         ������֪                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << "                          <<<<                       ϵͳ��δ��ȫ                       >>>>" << endl;
	cout << endl;
	cout << "                          <<                                                              >>" << endl;
	cout << "                          <<        ��1�� ͼ��黹һ��ֻ�ܹ黹һ������������˳��      >>" << endl;
	cout << "                          <<                                                              >>" << endl;
	cout << endl;
	cout << "                          <<<<                  ���ͼ����֪���������                  >>>>" << endl;

	cout << "************************************************************************************************************************" << endl;
	system("pause");
	system("cls");
}

//ͼ�鶪ʧ
void UsersManagement::reduceBook()
{

	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         ͼ�鶪ʧ                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << endl;
	cout << "                                       <<��ʧͼ������ϵͼ�鶪ʧ�����ˣ�С��>>" << endl;
	cout << endl;
	cout << "                                       <<�⳥�����С��΢�Ž���΢��ת���⳥>>" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "С�Ƶ绰�� 10086" << endl;
	cout << "С��qq�� 2607995048" << endl;
	cout << "************************************************************************************************************************" << endl;
	system("pause");
	system("cls");
}




/**************************************************************************************************/
/*************************************************************************************************/


//���캯��
Users::Users() {}
		 
//���ͼ��
void Users::borrowBook(BookManagement* library)//����Ķ����ַ
{
	//������Ϣ
	string name;
	cout << "����������������" << endl;
	cin >> name;

	string phone;
	cout << "�����������ֻ����룺" << endl;
	cin >> phone;

	string id;
	cout << "�����������˺ţ�" << endl;
	cin >> id;

	string mima;
	cout << "�������������룺" << endl;
	cin >> mima;


	//�û�ע����Ϣ.txt   ����
	ifstream ifs2;
	ifs2.open("�û�ע����Ϣ.txt", ios::in);//���ļ��ж�ȡ

	vector<string>tempV1;
	string borrowerData;//111111111111111111,123456,444444444444444444,123456,222222222222222222,123456,
	while (ifs2 >> borrowerData)
	{
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = borrowerData.find(",", start);
			if (pos == -1)
			{
				break;
			}

			string target = borrowerData.substr(start, pos - start);
			tempV1.push_back(target);

			start = pos + 1;
		}
	}

	ifs2.close();

	//���û��������Ϣ   ����������������Ϣ���жԱ�     return 

	int num = 0;
	for (vector<string>::iterator it = tempV1.begin(); it != tempV1.end(); it++)
	{//111111111111111111,123456,444444444444444444,123456,222222222222222222,123456,
		if (id == *it)//�˺�ƥ��
		{
			num++;
			it++;//����ƥ��
			if (*it == mima)
			{
				break;
			}
			else
			{
				cout << "�����������" << endl;
				system("pause");
				system("cls");
				this->m_Error = -1;
				return;
			}
		}
	}

	if (num == 0)
	{
		cout << "���˺Ż�û��ע�ᣡ" << endl;
		system("pause");
		system("cls");
		this->m_Error = -1;
		return;
	}



	/*cout << "���Խ�����" << endl;
	system("pause");*/

	//��ʼ����
	//ע�����ָ�����ȷ���ã���������������������������������������������
	library->m_BorrowerV.push_back(name);
	library->m_BorrowerV.push_back(id);
	library->m_BorrowerV.push_back(phone);
	//�洢���� �˻������֤�� �绰 ����Ϣ
	//��ʼ����

	library->HandleBorrow();
	

	//2.��ɾ����ʣ�µ�ͼ��Żص�  ϵͳͼ��.txt


	//��������Ϣ���  6    ����   ���֤   �ֻ�����    һ��ͼ�飨3��


}

//�黹ͼ��
void Users::backBook(BookManagement* library)
{
	//��ʾ����
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                           ͼ��黹                         ***" << endl;
	cout << "                          ******************************************************************" << endl;

	//������Ϣ
	string name;
	cout << "����������������" << endl;
	cin >> name;

	string phone;
	cout << "�����������ֻ����룺" << endl;
	cin >> phone;

	string id;
	cout << "�����������˺ţ�" << endl;
	cin >> id;

	string mima;
	cout << "�������������룺" << endl;
	cin >> mima;

	//���� �û�ע����Ϣ
	ifstream ifs("�û�ע����Ϣ.txt", ios::in);

	string data;
	vector<string>userData_v;
	while (ifs >> data)
	{
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string target = data.substr(start, pos - start);

			userData_v.push_back(target);
			start = pos + 1;
		}
	}
	ifs.close();



	//����˺�  ����  �Ƿ���ȷ
	bool isIdRight = false;
	for (vector<string>::iterator it = userData_v.begin(); it != userData_v.end(); it++)
	{
		if (*it == id)
		{
			isIdRight = true;
			//111111111111111111, 123456,
			it++;
			if (*it == mima)
			{
				break;
			}
			else
			{
				cout << "�����������" << endl;
				system("pause");
				this->m_Error = -1;
				return;
			}

		}

	}

	if (isIdRight == false)
	{
		cout << "�˺Ż������������" << endl;
		system("pause");
		this->m_Error = -1;
		return;
	}


	//1.�ɹ� ��ʼ�黹    2.ʧ��  return
	
	ifstream ifs2("��������Ϣ.txt", ios::in);

	string borrower_Data;
	vector<string>v;
	while (ifs2 >> borrower_Data)
	{
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = borrower_Data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string target = borrower_Data.substr(start, pos - start);

			v.push_back(target);
			start = pos + 1;
		}

	}

	ifs2.close();

	int count = 0;
	for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
	{
		count++;
		//�����, 111111111111111111, 121212121212, 1002, Java������ƻ���, ��ѧ,
		if (*it == name)
		{
			break;
		}
		if (count == v.size())
		{
			cout << "û�����Ľ�����Ϣ��" << endl;
			system("pause");
			this->m_Error = -1;
			return;
		}

	}

/**************************************************************************************************/

	//library->HandleReturn();

	library->displayBooks();
	string title;
	int ReturnNumber;
	cout << "����Ҫ�黹��ͼ����ĿΪ��";
	cin >> ReturnNumber;
	cout << endl;
	for (int i = 0; i < ReturnNumber; i++)
	{
		cout << "�������" << i + 1 << "��" << "Ҫ�黹����:";
		int mark = 1;
		if (i == 0)
		{
			cin.ignore();
		}
		getline(cin, title);


		for (auto& book : library->books)
		{
			if (book.GetTitle() == title && book.GetStatus() == "�ѽ��")
			{
				cout << "��" << title << "��" << "�黹�ɹ�" << endl;
				book.Return();//true���ѽ������Ϊfalse���ڹ��ڣ�,return false
				mark = 0;
				
				
				
				
				
				//ɾ��һ������������Ϣ  &&  ���汻ɾ����Ϣ�����ͼ����Ϣ��������
				for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
				{
					if (*it == title)
					{
						//1.����ͼ����Ϣ   2.ɾ��һ������Ϣ
						v.erase(it-4, it +2);////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						break;
					}
				}

				this->m_shengXiaBorrowerV = v;

				//����յ���������Ϣ.txt;
				ifstream ifs3;
				ifs3.open("��������Ϣ.txt", ios::trunc);
				ifs3.close();

				ofstream ofs("��������Ϣ.txt", ios::out);

				for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
				{
					ofs << *it << ",";//�������º�� vector�������������Զ��ŷָ�д�뵽�ļ���
				}

				ofs.close();
				this->m_shengXiaBorrowerV.clear();
			}
		}
		if (mark)
		{
			cout << "�黹ʧ��" << "��" << title << "��" << "�ǹ���ͼ��" << endl;
		}
		library->SaveBooksToFile(); // ������ĺ󱣴浽�ļ�
	}




	system("pause");
	system("cls");

}

//����ʣ�µĽ�������Ϣ
void Users::saveShengXiaBorrower(const vector<string>& v)
{
	ofstream ofs("��������Ϣ.txt", ios::out);

	for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		ofs << *it << ",";
	}

	ofs.close();
	this->m_shengXiaBorrowerV.clear();

}


/**************************************************************************************************/
/*************************************************************************************************/


Administrator::Administrator(){}

//����Ա�Ǽ�
void Administrator::guanLiYuanGuJi(BookManagement* library)
{
	//��¼
	this->managerLogOn();

	//�ϰ�
	if (this->m_Index == -1)
	{
		//�˻�
		this->m_Index = 0;
		return;
	}

	//��¼�ɹ�

	while (1)
	{
		this->managerShowMenu();

		switch (getchar())
		{
		case '1'://���ͼ��
			library->AddNewBook();
			break;
		case '2'://�¼�ͼ��
			library->DeleteBook();
			break;
		case '3'://�鿴��������Ϣ
			this->lookBorrowerData();
			break;
		case '4'://���ز˵�
			return;
			break;
		case '0'://�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			exit(0);
			break;
		default:
			system("cls");
			break;
		}

	}



	system("pause");



}

//����Ա��¼
void Administrator::managerLogOn()
{
	//��ս���
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                  ��ӭ�������Ա��¼����                    ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "<< ע����Χ�����Ƿ�ȫ >>" << endl;

	//��ȡ�ļ�������
	ifstream ifs;
	ifs.open("ManagerData.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		system("pause");
		return;
	}
	//�ļ�·��û����


	string data;

	//����Ӵ�
	vector<string>v;

	while (ifs >> data)
	{

		//cout << data << endl; �����,123456,

		int pos = -1;
		int start = 0;

		while (1)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
				//����
			}

			string target = data.substr(start, pos - start);

			//�ŵ�������
			v.push_back(target);

			start = pos + 1;//������ʼ��

		}


	}

	ifs.close();

	//��¼����
	string name;//����
	char words[50];//����

	cout << "���������Ա������" << endl;
	cin >> name;

	//��������
	int i = 0;
	cout << "���������Ա���룺" << endl;

	while (i < 9 && (words[i] = _getch()) && words[i] != '\r') //������볬�� ���� �����س���������ѭ��
	{
		printf("*");   //�������� 
		i++;
	}
	cout << endl;
	words[i] = 0;   //�ַ���������־ '/0'*/
	string mima(words);

	//�Ա�
	if (name == v[0] && mima == v[1])
	{
		cout << "��¼�ɹ���" << endl;
		system("pause");

		return;
	}
	else
	{
		cout << "��¼ʧ�ܣ�" << endl;
		system("pause");
		this->m_Index = -1;
		return;
	}





}

//����Ա�Ĳ˵�
void Administrator::managerShowMenu()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                    ��ӭ�������Ա����                      ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***           1.����ͼ��                2.�¼�ͼ��             ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           3.�鿴��������Ϣ          4.�������˵�           ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***                         0.�˳�ϵͳ                         ***" << endl;
	cout << "                          ******************************************************************" << endl;
}

//�鿴��������Ϣ
void Administrator::lookBorrowerData()
{
	//�ӽ�������Ϣ�ļ� ����  ����   �ŵ�һ��������
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                       ͼ��������                         ***" << endl;
	cout << "                          ******************************************************************" << endl;

	ifstream ifs;
	ifs.open("��������Ϣ.txt", ios::in);

	string data;
	vector<string>tempv;
	while (ifs >> data)
	{
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}

			string target = data.substr(start, pos - start);

			tempv.push_back(target);

			start = pos + 1;

		}
	}

	ifs.close();

	if (tempv.size() == 0)
	{
		cout << "<<δ�н�����Ϣ>>" << endl;
		system("pause");

		return;
	}

	//��������Ϣ���  ����  �˺ţ����֤��  �ֻ�����   ͼ����   ͼ������   ͼ������


	//��������
	//aaa, lll, kk, 1001, C++������ƻ���, ��ѧ,
	cout << "************************************************************************************************************************" << endl;
	cout << setw(13) << left << "����" << setw(24) << left << "���֤��"
		<< setw(17) << left << "��ϵ�绰" << setw(20) << left << "ISBN"
		<< setw(24) << left << "��������" << setw(6) << left << "����ͼ������" << endl;
	cout << "************************************************************************************************************************" << endl;

	int count = 0;
	for (vector<string>::iterator it = tempv.begin(); it != tempv.end(); it++)
	{
		//��������Ϣ���  ����  �˺ţ����֤��  �ֻ�����   ͼ����   ͼ������   ͼ������
		count++;
		if (count == 1)
		{
			cout << setw(13) << left << *it;
		}
		if (count == 2)
		{
			cout << setw(24) << left << *it;
		}
		if (count == 3)
		{
			cout << setw(17) << left << *it;
		}
		if (count == 4)
		{
			cout << setw(20) << left << *it;
		}
		if (count == 5)
		{
			cout << setw(24) << left << *it;
		}
		if (count == 6)
		{
			cout << setw(6) << left << *it << endl;
			count = 0;
		}

	}//�����ʾ���еĽ�������Ϣ
	cout << "************************************************************************************************************************" << endl;

	system("pause");
	system("cls");

}