#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int	i = 1;
	int j = 0;

	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			cout << (char)std::toupper(argv[i][j]);
			j++;
		}
		i++;
		if (i == argc)
			cout << "\n";
		else
			cout << " ";
	}
	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	return (0);
}
