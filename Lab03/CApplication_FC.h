#pragma once
class Application_FC {
private:
	List<FavoriteContent> m_FCList;
	SortedList<MultimediaContent> MCList;
	SortedList<string> m_nameOrder;
	int m_CommandFC;
	int m_order = 0; // 0: 들어온 순으로 보여줌, 1: 이름순으로 보여줌, 2: 
public:
	Application_FC() {};
	void Run(SortedList<MultimediaContent>& MCList);
	int GetCommand();
	int Add_FC(SortedList<MultimediaContent>& MCList);
	int Delete_FC();
	void Display_FC_list();
	int Display_Detail_FC(SortedList<MultimediaContent>& MCList);
	int Rearrange_FC();
	int DeleteMContents(MultimediaContent &mc);
};
