#include "dog.h"

/**
 * init_dog - function
 * @d: Pointer to dog
 * @name: Name
 * @age: Age
 * @owner: Owner
 *
 * Return: Nothing
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
