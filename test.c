#include <mlx.h>
#include <stdio.h>

int	render_next_frame(void *YourStruct)
{
	static int	i;
	printf("%i\t", i++);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 200, 300, "oo");
	mlx_loop_hook(mlx, render_next_frame, 0);
	mlx_loop(mlx);
}

