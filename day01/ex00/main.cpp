#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int		main(void)
{
	Zombie* zombie;

	zombie = newZombie("But_Why");
	zombie->announce();
	delete zombie;
	randomChump("Sesco");
	return (0);
}