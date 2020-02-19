/**
* @file Iterator.cpp
* @description Dugumleri dolasmak icin Iterator classi gerceklemesi.
* @course 1. Öğretim C Grubu
* @assignment 2. Ödev
* @date 7.11.19
* @author TEK KİŞİYİM. Kutay Yaman Mail: yamankutay1@gmail.com , kutay.yaman@ogr.sakarya.edu.tr
*/
#include "Iterator.hpp"

Dugum* Iterator::getGosterilenDugum()const
{
	return gosterilenDugum;
}
void Iterator::setGosterilenDugum(Dugum* gosterilenDugum)
{
	this->gosterilenDugum=gosterilenDugum;
}
bool Iterator::hasNext()
{
	return gosterilenDugum!=NULL;
}
void Iterator::next()
{
	gosterilenDugum=gosterilenDugum->getIleri();
}
string Iterator::getCurrent()const
{
	return gosterilenDugum->getEleman();
}