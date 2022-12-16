

int main()
{
	int fd = open("test", O_RDONLY | O_CREATE)
	// O_RDONLY = read only
	// O_CREATE = create file if it doesn't exist yet

	char *line;
	line = get_next_line(fd);

	while (line != NULL)
	{
		line = get_next_line(fd);
		line++; // la str de "test reprend a partir de la ou elle s est arretee?"
	}

	return(0);
}
