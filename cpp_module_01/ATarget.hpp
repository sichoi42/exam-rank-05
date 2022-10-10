#pragma once

#include <iostream>

class ASpell;

class ATarget {
	protected:
		std::string _type;

	public:
		ATarget();
		virtual ~ATarget();
		ATarget(const std::string& type);
		ATarget(const ATarget& at);
		ATarget	&operator=(const ATarget& at);

		const std::string	&getType() const;

		virtual ATarget		*clone() const = 0;

		void				getHitBySpell(const ASpell& as) const;
};

#include "ASpell.hpp"
