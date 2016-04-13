#include "ft_ls.h"

static void	recursive(t_opt opt, char *path)
{
	t_elem	*files;
	DIR		*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (elemget(&files, readdir(dir), \
					ft_strjoin(path, "/"), opt) != 0)
			;
		closedir(dir);
		if (files)
			display_file(opt, files, 1);
		files = NULL;
	}
	else
		error_path("ft_ls: ", path, 0);
}

void		recursion(t_opt opt, t_elem *files)
{
	t_elem	*cur;

	cur = files;
	while (cur)
	{
		if (cur->name && cur->path && S_ISDIR(cur->st_mode)
			&& ft_strcmp(".", cur->name) && ft_strcmp("..", cur->name)
			&& !(opt.a == 0 && cur->name[0] == '.'))
			recursive(opt, cur->path);
		cur = cur->next;
	}
}
