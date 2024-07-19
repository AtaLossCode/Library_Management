#include"Management.h"


BookManagement::BookManagement(){}

//����ļ��Ƿ���ڣ����ڱ�Ҫʱ����һ�����ļ�
BookManagement::BookManagement(const string& path) : filePath(path), books() //path����ָ���˴洢ͼ����Ϣ���ļ�·��
{
	//����һ��ofstream����file��������׷��ģʽ��filePathָ�����ļ�������ļ������ڣ�׷��ģʽ�ᴴ��һ�����ļ���
	ofstream file(filePath, ofstream::app);
	if (!file.is_open()) 
	{
		cerr << "�޷���������ļ�: " << filePath << endl;
	}
	else
	{
		LoadBooksFromFile(); // ���Լ���ͼ����Ϣ
	}
	file.close();
}
//�� filePath ָ�����ļ��м���ͼ����Ϣ
void BookManagement::LoadBooksFromFile() 
{
	ifstream file(filePath); //����һ�������ļ��� file,��ȡ�ļ�·����ָ����ļ�
	string line;
	if (file.is_open())
	{
		while (getline(file, line))//ʹ�� getline �������ļ��� file �ж�ȡһ���ı������� line��ֱ���ļ�����
		{
			std::stringstream iss(line); //����һ��stringstream ���� iss���� line ����ȡ����ֶ�
			string field;//���� field��������ʱ�洢�� iss �ж�ȡ��ÿ���ֶ�
			vector<string> fields;// fields �����������洢���е��ֶ�
			while (getline(iss, field, ','))// getline ������ iss �ж�ȡ�ֶΣ��Զ�����Ϊ�ָ�����ֱ�� iss ��û�и�������
			{
				//ÿ��ȡһ���ֶΣ��ͽ�����ӵ� fields������
				fields.push_back(field);
			}
			// ȷ���ֶ�������ȷ
			if (fields.size() != 6)//����ֶ���������6�����������Ϣ����׼��������˵���ļ���ʽ����
			{
				cerr << "�ļ���ʽ����ÿ��Ӧ��ǡ����6���ֶΡ�" << endl;
				continue;
			}
			//����ֶ�������ȷ���� fields �����е�ÿ���ֶηֱ�ֵ����Ӧ�ı���
			string title = fields[0];
			string author = fields[1];
			string date = fields[2];
			string isbn = fields[3];
			string category = fields[4];
			string statusStr = fields[5]; 
			//����book����
			Book book(title, author, date, isbn, category);
			book.SetStatus(statusStr == "�ѽ��");
			//�������� Book ������ӵ� BookManagement ��� books������
			books.push_back(book);
		}
	}
	else//����ļ�û�гɹ��򿪣����������Ϣ����׼������
	{
		cerr << "�޷����ļ��Զ�ȡͼ����Ϣ: " << filePath << endl;
	}
}
// ��ͼ����Ϣ���浽�ļ�
void BookManagement::SaveBooksToFile() 
{
	ofstream file(filePath);//����һ������ļ���file������д��filePathָ�����ļ�
	if (file.is_open())
	{
		for (const auto& book : books)//����books�����е�ÿ��Book����
		{
			// ��ͼ����Ϣת��Ϊ�ַ���д���ļ�����ʽΪ "title,author,date,isbn,category,status"
			file << book.GetTitle() << "," << book.GetAuthor() << ","
				<< book.GetPublicationDate() << "," << book.GetISBN() << ","
				<< book.GetCategory() << ","<< book.GetStatus() << endl;
		}
	}
}

//�������
void BookManagement::AddNewBook()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         ���ͼ��                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	string title, author, PublishDate, isbn, category;
	int AddNumber;
	cout << "����Ҫ����鼮����Ŀ��";
	cin >> AddNumber;
	if (AddNumber == 0)
	{
		system("cls");
	}
	else
	{
		for (int i = 0; i < AddNumber; i++)
		{
			cout << "��" << i + 1 << "��" << "Ҫ��ӵ�����:";
			cin.ignore();
			getline(cin, title);
			cout << "����������:";
			cin >> author;
			cout << "�������������:";
			cin >> PublishDate;
			cout << "������13λISBN��:";
			cin >> isbn;
			cout << "���������ķ���:";
			cin >> category;
			//�����鼮���� 
			Book newbook(title, author, PublishDate, isbn, category);
			AddNewBook(newbook);
		}
		SaveBooksToFile();//���ͼ��󱣴浽�ļ�
		system("pause");
		system("cls");
	}
}
void BookManagement::AddNewBook(const Book& book)
{
	books.push_back(book);
	cout << "�ѳɹ����" << book.GetTitle() << endl;
}
//��ʾ�����鼮
void BookManagement::displayBooks() const
{
	//չʾ����ͼ��Ľ���
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         ����ͼ��                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	if (books.empty())
	{
		cout << "�����鼮" << endl;
		return;
	}
	cout << "************************************************************************************************************************" << endl;
	for (const auto& book : books)
	{
		cout << "������" << setw(15) << left<<book.GetTitle();
		cout.width(0); // ���ÿ��
		cout << "���ߣ�" << setw(15) << left<<book.GetAuthor() ;
		cout.width(0); // ���ÿ��
		cout << "�������ڣ�" << setw(15) << left << book.GetPublicationDate() ;
		cout.width(0); // ���ÿ��
		cout << "ISBN�ţ�" << setw(15) << left << book.GetISBN() ;
		cout.width(0); // ���ÿ��
		cout << "���ࣺ" << setw(8) << left << book.GetCategory() ;
		cout.width(0); // ���ÿ��
		cout << "״̬��" << book.GetStatus() << endl;
	}
	cout << "************************************************************************************************************************" << endl;
}
//����ͼ��
void BookManagement::FindBook()
{
	getchar();
	//��ʾ����
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         ����ͼ��                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	string title;
	cout << "������Ҫ���ҵ�����:";
	getline(cin, title);
	for (const auto& book : books)
	{
		if (book.GetTitle() == title)
		{
			cout << "��ѯ��������Ϣ��"<< endl;
			cout << "������" << setw(15) << left<< title ;
			cout << "���ߣ�" << setw(15) << left << book.GetAuthor();
			cout << "�������ڣ�" << setw(15) << left << book.GetPublicationDate();
			cout << "ISBN��" << setw(15) << left << book.GetISBN();
			cout << "���ࣺ" << setw(10) << left << book.GetCategory() ;
			cout << "״̬��" << setw(15) << left << book.GetStatus() << endl;
			cout << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	cout << "δ�ҵ�" << "��" << title << "��"<<endl;
	system("pause");
	system("cls");
	return;
}
//ɾ��ͼ��
void  BookManagement::DeleteBook()
{
	//��ʾ����
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***                         ɾ��ͼ��                           ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "����ϵͳͼ�����£�" << endl;
	this->displayBooks();
	string title;
	cout << "������Ҫɾ�����鼮��";
	cin.ignore();//����֮ǰ���µĻ��з�
	getline(cin, title);//��������������
	// ʹ��remove_if��erase���ɾ���ض�Ԫ��
	auto newEnd = remove_if(books.begin(), books.end(), [&title](const Book& book)//[]ΪLambda���ʽ,title ���޸�
		{
		    return book.GetTitle() == title;
		});
	if (newEnd == books.end()) {
		cout << "û���ҵ� " << title << "���޷�ɾ����" << endl;
	}
	else {
		books.erase(newEnd, books.end());
		cout << title << " �ѱ�ɾ��" << endl;
		SaveBooksToFile(); // ɾ��ͼ��󱣴浽�ļ�
	}
	system("pause");
	system("cls");
}
//�Զ���ȽϺ�������ͼ������
bool CompareBook(const Book& a, const Book& b)
{
	return a.GetTitle() < b.GetTitle();
}
//����������
void  BookManagement::SortBookByTitle()
{
	std::sort(books.begin(), books.end(), CompareBook);//sort
	cout << "�Ѱ���������" << endl;
	system("pause");
}
//���������黹
void BookManagement::HandleBorrow()
{
	system("cls");
	cout << "                          ******************************************************************" << endl;
	cout << "                          ***              ��ӭʹ��ͼ�����ϵͳ-���ͼ��                ***" << endl;
	cout << "                          ******************************************************************" << endl;
	cout << "����ϵͳͼ�����£�" << endl;


	this->displayBooks();
	string title;
	int BorrowNumber;
	cout << "����Ҫ���ĵ�ͼ����ĿΪ��";
	cin >> BorrowNumber;
	cout << endl;
	for (int i = 0; i < BorrowNumber; i++)
	{
		cout << "�������" << i + 1 << "��" << "Ҫ���ĵ���:";
		int mark = 1;
		if (i == 0)
		{
			cin.ignore();
		}
		getline(cin, title);
		for (auto& book : books)
		{
			if (book.GetTitle() == title&&book.GetStatus()=="�ڹ���")
			{
				cout << "��"<<title << "��" << "���ĳɹ�" << endl;
				this->m_BorrowerV.push_back(book.GetISBN());
				this->m_BorrowerV.push_back(book.GetTitle());
				this->m_BorrowerV.push_back(book.GetCategory());
				//��m_BorrowerV�����Ӵ洢ISBN ���� ���͵���Ϣ
				book.Borrow();
				mark=0;
				//��������Ϣ����  6   ����  �˺�   �ֻ�����    ͼ��3
				//ͨ�����������ݵ���   ��������Ϣ.txt
				ofstream ofs2;
				ofs2.open("��������Ϣ.txt", ios::out | ios::app);

				for (int i = 0; i < 6; i++)
				{
					ofs2 << this->m_BorrowerV[i] << ",";
				}
				//��m_BorrowerV���������Ϣ�浽�ļ���
				ofs2.close();

				//m_BorrowerV.clear();//�������
				/*for (int i = 0; i < 3; i++)
				{
					m_BorrowerV.erase(m_BorrowerV.begin() + 3);
				}*/
				auto it = m_BorrowerV.begin() + 3; // ָ��Ҫɾ���ĵ�һ��Ԫ��
				m_BorrowerV.erase(it, it + 3); // ��it��ʼ��ɾ��������������Ԫ��
			}
		    else if (book.GetTitle() == title&&book.GetStatus() == "�ѽ��")
			{
				cout << "����ʧ��" << "��" << title << "��" << "�ѱ����" << endl;
				mark=0;
			}
		}
		if (mark)
		{
			cout << "����ʧ��" << "��" << title << "��" << "������" << endl;
		}
		SaveBooksToFile(); // ������ĺ󱣴浽�ļ�
	}
	this->m_BorrowerV.clear();//�������ʧ��mpd�ˣ�����Ҫ���֮ǰ�Ž�ȥ����������Ϣ
	system("pause");
	system("cls");
}


void BookManagement::HandleReturn()
{
	////��ʾ����
	//system("cls");
	//cout << "                          ******************************************************************" << endl;
	//cout << "                          ***                           ͼ��黹                         ***" << endl;
	//cout << "                          ******************************************************************" << endl;
	//cout << "����ϵͳͼ�����£�" << endl;
	this->displayBooks();
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


		for (auto& book : books)
		{
			if (book.GetTitle() == title&&book.GetStatus()=="�ѽ��")
			{
				cout << "��" << title << "��" << "�黹�ɹ�" << endl;
				book.Return();//true���ѽ������Ϊfalse���ڹ��ڣ�,return false
				mark = 0;
			}
		}
		if (mark)
		{
			cout << "�黹ʧ��" << "��" << title << "��" << "�ǹ���ͼ��" << endl;
		}
		SaveBooksToFile(); // ������ĺ󱣴浽�ļ�
	}
	system("pause");
	system("cls");
}

//��ȡ����
string Book::GetTitle() const
{
	return title;
}
//��ȡ����
string Book::GetAuthor() const
{
	return author;
}
//��ȡ��������
string Book::GetPublicationDate() const
{
	return PublicationDate;
}
//��ȡISBN��
string Book::GetISBN() const
{
	return ISBN;
}
//��ȡ״̬
string Book::GetStatus() const
{
	return (status?"�ѽ��":"�ڹ���");
}
void Book::Borrow()
{
	status = true;
}
void Book::Return()
{
	status = false;
}
//����״̬
void Book::SetStatus(bool borrowed) {
	status = borrowed;
}
//��ȡ����
string Book::GetCategory() const
{
	return category;
}
