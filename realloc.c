#include "shell.h"

/**
 * _realloc - Reallocate memory for a block of data.
 * @ptr: Pointer to the previously allocated memory.
 * @old_size: Size of the old memory block.
 * @new_size: Size of the new memory block.
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		old_size = new_size;

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return (new_ptr);
}
