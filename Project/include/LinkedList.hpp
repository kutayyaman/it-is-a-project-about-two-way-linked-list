#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Iterator.hpp"

class LinkedList{
	private:
		Dugum* ilkDugum;
		int size;
		
		Iterator* OncekiniKonumuIleBul(int)const;
	public:
		LinkedList();
		bool bosMu()const;
		int	Miktar() const;
		string ilkEleman()const;
		string sonEleman()const;
		void add(const string&,const string&);
		void insert(int,const string&,const string&);
		void remove(const string&);
		void removeAt(int);
		bool find(const string&)const;
		int indexOf(const string&)const;
		friend ostream& operator<<(ostream&,LinkedList&);
		void clear();
		~LinkedList();
		
};


#endif