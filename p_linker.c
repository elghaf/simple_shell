#include "shell.h"


/**
 * _getenv - can gets the value of the var
 * @name: global variable
 * Return: str.
 */
char *_getenv(const char *name)
{
	int cpt, lpt;
	char *value;

	if (!name)
	return (NULL);
	for (cpt = 0; environ[cpt]; cpt++)
	{
	lpt = 0;
	if (name[lpt] == environ[cpt][lpt])
	{
	while (name[lpt])
	{
	if (name[lpt] != environ[cpt][lpt])
	break;
	lpt++;
	}
	if (name[lpt] == '\0')
	{
	value = (environ[cpt] + lpt + 1);
	return (value);
	}
	}
	}
	return (0);
}



/**
 * add_node_end - adds a new node at the end of a list_t list struct
 * @head: pointer adresse
 * @str: pointer to the string in node
 * Return: address of the new node.
 */
list_path *add_node_end(list_path **head, char *str)
{

	list_path *TH;
	list_path *GH;

	GH = malloc(sizeof(list_path));

	if (!GH || !str)
	{
	return (NULL);
	}

	GH->dir = str;

	GH->p = '\0';
	if (!*head)
	{
	*head = GH;
	}
	else
	{
	TH = *head;
	while (TH->p)
	{
	TH = TH->p;
	}
	TH->p = GH;
	}

	return (*head);
}



/**
 * linkpath - afucntion that linked list for path directorys
 * @path: string.
 * Return: pointer.
 */
list_path *linkpath(char *path)
{
	list_path *ras = '\0';
	char *n_t;
	char *pthc = _strdup(path);

	n_t = strtok(pthc, ":");
	while (n_t)
	{
	/* Add the token to the end of the list */
	ras = add_node_end(&ras, n_t);
	n_t = strtok(NULL, ":");
	}
	/* Return the list of paths */
	return (ras);
}


/**
 * _which - gets the cuurent pathnm of a file
 * @filename: this name of the file
 * @head: the name of the head linked list
 * Return: pathname of filename or NULL if atherwise
 */
char *_which(char *filename, list_path *head)
{
	struct stat st;
	char *str;

	list_path *t = head;

	while (t)
	{

		str = concat_all(t->dir, "/", filename);
		if (stat(str, &st) == 0)
		{
			return (str);
		}
		free(str);
		t = t->p;
	}

	return (NULL);
}

/**
 * free_list - free the structer
 *@head: the head of our linked list.
 */
void free_list(list_path *head)
{
	list_path *gb;

	while (head)
	{
		gb = head->p;/*Save the next node*/
		free(head->dir);
		free(head);/*Free the memory for the current node*/
		head = gb;
	}

}
