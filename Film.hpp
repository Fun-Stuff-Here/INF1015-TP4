/*
* Définition de la Classe Film, TD4-INF1015
*\file		Film.hpp
*\author	Elizabeth Michaud 2073093, Nicolas Dépelteau 2083544
*\date		21 mars 2021
* Créé le	26 février 2021
*/
#pragma once


#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Item.hpp"
#include "Acteur.hpp"


#ifndef FILM_H
#define FILM_H

class Film : public Item {
public:
	Film() = default;
	Film(const std::string& titre, int annee, std::string& realisateur, int recette, std::vector<std::shared_ptr<Acteur>>&& acteurs);

	static std::unique_ptr<Film> lire(std::istream& fichier);

	std::shared_ptr<Acteur> trouverActeur(const std::string& nomRechercher) const;

protected:

private:
	std::string realisateur_ = "";
	int recette_;
	std::vector<std::shared_ptr<Acteur>> acteurs_;
};


#endif 

