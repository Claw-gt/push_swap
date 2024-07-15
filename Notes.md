# Types of Sort Algorithms

- Mergesort: O(n log n) average and worst case
- Quicksort O(n log n) average case
- Selection sort and insertion sort are both O(n^2) average and worst-case

## Selection Sort

## Insertion Sort

## Merge Sort

- Principio de **Divide y vencerás (*n * log(n)*)**:
    1. Dividir: divides en dos subarreglos
    2. Conquistar: ordenar cada mitad con *merge sort* (*merge sort* a cada mitad)
    3. Combinar
- Emplea recursividad

## Quick Sort

- Principio de **Divide y vencerás (*n * log(n)*)**:
    1. Dividir: elegir un pivote (afecta en el tiempo de computación) y colocar los elementos más pequeños a su izquierda y los más grandes a su derecha
    2. Conquistar: los dos arreglos que se forman en 1. se ordenan con llamadas recursivas a *Quick Sort*
    3. Combinar
- Emplea recursividad

## Bubble Sort

- Compara por pares los elementos adyacentes
- El elemento más grande se coloca (al final) tras finalizar la primera iteración, por lo que se repite el mismo procedimiento pero con los elementos restantes.

no bubble sort - it's terrible - O(n^2), except when n <= 16

## Counting Sort

- No usa comparaciones, sino que ordena unas *clasificaciones*  o *llaves*
- Ordenamiento **lineal (*n + k*)**:
    1. los índices de la tabla ya se encuentran ordenados


1. Suma acumulativa


1. Se decrementan los valores dentro de la tabla a medida que se colocan los números en su posición


Útil salvo cuando **k** (elemento más grande) es mucho mayor que **n** (número de elementos dentro del array) → Aumenta la complejidad a **n^2**


## Radix Sort

- Usa *Counting Sort* como subrutina para poder ordenar ***O (b * (n + k))*** donde **b** es el número de dígitos del número más grande, **n** el número de elementos del array y donde **k** siempre es la base de los elementos → 10 (nº más grande de unidades en sistema decimal)
- Ordena dígito por dígito (primero unidades, luego decenas, luego centenas…)


## Big O

• [Best, worst and average case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) behavior in terms of the size of the list. For typical serial sorting algorithms, good behavior is O(*n* log *n*), with parallel sort in O(log2 *n*), and bad behavior is O(*n*2). Ideal behavior for a serial sort is O(*n*), but this is not possible in the average case. Optimal parallel sorting is O(log *n*).

For best-case scenario it is used the symbol Omega, while the worst case is Big O. If both are equivalent, it is designated with Theta

f(n) is O(g(n)) if there is C (constant) and no such that:\
&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;**f(n) ≤ C*g(n) for n > no**

## Stability

A sorting algorithm is said to be **stable** if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted. Some sorting algorithms are stable by nature like Insertion sort, Merge Sort, Bubble Sort, etc. And some sorting algorithms are not, like Heap Sort, Quick Sort, etc.

*Background*: a "stable" sorting algorithm keeps the items with the same sorting key in order. Suppose we have a list of 5-letter words:

```
peach
straw
apple
spork

```

If we sort the list by just the first letter of each word then a stable-sort would produce:

```
apple
peach
straw
spork

```

In an **unstable** sort algorithm, `straw` or `spork` may be interchanged, but in a stable one, they stay in the same relative positions (that is, since `straw` appears before `spork` in the input, it also appears before `spork` in the output).

We could sort the list of words using this algorithm: stable sorting by column 5, then 4, then 3, then 2, then 1. In the end, it will be correctly sorted. Convince yourself of that. (by the way, that algorithm is called radix sort)

Now to answer your question, suppose we have a list of first and last names. We are asked to sort "by last name, then by first". We could first sort (stable or unstable) by the first name, then stable sort by the last name. After these sorts, the list is primarily sorted by the last name. However, where last names are the same, the first names are sorted.

You can't stack unstable sorts in the same fashion.

# Makefile

### Regla .c.o:
Any defined implicit rule suffix also counts as a special target if it appears as a target, and so does the concatenation of two suffixes, such as **‘.c.o’**. These targets are suffix rules, an obsolete way of defining implicit rules (but a way still widely used). In principle, any target name could be special in this way if you break it in two and add both pieces to the suffix list. In practice, suffixes normally begin with ‘.’, so these special target names also begin with ‘.’. 
A two-suffix rule ‘.c.o’ (whose target and source suffixes are ‘.o’ and ‘.c’) is equivalent to the pattern rule ‘%.o : %.c’.

#### $<
Often the prerequisites include header files as well, which you do not want to mention in the recipe. The automatic variable **‘$<’** is just the first prerequisite:

`VPATH = src:../headers`
`foo.o : foo.c defs.h hack.h`
        `cc -c $(CFLAGS) $< -o $@`

#### $@
Similar recipes work for all the targets. The automatic variable ‘$@’ can be used to substitute the particular target to be remade into the commands (see Automatic Variables). For example:

`bigoutput littleoutput : text.g`
        `generate text.g -$(subst output,,$@) > $@`
is equivalent to

`bigoutput : text.g`
        `generate text.g -big > bigoutput`
`littleoutput : text.g`
        `generate text.g -little > littleoutput`

### Incluir otras librerías

Incluir librería libft.a y libftprintf.a

`LDFLAGS= -L<Directory where the library resides> -l<library name>`

-L flag tells **where** (the directory) to search the library

LIBS = -l:libft.a -l:libftprintf.a

`$(NAME): $(MY_OBJECTS)`
		make -C libft
		make -C printf
		$(CC) $(CFLAGS) $(MY_OBJECTS) -o $(NAME) $(LDFLAGS) $(LIBS)
		@echo "\n Compilation of $(NAME):  $(GREEN)SUCCESS!"

Explanation

- **CC**: The compiler to use (e.g., `gcc`).
- **CFLAGS**: Compiler flags, including the path to your library's headers (`I/usr/local/include`).
- **LDFLAGS**: Linker flags, including the path to your library's archive or shared object (`L/usr/local/lib`).
- **LIBS**: Libraries to link against, specified with `l`. For `libmylibrary.a` or `libmylibrary.so`, use `lmylibrary`.

*Nota: si la librería no empieza por **lib…**, se puede usar -l**:**mylibrary**.a***