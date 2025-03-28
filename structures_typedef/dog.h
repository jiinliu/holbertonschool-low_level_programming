#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure
 * @name: Name
 * @age: Age
 * @owner: Owner
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

typedef struct dog dog_t;

dog_t *new_dog(char *name, float age, char *owner);

void free_dog(dog_t *d);

#endif
