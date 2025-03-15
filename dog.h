#ifndef DOG_H
#define DOG_H

/**
 * struct dog - function
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

/* Define dog_t as a new name for struct dog */
typedef struct dog dog_t;

#endif
