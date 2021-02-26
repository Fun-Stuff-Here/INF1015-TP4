/*
* Définition de la Classe Livre, TD4-INF1015
*\file		Livre.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once

//#include "Bibliotheque.hpp"
#include <string>

#include "Item.hpp"


#ifndef LIVRE_H
#define LIVRE_H

class Livre : public Item
{
public:
	Livre() = default;
	Livre(const std::string& auteur, int nMillionsCopiesVendues, int nPages, std::string& titre, int annee) :
		Item(titre, annee),
		auteur_(auteur),
		nMillionsCopiesVendues_(nMillionsCopiesVendues),
		nPages_(nPages)
	{}


protected:

private:
	std::string auteur_ = "";
	int nMillionsCopiesVendues_ = 0;
	int nPages_ = 0;

};



#endif
