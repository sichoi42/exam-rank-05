#pragma once

#include <iostream>

class ATarget;

class ASpell {
	protected:
		std::string _name;
		std::string _effects;

	public:
		ASpell();
		virtual ~ASpell();
		ASpell(const std::string& name, const std::string& effects);
		ASpell(const ASpell& as);
		ASpell	&operator=(const ASpell& as);

		const std::string	&getName() const;
		const std::string	&getEffects() const;

		virtual ASpell		*clone() const = 0;

		void				launch(const ATarget& at) const;
};

#include "ATarget.hpp"
