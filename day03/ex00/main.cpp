#include "ClapTrap.hpp"

#define GREEN "\033[1;32m"
#define RESET "\033[0m"

int		main(void)
{
	ClapTrap	obj("\033[1;32mEren\033[0m");

	obj.attack("Reiner");
	obj.takeDamage(13);
	obj.beRepaired(5);
	return (0);
}