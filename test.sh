#!/bin/zsh

for ((i = 1; i < 101; i++));
do
		echo "Round $i";
		rm -f output.txt;
        gcc -g3 -fsanitize=address -D BUFFER_SIZE=$i get_next_line.c get_next_line_utils.c main.c
		./a.out;
		diff input.txt output.txt;
done
echo "-------END OF TEST------------"
