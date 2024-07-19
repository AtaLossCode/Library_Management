#include"Management.h"

//构造函数
UsersManagement::UsersManagement()
{
	this->m_Index = 0;
	this->m_Error = 0;
}


void UsersManagement::showMenu()
{
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                   欢迎使用图书管理系统                     ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***           1.租借图书                2.归还图书             ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           3.图书丢失                4.查看所有图书         ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           5.查找图书                6.用户注册             ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           7.管理员特权              8.借书须知             ***" << endl;
	cout << "                          ******************************************************************" << endl;
}

//用户注册
void UsersManagement::addUser()
{
	//显示注册界面
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         用户注册                           ***" << endl;
	cout << "                          ******************************************************************" << endl;

	//输入身份证号
	cout << "请输入身份证号码：" << endl;
	string idCard;
	cin >> idCard;

	//判断  18   0~9  idCard[17]   ->A  Z

	for (int i = 0; i < 17; i++)
	{
		if (idCard.size() != 18 || idCard[i] > '9' || idCard[i] < '0' || (idCard[17] > 'Z' && idCard[17] < 'A') || (idCard[17] < '0' && idCard[17]>'9'))
		{
			cout << "输入的账号不符合规范！" << endl;
			system("pause");
			return;
		}
	}



	//创建密码
	string mima1;
	string mima2;
	cout << "请输入密码：" << endl;
	cin >> mima1;
	cout << "请再次输入密码：" << endl;
	cin >> mima2;

	//比对密码
	if (mima1 != mima2)
	{
		cout << "您两次输入的密码不匹配！" << endl;
		cout << "请重新进入本页面<<谢谢>>" << endl;
		system("pause");
		system("cls");
		return;
	}

	//打开文件

	ifstream ifs;
	ifs.open("用户注册信息.txt", ios::out);

	if (!ifs.is_open())
	{
		cout << "文件路径出现问题！" << endl;
		system("pause");
		return;
	}
	else
	{
		//解析数据
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
						cout << "账号已经存在！《无法再进行注册》" << endl;
						system("pause");
						system("cls");
						return;
					}
				}

				//更该截取的起始点
				start = pos + 1;
			}

		}

	}

	//注册成功后  把数据添加到文件中
	ofstream ofs;
	ofs.open("用户注册信息.txt", ios::in | ios::app);
	//打开失败
	if (!ofs.is_open())
	{
		cout << "文件路径出现问题！" << endl;
		system("pause");
		return;
	}

	//成功
	ofs << idCard << "," << mima1 << ",";

	//关闭文件
	ofs.close();

	cout << "【注册成功】" << endl;
	system("pause");




}

//借书须知
void UsersManagement::borrowBookNotice()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         借书须知                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "************************************************************************************************************************" << endl;
	cout << "                          <<<<                       系统尚未健全                       >>>>" << endl;
	cout << endl;
	cout << "                          <<                                                              >>" << endl;
	cout << "                          <<        【1】 图书归还一次只能归还一本（按照租借的顺序）      >>" << endl;
	cout << "                          <<                                                              >>" << endl;
	cout << endl;
	cout << "                          <<<<                  租借图书请知晓以上情况                  >>>>" << endl;

	cout << "************************************************************************************************************************" << endl;
	system("pause");
	system("cls");
}

//图书丢失
void UsersManagement::reduceBook()
{

	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         图书丢失                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << endl;
	cout << "                                       <<丢失图书请联系图书丢失负责人：小黄>>" << endl;
	cout << endl;
	cout << "                                       <<赔偿金添加小黄微信进行微信转账赔偿>>" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "小黄电话： 10086" << endl;
	cout << "小黄qq： 2607995048" << endl;
	cout << "************************************************************************************************************************" << endl;
	system("pause");
	system("cls");
}




/**************************************************************************************************/
/*************************************************************************************************/


//构造函数
Users::Users() {}
		 
//租借图书
void Users::borrowBook(BookManagement* library)//传类的对象地址
{
	//输入信息
	string name;
	cout << "请输入您的姓名：" << endl;
	cin >> name;

	string phone;
	cout << "请输入您的手机号码：" << endl;
	cin >> phone;

	string id;
	cout << "请输入您的账号：" << endl;
	cin >> id;

	string mima;
	cout << "请输入您的密码：" << endl;
	cin >> mima;


	//用户注册信息.txt   解析
	ifstream ifs2;
	ifs2.open("用户注册信息.txt", ios::in);//从文件中读取

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

	//将用户输入的信息   跟解析到容器的信息进行对比     return 

	int num = 0;
	for (vector<string>::iterator it = tempV1.begin(); it != tempV1.end(); it++)
	{//111111111111111111,123456,444444444444444444,123456,222222222222222222,123456,
		if (id == *it)//账号匹配
		{
			num++;
			it++;//密码匹配
			if (*it == mima)
			{
				break;
			}
			else
			{
				cout << "密码输入错误！" << endl;
				system("pause");
				system("cls");
				this->m_Error = -1;
				return;
			}
		}
	}

	if (num == 0)
	{
		cout << "该账号还没有注册！" << endl;
		system("pause");
		system("cls");
		this->m_Error = -1;
		return;
	}



	/*cout << "可以借书了" << endl;
	system("pause");*/

	//开始借书
	//注意对象指针的正确调用！！！！！！！！！！！！！！！！！！！！！！！
	library->m_BorrowerV.push_back(name);
	library->m_BorrowerV.push_back(id);
	library->m_BorrowerV.push_back(phone);
	//存储名字 账户（身份证） 电话 的信息
	//开始借书

	library->HandleBorrow();
	

	//2.把删除后剩下的图书放回到  系统图书.txt


	//借书人信息组成  6    名字   身份证   手机号码    一本图书（3）


}

//归还图书
void Users::backBook(BookManagement* library)
{
	//显示界面
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                           图书归还                         ***" << endl;
	cout << "                          ******************************************************************" << endl;

	//输入信息
	string name;
	cout << "请输入您的姓名：" << endl;
	cin >> name;

	string phone;
	cout << "请输入您的手机号码：" << endl;
	cin >> phone;

	string id;
	cout << "请输入您的账号：" << endl;
	cin >> id;

	string mima;
	cout << "请输入您的密码：" << endl;
	cin >> mima;

	//解析 用户注册信息
	ifstream ifs("用户注册信息.txt", ios::in);

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



	//检查账号  密码  是否正确
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
				cout << "密码输入错误！" << endl;
				system("pause");
				this->m_Error = -1;
				return;
			}

		}

	}

	if (isIdRight == false)
	{
		cout << "账号或密码输入错误！" << endl;
		system("pause");
		this->m_Error = -1;
		return;
	}


	//1.成功 开始归还    2.失败  return
	
	ifstream ifs2("借书人信息.txt", ios::in);

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
		//大聪明, 111111111111111111, 121212121212, 1002, Java程序设计基础, 哲学,
		if (*it == name)
		{
			break;
		}
		if (count == v.size())
		{
			cout << "没有您的借书信息！" << endl;
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
	cout << "本次要归还的图书数目为：";
	cin >> ReturnNumber;
	cout << endl;
	for (int i = 0; i < ReturnNumber; i++)
	{
		cout << "请输入第" << i + 1 << "本" << "要归还的书:";
		int mark = 1;
		if (i == 0)
		{
			cin.ignore();
		}
		getline(cin, title);


		for (auto& book : library->books)
		{
			if (book.GetTitle() == title && book.GetStatus() == "已借出")
			{
				cout << "《" << title << "》" << "归还成功" << endl;
				book.Return();//true（已借出）变为false（在馆内）,return false
				mark = 0;
				
				
				
				
				
				//删除一整条借书人信息  &&  保存被删除信息里面的图书信息（容器）
				for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
				{
					if (*it == title)
					{
						//1.保存图书信息   2.删除一整条信息
						v.erase(it-4, it +2);////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						break;
					}
				}

				this->m_shengXiaBorrowerV = v;

				//先清空掉借书人信息.txt;
				ifstream ifs3;
				ifs3.open("借书人信息.txt", ios::trunc);
				ifs3.close();

				ofstream ofs("借书人信息.txt", ios::out);

				for (vector<string>::const_iterator it = v.begin(); it != v.end(); it++)
				{
					ofs << *it << ",";//遍历更新后的 vector，并将其内容以逗号分隔写入到文件中
				}

				ofs.close();
				this->m_shengXiaBorrowerV.clear();
			}
		}
		if (mark)
		{
			cout << "归还失败" << "《" << title << "》" << "非馆内图书" << endl;
		}
		library->SaveBooksToFile(); // 处理借阅后保存到文件
	}




	system("pause");
	system("cls");

}

//保存剩下的借书人信息
void Users::saveShengXiaBorrower(const vector<string>& v)
{
	ofstream ofs("借书人信息.txt", ios::out);

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

//管理员骨架
void Administrator::guanLiYuanGuJi(BookManagement* library)
{
	//登录
	this->managerLogOn();

	//障碍
	if (this->m_Index == -1)
	{
		//退回
		this->m_Index = 0;
		return;
	}

	//登录成功

	while (1)
	{
		this->managerShowMenu();

		switch (getchar())
		{
		case '1'://添加图书
			library->AddNewBook();
			break;
		case '2'://下架图书
			library->DeleteBook();
			break;
		case '3'://查看借书人信息
			this->lookBorrowerData();
			break;
		case '4'://返回菜单
			return;
			break;
		case '0'://退出系统
			cout << "欢迎下次使用" << endl;
			exit(0);
			break;
		default:
			system("cls");
			break;
		}

	}



	system("pause");



}

//管理员登录
void Administrator::managerLogOn()
{
	//清空界面
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                  欢迎进入管理员登录界面                    ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "<< 注意周围环境是否安全 >>" << endl;

	//读取文件的数据
	ifstream ifs;
	ifs.open("ManagerData.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		system("pause");
		return;
	}
	//文件路径没问题


	string data;

	//存放子串
	vector<string>v;

	while (ifs >> data)
	{

		//cout << data << endl; 大聪明,123456,

		int pos = -1;
		int start = 0;

		while (1)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
				//跳出
			}

			string target = data.substr(start, pos - start);

			//放到容器中
			v.push_back(target);

			start = pos + 1;//更新起始点

		}


	}

	ifs.close();

	//登录输入
	string name;//姓名
	char words[50];//密码

	cout << "请输入管理员姓名：" << endl;
	cin >> name;

	//密码输入
	int i = 0;
	cout << "请输入管理员密码：" << endl;

	while (i < 9 && (words[i] = _getch()) && words[i] != '\r') //如果输入超限 或者 遇到回车符就跳出循环
	{
		printf("*");   //掩饰密码 
		i++;
	}
	cout << endl;
	words[i] = 0;   //字符串结束标志 '/0'*/
	string mima(words);

	//对比
	if (name == v[0] && mima == v[1])
	{
		cout << "登录成功！" << endl;
		system("pause");

		return;
	}
	else
	{
		cout << "登录失败！" << endl;
		system("pause");
		this->m_Index = -1;
		return;
	}





}

//管理员的菜单
void Administrator::managerShowMenu()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                    欢迎进入管理员界面                      ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***           1.加入图书                2.下架图书             ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***           3.查看借书人信息          4.返回主菜单           ***" << endl;
	cout << "                          ***                                                            ***" << endl;
	cout << "                          ***                         0.退出系统                         ***" << endl;
	cout << "                          ******************************************************************" << endl;
}

//查看借书人信息
void Administrator::lookBorrowerData()
{
	//从借书人信息文件 解析  数据   放到一个容器里
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                       图书租借情况                         ***" << endl;
	cout << "                          ******************************************************************" << endl;

	ifstream ifs;
	ifs.open("借书人信息.txt", ios::in);

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
		cout << "<<未有借书信息>>" << endl;
		system("pause");

		return;
	}

	//借书人信息组成  姓名  账号（身份证）  手机号码   图书编号   图书姓名   图书类型


	//遍历容器
	//aaa, lll, kk, 1001, C++程序设计基础, 哲学,
	cout << "************************************************************************************************************************" << endl;
	cout << setw(13) << left << "姓名" << setw(24) << left << "身份证号"
		<< setw(17) << left << "联系电话" << setw(20) << left << "ISBN"
		<< setw(24) << left << "所借书名" << setw(6) << left << "所借图书类型" << endl;
	cout << "************************************************************************************************************************" << endl;

	int count = 0;
	for (vector<string>::iterator it = tempv.begin(); it != tempv.end(); it++)
	{
		//借书人信息组成  姓名  账号（身份证）  手机号码   图书编号   图书姓名   图书类型
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

	}//如何显示所有的借书人信息
	cout << "************************************************************************************************************************" << endl;

	system("pause");
	system("cls");

}