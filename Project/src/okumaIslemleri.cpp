/**
* @file okumaIslemleri.cpp
* @description dosyadan okuma islemleri yapip gerekli islemleri uygulamak icin OkumaIslemleri classi gerceklemesi.
* @course 1. Öğretim C Grubu
* @assignment 2. Ödev
* @date 7.11.19
* @author TEK KİŞİYİM. Kutay Yaman Mail: yamankutay1@gmail.com , kutay.yaman@ogr.sakarya.edu.tr
*/
#include "okumaIslemleri.hpp"
#include <sstream>

OkumaIslemleri::OkumaIslemleri(string dosyaYolu)
{
	okunacakDosyaYolu=dosyaYolu;
	yerKazanci=0;
}
LinkedList* OkumaIslemleri::getListe()const
{
	return liste;
}
void OkumaIslemleri::dosyayiOku()
{
	liste=new LinkedList();
	fstream dosya;
	dosya.open(okunacakDosyaYolu,ios::in);
	if(dosya.is_open())
	{
		string eleman;
		while(dosya>>eleman)
		{
			if(!liste->find(eleman))
			{
				liste->add(eleman,"0");
			}
			else
			{
				int indexOf=liste->indexOf(eleman);
				int size=liste->Miktar();
				int neKadarSolunda=size-indexOf;
				string aynisiBuKadarSolda=to_string(neKadarSolunda);
				liste->add("",aynisiBuKadarSolda);
				yerKazanci+=eleman.length()-aynisiBuKadarSolda.length();
			}
		}
	}
	dosya.close();
	cout<<*liste;
	cout << "Toplam Kazanc : " << yerKazanci << " Byte" << endl;
}
int OkumaIslemleri::getYerKazanci()
{
	return yerKazanci;
}
OkumaIslemleri::~OkumaIslemleri()
{
	delete liste;
}