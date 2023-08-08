#include "headers/parsing.h"

void d_print_parsedata(t_parse *data)
{
	printf("no=%s\n", data->no_text);
	printf("so=%s\n", data->so_text);
	printf("we=%s\n", data->we_text);
	printf("ea=%s\n", data->ea_text);
	printf("floor=%s\n", data->floor);
	printf("ceil=%s\n", data->ceil);
}
