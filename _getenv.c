#include "Shell.h"



char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i] != NULL)
	{

		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{

			return (strdup(&environ[i][len + 1]));
		}
		i++;
	}
	free(strdup(&environ[i][len + 1]));
	return (NULL);
}