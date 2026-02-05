_This project was created as part of 42's curriculum by jorpere2_

**DESCRIPTION**
This project consists of a recreation of C's printf() function.
Printf() is a function consisting of a conditional loop that checks what type of variable we want to print. 
Once it checks the type it just sends it to a write adapted to each type of data.
In this project, we're asked to handle this type of data:
    %c -> For single characters (ft_putchar)
    %s -> For character strings (ft_putstr)
    %p -> For void * pointers (ft_putptrnull)
    %d -> For decimal numbers (ft_putnbr)
    %i -> For interger numbers (ft_putnbr)
    %u -> For unsigned numbers (ft_putunbr)
    %x -> For hexadecimal numbers in lowercase (ft_hexnbr)
    %X -> For hexadecimal numbers in uppercase (ft_hexnbr)
    %% -> For printing '%' (ft_putchar)

**INSTRUCTIONS**
Make must be written in the terminal so everything is compiled at the same time, make clean should be written to delete the .o files and the make fclean should be used to delete all the .o and .a files.

**SOURCES**
