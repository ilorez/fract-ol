#include "libft.h"
#include <string.h>
#include <stdlib.h>


int	ft_print_double(double n)
{
	int	out_len;
  unsigned long long un;
  
  if (n > (double)LLONG_MAX)
		return (ft_print_str("inf"));
	out_len = 0;
  if (n < 0)
  {
		out_len += ft_print_char('-');
    n *= -1;
  }
  un = (unsigned long long)n;
	if (un >= 10)
	{
		out_len += ft_print_double(un / 10);
		out_len += ft_print_char(un % 10 + '0');
	}
	else if (n != 0)
  {
		out_len += ft_print_char(un + '0');
		out_len += ft_print_char('.');
    out_len += ft_print_double(n * 10);
  } 
  else 
		out_len += ft_print_char(un + '0');
	return (out_len);
}

int main(int ac, char **av)
{
  char *str;
  ft_print_double(strtod(av[ac * 0 + 1], &str));
}
