#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>

class Brain {
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &src);
	~Brain();
	Brain	&operator =(const Brain &src);

	const std::string	*getIdeas(void) const;
	void				setIdeas(const std::string *new_ideas);
	void				setIdea(std::string idea, int index);
};

#endif