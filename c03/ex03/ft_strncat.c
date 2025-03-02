char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len_dest;

	i = 0;
	len_dest = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[i] && i < nb)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (dest);
}
