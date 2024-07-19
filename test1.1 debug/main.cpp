#include<iostream>
#include"Management.h"
using namespace std;
int main()
{
	const string file_path = "library_books.txt"; // �����ļ�·��
	BookManagement library(file_path); // ���� BookManagement ����

	Users users;

	Administrator administrator;

	UsersManagement um;

	while (1)
	{
		um.showMenu();

		switch (getchar())
		{
		case '1'://���ͼ��
			users.borrowBook(&library);//����ַ
			if (um.m_Error == -1)
			{
				um.m_Error = 0;
				break;
			}
			//����ϵͳʣ�µ�ͼ��
			//sm.saveShengXia(sm.m_shengXiaV);
			break;
		case '2'://�黹ͼ��
			users.backBook(&library);
			if (um.m_Error == -1)
			{
				um.m_Error = 0;
				break;
			}
			break;
		case '3'://ͼ�鶪ʧ
			um.reduceBook();
			break;
		case '4'://�鿴����ͼ��
			library.displayBooks();
			system("pause");
			system("cls");
			break;
		case '5'://����ͼ��
			library.FindBook();
			break;
		case '6'://�û�ע��
			users.addUser();
			break;
		case '7'://����Ա��Ȩ
			administrator.guanLiYuanGuJi(&library);
			break;
		case '8'://������֪
			um.borrowBookNotice();
			break;

		default:
			system("cls");
			break;
		}


		/*
		library.displayBooks();
		system("pause");
		library.DeleteBook();
		library.displayBooks();
		system("cls");
		library.FindBook();
		library.SortBookByTitle();
		library.displayBooks();
		library.HandleBorrow();
		library.displayBooks();
		library.HandleReturn();
		library.displayBooks();*/
	}
}