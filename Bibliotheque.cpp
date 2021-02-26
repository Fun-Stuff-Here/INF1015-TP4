/*
* Implémentation de la Classe Bibliotheque, TD4-INF1015
*\file		Bibliotheque.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#include "Bibliotheque.hpp"

using namespace std;
using namespace gsl;
using namespace iter;


UInt8 Bibliotheque::lireUint8(istream& fichier)
	{
		UInt8 valeur = 0;
		fichier.read((char*)&valeur, sizeof(valeur));
		return valeur;
	}

 UInt16 Bibliotheque::lireUint16(std::istream& fichier)
	{
		UInt16 valeur = 0;
		fichier.read((char*)&valeur, sizeof(valeur));
		return valeur;
	}

string Bibliotheque::lireString(std::istream& fichier)
	{
		std::string texte;
		texte.resize(lireUint16(fichier));
		fichier.read((char*)&texte[0], std::streamsize(sizeof(texte[0])) * texte.length());
		return texte;
	}


void Bibliotheque::ajouterFilms(const std::string& nomFichier)
{

	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);

	int nFilms = lireUint16(fichier);

	for (int i : iter::range(nFilms))
	{
		unique_ptr<Film> film = Film::lire(fichier);
		items_.push_back(move(film));
	}
}



void Bibliotheque::ajouterLivres(const std::string& nomFichier)
{
	ifstream fichier(nomFichier, ios::binary);
	fichier.exceptions(ios::failbit);
	

	string titre = "";
	int annee = 0;
	string auteur = "";
	int nMillionsCopiesVendues = 0;
	int nPage = 0;

	string nextthing = "";

	fichier >> titre;
	fichier >> annee;
	fichier >> auteur;
	fichier >> nMillionsCopiesVendues;
	fichier >> nPage;
	cout << titre << endl;
	cout << annee << endl;
	cout << auteur << endl;
	cout << nMillionsCopiesVendues << endl;
	cout << nPage << endl;

	fichier >> nextthing;
	cout << nextthing << endl;

}


shared_ptr<Acteur> Bibliotheque::trouverActeur(const string& nom) const
{
	shared_ptr<Acteur> acteur = nullptr;

	for(auto&& item : items_)
	{
		if(auto film = dynamic_cast<Film*>(item.get()))
		{
			acteur = film->trouverActeur(nom);
			if (acteur)
				break;
		}
	}
	return acteur;
}
