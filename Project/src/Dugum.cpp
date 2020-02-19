/**
* @file Dugum.cpp
* @description iki yonlu bagli liste icin Dugum classini olusturuyorum icinde veri olarak dosyadan okunacak olana elaman ve okunan elemanin aynisindan varsa onun ne kadar solunda oldugnu tutan aynisiBuKadarSolda degiskeni var. 
* @course 1. Öğretim C Grubu
* @assignment 2. Ödev
* @date 7.11.19
* @author TEK KİŞİYİM. Kutay Yaman Mail: yamankutay1@gmail.com , kutay.yaman@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

string Dugum::getEleman()const
{
	return this->eleman;
}
void Dugum::setEleman(const string& eleman)
{
	this->eleman=eleman;
}
string Dugum::getAynisiBuKadarSolda()
{
	return aynisiBuKadarSolda;
}
void Dugum::setAynisiBuKadarSolda(const string& aynisiBuKadarSolda)
{
	this->aynisiBuKadarSolda=aynisiBuKadarSolda;
}
Dugum* Dugum::getIleri()const
{
	return ileri;
}
void Dugum::setIleri(Dugum* ileri)
{
	this->ileri=ileri;
}
Dugum* Dugum::getGeri()const
{
	return geri;
}
void Dugum::setGeri(Dugum* geri)
{
	this->geri=geri;
}