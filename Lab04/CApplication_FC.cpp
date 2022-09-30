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


// ȭ�鿡 ��ɾ ���
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


// FC�� ������ �޾� ����Ʈ�� ����
int Application_FC::Add_FC(SortedList<MultimediaContent>& MCList) {

	cout << "\t=====�����ϴ� ��Ͽ� �߰��� ������ ���=====" << endl;
	if (MCList.GetLength() == 0) {
		cout << "\t!���� : ������ �������� ����ֽ��ϴ�." << endl;
		return 0;
	}
	MCList.ResetList();
	MultimediaContent item;
	while (MCList.GetNextItem(item) != -1) {
		item.DisplayRecordOnScreen();
	}

	cout << "\t �����ϴ� ��Ͽ� �߰��� ������ �̸��� �Է����ּ���" << endl;
	item.SetNameFromKB();
	FavoriteContent fItem;
	if (MCList.Retrieve_Binary(item)) {
		fItem.SetRecord(item.GetName(), item.GetType());
		cout << "\t setRecord �۵�" << endl;
	}
	else 
	{
		cout << "\telse�� �ߵ�" << endl;
		return 0;
	}
	cout << "\t������ �߰� ����" << endl;

	if (m_FCList.Add(fItem) == 1) {
		m_nameOrder.Add(fItem.GetName());
		cout << "\t���ο� �������� �߰��Ͽ����ϴ�." << endl;
		cout << "\t������ �߰�" << endl;
		return 1;
	}
	else if (m_FCList.Add(fItem) == -1) {
		cout << "\t������ �̸��� ���� �������� �̹� �����մϴ�" << endl;
		cout << "\t������ �߰� ����" << endl;
		return 0;
	}
	else {
		cout << "\t�� �̻� �������� �߰��� �� �����ϴ�." << endl;
		cout << "\t������ �߰� ����" << endl;
		return 0;
	}
}

int Application_FC::Delete_FC() {
	FavoriteContent item;
	string name;
	cout << "\t �����ϴ� ��Ͽ��� ������ ������ �̸��� �Է����ּ���: ";
	cin >> name;
	item.SetName(name);
	if (m_FCList.Delete(item)) {
		m_nameOrder.Delete(name);
		cout << "\t�������� �����Ͽ����ϴ�." << endl;
		return 1;
	}
	else {
		cout << "\t�Է��� �̸��� ��ġ�ϴ� �������� ã�� �� �����ϴ�." << endl;
		return 0;
	}
}

// MC���� FC ���� �ִ� �������� ������ FC������ �����ϴ� �Լ�
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

	if (m_order == 1) { // �̸� �� ���
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
		m_FCList.ResetList(); // ���� �� ���
		cout << "\t=====��� �����ϴ� ������=====" << endl;
		cout << "\t�� " << m_FCList.GetLength() << "���� ������" << endl << endl;
		while (m_FCList.GetNextItem(item) != -1) {
			item.DisplayRecordOnScreen();
		}
		return;
	}

	else if(m_order == 2){ //��ȸ�� ��
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
	cout << "\t �ڼ��� ���캼 �����ϴ� ������ ���� �Է����ּ���" << endl;
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
	cout << "\t���� ���� ����" << endl;
	cout << "\t 0 : �ֱٳ�¥, 1 : �̸�, 2 : ��ȸ��" << endl;
	cout << "\t>>> ";
	int n;
	cin >> n;
	m_order = n;
	Display_FC_list();
}