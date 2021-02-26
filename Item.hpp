/*
* Définition de la Classe Item, TD4-INF1015
*\file		Item.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once

#include "Bibliotheque.hpp"

#ifndef ITEM_H
#define ITEM_H

class Item
{
public:
	Item(const std::string& titre, int annee) : titre_(titre), annee_(annee) {}
	virtual void feee(void);
protected:

private:
	std::string titre_;
	int annee_;
};






#endif 
