#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	std::map<std::string, ATarget *>::iterator begin = _targets.begin();
	std::map<std::string, ATarget *>::iterator end = _targets.end();
	while (begin != end) {
		delete begin->second;
		++begin;
	}
	_targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget *at) {
	if (at) {
		_targets.insert(std::pair<std::string, ATarget *>(at->getType(), at->clone()));
	}
}

void	TargetGenerator::forgetTargetType(const std::string& type) {
	std::map<std::string, ATarget *>::iterator it = _targets.find(type);
	if (it != _targets.end()) {
		delete it->second;
	}
	_targets.erase(type);
}

ATarget	*TargetGenerator::createTarget(const std::string& type) {
	std::map<std::string, ATarget *>::iterator it = _targets.find(type);
	if (it != _targets.end()) {
		return _targets[type];
	}
	return NULL;
}
