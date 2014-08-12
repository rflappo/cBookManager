#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include "cBook.h"
#include "cBookManager.h"
using namespace std;

bool SortEditorial(cBook A, cBook B){
	return (A.GetEditorial() < B.GetEditorial());
}
bool SortAuthor(cBook A, cBook B){
	return (A.GetAuthor() < B.GetAuthor());
}
bool SortTitle(cBook A, cBook B){
	return (A.GetTitle() < B.GetTitle());
}
bool SortPrice(cBook A, cBook B){
	return (A.GetPrice() < B.GetPrice());
}
bool SortStock(cBook A, cBook B){
	return (A.GetStock() < B.GetStock());
}
bool SortCategory(cBook A, cBook B){
	return (A.GetCategory() < B.GetCategory());
}

cBookManager::cBookManager(){
	_anyChange = false;
	_searchFlag = false;
	EmptyData();
}

cBookManager::cBookManager(string openDBFile){
	_anyChange = false;
	_searchFlag = false;
	OpenDB(openDBFile);
}

void cBookManager::SetLastUpdate(){
	time_t rawtime;
	struct tm * timeinfo;	
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );	
	string aux(asctime(timeinfo));
	if(!_lastUpdate.empty())
		_lastUpdate.clear();
	_lastUpdate = aux;
	transform(_lastUpdate.begin(),_lastUpdate.end(), _lastUpdate.begin(), ::tolower);
}
string cBookManager::GetLastUpdate(){
	return _lastUpdate;
}
int cBookManager::OpenDB(string openDBFile){
	sBook _tmpBook;
	char _tmplastUpdate[32];
	_filePath = openDBFile;
	ifstream _tmpInFile((_filePath.c_str()), ios::binary);
	if(!_tmpInFile.is_open()) return 0;
	LoadCategories();
	_tmpInFile.seekg(0, ios::end);
	if(_tmpInFile.tellg()==0) return 0;	
	int _numberOfRecords = ((int) _tmpInFile.tellg()) - sizeof(_tmplastUpdate);
	_numberOfRecords = (_numberOfRecords / sizeof(sBook));
	_tmpInFile.seekg(0, ios::beg);
	_tmpInFile.read((char *)&_tmplastUpdate, sizeof(_tmplastUpdate));
	_lastUpdate.clear();
	_lastUpdate = _tmplastUpdate;	
	for(int i=0;i<_numberOfRecords;i++){
		_tmpInFile.read((char *)&_tmpBook, sizeof(sBook));
		AddBook(_tmpBook);
	}
	_anyChange = false;
	_tmpInFile.close();
	return _numberOfRecords;
}

bool cBookManager::SaveDB(){
	if(_filePath.empty()) return false;
	_anyChange = false;
	char _tmplastUpdate[32];
	sBook tmpSBook;
	cBook *tmpCBook;
	SetLastUpdate();	
	ofstream tmpOutFile((_filePath.c_str()), ios::binary);	
	strcpy(_tmplastUpdate, _lastUpdate.c_str());
	tmpOutFile.write((char*)&_tmplastUpdate, sizeof(_tmplastUpdate));
	for (int i=0;i<((int)_library.size());i++){
		GetBook(i,&tmpCBook);
		tmpCBook->GetSBook(tmpSBook);
		delete tmpCBook;
		tmpOutFile.write((char*)&tmpSBook, sizeof(tmpSBook));
	}	
	tmpOutFile.close();
	return true;
}

int cBookManager::AddBook(sBook tmpSBook){
	_anyChange = true;
	cBook tmpCBook(tmpSBook);	
	_library.push_back(tmpCBook);
	_searchFlag = false;
	return ((int)_library.size());
}
int cBookManager::AddBook(cBook tmpCBook){
	_anyChange = true;
	_library.push_back(tmpCBook);
	_searchFlag = false;
	return((int)_library.size());
}
int cBookManager::RemoveBook(int i){
	if(i<0) return -1;
	_anyChange = true;
	if(!_searchFlag){
		_library.erase(_library.begin()+i);
	} else {
		_library.erase(_library.begin()+_searchResults[i]);
		_searchResults.erase(_searchResults.begin() + i);
	}
	return ((int)_library.size());
}

int cBookManager::ReplaceBook(int i, sBook tmpSBook){	
	if(i<0) return -1;
	_anyChange = true;
	cBook tmpCBook(tmpSBook);
	if(!_searchFlag){
		_library.insert(_library.begin()+i, tmpCBook);
		_library.erase(_library.begin()+i+1);
	} else {
		_library.insert(_library.begin()+_searchResults[i], tmpCBook);
		_library.erase(_library.begin()+_searchResults[i]+1);
	}
	return((int)_library.size());
}

int cBookManager::ReplaceBook(int i, cBook tmpCBook){
	if(i<0) return -1;
	_anyChange = true;
	if(!GetSearchStatusMode()){
		_library.insert(_library.begin()+i, tmpCBook);
		_library.erase(_library.begin()+i+1);
	} else {
		_library.insert(_library.begin()+_searchResults[i], tmpCBook);
		_library.erase(_library.begin()+(_searchResults[i]+1));
	}
	return((int)_library.size());
}

bool cBookManager::ChangeSearchStatusMode(){
	_searchFlag = !_searchFlag;
	return _searchFlag;
}
void cBookManager::EmptyData(){
	_filePath.empty();
	_library.erase(_library.begin(), _library.end());
	_searchResults.erase(_searchResults.begin(), _searchResults.end());	
}
void cBookManager::GetBook(int i, cBook** tmpCBook){
	if(!_searchFlag){
		*tmpCBook = new cBook(_library[i]);	
	} else {
		*tmpCBook = new cBook(_library[_searchResults[i]]);
	} 		
}
bool cBookManager::SaveDB(string saveDBFile){
	_filePath = saveDBFile;
	return SaveDB();
}
int cBookManager::GetSize(){
	if(!_searchFlag){
		return _library.size();
	} else {
		return _searchResults.size();
	}
}
void cBookManager::Sort(SortOps X){
	switch(X) {
		case SORT_BY_EDITORIAL: 
			sort(_library.begin(), _library.end(), SortEditorial);
			break;		
		case SORT_BY_AUTHOR:
			sort(_library.begin(), _library.end(), SortAuthor);
			break;
		case SORT_BY_TITLE:
			sort(_library.begin(), _library.end(), SortTitle);
			break;
		case SORT_BY_PRICE:
			sort(_library.begin(), _library.end(), SortPrice);
		case SORT_BY_STOCK:
			sort(_library.begin(), _library.end(), SortStock);
		case SORT_BY_CATEGORY:
			sort(_library.begin(), _library.end(), SortCategory);
		default:
			return;
	}	
}
bool cBookManager::GetSearchStatusMode(){
	return _searchFlag;
}
int cBookManager::Search(string criteria, SearchOps X){
	_searchResults.clear();
	string aux;
	string::size_type _fpos;
	for(int i=0;i<(int)_library.size();i++){		
		aux.clear();
		switch (X){
			case SEARCH_BY_EDITORIAL:
				aux = _library[i].GetEditorial();							
				break;
			case SEARCH_BY_AUTHOR:
				aux = _library[i].GetAuthor();
				break;
			case SEARCH_BY_TITLE:
				aux = _library[i].GetTitle();
				break;
			case SEARCH_BY_ISBN:
				aux = _library[i].GetISBN();
			default:				
				break;
		}
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		_fpos = aux.find(criteria, 0);
		if(_fpos != string::npos) _searchResults.push_back(i);
	}
	if((int) _searchResults.size() == 0){
		_searchFlag = false;
		return 0;
	} else {
		_searchFlag = true;
		return ((int)_searchResults.size());
	}
}
void cBookManager::LogIt(string toLog){
	SetLastUpdate();	
	string appStr = "[" + GetLastUpdate() + "] -> " + toLog;
	size_t pos = appStr.find('\n',0);
	appStr.erase(pos, 1);
	appStr.append("\n");
	ofstream outLogFile("wxRamLexBSM.log.txt", ios::app);
	outLogFile << appStr.c_str();
	outLogFile.close();
}
bool cBookManager::IsFilePathEmpty(){
	if(_filePath.size() == 0)
		return true;
	else
		return false;
}
bool cBookManager::IsAnyChange(){
	return _anyChange;
}
string cBookManager::GetFilePath(){
	return _filePath;
}
int cBookManager::LoadCategories(){
	if(!CheckIntegrityCategoryFile()) { return -1; }
	ifstream _categoriesFile("wxRamLexCategories.dat");
	if(_categoriesFile.is_open()){
		_categories.clear();
		char tmpCategory[100];
		string tmpStr;
		string tmpInt;
		sCategory sTmpCategory;
		while(_categoriesFile.getline(tmpCategory,100)){
			tmpStr = tmpCategory;
			size_t _pos;
			_pos = tmpStr.find('-');
			tmpInt = tmpStr.substr(1,_pos-2);
			tmpStr.erase(tmpStr.begin(), tmpStr.begin()+_pos+1);
			sTmpCategory._idCategory = atoi(tmpInt.c_str());
			sTmpCategory._nameCategory = tmpStr;
			_categories.push_back(sTmpCategory);			
		}
		return _categories.size();
	} else {
		return -1;
	}
}
void cBookManager::GetCategory(int id, sCategory& tmpCategory){
	if(id < 0) return;
	tmpCategory = _categories[id];
}
bool cBookManager::CheckIntegrityCategoryFile(){
	ifstream *_file = new ifstream("wxRamLexCategories.dat");
	if(!_file->is_open()) return false;
	char tmpCategory[100];
	string tmpStr;	
	while(_file->getline(tmpCategory,100)){
		tmpStr = tmpCategory;
		if((tmpStr.find('[') == string::npos) || (tmpStr.find(']') == string::npos) || (tmpStr.find('-') == string::npos))
			return false;
	}
	_file->close();
	delete _file;
	return true;
}
int cBookManager::SetStockOnSellcBook(int _opsIdStock, int _objDBid){
	_anyChange = true;
	if(_searchFlag){
		if(_opsIdStock == 1){
			_library[(_searchResults[_objDBid])].SetStock((_library[_searchResults[_objDBid]].GetStock())+1);			
		}
		if(_opsIdStock == -1){
			_library[(_searchResults[_objDBid])].SetStock((_library[_searchResults[_objDBid]].GetStock())-1);			
		}
		return _library[_searchResults[_objDBid]].GetStock();
	} else {
		if(_opsIdStock == 1){
			_library[_objDBid].SetStock(_library[_objDBid].GetStock()+1);
			
		}
		if(_opsIdStock == -1){
			_library[_objDBid].SetStock(_library[_objDBid].GetStock()-1);			
		}
		return _library[_objDBid].GetStock();		
	}
	return -1;
}
ValidationTexts cBookManager::ValidateBookData(cBook tmpCBook){
	string MytmpString; int MytmpSize=0;
	ValidationTexts StringsOnError;
	
	MytmpString = tmpCBook.GetAuthor();
	MytmpSize = MytmpString.size();
	if((MytmpSize <= 0) || (MytmpSize > 128)){
		StringsOnError._erroronauthor = "Campo <Autor> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	MytmpString = tmpCBook.GetEditorial();
	MytmpSize = MytmpString.size();
	if((MytmpSize <= 0) || (MytmpSize > 128)){
		StringsOnError._erroronauthor = "Campo <Editorial> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	MytmpString = tmpCBook.GetTitle();
	MytmpSize = MytmpString.size();
	if((MytmpSize <= 0) || (MytmpSize > 128)){
		StringsOnError._erroronauthor = "Campo <Titulo> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	
	if(tmpCBook.GetPages() <= 0){
		StringsOnError._erroronpages = "Campo <Paginas> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	if(tmpCBook.GetPrice() <= 0.0 ){
		StringsOnError._erroronprice = "Campo <Precio> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	if(tmpCBook.GetStock() < 0 ){
		StringsOnError._erroronstock = "Campo <Stock> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;
	}
	
	if(tmpCBook.GetWeight() <= 0.0){
		StringsOnError._erroronweight = "Campo <Peso> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;
	}
	
	return StringsOnError;
}
ValidationTexts cBookManager::ValidateBookData(cBook *tmpCBook){
	string MytmpString; int MytmpSize=0;
	ValidationTexts StringsOnError;
	
	MytmpString = tmpCBook->GetAuthor();
	MytmpSize = MytmpString.size();
	if((MytmpSize == 0) || (MytmpSize > 128)){
		StringsOnError._erroronauthor = "Campo <Autor> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	MytmpString = tmpCBook->GetEditorial();
	MytmpSize = MytmpString.size();
	if((MytmpSize <= 0) || (MytmpSize > 128)){
		StringsOnError._erroronauthor = "Campo <Editorial> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	MytmpString = tmpCBook->GetTitle();
	MytmpSize = MytmpString.size();
	if((MytmpSize <= 0) || (MytmpSize > 128)){
		StringsOnError._erroronauthor = "Campo <Titulo> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	
	if(tmpCBook->GetPages() <= 0){
		StringsOnError._erroronpages = "Campo <Paginas> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	if(tmpCBook->GetPrice() <= 0.0 ){
		StringsOnError._erroronprice = "Campo <Precio> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;}
	
	if(tmpCBook->GetStock() < 0 ){
		StringsOnError._erroronstock = "Campo <Stock> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;
	}
	
	if(tmpCBook->GetWeight() <= 0.0){
		StringsOnError._erroronweight = "Campo <Peso> Vacio o fuera de rango";
		StringsOnError.isanyerror = true;
	}
	
	return StringsOnError;	
}
string cBookManager::EraseISBN(int i){
	if(_searchFlag){
		return _library[_searchResults[i]].EraseIsbn();
	} else {
		return _library[i].EraseIsbn();	
	}
}

bool cBookManager::ValidateIsbn(cBook* tmpCBook){
	bool IsbnOk=true;
	bool auxStatus = _searchFlag;
	string MytmpString = tmpCBook->GetISBN();
	int MytmpSize = MytmpString.size();
	if((MytmpSize != 13) || (Search(MytmpString, SEARCH_BY_ISBN) > 0 )){
		IsbnOk = false;
	}
	if(_searchFlag!=auxStatus)
		_searchFlag = auxStatus;
	return IsbnOk;
}

bool cBookManager::ValidateIsbn(cBook tmpCBook){
	bool IsbnOk=true;
	bool auxStatus = _searchFlag;
	string MytmpString = tmpCBook.GetISBN();
	int MytmpSize = MytmpString.size();
	if((MytmpSize != 13) || (Search(MytmpString,SEARCH_BY_ISBN))){
		IsbnOk = false;
	}
	if(_searchFlag!=auxStatus)
		_searchFlag = auxStatus;
	return IsbnOk;
}

cBookManager* myManager;
SearchOps searchOpSetted;
