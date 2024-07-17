#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	return;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return;
}

void Harl::complain(std::string level) {
    void (Harl::*ptrfuncDebug) (void) = &Harl::debug;
    void (Harl::*ptrfuncInfo) (void) = &Harl::info;
    void (Harl::*ptrfuncWarning) (void) = &Harl::warning;
    void (Harl::*ptrfuncError) (void) = &Harl::error;

	if (level == "debug") {
		(this->*ptrfuncDebug)();
	} else if (level == "info") {
		(this->*ptrfuncInfo)();
	} else if (level == "warning") {
		(this->*ptrfuncWarning)();
	} else if (level == "error") {
		(this->*ptrfuncError)();
	} else {
		std::cout << "ERROR: Unknown level!" << std::endl;
	}
	return ;
}