# Libft

*Projet réalisé dans le cadre du cursus 42 par msingh.*

Première bibliothèque C du tronc commun : réécrire une partie de la libc, plus des fonctions utilitaires sur les chaînes et les listes chaînées.
Cette `libft.a` sert ensuite de base à tous les projets C suivants (ft_printf, push_swap, pipex, so_long, cub3D, minishell…).

## Compilation

```bash
make        # compile libft.a
make bonus  # même cible (les fonctions de liste sont incluses)
make clean  # supprime les .o
make fclean # supprime les .o et libft.a
make re
```

Utilisation dans un projet :

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -I.
```

## Contenu

### Partie 1 : fonctions de la libc

| Catégorie | Fonctions |
|---|---|
| Tests de caractères | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Conversion de casse | `ft_toupper`, `ft_tolower` |
| Mémoire | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Chaînes | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Conversion | `ft_atoi` |

### Partie 2 : fonctions supplémentaires

| Fonction | Rôle |
|---|---|
| `ft_substr` | extrait une sous-chaîne (allouée) |
| `ft_strjoin` | concatène deux chaînes dans une nouvelle allocation |
| `ft_strtrim` | retire les caractères d'un set au début et à la fin |
| `ft_split` | découpe une chaîne selon un séparateur, renvoie un tableau terminé par `NULL` |
| `ft_itoa` | entier vers chaîne (gère `INT_MIN`) |
| `ft_strmapi` / `ft_striteri` | applique une fonction à chaque caractère |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | écriture sur un descripteur de fichier |

### Bonus : listes chaînées

Structure utilisée :

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Points d'implémentation

- **`ft_memmove`** copie de la fin vers le début quand la destination chevauche la source après elle, ce qui évite d'écraser les données pas encore copiées.
- **`ft_split`** compte d'abord les mots, alloue le tableau, puis alloue chaque mot. En cas d'échec d'un `malloc`, tout ce qui a déjà été alloué est libéré.
- **`ft_strlcpy` / `ft_strlcat`** renvoient la longueur de la chaîne qu'elles *ont essayé* de créer, comme les versions BSD, ce qui permet de détecter une troncature.
- **`ft_strncmp`** compare les octets en `unsigned char`, comme la libc, pour que les caractères étendus (> 127) soient bien classés.
- **`ft_lstmap`** libère la nouvelle liste partiellement construite si une allocation échoue.

## Tests

Les fonctions ont été comparées à la libc (et à `libbsd` pour `strlcpy` / `strlcat`) sur les cas limites : chaînes vides, `n = 0`, chevauchement mémoire, `INT_MIN` / `INT_MAX`, séparateurs multiples. Valgrind ne signale aucune fuite.
