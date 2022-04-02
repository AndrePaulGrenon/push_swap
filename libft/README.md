# libft
42 school first project

FR // Ce projet a pour objectif de vous faire coder en C une librairie de fonctions usuelles que vous pourrez utiliser dans tous vos prochains projets.
EN // Project consist on recreating on recreating many functions of the standard library in C and adds new functions. 


Parmi les fonctions supplémenatire nous retrouverons :/ Amongs extra function there are: 

SUBSTR: char *ft_substr(char const *s, unsigned int start, size_t len);

Fr // Alloue avec malloc une nouvelle string issue de la string *s commençant part start et faisant len longueur. Rajoute un \0 à la fin. 
EN // Allocates with malloc a copy of string *s from the annex start and for len lenght. Adds \0 at the end. 

STRJOIN : char *ft_strjoin(char const *s1, char const *s2);

FR // Alloue avec malloc le résultat de la concaténation des deux strings. Rajoute un \0 à la fin. 
EN // Allocates with malloc the result of both string. Adds \0 at the end.  

STRTRIM : char *ft_strtrim(char const *s1, char const *set);

FR // Alloue avec malloc une chaîne de caractère à partir de la chaîne *s qui est tonquée au début et à la fin par l'occurence du caractère *set. Rajoute un \0 
à la fin. 
EN // Allocates with malloc a copy of the string *s troncated both at the beginning and at the end throught the occurence of the set character. 

SPLIT : char **ft_split(char const *s, char c);

FR // Alloue avec malloc un tableau de string de charactère formé par le découpage du string *s délimité par le caractère c. 
EN // Allocate with malloc an array of string formed by cutting the string *s using the c character as a delimitation marker. 

ITOA : char *ft_itoa(int n)

FT // Alloue avec malloc une string qui représente en caractères le nombre passé en paramètre.
EN// Allocates a string using malloc thats represents the number given in parameters. 

STRMAPI : char *ft_strmapi(char const *s, char (*f)(unsignedint, char));

FR : Alloue avec malloc une copy du string *s dont chaque caratère a subit l'application de la fonction (*f).
EN : Allocates with malloc a copy of string *s in which the function (*f) was applied to each character. 




