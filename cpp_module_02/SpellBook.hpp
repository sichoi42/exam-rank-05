#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook {
	private:
		SpellBook(const SpellBook& sb);
		SpellBook	&operator=(const SpellBook& sb);

		std::map<std::string, ASpell *> _spells;

	public:
		SpellBook();
		~SpellBook();

		void		learnSpell(ASpell *as);
		void		forgetSpell(const std::string& name);
		ASpell		*createSpell(const std::string& name);
};
