/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgeperez <jorgeperez@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:11:04 by jorgeperez        #+#    #+#             */
/*   Updated: 2026/01/05 12:19:44 by jorgeperez       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_parse_line(char *aux)
{
    int     i;
    char    *line;
    int     j;

    i = 0;
    j = 0;
    if (!aux || aux[0] == '\0')
        return (NULL); //si viene vacío devolvemos nulo
    while (aux[i] && aux[i] != '\n')
        i++; //recorremos el string para ver cuanta memoria necesitamos reservar
    line = malloc((i + (aux[i] == '\n') + 1) * sizeof(char));
    //reservamos malloc con la longitud del string mas el salto de linea mas 1 para el '\0' del final
    if (!line)
        return (NULL);
    while (j < i)
    {
        line[j] = aux[j];
        j++; //copiamos la linea en linea xd
    }
    if (aux[i] == '\n')
        line[j++] = '\n';
    //antes al recorrer aux con i como usamos < se queda justo en el salto de linea
    //con lo cual este condicional sera siempre verdad
    //hacemos que j sea '\n' y le sumamos 1
    line[j] = '\0';
    //para aqui convertir la ultima posicion del string en nulo
    return (line);
}
char    *ft_update_line(char *upi)
{
    int     i;
    char    *new_line;
    int     j;

    if (!upi)
        return (NULL);
    i = 0;
    j = 0;
    while (upi[i] && upi[i] != '\n')
        i++;
    if (!upi[i])
        return (free(upi), NULL);
    i++;
    new_line = malloc((ft_strlen(upi + i) + 1) * sizeof(char));
    if (!new_line)
        return(free(upi), NULL);
    while (upi[i])
        new_line[j++] = upi[i++];
    new_line[j] = '\0';
    free(upi);
    return (new_line);
}

static char *ft_read_file(int fd, char *aux)
{
    char    *buff; //Declaramos un array
    int     r; //Declaramos un contador

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    //Para el string reservamos con malloc del tamaño del buffer (se cambia en el makefile)
    //El mas uno creo que es para el salto de linea
    if (!buff)
        return (free(buff), NULL);
    r = 1;
    while ((!aux || !ft_strchr(aux, '\n')) && r > 0)
    //!aux -> No lefover text
    //!ft_strchr(aux, '\n) -> the text we have does not yet contain a newline 
    //r > 0 -> the last read succeeded and gave us bytes, r will be storing
        //the bytes of the text we´re reading, if it's <0 it means the reading failed
    {
        r = read(fd, buff, BUFFER_SIZE);
        //We ask for the new chunk of text
        if (r < 0)
            return (free(buff), free(aux), NULL);
            //if the read fails, we free the memory and return NULL
        buff[r] = '\0';
        //Since r will be the nuber of bytes, buff[r] is equivalent to the last
        //position of the text, where we'll place '\0' for it to be a correct string
        aux = ft_strjoin(aux, buff);
        //append the chunk of text to what we already have, we concatenate the strings recieved
        if (!aux)
        {
            free(buff);
            return (NULL);
        }
    }
    free(buff);
    //Mandatory free
    return (NULL);
}

char    *get_next_line(int fd)
{
    static char *buff = NULL;
    char        *helpy;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buff = ft_read_file(fd, buff);
    //We read the file and store it in buff, we accumulate the next chunk(s) if text into buff until a newline appears
    if (!buff)
        return (NULL);
    helpy = ft_parse_line(buff);
    //here we copy the buff stored data into an organised array, which will be the one returned
    if (!helpy)
    {
        free(buff);
        buff = NULL;
        return (NULL);
    }
    buff = ft_update_line(buff);
    //here we clean up the memory and make it so t leaves everything that comes after the newline you just returned 
    //these are the leftovers, which may contain zero, one, or many future lines
    return (helpy);
}

/*int main(int argc, char **argv)
{
	(void)argc;
	int   fd;
    char *line;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (0);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}*/