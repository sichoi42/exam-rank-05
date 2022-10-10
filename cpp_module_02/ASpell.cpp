#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(const std::string& name, const std::string& effects) {
	_name = name;
	_effects = effects;
}

ASpell::ASpell(const ASpell& as) {
	if (this != &as) {
		_name = as.getName();
		_effects = as.getEffects();
	}
}

ASpell	&ASpell::operator=(const ASpell& as) {
	if (this != &as) {
		_name = as.getName();
		_effects = as.getEffects();
	}
	return *this;
}

const std::string	&ASpell::getName() const {
	return _name;
}

const std::string	&ASpell::getEffects() const {
	return _effects;
}

void				ASpell::launch(const ATarget& at) const {
	at.getHitBySpell(*this);
}
