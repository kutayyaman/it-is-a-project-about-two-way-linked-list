#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Dugum.hpp"

class Iterator{
	private:
		Dugum* gosterilenDugum;
	public:
		Iterator():gosterilenDugum(NULL)
		{}
		Iterator(Dugum* gosterilenDugum):gosterilenDugum(gosterilenDugum)
		{}
		Dugum* getGosterilenDugum()const;
		void setGosterilenDugum(Dugum*);
		bool hasNext();
		void next();
		string getCurrent()const;
	
};


#endif