gcc -Wall -Werror -Wextra -fsanitize=address -g3 ft_printf.c main.c -o ft_printf
./ft_printf > yy
cat -e yy > y
gcc -D REAL main.c -o printf
./printf | cat -e > r
diff -y --suppress-common-lines r y
rm -rf yy y r ft_printf printf
