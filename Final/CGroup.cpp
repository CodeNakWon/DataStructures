#include "pch.h"
#include "CGroup.h"


// �׷���� ����
void Group::SetTitle(QString name) {
	m_cName = name;
}


// �׷� ������ ����
void Group::SetDescription(QString des) {
	m_cDes = des;
}


// �׷� �̸��� ��ȯ
QString Group::GetTitle() const {
	return m_cName;
}


// �׷� ������ ��ȯ
QString Group::GetDescription() const {
	return m_cDes;
}

int Group::GetLenght() const {
	return m_cLen;
}

// �׷� ����Ʈ�� ������� Ȯ��
bool Group::isEmpty() {
	if (m_cLen == 0) {
		return true;
	}
	return false;
}