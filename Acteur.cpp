/*
* Implémentation de la Classe Acteur, TD4-INF1015
*\file		Acteur.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#pragma once

#include "Acteur.hpp"
#include "Bibliotheque.hpp"

using namespace std;
using namespace gsl;
using namespace iter;


Acteur::Acteur(const std::string& nom, const int anneeNaissance, const char sexe)
: nom_(nom),anneeNaissance_(anneeNaissance),sexe_(sexe) {}


std::shared_ptr<Acteur> Acteur::lire(std::istream& fichier)
{
	string nom = Bibliotheque::lireString(fichier);
	int anneeNaissance = Bibliotheque::lireUint16(fichier);
	char sexe = Bibliotheque::lireUint8(fichier);

	shared_ptr<Acteur> acteur = make_shared<Acteur>(nom, anneeNaissance, sexe);

	shared_ptr<Acteur> acteurExistant = Bibliotheque::get().trouverActeur(nom);
	//check si existant
	if (acteurExistant)
	{
		acteur = nullptr;
		return acteurExistant;
	}
	else
	{	//Debug line
		cout << acteur->getNom() << endl;
		return  acteur; 
	}
}