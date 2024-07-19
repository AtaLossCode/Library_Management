#pragma once
#include<vector>
#include <iostream>
#include <fstream>//������׼�ļ����⣬�����ļ����������
#include <sstream>//�����ַ������⣬���ڴ����ַ����е�������
#include <vector>
#include <conio.h>
#include <map>
#include <iomanip>//setw��left�����ͷ�ļ�
#include<cstdlib>
#include<string>
#include<algorithm>//sort,remove_if

using namespace std;


//��������鼮��Ϣ����
class Book
{
public:
	//���캯��
	Book(string _title, string _author, string _publicationDate, string _ISBN, string _category) :
		title(_title),  author(_author), PublicationDate(_publicationDate),
		ISBN(_ISBN), status(false), category(_category) {};
	//��ȡ����
	string GetTitle() const;
	//��ȡ����
	string GetAuthor() const;
	//��ȡ��������
	string GetPublicationDate() const;
	//��ȡISBN��
	string GetISBN() const;
	//��ȡ״̬
	string GetStatus() const;
	void Borrow();
	void Return();
    //����״̬
	void SetStatus(bool borrowed);
	//��ȡ����
	string GetCategory() const;
protected:
	//����
	string title;
	//����
	string author;
	//��������
	string PublicationDate;
	//ISBN��
	string ISBN;
	//״̬(���Ϊtrue���ڹ���Ϊfalse)
	bool status;
	//����
	string category;
};


//��ͼ����и��ֲ�������
class BookManagement
{
public:

	BookManagement();//���캯��
	// ���캯���м���ͼ����Ϣ
	BookManagement(const string& filePath);
	//�������
	void AddNewBook();
	void AddNewBook(const Book&book);
	//����ͼ��
	void FindBook();
	//ɾ��ͼ��
	void DeleteBook();
	//����������
	void SortBookByTitle();
	//���������黹
	void HandleBorrow();
	void HandleReturn();
	//��ʾ�����鼮
	void displayBooks() const;
	//����ͼ����Ϣ���ļ�
	void LoadBooksFromFile();
	//����ͼ����Ϣ
	void SaveBooksToFile();
	
	vector<Book> books;

	string filePath; //�洢�ļ�·�����ַ���

	vector<string>m_BorrowerV; //ר�����������������Ϣ������

protected:
	
};


/***************************************************************************************************/

class UsersManagement
{
public:
	UsersManagement();

	void showMenu();

	//�û�ע��
	void addUser();

	//������֪
	void borrowBookNotice();

	//ͼ�鶪ʧ
	void reduceBook();

	vector<string>m_shengXiaBorrowerV;//ʣ�µĽ�������Ϣ

	int m_Index;
	int m_Error;
private:

};


class Users : public UsersManagement,BookManagement
{
public:

	Users();

	//���ͼ��
	void borrowBook(BookManagement* library);

	//�黹ͼ��
	void backBook(BookManagement* library);

	//����ʣ�µĽ�������Ϣ
	void saveShengXiaBorrower(const vector<string>& v);

protected:

	
	//	vector<string>m_shengXiaV;  //����ʣ�µ�ͼ�飨�¼�ͼ��ר�ã�
	//	map<int, Books>m_Bookm;//���ͼ�����ϵͳ��һ���м�����
};


class Administrator : public UsersManagement,BookManagement
{
public:

	Administrator();

	//����Ա�Ǽ�
	void guanLiYuanGuJi(BookManagement* library);

	//����Ա��¼
	void managerLogOn();

	//����Ա�Ĳ˵�
	void managerShowMenu();

	//�鿴��������Ϣ
	void lookBorrowerData();


};