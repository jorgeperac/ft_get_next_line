_This project was created as part of 42's curriculum by jorpere2_

**DESCRIPTION**
Get_Next_line consist of a program which calls for a loop that will read a given file, line by line, until there's nothing else to read. It should be able to read each line until '\n' is found, store it, and go to the next line until there are no more '\n'.
For the main archive we get a few functions.
Lets start in char  *get_next_line(int fd). Here fd is the file we want to read.
We first create a static char *buff for the array that we´ll be creating. buff will store everything we read temporarily and helpy will be the definitive one, we'll copy from buff to helpy onwards.
We ask tell the program to read the file and store it in buff, giving the read fd which will be the read file, and also buff which will be where we store it.
These are the main functions we will be using in get_netx_line:
    * buff = ft_read_file(fd, buff);
        We read the file and store it in buff, we accumulate the next chunk(s) if text into buff until a newline appears
    * helpy = ft_parse_line(buff);
        here we copy the buff stored data into an organised array, which will be the one returned
    * buff = ft_update_line(buff);
        here we clean up the memory and make it so t leaves everything that comes after the newline you just returned, these are the leftovers, which may contain zero, one, or many future lines

**INSTRUCTIONS**


**SOURCES**
