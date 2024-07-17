#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
	return;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
	return;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
	return;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
	return;
}

void Harl::complain(std::string level) {
    void (Harl::*ptrfuncDebug) (void) = &Harl::debug;
    void (Harl::*ptrfuncInfo) (void) = &Harl::info;
    void (Harl::*ptrfuncWarning) (void) = &Harl::warning;
    void (Harl::*ptrfuncError) (void) = &Harl::error;

	int IntLevel;
	if (level == "DEBUG") {
		IntLevel = 0;
	} else if (level == "INFO") {
		IntLevel = 1;
	} else if (level == "WARNING") {
		IntLevel = 2;
	} else if (level == "ERROR") {
		IntLevel = 3;
	} else {
		IntLevel = -1;
	}
	
	switch (IntLevel)
	{
		case 0 :
		{
			(this->*ptrfuncDebug)();
			(this->*ptrfuncInfo)();
			(this->*ptrfuncWarning)();
			(this->*ptrfuncError)();
			break;
		}
		case 1 :
		{
			(this->*ptrfuncInfo)();
			(this->*ptrfuncWarning)();
			(this->*ptrfuncError)();
			break;
		}
		case 2 :
		{
			(this->*ptrfuncWarning)();
			(this->*ptrfuncError)();
			break;
		}
		case 3 :
		{
			(this->*ptrfuncError)();
			break;
		}
		default :
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	return ;
}