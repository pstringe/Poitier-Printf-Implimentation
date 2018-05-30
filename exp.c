#include <wchar.h>
#include <unistd.h>

int main (void)
{
	//char a[8] = "Poitier";
	wchar_t b[8] = L"Poitier";
	char c[8];
	int	i;

	i = -1;
	while (++i < 8)
		c[i] = b[i];
	write (1, c, 7);
	write (1, "\n", 1);
	return (0);
}
