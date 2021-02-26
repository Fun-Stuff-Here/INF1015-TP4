/*
* D�finition de la Classe Bibliotheque, TD4-INF1015
*\file		Acteur.hpp
*\author	Elizabeth Michaud 2073093, Nicolas D�pelteau 2083544
*\date		21 mars 2021
* Cr�� le	26 f�vrier 2021
*/
#pragma once

#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp" // Nos fonctions pour le rapport de fuites de m�moire.
#include "debogage_memoire.hpp"   // Ajout des num�ros de ligne des "new" dans le rapport de fuites.
#include "gsl/span"
#include "cppitertools/range.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <algorithm>
#include <memory>
#include <functional>
#include <iterator>
#include <iomanip>

#include "Acteur.hpp"
#include "Item.hpp"
#include "Film.hpp"
#include "Livre.hpp"
#include "FilmLivre.hpp"

typedef uint8_t UInt8;
typedef uint16_t UInt16;

#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

class Bibliotheque 
{
public:
	Bibliotheque(const Bibliotheque&) = delete;
	static Bibliotheque& get() { return bibliotheque_; }
	void ajouterFilms(const std::string& nomFichier);
	void ajouterLivres(const std::string& nomFichier);
	std::shared_ptr<Acteur> trouverActeur(const std::string& nom) const;
	void enleverFilm(std::unique_ptr<Film> film) { items_.erase(find(items_.begin(), items_.end(), film)); }
	void ajouterFilm(std::unique_ptr<Film> film) { items_.push_back(move(film)); }

private:
	Bibliotheque() { items_ = {}; };
	static Bibliotheque bibliotheque_;
	std::vector<std::unique_ptr<Item>> items_;

public:

	static UInt8 lireUint8(std::istream& fichier);
	static UInt16 lireUint16(std::istream& fichier);
	static std::string lireString(std::istream& fichier);
	


};






#endif 

