#include "CItemType.h"


// ������ �̸� ��ȯ
string ItemType::GetName() const {
	return m_cName;
}


// ������ ���� ��ȯ
ContentType ItemType::GetType() const {
	return m_cType;
}


// ������ ������¥�� �ð� ��ȯ
string ItemType::GetDate() const {
	return m_Date;
}


// �������� ���Ե� ��� ��ȯ
string ItemType::GetPerson() const {
	return m_Person;
}

// ������ ���� ��ȯ
int ItemType::GetCategory() const {
	return m_Category;
}

//�̺�Ʈ �� ��ȯ
string ItemType::GetEventName() const {
	return m_EventName;
}


// ������ �̸� ����
void ItemType::SetName(string inName) {
	m_cName = inName;
}


// ������ ���� ����
void ItemType::SetType(ContentType inType) {
	m_cType = inType;
}


// ������ ������¥�� �ð� ����
void ItemType::SetDate(string inDate) {
	m_Date = inDate;
}


// �������� ���Ե� ��� ����
void ItemType::SetPerson(string inPerson) {
	m_Person = inPerson;
}

// ������ ���� ����
void ItemType::SetCategory(int inCategory) {
	m_Category = inCategory;
}

// �̺�Ʈ�� ����
void ItemType::SetEventName(string inEventName) {
	m_EventName = inEventName;
}


// �̺�Ʈ ���� ����
void ItemType::SetRecord(string inName, ContentType inType, string inDate, string inPerson, string inEventName) {
	m_cName = inName;
	m_cType = inType;
	m_Date = inDate;
	m_Person = inPerson;
	m_EventName = inEventName;
}


// ������ �̸� ���
void ItemType::DisplayNameOnScreen() const {
	cout << "\tContent name : " << m_cName << endl;
}


// ������ ���� ���
void ItemType::DisplayTypeOnScreen() const {
	if (m_cType == VIDEO) {
		cout << "\tContent type: " << "Video" << endl;
	}
	else if (m_cType == PICTURE) {
		cout << "\tContent type : " << "Picture" << endl;
	}
	else {
		cout << "\tContent type : " << "Unknown" << endl;
	}
}


// ������ ������¥�� �ð� ���
void ItemType::DisplayDateOnScreen() const {
	cout << "\tContent generated date : " << m_Date << endl;
}


// �������� ���Ե� ��� ���
void ItemType::DisplayPersonOnScreen() const {
	cout << "\tContent included person : " << m_Person << endl;
}

// ������ ���� ���
void ItemType::DisplayCategoryOnScreen() const {
	switch (m_Category) {
	case 0:// �ι�
		cout << "\tCategory : �ι�" << endl;
		break;
	case 1://����
		cout << "\tCategory : ����" << endl;
		break;
	case 2://�繰
		cout << "\tCategory : �繰" << endl;
		break;
	case 3://���
		cout << "\tCategory : ���" << endl;
		break;
	default:
		cout << "\tCategory : �� �� ����" << endl;
		break;
	}
}


// �̺�Ʈ�� ���
void ItemType::DisplayEventNameOnScreen() const {
	cout << "\tEvent name : " << m_EventName << endl;
}



// ������ ���� ���
void ItemType::DisplayRecordOnScreen() const {
	DisplayNameOnScreen();
	DisplayTypeOnScreen();
	DisplayDateOnScreen();
	DisplayPersonOnScreen();
	DisplayCategoryOnScreen();
	DisplayEventNameOnScreen();
	cout << endl;
}



// Ű����� ������ �̸� �Է� �Լ�
void ItemType::SetNameFromKB() {
	string inName;
	cout << "\t====Content name====" << endl;
	cout << "\t>>> ";
	cin >> inName;
	SetName(inName);
	cout << endl;
}


// Ű����� ������ Ÿ�� �Է� �Լ�
void ItemType::SetTypeFromKB() {
	string type;
	cout << "\t====Content type====" << endl;
	cout << "\t(Picture : 0 / Video : 1)>>> ";
	cin >> type;
	if (type == "0") {
		SetType(PICTURE);
	}
	else if (type == "1") {
		SetType(VIDEO);
	}
	else {
		SetType(UNKNOWN);
	}
	cout << endl;
}


// Ű����� ������ ���� ��¥�� �ð� �Է� �Լ�
void ItemType::SetDateFromKB() {
	string inDate;
	cout << "\t====Generated date====" << endl;
	cout << "\t>>> ";
	cin >> inDate;
	SetDate(inDate);
	cout << endl;
}


// Ű����� �������� ���Ե� ��� �Է� �Լ�
void ItemType::SetPersonFromKB() {
	string inPerson;
	cout << "\t====Included person====" << endl;
	cout << "\t>>> ";
	cin >> inPerson;
	SetPerson(inPerson);
	cout << endl;
}

// Ű����� �������� ���Ե� ��� �Է� �Լ�
void ItemType::SetCategoryFromKB() {
	int inCategory;
	cout << "\t====Category( 0:�ι� / 1:���� / 2:�繰 / 3:��� )====" << endl;
	cout << "\t>>> ";
	cin >> inCategory;
	SetCategory(inCategory);
	cout << endl;
}

// Ű����� �̺�Ʈ �� �Է� �Լ�
void ItemType::SetEventNameFromKB() {
	string inEvent;
	cout << "\t====Event name====" << endl;
	cout << "\t>>> ";
	cin >> inEvent;
	SetEventName(inEvent);
	cout << endl;
}


// Ű����� ������ ���� �Է� �Լ�
void ItemType::SetRecordFromKB() {
	cout << "\t===SetRecord===" << endl << endl;
	cout << "\t_1_ ";
	SetNameFromKB();
	cout << "\t_2_ ";
	SetTypeFromKB();
	cout << "\t_3_ ";
	SetDateFromKB();
	cout << "\t_4_ ";
	SetPersonFromKB();
	cout << "\t_5_ ";
	SetCategoryFromKB();
	cout << "\t_6_ ";
	SetEventNameFromKB();
	cout << endl;
}


// ������ ������ ���Ͽ��� �д� �Լ�
int ItemType::ReadDataFromFile(ifstream& fin) {
	string inType;
	fin >> m_cName >> inType >> m_Date >> m_Person >> m_Category >> m_EventName;
	if (inType == "PICTURE") {
		SetType(PICTURE);
	}
	else if (inType == "VIDEO") {
		SetType(VIDEO);
	}
	if (fin) { return 1; }
	else { return 0; }
}


// ������ ������ ���Ϸ� ����ϴ� �Լ�
int ItemType::WriteDataToFile(ofstream& fout) {
	string outType;
	if (m_cType == PICTURE) {
		outType = "PICTURE";
	}
	else if (m_cType == VIDEO) {
		outType = "VIDEO";
	}
	else {
		outType = "UNKNOWN";
	}
	fout << m_cName << '\t' << outType << '\t' << m_Date << '\t' << m_Person << '\t' << m_Category << '\t' << m_EventName << endl;
	if (fout) { return 1; }
	else { return 0; }
}


// �������̸��� �������� �л� ������ ���ϴ� �Լ�
RelationType ItemType::CompareByName(const ItemType& data) {
	if (this->GetName() == data.GetName()) {
		return EQUAL;
	}
	else if (this->m_cName < data.GetName()) {
		return LESS;
	}
	else {
		return GREATER;
	}
}