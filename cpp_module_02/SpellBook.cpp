#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::map<std::string, ASpell *>::iterator begin = _spells.begin();
	std::map<std::string, ASpell *>::iterator end = _spells.end();
	while (begin != end) {
		delete begin->second;
		++begin;
	}
	_spells.clear();
}

void		SpellBook::learnSpell(ASpell *as) {
	if (as) {
		_spells.insert(std::pair<std::string, ASpell *>(as->getName(), as->clone()));
	}
}

void		SpellBook::forgetSpell(const std::string& name) {
	std::map<std::string, ASpell *>::iterator it = _spells.find(name);
	if (it != _spells.end()) {
		delete it->second;
	}
	_spells.erase(name);
}

ASpell		*SpellBook::createSpell(const std::string& name) {
	std::map<std::string, ASpell *>::iterator it = _spells.find(name);
	if (it != _spells.end()) {
		return _spells[name];
	}
	return NULL;
}

