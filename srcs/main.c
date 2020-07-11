
#include "fdf.h"

int			main(int av, char **ac)
{
	t_fdf	*data;

	if (av != 2)
		error_proc(ERR_USAGE);
	data = fdf_init();
	if (check_file(ac[1]) == -1 || read_file(data->map, ac[1]) == -1)
		error_proc(ERR_FILE);
	data->camera->zoom = min_v((WIDTH_WIN / data->map->width_map) / 1.7,
			(HEIGHT_WIN / data->map->height_map) / 1.7);
	data->camera->zoom_max = data->camera->zoom;
	draw(data);
	control(data);
	mlx_loop(data->mlx);
	return (0);
}
