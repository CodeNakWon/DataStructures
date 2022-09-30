#pragma once

// Base class
class Content
{
protected:
	string title; // ������ Ÿ��Ʋ

public:
	virtual void SetTitle(string str) {
		title = str;
	}
	virtual void play() = 0;
	virtual void Read() = 0;
	
	// ������ �����ε�
	friend ostream& operator << (ostream& out, Content& con)
	{
		con.play();
		return out;
	}
	bool operator< (const Content& mc) const {
		if (title < mc.title) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator> (const Content& mc) const {
		if (title > mc.title) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator== (const Content& mc) const {
		if (title == mc.title) {
			return true;
		}
		else {
			return false;
		}
	}


};


// ���� ������
class Photo : public Content {
private:
	string person; //�ι�
	string location; //���
	string event; // �̺�Ʈ
public:
	void play() override {
		cout << "\t--Photo--" << endl;
		cout << "\tTitle : " << title << endl;
		cout << "\tPerson : " << person << endl;
		cout << "\tLocation : " << location << endl;
		cout << "\tEvent : " << event << endl;
	}

	void Read() override {
		cout << "\tTitle -> ";
		cin >> title;
		cout << "\tPerson -> ";
		cin >> person;
		cout << "\tLocation -> ";
		cin >> location;
		cout << "\tEvent -> ";
		cin >> event;
	}

};

// ������ ������
class Video : public Content {
private:
	string person; // �ι�
	string location; // ���
	string event; // �̺�Ʈ
	string len; // ����ð� ex) "4:30"
public:
	void play() override {
		cout << "\t--Video--" << endl;
		cout << "\tTitle : " << title << endl;
		cout << "\tPerson : " << person << endl;
		cout << "\tLocation : " << location << endl;
		cout << "\tEvent : " << event << endl;
		cout << "\tPlaying time : " << len << endl;
	}
	void Read() override {
		cout << "\tTitle -> ";
		cin >> title;
		cout << "\tPerson -> ";
		cin >> person;
		cout << "\tLocation -> ";
		cin >> location;
		cout << "\tEvent -> ";
		cin >> event;
		cout << "\tplaying time -> ";
		cin >> len;
	}

};

