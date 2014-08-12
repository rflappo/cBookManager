#include <cstring>
#include <string>
#include "cBook.h"

using namespace std;

cBook::cBook(){
	string tmpStr;
	tmpStr.clear();
	strcpy(_tmpSBook._editorial, tmpStr.c_str());
	strcpy(_tmpSBook._author, tmpStr.c_str());
	strcpy(_tmpSBook._title, tmpStr.c_str());
	strcpy(_tmpSBook._isbn, tmpStr.c_str());
	_tmpSBook._price = 0.0;
	_tmpSBook._stock = 0;
	_tmpSBook._idCategory = -1;
	_tmpSBook._pages = 0;
	_tmpSBook._weight = 0.0;
	
}
cBook::cBook(sBook sB){
	_tmpSBook = sB;
}
void cBook::GetSBook(sBook& sB){
	sB = _tmpSBook;
}
void cBook::SetSBook(sBook sB){
	_tmpSBook = sB;
}
int cBook::operator++(int){
	_tmpSBook._stock += 1;
	return _tmpSBook._stock;
}
int cBook::operator--(int){	
	_tmpSBook._stock -= 1;
	return _tmpSBook._stock;
}
string cBook::GetEditorial(){
	return (string)_tmpSBook._editorial;
}
string cBook::GetAuthor(){
	return (string)_tmpSBook._author;
}
string cBook::GetTitle(){
	return (string)_tmpSBook._title;
}
string cBook::GetISBN(){
	return (string)_tmpSBook._isbn;
}
float cBook::GetPrice(){
	return _tmpSBook._price;
}
int cBook::GetStock(){
	return _tmpSBook._stock;
}
int cBook::GetCategory(){
	return _tmpSBook._idCategory;
}
int cBook::GetPages(){
	return _tmpSBook._pages;
}
float cBook::GetWeight(){
	return _tmpSBook._weight;
}

void cBook::SetEditorial(string x){
	strcpy(_tmpSBook._editorial,x.c_str());
}
void cBook::SetAuthor(string x){
	strcpy(_tmpSBook._author,x.c_str());
}
void cBook::SetTitle(string x){
	strcpy(_tmpSBook._title,x.c_str());
}
void cBook::SetISBN(string x){
	strcpy(_tmpSBook._isbn,x.c_str());
}
void cBook::SetPrice(float x){
	_tmpSBook._price = x;
}
void cBook::SetStock(int x){
	_tmpSBook._stock = x;
}
void cBook::SetCategory(int x){
	_tmpSBook._idCategory = x;
}
void cBook::SetPages(int x){
	_tmpSBook._pages = x;
}
void cBook::SetWeight(float x){
	_tmpSBook._weight = x;
}

string cBook::EraseIsbn(){
	string isbnaux = _tmpSBook._isbn;
	strcpy(_tmpSBook._isbn,"");
	return (isbnaux);
}

