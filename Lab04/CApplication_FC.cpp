#include "pch.h"
#include "CApplication_FC.h"



void Application_FC::Run(SortedList<MultimediaContent>& MCList) {
	while (1) {
		m_CommandFC = GetCommand();

		switch (m_CommandFC)
		{
		case 1:
			Add_FC(MCList);
			break;
		case 2:
			Delete_FC();
			break;
		case 3:
			Display_FC_list();
			break;
		case 4:
			Display_Detail_FC(MCList);
			break;
		case 5:
			Rearrange_FC();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// 화면에 명령어를 출력
int Application_FC::GetCommand() {
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t 1 : Add favorite content" << endl;
	cout << "\t 2 : Delete favorite contents" << endl;
	cout << "\t 3 : Display favorite contents " << endl;
	cout << "\t 4 : Display Details" << endl;
	cout << "\t 5 : Rearrange favorite contents" << endl;
	cout << "\t 0 : Quit" << endl;
	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;
	return command;
}


// FC의 정보를 받아 리스트에 저장
int Application_FC::Add_FC(SortedList<MultimediaContent>& MCList) {

	cout << "\t=====좋아하는 목록에 추가할 컨텐츠 목록=====" << endl;
	if (MCList.GetLength() == 0) {
		cout << "\t!오류 : 컨텐츠 보관함이 비어있습니다." << endl;
		return 0;
	}
	MCList.ResetList();
	MultimediaContent item;
	while (MCList.GetNextItem(item) != -1) {
		item.DisplayRecordOnScreen();
	}

	cout << "\t 좋아하는 목록에 추가할 컨텐츠 이름을 입력해주세요" << endl;
	item.SetNameFromKB();
	FavoriteContent fItem;
	if (MCList.Retrieve_Binary(item)) {
		fItem.SetRecord(item.GetName(), item.GetType());
		cout << "\t setRecord 작동" << endl;
	}
	else 
	{
		cout << "\telse문 발동" << endl;
		return 0;
	}
	cout << "\t콘텐츠 추가 입장" << endl;

	if (m_FCList.Add(fItem) == 1) {
		m_nameOrder.Add(fItem.GetName());
		cout << "\t새로운 콘텐츠를 추가하였습니다." << endl;
		cout << "\t콘텐츠 추가" << endl;
		return 1;
	}
	else if (m_FCList.Add(fItem) == -1) {
		cout << "\t동일한 이름을 가진 콘텐츠가 이미 존재합니다" << endl;
		cout << "\t콘텐츠 추가 실패" << endl;
		return 0;
	}
	else {
		cout << "\t더 이상 콘텐츠를 추가할 수 없습니다." << endl;
		cout << "\t콘텐츠 추가 실패" << endl;
		return 0;
	}
}

int Application_FC::Delete_FC() {
	FavoriteContent item;
	string name;
	cout << "\t 좋아하는 목록에서 삭제할 컨텐츠 이름을 입력해주세요: ";
	cin >> name;
	item.SetName(name);
	if (m_FCList.Delete(item)) {
		m_nameOrder.Delete(name);
		cout << "\t콘텐츠를 삭제하였습니다." << endl;
		return 1;
	}
	else {
		cout << "\t입력한 이름과 일치하는 콘텐츠를 찾을 수 없습니다." << endl;
		return 0;
	}
}

// MC에서 FC 속해 있는 컨텐츠가 삭제시 FC에서도 삭제하는 함수
int Application_FC::DeleteMContents(MultimediaContent &mc) {
	FavoriteContent item;
	string name = mc.GetName();
	item.SetName(mc.GetName());
	if (m_FCList.Delete(item)) {
		m_nameOrder.Delete(name);
		return 1;
	}
	return 0;
}

void Application_FC::Display_FC_list() {
	FavoriteContent item;
	string name;

	if (m_order == 1) { // 이름 순 출력
		m_nameOrder.ResetList();
		for(int i =0;i < m_nameOrder.GetLength(); i++){
			m_nameOrder.GetNextItem(name);
			cout << name << endl;
			m_FCList.ResetList();
			while (1) {
				m_FCList.GetNextItem(item);
				if (item.GetName() == name) {
					item.DisplayRecordOnScreen();
					break;
				}
			}
		}
		return;
	}

	else if (m_order == 0) {
		m_FCList.ResetList(); // 들어온 순 출력
		cout << "\t=====모든 좋아하는 컨텐츠=====" << endl;
		cout << "\t총 " << m_FCList.GetLength() << "개의 컨텐츠" << endl << endl;
		while (m_FCList.GetNextItem(item) != -1) {
			item.DisplayRecordOnScreen();
		}
		return;
	}

	else if(m_order == 2){ //조회수 순
		int max = 0;
		m_FCList.ResetList();
		while (m_FCList.GetNextItem(item)!=-1) {
			if (item.GetViews() > max) {
				max = item.GetViews();
			}
		}
		for (int i = max; i >= 0; i--) {
			m_FCList.ResetList();
			while (m_FCList.GetNextItem(item) != -1) {
				if (item.GetViews() == i) {
					item.DisplayRecordOnScreen();
				}
			}
		}
	}
}

int Application_FC::Display_Detail_FC(SortedList<MultimediaContent>& MCList) {

	string name;
	cout << "\t 자세히 살펴볼 좋아하는 콘텐츠 명을 입력해주세요" << endl;
	cout << "\t >>> ";
	cin >> name;
	FavoriteContent fItem;
	fItem.SetName(name);
	if (m_FCList.Retrieve(fItem)) {
		fItem.View();
		m_FCList.Replace(fItem);
		MultimediaContent mItem;
		mItem.SetName(name);
		MCList.Retrieve_Binary(mItem);
		mItem.DisplayRecordOnScreen();
		return 1;
	}
	return 0;
}

void Application_FC::Rearrange_FC() {
	string choose;
	cout << "\t정렬 기준 선택" << endl;
	cout << "\t 0 : 최근날짜, 1 : 이름, 2 : 조회수" << endl;
	cout << "\t>>> ";
	int n;
	cin >> n;
	m_order = n;
	Display_FC_list();
}