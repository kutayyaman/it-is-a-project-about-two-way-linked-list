#ifndef OKUMAISLEMLERI_HPP
#define OKUMAISLEMLERI_HPP

#include<iostream>
#include<string>
#include<fstream>
#include "LinkedList.hpp"
using namespace std;

class OkumaIslemleri
{
	private:
	string okunacakDosyaYolu;
	LinkedList* liste;
	int yerKazanci;
	
	public:
	OkumaIslemleri(string);
	LinkedList* getListe()const;
	void dosyayiOku();
	int getYerKazanci();
	~OkumaIslemleri();
	
};



#endif