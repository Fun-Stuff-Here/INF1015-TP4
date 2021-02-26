/*
* Définition de la Classe Acteur, TD4-INF1015
*\file		Acteur.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once

#include<memory>
#include <string>
#include <iostream>
//#include "Bibliotheque.hpp"

#ifndef ACTEUR_H
#define ACTEUR_H


class Acteur{
public:
	Acteur() = default;
	Acteur(const std::string& nom, const int anneeNaissance, const char sexe);
	std::string getNom() { return nom_; }
	static std::shared_ptr<Acteur> lire(std::istream& fichier);
	//TODO afficher acteur 

private:
	std::string nom_ = "";
	int anneeNaissance_ =0;
	char sexe_ =' ';

};





#endif 


