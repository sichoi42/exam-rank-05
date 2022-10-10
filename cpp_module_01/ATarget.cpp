#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::~ATarget() {}

ATarget::ATarget(const std::string& type) {
	_type = type;
}

ATarget::ATarget(const ATarget& at) {
	if (this != &at) {
		_type = at.getType();
	}
}

ATarget	&ATarget::operator=(const ATarget& at) {
	if (this != &at) {
		_type = at.getType();
	}
	return *this;
}

const std::string	&ATarget::getType() const {
	return _type;
}

void				ATarget::getHitBySpell(const ASpell& as) const {
	std::cout << _type << " has been " << as.getEffects() << "!" << std::endl;
}
