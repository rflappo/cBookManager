#ifndef CBOOKMANAGER_H
#define CBOOKMANAGER_H

#include "cBook.h"
#include <fstream>
using namespace std;

struct ValidationTexts{
	string _errorontitle, _erroroneditorial, _erroronauthor, _erroronisbn,	_erroronweight, _erroronprice, _erroronpages, _erroronstock, _erroronidCategory;
	bool isanyerror;
};

struct sCategory {
	int _idCategory;
	string _nameCategory;
};

enum SortOps { SORT_BY_EDITORIAL, SORT_BY_AUTHOR, SORT_BY_TITLE, SORT_BY_PRICE, SORT_BY_STOCK, SORT_BY_CATEGORY };
enum SearchOps { SEARCH_BY_EDITORIAL, SEARCH_BY_AUTHOR, SEARCH_BY_TITLE, SEARCH_BY_ISBN };

class cBookManager {
private:
	vector<cBook> _library;
	vector<int> _searchResults;
	vector<sCategory> _categories;
	string _lastUpdate;
	string _filePath;
	bool _searchFlag;
	bool _anyChange;
	bool CheckIntegrityCategoryFile();
	
public:
	cBookManager();
	cBookManager(string openDBFile);	
	void SetLastUpdate(); //Sets last time modified.
	string GetLastUpdate();	//Gets last time modified.
	int OpenDB(string); //Returns number of records in file.
	int AddBook(sBook); //Returns number of records in _library.
	int AddBook(cBook); //Returns number of records in _library.	
	int RemoveBook(int); //Returns number of records in _library.
	int ReplaceBook(int, sBook); //Returns number of records in _library.
	int ReplaceBook(int, cBook); //Returns number of records in _library.
	bool ChangeSearchStatusMode(); //Returns status of search mode setted; on/off
	void EmptyData(); //Empties vectors.
	void GetBook(int, cBook**); 
	bool SaveDB();
	bool SaveDB(string);
	string EraseISBN(int i);
	int GetSize();
	void Sort(SortOps); //Choose sort option. Check enum(SortOps) above.
	bool GetSearchStatusMode();
	int Search(string, SearchOps); //Choose searh option. Check enum(SearchOps) above.
	void LogIt(string);
	bool IsFilePathEmpty();
	bool IsCBookManagerEmpty();
	bool IsAnyChange();
	string GetFilePath();
	int LoadCategories();
	void GetCategory(int id, sCategory& tmpCategory);
	int SetStockOnSellcBook(int, int);
	ValidationTexts ValidateBookData(cBook);
	ValidationTexts ValidateBookData(cBook *);
	bool ValidateIsbn(cBook *);
	bool ValidateIsbn(cBook );
};
extern cBookManager* myManager;
extern SearchOps searchOpSetted;
#endif
