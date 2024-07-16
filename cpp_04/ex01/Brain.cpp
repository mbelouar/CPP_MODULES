#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain()
{
	std::cout << " -> Default Brain constructor called." << std::endl;
}

Brain::Brain(const Brain &src)
{
	std::cout << " -> Copy Brain constructor called." << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << " -> Brain destructor called." << std::endl;
}

Brain	&Brain::operator =(const Brain &src)
{
	if (this != &src)
	{
		std::cout << " -> Copy assignement Brain called." << std::endl;
		this->setIdeas(src.getIdeas());
		// *this->ideas = *src.ideas;
		// for (int i = 0; i < 100; ++i) {
    	// 	this->ideas[i] = src.ideas[i];
		// }
	}
	return *this;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              

const std::string	*Brain::getIdeas(void) const
{
	const std::string	*new_ideas = this->ideas;
	return new_ideas; // return a new memory address
}

void	Brain::setIdeas(const std::string *new_ideas)
{
	for (int cur = 0; cur < 100; cur++)
		this->ideas[cur] = new_ideas[cur];
}
