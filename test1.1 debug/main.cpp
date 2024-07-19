#include<iostream>
#include"Management.h"
using namespace std;
int main()
{
	const string file_path = "library_books.txt"; // 定义文件路径
	BookManagement library(file_path); // 创建 BookManagement 对象

	Users users;

	Administrator administrator;

	UsersManagement um;

	while (1)
	{
		um.showMenu();

		switch (getchar())
		{
		case '1'://租借图书
			users.borrowBook(&library);//传地址
			if (um.m_Error == -1)
			{
				um.m_Error = 0;
				break;
			}
			//保存系统剩下的图书
			//sm.saveShengXia(sm.m_shengXiaV);
			break;
		case '2'://归还图书
			users.backBook(&library);
			if (um.m_Error == -1)
			{
				um.m_Error = 0;
				break;
			}
			break;
		case '3'://图书丢失
			um.reduceBook();
			break;
		case '4'://查看所有图书
			library.displayBooks();
			system("pause");
			system("cls");
			break;
		case '5'://查找图书
			library.FindBook();
			break;
		case '6'://用户注册
			users.addUser();
			break;
		case '7'://管理员特权
			administrator.guanLiYuanGuJi(&library);
			break;
		case '8'://借书须知
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