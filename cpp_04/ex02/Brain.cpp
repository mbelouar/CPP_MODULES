#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << "Copy Brain constructor called." << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain	&Brain::operator =(const Brain &src)
{
	if (this != &src)
	{
		std::cout << "Copy assignement Brain called." << std::endl;
		this->setIdeas(src.getIdeas());
		// *this->ideas = *src.ideas;
	}
	return *this;
}

const std::string	*Brain::getIdeas(void) const
{
	const std::string	*p_ideas = this->ideas;
	return p_ideas;
}

void	Brain::setIdeas(const std::string *new_ideas)
{
	for (int cur = 0; cur < 100; cur++)
		this->ideas[cur] = new_ideas[cur];
}
