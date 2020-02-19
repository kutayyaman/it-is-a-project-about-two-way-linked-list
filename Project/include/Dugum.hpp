#ifndef LinkedList_HPP
#define LinkedList_HPP

#include<iostream>
#include<string>
#include<clocale> //ise yaramadi
using namespace std;

class Dugum{
	private:
		string eleman;
		string aynisiBuKadarSolda;
		Dugum* ileri;
		Dugum* geri;
	public:
		Dugum(const string& eleman = "", const string& aynisiBuKadarSolda = "0", Dugum* ileri = NULL, Dugum* geri = NULL) :
		eleman(eleman), aynisiBuKadarSolda(aynisiBuKadarSolda), ileri(ileri), geri(geri)
		{
		}
		string getEleman()const;
		void   setEleman(const string&); //kullanmaya gerek kalmazsa en son sil
		string getAynisiBuKadarSolda();
		void setAynisiBuKadarSolda(const string&);
		Dugum* getIleri()const;
		void   setIleri(Dugum*);
		Dugum* getGeri()const;
		void   setGeri(Dugum*);
	
	
};


#endif