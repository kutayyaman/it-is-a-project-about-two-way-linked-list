/**
* @file LinkedList.cpp
* @description odevde kullanılması istenen iki yonlu bagli liste icin LinkedList classi gerceklemesi.
* @course 1. Öğretim C Grubu
* @assignment 2. Ödev
* @date 7.11.19
* @author TEK KİŞİYİM. Kutay Yaman Mail: yamankutay1@gmail.com , kutay.yaman@ogr.sakarya.edu.tr
*/
#include "LinkedList.hpp"

LinkedList::LinkedList()
{
	size=0;
	ilkDugum=NULL;
}
Iterator* LinkedList::OncekiniKonumuIleBul(int konum)const
{
	if(konum==0) //1. eleman 0. indexte 
	{
		cout<<"zaten ilk konumu istediniz bundan öncesi yok"<<endl;
		return NULL;
	}
	int index=0;
	Iterator* iterator =new Iterator(ilkDugum);
	while(iterator->hasNext() && index!=konum-1)
	{
		iterator->next();
		index++;
	}
	return iterator;
}
bool LinkedList::bosMu()const
{
	return size==0;
}
int LinkedList::Miktar()const
{
	return size;
}
string LinkedList::ilkEleman()const
{
	return ilkDugum->getEleman();
}
string LinkedList::sonEleman()const
{
	Iterator* iterator=OncekiniKonumuIleBul(size);
	string eleman=iterator->getCurrent();
	delete iterator;
	return eleman;
}
void LinkedList::add(const string& eleman,const string& aynisiBuKadarSolda)
{
	if(size==0)
	{
		ilkDugum=new Dugum();
		ilkDugum->setEleman(eleman);
		ilkDugum->setAynisiBuKadarSolda(aynisiBuKadarSolda);
	}
	else
	{
	Iterator* iterator=OncekiniKonumuIleBul(size);
	Dugum* yeniDugum=new Dugum(eleman,aynisiBuKadarSolda,NULL,iterator->getGosterilenDugum());
	iterator->getGosterilenDugum()->setIleri(yeniDugum);
	delete iterator;
	}
	size++;
}
void LinkedList::insert(int konum,const string& eleman,const string& aynisiBuKadarSolda)
{
	if(konum==0 && size==0)
	{
		ilkDugum=new Dugum();
		ilkDugum->setEleman(eleman);
		ilkDugum->setAynisiBuKadarSolda(aynisiBuKadarSolda);
	}
	else if(konum==0)
	{
		Dugum* yeniDugum=new Dugum(eleman,aynisiBuKadarSolda,ilkDugum,NULL);
		ilkDugum->setGeri(yeniDugum);
		this->ilkDugum=yeniDugum;
	}
	else
	{
	Iterator* iterator=OncekiniKonumuIleBul(konum);
	Dugum* yeniDugum=new Dugum(eleman,aynisiBuKadarSolda,iterator->getGosterilenDugum()->getIleri(),iterator->getGosterilenDugum());
	iterator->getGosterilenDugum()->setIleri(yeniDugum);
	delete iterator;
	}
	size++;
}
void LinkedList::remove(const string& eleman)
{
	if(size==0)
	{
		cout<<"Listede Eleman Yok"<<endl;
		return;
	}
	if(ilkDugum->getEleman()==eleman && size==1)
	{
		delete ilkDugum;
		ilkDugum==NULL;
		size--;
		return;
	}
	if(ilkDugum->getEleman()==eleman)
	{
		Dugum* temp=ilkDugum->getIleri();
		temp->setGeri(ilkDugum->getGeri());
		delete ilkDugum;
		ilkDugum=temp;
		size--;
		return;
	}
	Iterator* iterator=new Iterator(ilkDugum);
	while(iterator->hasNext() && iterator->getGosterilenDugum()->getIleri()->getEleman()!=eleman)
	{
		iterator->next();
	}
	Dugum* temp=iterator->getGosterilenDugum()->getIleri();
	iterator->getGosterilenDugum()->setIleri(temp->getIleri());
	if(temp->getIleri()!=NULL)
		temp->getIleri()->setGeri(iterator->getGosterilenDugum());
	delete temp;
	delete iterator;
	size--;
	return;
	
}
void LinkedList::removeAt(int konum)
{
	if(size==0)
	{
		cout<<"Listede Eleman Yok"<<endl;
		return;
	}
	if(konum==0 && size==1)
	{
		delete ilkDugum;
		ilkDugum=NULL;
		size--;
		return;
	}
	if(konum==0)
	{
		Dugum* temp=ilkDugum;
		ilkDugum=ilkDugum->getIleri();
		ilkDugum->setGeri(NULL);
		delete temp;
		size--;
		return;
	}
	Iterator* iterator=OncekiniKonumuIleBul(konum);
	Dugum* temp=iterator->getGosterilenDugum()->getIleri();
	iterator->getGosterilenDugum()->setIleri(temp->getIleri());
	if(temp->getIleri()!=NULL)
	temp->getIleri()->setGeri(iterator->getGosterilenDugum());
	delete temp;
	delete iterator;
	size--;
}
bool LinkedList::find(const string& eleman)const
{
		Iterator* iterator=new Iterator(ilkDugum);

		while(iterator->hasNext())
		{
			if(iterator->getCurrent()==eleman)
			{
				delete iterator;
				return true;
			}
			iterator->next();
		}
		delete iterator;
		return false;
}
int LinkedList::indexOf(const string& eleman)const
{
	int index=0;
	Iterator* iterator=new Iterator(ilkDugum);
	while(iterator->hasNext())
	{
		if(iterator->getCurrent()==eleman)
		{
			delete iterator;
			return index;
		}
		iterator->next();
		index++;
	}
	cout<<"ARANAN ELEMAN BULUNAMADI"<<endl;
	delete iterator;
	return -1;
}
void LinkedList::clear()
{
	while(bosMu()==false)
	{
		removeAt(0);
	}
}
LinkedList::~LinkedList()
{
	LinkedList::clear();
}
ostream& operator<<(ostream& ekran,LinkedList& liste)
{
	Dugum* temp=liste.ilkDugum;
	while(temp!=NULL)
	{
		if(temp->getGeri()==NULL)
			ekran<<"NULL<-";
		else
			ekran<<"<->";
		ekran<<":"<<temp->getEleman()<<" - "<<temp->getAynisiBuKadarSolda()<<":";
		if(temp->getIleri()==NULL)
			ekran<<"->NULL";
		temp=temp->getIleri();
	}
	ekran<<endl;
	return ekran;
}
