/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogata <dogata@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:46:01 by dogata            #+#    #+#             */
/*   Updated: 2020/08/11 17:49:32 by dogata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int chr)
{
	size_t count;

	count = ft_strlen(str);
	count = count + 1;
	while (count-- != 0)
	{
		if (*(unsigned char *)str == (unsigned char)chr)
			return ((char*)str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while ((char)s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	count;
	char	*dup;

	size = ft_strlen(s);
	if (!(dup = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	count = 0;
	while ((char)s[count] != '\0')
	{
		dup[count] = (char)s[count];
		count++;
	}
	dup[count] = '\0';
	return (dup);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sstr;
	size_t	sslen;
	size_t	count;

	if (s == NULL)
		return (NULL);
	if ((ft_strlen(s)) < start)
		return (ft_strdup(""));
	if (((ft_strlen(s)) - start) <= len)
		sslen = (ft_strlen(s)) - start;
	else
		sslen = len;
	if (!(sstr = malloc(sizeof(char) * (sslen + 1))))
	{
		free((char *)s);
		return (NULL);
	}
	count = 0;
	while (sslen > count)
		sstr[count++] = (char)s[start++];
	sstr[sslen] = '\0';
	return (sstr);
}

char	*ft_free_strjoin(const char *s1, const char *s2)
{
	char	*cstr;
	size_t	s1len;
	size_t	s2len;
	int		count;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!(cstr = malloc(sizeof(char) * (s1len + s2len + 1))))
	{
		free((char *)s1);
		return (NULL);
	}
	count = -1;
	while ((int)s1len > ++count)
		cstr[count] = s1[count];
	count = -1;
	while (((int)s1len + (int)s2len + 1) > ((int)s1len + ++count))
		cstr[(int)s1len + count] = s2[count];
	free((char *)s1);
	return (cstr);
}
