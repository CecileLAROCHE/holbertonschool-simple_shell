#include "Shell.h"


char *find_in_path(const char *command)
{
	char *path = _getenv("PATH");
	char *path_copy, *dir, full_path[1024], *result;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			result = strdup(full_path);
			free(path_copy);
			return (result);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
