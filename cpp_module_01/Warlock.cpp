#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) {
	_name = name;
	_title = title;
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator begin = _spells.begin();
	std::map<std::string, ASpell *>::iterator end = _spells.end();
	while (begin != end) {
		delete begin->second;
		++begin;
	}
	_spells.clear();
}

const std::string	&Warlock::getName() const {
	return _name;
}

const std::string	&Warlock::getTitle() const {
	return _title;
}

void				Warlock::setTitle(const std::string& title) {
	_title = title;
}

void				Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void				Warlock::learnSpell(ASpell *as) {
	if (as) {
		_spells.insert(std::pair<std::string, ASpell *>(as->getName(), as->clone()));
	}
}

void				Warlock::forgetSpell(std::string name) {
	std::map<std::string, ASpell *>::iterator it = _spells.find(name);
	if (it != _spells.end()) {
		delete it->second;
	}
	_spells.erase(name);
}

void				Warlock::launchSpell(std::string name, ATarget& at) {
	ASpell *as = _spells[name];
	if (as) {
		as->launch(at);
	}
}
