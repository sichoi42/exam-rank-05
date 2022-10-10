#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator {
	private:
		TargetGenerator(const TargetGenerator& tg);
		TargetGenerator	&operator=(const TargetGenerator& tg);

		std::map<std::string, ATarget *> _targets;

	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *at);
		void	forgetTargetType(const std::string& type);
		ATarget	*createTarget(const std::string& type);
};
