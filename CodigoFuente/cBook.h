#ifndef CBOOK_H
#define CBOOK_H

using namespace std;

struct sBook {
	char _editorial[128];
	char _author[128];
	char _title[128];
	char _isbn[24];
	float _price;
	int _stock;
	int _idCategory;
	int _pages;
	float _weight;	
};

class cBook {
private:
	sBook _tmpSBook;	
public:
	cBook();
	cBook(sBook sB);	
	void GetSBook(sBook& sB);
	void SetSBook(sBook sB);	
	int operator++(int);
	int operator--(int);
	
	//Getters.
	string GetEditorial();
	string GetAuthor();
	string GetTitle();
	string GetISBN();
	float GetPrice();
	int GetStock();
	int GetCategory();
	int GetPages();
	float GetWeight();
	
	//Setters.
	void SetEditorial(string);
	void SetAuthor(string);
	void SetTitle(string);
	void SetISBN(string);
	void SetPrice(float);
	void SetStock(int);
	void SetCategory(int);
	void SetPages(int);
	void SetWeight(float);
	
	string EraseIsbn();
};
#endif

