/*
* Implémentation de la Classe Film, TD4-INF1015
*\file		Film.cpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		7 mars 2021
* Créé le	26 février 2021
*/
#include "Film.hpp"

using namespace std;
using namespace gsl;
using namespace iter;



Film::Film(const std::string& titre, int annee, std::string& realisateur,
	int recette, std::vector<std::shared_ptr<Acteur>>&& acteurs)
	:Item(titre, annee),
	realisateur_(realisateur),
	recette_(recette)
{
	acteurs_ = acteurs;
}

std::unique_ptr<Film> Film::lire(istream& fichier)
{
	string titre = Bibliotheque::lireString(fichier);
	string realisateur = Bibliotheque::lireString(fichier);
	int anneeSortie = Bibliotheque::lireUint16(fichier);
	int recette = Bibliotheque::lireUint16(fichier);
	int nActeurs = Bibliotheque::lireUint8(fichier);
	//Allocation de la liste d'acteur
	std::vector<std::shared_ptr<Acteur>> acteurs;

	for (int i : iter::range(nActeurs))
	{
		acteurs.push_back(Acteur::lire(fichier));
	}
	return make_unique<Film>(titre, anneeSortie, realisateur, recette,
		(std::vector<std::shared_ptr<Acteur>>&&)acteurs);

}


shared_ptr<Acteur> Film::trouverActeur(const string& nomRechercher) const
{
	for (auto&& acteur : acteurs_)
	{
		if (acteur->getNom() == nomRechercher)
			return acteur;
	}
	return nullptr;
}
