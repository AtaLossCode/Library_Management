#include"Management.h"


BookManagement::BookManagement(){}

//检查文件是否存在，并在必要时创建一个空文件
BookManagement::BookManagement(const string& path) : filePath(path), books() //path参数指定了存储图书信息的文件路径
{
	//创建一个ofstream对象file，尝试以追加模式打开filePath指定的文件。如果文件不存在，追加模式会创建一个新文件。
	ofstream file(filePath, ofstream::app);
	if (!file.is_open()) 
	{
		cerr << "无法创建或打开文件: " << filePath << endl;
	}
	else
	{
		LoadBooksFromFile(); // 尝试加载图书信息
	}
	file.close();
}
//从 filePath 指定的文件中加载图书信息
void BookManagement::LoadBooksFromFile() 
{
	ifstream file(filePath); //创建一个输入文件流 file,读取文件路径所指向的文件
	string line;
	if (file.is_open())
	{
		while (getline(file, line))//使用 getline 函数从文件流 file 中读取一行文本到变量 line，直到文件结束
		{
			std::stringstream iss(line); //创建一个stringstream 对象 iss，从 line 中提取多个字段
			string field;//变量 field，用来临时存储从 iss 中读取的每个字段
			vector<string> fields;// fields 容器，用来存储所有的字段
			while (getline(iss, field, ','))// getline 函数从 iss 中读取字段，以逗号作为分隔符，直到 iss 中没有更多数据
			{
				//每读取一个字段，就将其添加到 fields容器中
				fields.push_back(field);
			}
			// 确保字段数量正确
			if (fields.size() != 6)//如果字段数量不是6，输出错误信息到标准错误流，说明文件格式有误
			{
				cerr << "文件格式错误，每行应该恰好有6个字段。" << endl;
				continue;
			}
			//如果字段数量正确，将 fields 容器中的每个字段分别赋值给相应的变量
			string title = fields[0];
			string author = fields[1];
			string date = fields[2];
			string isbn = fields[3];
			string category = fields[4];
			string statusStr = fields[5]; 
			//创建book对象
			Book book(title, author, date, isbn, category);
			book.SetStatus(statusStr == "已借出");
			//将创建的 Book 对象添加到 BookManagement 类的 books容器中
			books.push_back(book);
		}
	}
	else//如果文件没有成功打开，输出错误信息到标准错误流
	{
		cerr << "无法打开文件以读取图书信息: " << filePath << endl;
	}
}
// 将图书信息保存到文件
void BookManagement::SaveBooksToFile() 
{
	ofstream file(filePath);//创建一个输出文件流file，用于写入filePath指定的文件
	if (file.is_open())
	{
		for (const auto& book : books)//遍历books向量中的每个Book对象
		{
			// 将图书信息转换为字符串写入文件，格式为 "title,author,date,isbn,category,status"
			file << book.GetTitle() << "," << book.GetAuthor() << ","
				<< book.GetPublicationDate() << "," << book.GetISBN() << ","
				<< book.GetCategory() << ","<< book.GetStatus() << endl;
		}
	}
}

//添加新书
void BookManagement::AddNewBook()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         添加图书                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	string title, author, PublishDate, isbn, category;
	int AddNumber;
	cout << "本次要添加书籍的数目：";
	cin >> AddNumber;
	if (AddNumber == 0)
	{
		system("cls");
	}
	else
	{
		for (int i = 0; i < AddNumber; i++)
		{
			cout << "第" << i + 1 << "本" << "要添加的书名:";
			cin.ignore();
			getline(cin, title);
			cout << "请输入作者:";
			cin >> author;
			cout << "请输入出版日期:";
			cin >> PublishDate;
			cout << "请输入13位ISBN号:";
			cin >> isbn;
			cout << "请输入该书的分类:";
			cin >> category;
			//创建书籍对象 
			Book newbook(title, author, PublishDate, isbn, category);
			AddNewBook(newbook);
		}
		SaveBooksToFile();//添加图书后保存到文件
		system("pause");
		system("cls");
	}
}
void BookManagement::AddNewBook(const Book& book)
{
	books.push_back(book);
	cout << "已成功添加" << book.GetTitle() << endl;
}
//显示所有书籍
void BookManagement::displayBooks() const
{
	//展示所有图书的界面
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         所有图书                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	if (books.empty())
	{
		cout << "暂无书籍" << endl;
		return;
	}
	cout << "************************************************************************************************************************" << endl;
	for (const auto& book : books)
	{
		cout << "书名：" << setw(15) << left<<book.GetTitle();
		cout.width(0); // 重置宽度
		cout << "作者：" << setw(15) << left<<book.GetAuthor() ;
		cout.width(0); // 重置宽度
		cout << "出版日期：" << setw(15) << left << book.GetPublicationDate() ;
		cout.width(0); // 重置宽度
		cout << "ISBN号：" << setw(15) << left << book.GetISBN() ;
		cout.width(0); // 重置宽度
		cout << "分类：" << setw(8) << left << book.GetCategory() ;
		cout.width(0); // 重置宽度
		cout << "状态：" << book.GetStatus() << endl;
	}
	cout << "************************************************************************************************************************" << endl;
}
//查找图书
void BookManagement::FindBook()
{
	getchar();
	//显示界面
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         查找图书                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	string title;
	cout << "请输入要查找的书名:";
	getline(cin, title);
	for (const auto& book : books)
	{
		if (book.GetTitle() == title)
		{
			cout << "查询到该书信息："<< endl;
			cout << "书名：" << setw(15) << left<< title ;
			cout << "作者：" << setw(15) << left << book.GetAuthor();
			cout << "出版日期：" << setw(15) << left << book.GetPublicationDate();
			cout << "ISBN：" << setw(15) << left << book.GetISBN();
			cout << "分类：" << setw(10) << left << book.GetCategory() ;
			cout << "状态：" << setw(15) << left << book.GetStatus() << endl;
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "未找到" << "《" << title << "》"<<endl;
	system("pause");
	system("cls");
	return;
}
//删除图书
void  BookManagement::DeleteBook()
{
	//显示界面
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         删除图书                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "所有系统图书如下：" << endl;
	this->displayBooks();
	string title;
	cout << "请输入要删除的书籍：";
	cin.ignore();//忽略之前留下的换行符
	getline(cin, title);//输入完整的书名
	// 使用remove_if和erase结合删除特定元素
	auto newEnd = remove_if(books.begin(), books.end(), [&title](const Book& book)//[]为Lambda表达式,title 可修改
		{
		    return book.GetTitle() == title;
		});
	if (newEnd == books.end()) {
		cout << "没有找到 " << title << "，无法删除。" << endl;
	}
	else {
		books.erase(newEnd, books.end());
		cout << title << " 已被删除" << endl;
		SaveBooksToFile(); // 删除图书后保存到文件
	}
	system("pause");
	system("cls");
}
//自定义比较函数用于图书排序
bool CompareBook(const Book& a, const Book& b)
{
	return a.GetTitle() < b.GetTitle();
}
//按书名排序
void  BookManagement::SortBookByTitle()
{
	std::sort(books.begin(), books.end(), CompareBook);//sort
	cout << "已按书名排序：" << endl;
	system("pause");
}
//处理借阅与归还
void BookManagement::HandleBorrow()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***              欢迎使用图书管理系统-租借图书                ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "所有系统图书如下：" << endl;


	this->displayBooks();
	string title;
	int BorrowNumber;
	cout << "本次要借阅的图书数目为：";
	cin >> BorrowNumber;
	cout << endl;
	for (int i = 0; i < BorrowNumber; i++)
	{
		cout << "请输入第" << i + 1 << "本" << "要借阅的书:";
		int mark = 1;
		if (i == 0)
		{
			cin.ignore();
		}
		getline(cin, title);
		for (auto& book : books)
		{
			if (book.GetTitle() == title&&book.GetStatus()=="在馆内")
			{
				cout << "《"<<title << "》" << "借阅成功" << endl;
				this->m_BorrowerV.push_back(book.GetISBN());
				this->m_BorrowerV.push_back(book.GetTitle());
				this->m_BorrowerV.push_back(book.GetCategory());
				//向m_BorrowerV容器加存储ISBN 书名 类型的信息
				book.Borrow();
				mark=0;
				//借书人信息容器  6   姓名  账号   手机号码    图书3
				//通过容器将数据导入   借书人信息.txt
				ofstream ofs2;
				ofs2.open("借书人信息.txt", ios::out | ios::app);

				for (int i = 0; i < 6; i++)
				{
					ofs2 << this->m_BorrowerV[i] << ",";
				}
				//把m_BorrowerV容器里的信息存到文件里
				ofs2.close();

				//m_BorrowerV.clear();//清空容器
				/*for (int i = 0; i < 3; i++)
				{
					m_BorrowerV.erase(m_BorrowerV.begin() + 3);
				}*/
				auto it = m_BorrowerV.begin() + 3; // 指向要删除的第一个元素
				m_BorrowerV.erase(it, it + 3); // 从it开始，删除接下来的三个元素
			}
		    else if (book.GetTitle() == title&&book.GetStatus() == "已借出")
			{
				cout << "借阅失败" << "《" << title << "》" << "已被借出" << endl;
				mark=0;
			}
		}
		if (mark)
		{
			cout << "借阅失败" << "《" << title << "》" << "不存在" << endl;
		}
		SaveBooksToFile(); // 处理借阅后保存到文件
	}
	this->m_BorrowerV.clear();//如果借阅失败mpd了，还是要清空之前放进去的姓名等信息
	system("pause");
	system("cls");
}


void BookManagement::HandleReturn()
{
	////显示界面
	//system("cls");
	//cout << "                          ******************************************************************" << endl;
	//cout << "                          ***                           图书归还                         ***" << endl;
	//cout << "                          ******************************************************************" << endl;
	//cout << "所有系统图书如下：" << endl;
	this->displayBooks();
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


		for (auto& book : books)
		{
			if (book.GetTitle() == title&&book.GetStatus()=="已借出")
			{
				cout << "《" << title << "》" << "归还成功" << endl;
				book.Return();//true（已借出）变为false（在馆内）,return false
				mark = 0;
			}
		}
		if (mark)
		{
			cout << "归还失败" << "《" << title << "》" << "非馆内图书" << endl;
		}
		SaveBooksToFile(); // 处理借阅后保存到文件
	}
	system("pause");
	system("cls");
}

//获取标题
string Book::GetTitle() const
{
	return title;
}
//获取作者
string Book::GetAuthor() const
{
	return author;
}
//获取出版日期
string Book::GetPublicationDate() const
{
	return PublicationDate;
}
//获取ISBN号
string Book::GetISBN() const
{
	return ISBN;
}
//获取状态
string Book::GetStatus() const
{
	return (status?"已借出":"在馆内");
}
void Book::Borrow()
{
	status = true;
}
void Book::Return()
{
	status = false;
}
//设置状态
void Book::SetStatus(bool borrowed) {
	status = borrowed;
}
//获取分类
string Book::GetCategory() const
{
	return category;
}
