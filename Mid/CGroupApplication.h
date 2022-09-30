#pragma once

class GroupApplication
{
private:
	DoublySortedLinkedList<Event> m_eventList; // 이벤트 리스트
	DoublySortedLinkedList<Person> m_personList; // 인물 리스트
	DoublySortedLinkedList<Location> m_LocationList;// 장소 리스트
	List<Content>* m_mList;// 마스터리스트의 포인터


public:
	// 생성자, 마스터 리스트의 포인터 초기화
	GroupApplication(List<Content> &m_List) {
		m_mList = &m_List;
	}

	/**
	*	@brief	모든 리스트를 비움
	*	@pre	없음
	*	@post	모든 리스트가 비워짐
	*/
	void MakeEmpty() {
		m_eventList.MakeEmpty();
		m_personList.MakeEmpty();
		m_LocationList.MakeEmpty();
	}


	/**
	*	@brief	파일을 읽어 데이터를 각각의 그룹 리스트에 저장
	*	@pre	파일이 열림
	*	@post	리스트에 파일의 정보가 저장됨
	*	@param	fin	파일 디스크립터
	*/
	void ReadFile(ifstream& fin) {
		int n;
		Event event;
		Person person;
		Location location;
		string title;
		string des;
		/*
			이벤트수N
			이벤트n0	이벤트n0 설명
			이벤트n1	이벤트n1 설명
			...
			인물수N
			인물n0	인물n0 설명
			...
			장소수N
			장소n0	장소n0 설명
			....

			형태의 파일을 읽음
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
	*	@brief	각각의 그룹 리스트의 데이터를 파일에 쓴다
	*	@pre	파일이 열림
	*	@post	파일에 리스트의 정보가 쓰임
	*	@param	fout	파일 디스크립터
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
	*	@brief	새로운 컨텐츠를 추가
	*	@pre	없음
	*	@post	새로운 컨텐츠가 각각의 그룹리스트에 추가됨
	*	@param	mc	추가할 컨텐츠
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
	*	@brief	새로운 컨텐츠를 추가
	*	@pre	없음
	*	@post	새로운 컨텐츠가 각각의 그룹리스트에 추가됨
	*	@param	mc	추가할 컨텐츠
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
	*	@brief	GroupApplication의 메뉴를 출력
	*	@pre	마스터리스트를 가리키는 포인터가 초기화됨
	*	@post	GroupApplication의 메뉴가 출력됨
	*/
	void Run() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : 이벤트 " << endl;
			cout << "\t 2 : 인물 " << endl;
			cout << "\t 3 : 장소 " << endl;
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
	*	@brief	Event 메뉴를 출력
	*	@pre	없음.
	*	@post	Event의 메뉴가 출력됨
	*/
	void EventMenu() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t--- 이벤트 리스트 ----- " << endl;
			DisplayAll(m_eventList); // 이벤트리스트가 간략하게 출력됨
			cout << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : 이벤트 설명 수정 " << endl;
			cout << "\t 2 : 이벤트 검색 " << endl;;
			cout << "\t 3 : 전체 이벤트 출력 " << endl;;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:		//이벤트 설명 수정
				ModifyDescription(m_eventList);
				break;
			case 2:		// 이벤트 이름을 입력받아서 event리스트에서 찾고, 찾은 event에 소속된 콘텐츠의 자세한 정보를 화면에 출력	                 
				FindNDisplay(m_eventList);
				break;
			case 3:		// 이벤트 리스트의 정보를 출력
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
	*	@brief	Location 메뉴를 출력
	*	@pre	없음.
	*	@post	Location의 메뉴가 출력됨
	*/
	void LocationMenu() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t--- 장소 리스트 ----- " << endl;
			DisplayAll(m_LocationList);
			cout << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : 장소 설명 수정 " << endl;
			cout << "\t 2 : 장소 검색 " << endl;;
			cout << "\t 3 : 전체 장소 출력 " << endl;;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:		//이벤트 설명 수정
				ModifyDescription(m_LocationList);
				break;
			case 2:		// 이벤트 이름을 입력받아서 event리스트에서 찾고, 찾은 event에 소속된 콘텐츠의 자세한 정보를 화면에 출력	                 
				FindNDisplay(m_LocationList);
				break;
			case 3:		// 이벤트 리스트의 정보를 출력
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
	*	@brief	Person 메뉴를 출력
	*	@pre	없음.
	*	@post	Persons의 메뉴가 출력됨
	*/
	void PersonMenu() {
		int command;
		while (1) {
			cout << endl << endl;
			cout << "\t--- 인물 리스트 ----- " << endl;
			DisplayAll(m_personList);
			cout << endl;
			cout << "\t---ID -- Command ----- " << endl;
			cout << "\t 1 : 인물 설명 수정 " << endl;
			cout << "\t 2 : 인물로 검색 " << endl;;
			cout << "\t 3 : 전체 인물 출력 " << endl;;
			cout << "\t 0 : Quit" << endl;
			cout << endl << "\t Choose a Command--> ";
			cin >> command;
			cout << endl;
			switch (command)
			{
			case 1:		//이벤트 설명 수정
				ModifyDescription(m_personList);
				break;
			case 2:		// 이벤트 이름을 입력받아서 event리스트에서 찾고, 찾은 event에 소속된 콘텐츠의 자세한 정보를 화면에 출력	                 
				FindNDisplay(m_personList);
				break;
			case 3:		// 이벤트 리스트의 정보를 출력
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
	*	@brief	리스트의 정보를 간략하게 출력
	*	@pre	리스트가 초기화됨
	*	@post	리스트의 정보를 간략하게 출력됨
	*	@param	lst 출력할 리스트
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
	*	@brief	그룹 리스트에서 검색해서 해당항목의 설명을 수정
	*	@pre	리스트가 초기화됨
	*	@post	그룹 리스트의 해당 정보가 수정됨
	*	@param	lst 수정할 리스트
	*/
	template <typename T>
	int ModifyDescription(DoublySortedLinkedList<T>& lst) {
		string str;
		cout << "\t수정할 항목: ";
		cin >> str;
		cout << endl;
		T group;
		group.SetTitle(str);
		DoublyIterator<T> iter(lst);
		if (lst.Get(group)) {
			cout << "\t수정할 설명을 입력해 주세요" << endl;
			group.SetDescriptionfromKB();
			cout << endl;
			cout << "\t done!" << endl;
			lst.Replace(group);
			system("pause");
			return 1;
		}
		else {
			cout << "\t해당 항목은 존재하지 않습니다." << endl;
			system("pause");
			return 0;
		}
	}


	/**
	*	@brief	그룹 리스트에서 검색해서 해당항목을 자세히 출력
	*	@pre	리스트가 초기화됨
	*	@post	그룹 리스트의 해당 정보가 화면에 출력됨
	*	@param	lst 출력할 리스트
	*/
	template <typename T>
	int FindNDisplay(DoublySortedLinkedList<T>& lst) {
		string str;
		cout << "\t검색할 항목: ";
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
			cout << "\t해당 항목은 존재하지 않습니다." << endl;
			system("pause");
			return 0;
		}
	}

	/**
	*	@brief	그룹 리스트의 모든 정보를 자세히 출력
	*	@pre	리스트가 초기화됨
	*	@post	그룹 리스트의 정보가 화면에 출력됨
	*	@param	lst 출력할 리스트
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

