/**
* @file Main.cpp
* @description programi calistirmak icin Main
* @course 1. Öğretim C Grubu
* @assignment 2. Ödev
* @date 7.11.19
* @author TEK KİŞİYİM. Kutay Yaman Mail: yamankutay1@gmail.com , kutay.yaman@ogr.sakarya.edu.tr
*/
#include "okumaIslemleri.hpp"

int main()
{
	setlocale(LC_ALL, "Turkish"); //ise yaramadi.
	OkumaIslemleri* islem = new OkumaIslemleri("icerik.txt");
	islem->dosyayiOku();
	delete islem;
	cin.get();

}