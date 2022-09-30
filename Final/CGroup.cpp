#include "pch.h"
#include "CGroup.h"


// 그룹명을 설정
void Group::SetTitle(QString name) {
	m_cName = name;
}


// 그룹 설명을 설정
void Group::SetDescription(QString des) {
	m_cDes = des;
}


// 그룹 이름을 반환
QString Group::GetTitle() const {
	return m_cName;
}


// 그룹 설명을 반환
QString Group::GetDescription() const {
	return m_cDes;
}

int Group::GetLenght() const {
	return m_cLen;
}

// 그룹 리스트가 비었는지 확인
bool Group::isEmpty() {
	if (m_cLen == 0) {
		return true;
	}
	return false;
}