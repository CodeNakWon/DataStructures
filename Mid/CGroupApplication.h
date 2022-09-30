#pragma once

class GroupApplication
{
private:
	DoublySortedLinkedList<Event> m_eventList; // �̺�Ʈ ����Ʈ
	DoublySortedLinkedList<Person> m_personList; // �ι� ����Ʈ
	DoublySortedLinkedList<Location> m_LocationList;// ��� ����Ʈ
	List<Content>* m_mList;// �����͸���Ʈ�� ������


public:
	// ������, ������ ����Ʈ�� ������ �ʱ�ȭ
	GroupApplication(List<Content> &m_List) {
		m_mList = &m_List;
	}

	/**
	*	@brief	��� ����Ʈ�� ���
	*	@pre	����
	*	@post	��� ����Ʈ�� �����
	*/
	void MakeEmpty() {
		m_eventList.MakeEmpty();
		m_personList.MakeEmpty();
		m_LocationList.MakeEmpty();
	}


	/**
	*	@brief	������ �о� �����͸� ������ �׷� ����Ʈ�� ����
	*	@pre	������ ����
	*	@post	����Ʈ�� ������ ������ �����
	*	@param	fin	���� ��ũ����
	*/
	void ReadFile(ifstream& fin) {
		int n;
		Event event;
		Person person;
		Location location;
		string title;
		string des;
		/*
			�̺�Ʈ��N
			�̺�Ʈn0	�̺�Ʈn0 ����
			�̺�Ʈn1	�̺�Ʈn1 ����
			...
			�ι���N
			�ι�n0	�ι�n0 ����
			...
			��Ҽ�N
			���n0	���n0 ����
			....

			������ ������ ����
		*/

		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> title;
			fin.get();
			getline(fin, des);
			event.SetTitle(title);
			event.SetDescription(des);
			m_eventList.Add(event);
		}

		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> title;
			fin.get();
			getline(fin, des);
			person.SetTitle(title);
			person.SetDescription(des);
			m_personList.Add(person);
		}

		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> title;
			fin.get();
			getline(fin, des);
			location.SetTitle(title);
			location.SetDescription(des);
			m_LocationList.Add(location);
		}
	}


	/**
	*	@brief	������ �׷� ����Ʈ�� �����͸� ���Ͽ� ����
	*	@pre	������ ����
	*	@post	���Ͽ� ����Ʈ�� ������ ����
	*	@param	fout	���� ��ũ����
	*/
	void WriteFile(ofstream& fout) {
		fout << m_eventList.GetLength() << endl;
		DoublyIterator<Event> e_iter(m_eventList);
		while (e_iter.NotNull()) {
			fout << e_iter.GetCurrentNode().data.GetTitle() << "\t" << e_iter.GetCurrentNode().data.GetDescription() << endl;
			e_iter.Next();
		}
		fout << m_personList.GetLength() << endl;
		DoublyIterator<Person> p_iter(m_personList);
		while (p_iter.NotNull()) {
			fout << p_iter.GetCurrentNode().data.GetTitle() << "\t" << p_iter.GetCurrentNode().data.GetDescription() << endl;
			p_iter.Next();
		}
		fout << m_LocationList.GetLength() << endl;
		DoublyIterator<Location> l_iter(m_LocationList);
		while (l_iter.NotNull()) {
			fout << l_iter.GetCurrentNode().data.GetTitle() << "\t" << l_iter.GetCurrentNode().data.GetDescription() << endl;
			l_iter.Next();
		}
	}


	/**
	*	@brief	���ο� �������� �߰�
	*	@pre	����
	*	@post	���ο� �������� ������ �׷츮��Ʈ�� �߰���
	*	@param	mc	�߰��� ������
	*/
	void AddContent(Content& mc) {
		mc.GetEventName();
		Event event;
		Person person;
		Location location;
		event.SetTitle(mc.GetEventName());
		person.SetTitle(mc.GetPerson());
		location.SetTitle(mc.GetLocation());

		if (m_eventList.Get(event)) {
			event.AddMC(mc);
			m_eventList.Replace(event);
		}
		else {
			event.AddMC(mc);
			m_eventList.Add(event);
		}

		if (m_personList.Get(person)) {
			person.AddMC(mc);
			m_personList.Replace(person);
		}
		else {
			person.AddMC(mc);
			m_personList.Add(person);
		}

		if (m_LocationList.Get(location)) {
			location.AddMC(mc);
			m_LocationList.Replace(location);
		}
		else {
			location.AddMC(mc);
			m_LocationList.Add(location);
		}
	}


	/**
	*	@brief	���ο� �������� �߰�
	*	@pre	����
	*	@post	���ο� �������� ������ �׷츮��Ʈ�� �߰���
	*	@param	mc	�߰��� ������
	*/
	void DeleteContent(Content& mc) {
		Event event;
		Person person;
		Location location;

		event.SetTitle(mc.GetEventName());
		person.SetTitle(mc.GetPerson());
		location.SetTitle(mc.GetLocation());

		m_eventList.Get(event);
		event.Delete(mc);
		if (event.isEmpty()) {
			m_eventList.Delete(event);
		}
		else {
			m_eventList.Replace(event);
		}

		m_personList.Get(person);
		person.Delete(mc);
		if (person.isEmpty()) {
			m_personList.Delete(person);
		}
		else {
			m_personList.Replace(person);
		}

		m_LocationList.Get(location);
		location.Delete(mc);
		if (location.isEmpty()) {
			m_LocationList.Delete(location);
		}
		else {
			m_LocationList.Replace(location);
		}

	}

	/**
	*	@brief	GroupApplication�� �޴��� ���
	*	@pre	�����͸���Ʈ�� ����Ű�� �����Ͱ� �ʱ�ȭ��
	*	@post	GroupApplication�� �޴��� ��µ�
	*/
	void Run() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : �̺�Ʈ " << endl;
			cout << "\t 2 : �ι� " << endl;
			cout << "\t 3 : ��� " << endl;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:
				EventMenu();
				break;
			case 2:
				PersonMenu();
				break;
			case 3:
				LocationMenu();
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}

	}

	/**
	*	@brief	Event �޴��� ���
	*	@pre	����.
	*	@post	Event�� �޴��� ��µ�
	*/
	void EventMenu() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t--- �̺�Ʈ ����Ʈ ----- " << endl;
			DisplayAll(m_eventList); // �̺�Ʈ����Ʈ�� �����ϰ� ��µ�
			cout << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : �̺�Ʈ ���� ���� " << endl;
			cout << "\t 2 : �̺�Ʈ �˻� " << endl;;
			cout << "\t 3 : ��ü �̺�Ʈ ��� " << endl;;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:		//�̺�Ʈ ���� ����
				ModifyDescription(m_eventList);
				break;
			case 2:		// �̺�Ʈ �̸��� �Է¹޾Ƽ� event����Ʈ���� ã��, ã�� event�� �Ҽӵ� �������� �ڼ��� ������ ȭ�鿡 ���	                 
				FindNDisplay(m_eventList);
				break;
			case 3:		// �̺�Ʈ ����Ʈ�� ������ ���
				DisplayDetailsAll(m_eventList);
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}

	/**
	*	@brief	Location �޴��� ���
	*	@pre	����.
	*	@post	Location�� �޴��� ��µ�
	*/
	void LocationMenu() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t--- ��� ����Ʈ ----- " << endl;
			DisplayAll(m_LocationList);
			cout << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : ��� ���� ���� " << endl;
			cout << "\t 2 : ��� �˻� " << endl;;
			cout << "\t 3 : ��ü ��� ��� " << endl;;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:		//�̺�Ʈ ���� ����
				ModifyDescription(m_LocationList);
				break;
			case 2:		// �̺�Ʈ �̸��� �Է¹޾Ƽ� event����Ʈ���� ã��, ã�� event�� �Ҽӵ� �������� �ڼ��� ������ ȭ�鿡 ���	                 
				FindNDisplay(m_LocationList);
				break;
			case 3:		// �̺�Ʈ ����Ʈ�� ������ ���
				DisplayDetailsAll(m_LocationList);
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}

	/**
	*	@brief	Person �޴��� ���
	*	@pre	����.
	*	@post	Persons�� �޴��� ��µ�
	*/
	void PersonMenu() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t--- �ι� ����Ʈ ----- " << endl;
			DisplayAll(m_personList);
			cout << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : �ι� ���� ���� " << endl;
			cout << "\t 2 : �ι��� �˻� " << endl;;
			cout << "\t 3 : ��ü �ι� ��� " << endl;;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:		//�̺�Ʈ ���� ����
				ModifyDescription(m_personList);
				break;
			case 2:		// �̺�Ʈ �̸��� �Է¹޾Ƽ� event����Ʈ���� ã��, ã�� event�� �Ҽӵ� �������� �ڼ��� ������ ȭ�鿡 ���	                 
				FindNDisplay(m_personList);
				break;
			case 3:		// �̺�Ʈ ����Ʈ�� ������ ���
				DisplayDetailsAll(m_personList);
				break;
			case 0:
				return;
			default:
				cout << "\tIllegal selection...\n";
				break;
			}
		}
	}

	

	/**
	*	@brief	����Ʈ�� ������ �����ϰ� ���
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	����Ʈ�� ������ �����ϰ� ��µ�
	*	@param	lst ����� ����Ʈ
	*/
	template <typename T>
	void DisplayAll(DoublySortedLinkedList<T>& lst) {
		T group;
		DoublyIterator<T> iter(lst);
		while (iter.NotNull()) {
			group = iter.GetCurrentNode().data;
			group.DisplayTitle();
			group.DisplayDescriptionOnScreen();
			group.DisplayIncludedContents();
			iter.Next();
		}
	}


	/**
	*	@brief	�׷� ����Ʈ���� �˻��ؼ� �ش��׸��� ������ ����
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	�׷� ����Ʈ�� �ش� ������ ������
	*	@param	lst ������ ����Ʈ
	*/
	template <typename T>
	int ModifyDescription(DoublySortedLinkedList<T>& lst) {
		string str;
		cout << "\t������ �׸�: ";
		cin >> str;
		cout << endl;
		T group;
		group.SetTitle(str);
		DoublyIterator<T> iter(lst);
		if (lst.Get(group)) {
			cout << "\t������ ������ �Է��� �ּ���" << endl;
			group.SetDescriptionfromKB();
			cout << endl;
			cout << "\t done!" << endl;
			lst.Replace(group);
			system("pause");
			return 1;
		}
		else {
			cout << "\t�ش� �׸��� �������� �ʽ��ϴ�." << endl;
			system("pause");
			return 0;
		}
	}


	/**
	*	@brief	�׷� ����Ʈ���� �˻��ؼ� �ش��׸��� �ڼ��� ���
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	�׷� ����Ʈ�� �ش� ������ ȭ�鿡 ��µ�
	*	@param	lst ����� ����Ʈ
	*/
	template <typename T>
	int FindNDisplay(DoublySortedLinkedList<T>& lst) {
		string str;
		cout << "\t�˻��� �׸�: ";
		cin >> str;
		cout << endl;
		T group;
		group.SetTitle(str);
		DoublyIterator<T> iter(lst);
		if (lst.Get(group)) {
			group.DisplayDetailAll(*m_mList);
			system("pause");
			return 1;
		}
		else {
			cout << "\t�ش� �׸��� �������� �ʽ��ϴ�." << endl;
			system("pause");
			return 0;
		}
	}

	/**
	*	@brief	�׷� ����Ʈ�� ��� ������ �ڼ��� ���
	*	@pre	����Ʈ�� �ʱ�ȭ��
	*	@post	�׷� ����Ʈ�� ������ ȭ�鿡 ��µ�
	*	@param	lst ����� ����Ʈ
	*/
	template <typename T>
	void DisplayDetailsAll(DoublySortedLinkedList<T>& lst) {
		T group;
		DoublyIterator<T> iter(lst);
		while (iter.NotNull()) {
			iter.GetCurrentNode().data.DisplayDetailAll(*m_mList);
			iter.Next();
		}
		system("pause");
	}
};

