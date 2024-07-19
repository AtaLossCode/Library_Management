#pragma once
#include<vector>
#include <iostream>
#include <fstream>//包含标准文件流库，用于文件的输入输出
#include <sstream>//包含字符串流库，用于处理字符串中的流操作
#include <vector>
#include <conio.h>
#include <map>
#include <iomanip>//setw和left所需的头文件
#include<cstdlib>
#include<string>
#include<algorithm>//sort,remove_if

using namespace std;


//管理各类书籍信息的类
class Book
{
public:
	//构造函数
	Book(string _title, string _author, string _publicationDate, string _ISBN, string _category) :
		title(_title),  author(_author), PublicationDate(_publicationDate),
		ISBN(_ISBN), status(false), category(_category) {};
	//获取标题
	string GetTitle() const;
	//获取作者
	string GetAuthor() const;
	//获取出版日期
	string GetPublicationDate() const;
	//获取ISBN号
	string GetISBN() const;
	//获取状态
	string GetStatus() const;
	void Borrow();
	void Return();
    //设置状态
	void SetStatus(bool borrowed);
	//获取分类
	string GetCategory() const;
protected:
	//书名
	string title;
	//作者
	string author;
	//出版日期
	string PublicationDate;
	//ISBN号
	string ISBN;
	//状态(借出为true，在馆内为false)
	bool status;
	//分类
	string category;
};


//对图书进行各种操作的类
class BookManagement
{
public:

	BookManagement();//构造函数
	// 构造函数中加载图书信息
	BookManagement(const string& filePath);
	//添加新书
	void AddNewBook();
	void AddNewBook(const Book&book);
	//查找图书
	void FindBook();
	//删除图书
	void DeleteBook();
	//按书名排序
	void SortBookByTitle();
	//处理借阅与归还
	void HandleBorrow();
	void HandleReturn();
	//显示所有书籍
	void displayBooks() const;
	//加载图书信息从文件
	void LoadBooksFromFile();
	//储存图书信息
	void SaveBooksToFile();
	
	vector<Book> books;

	string filePath; //存储文件路径的字符串

	vector<string>m_BorrowerV; //专门用来储存借书人信息的容器

protected:
	
};


/***************************************************************************************************/

class UsersManagement
{
public:
	UsersManagement();

	void showMenu();

	//用户注册
	void addUser();

	//借书须知
	void borrowBookNotice();

	//图书丢失
	void reduceBook();

	vector<string>m_shengXiaBorrowerV;//剩下的借书人信息

	int m_Index;
	int m_Error;
private:

};


class Users : public UsersManagement,BookManagement
{
public:

	Users();

	//租借图书
	void borrowBook(BookManagement* library);

	//归还图书
	void backBook(BookManagement* library);

	//保存剩下的借书人信息
	void saveShengXiaBorrower(const vector<string>& v);

protected:

	
	//	vector<string>m_shengXiaV;  //储存剩下的图书（下架图书专用）
	//	map<int, Books>m_Bookm;//添加图书进入系统的一个中间容器
};


class Administrator : public UsersManagement,BookManagement
{
public:

	Administrator();

	//管理员骨架
	void guanLiYuanGuJi(BookManagement* library);

	//管理员登录
	void managerLogOn();

	//管理员的菜单
	void managerShowMenu();

	//查看借书人信息
	void lookBorrowerData();


};