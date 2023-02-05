sokoban: sokoban.o charge_niveau.o creation_map.o affiche_map.o deplacement.o detection_joueur.o copie_map.o terminal.o test_victoire.o undo_deplacement.o will.o enregistrement_solution.o liste.o reinitialiser.o save.o
	cc -Wall -fsanitize=address -g sokoban.o charge_niveau.o creation_map.o affiche_map.o deplacement.o detection_joueur.o copie_map.o terminal.o test_victoire.o undo_deplacement.o will.o enregistrement_solution.o liste.o reinitialiser.o save.o -o sokoban

sokoban.o: header.h main.c
	cc -Wall -fsanitize=address -g -c main.c -o sokoban.o

charge_niveau.o: header.h charge_niveau.c
	cc -Wall -fsanitize=address -g -c charge_niveau.c -o charge_niveau.o

creation_map.o: header.h creation_map.c
	cc -Wall -fsanitize=address -g -c creation_map.c -o creation_map.o

affiche_map.o: header.h affiche_map.c
	cc -Wall -fsanitize=address -g -c affiche_map.c -o affiche_map.o

deplacement.o: header.h deplacement.c
	cc -Wall -fsanitize=address -g -c deplacement.c -o deplacement.o

detection_joueur.o: header.h detection_joueur.c
	cc -Wall -fsanitize=address -g -c detection_joueur.c -o detection_joueur.o

copie_map.o: header.h copie_map.c
	cc -Wall -fsanitize=address -g -c copie_map.c -o copie_map.o

terminal.o: header.h terminal.c
	cc -Wall -fsanitize=address -g -c terminal.c -o terminal.o

test_victoire.o: header.h test_victoire.c
	cc -Wall -fsanitize=address -g -c test_victoire.c -o test_victoire.o

undo_deplacement.o: header.h undo_deplacement.c
	cc -Wall -fsanitize=address -g -c undo_deplacement.c -o undo_deplacement.o

will.o: header.h will.c
	cc -Wall -fsanitize=address -g -c will.c -o will.o

enregistrement_solution.o: header.h enregistrement_solution.c
	cc -Wall -fsanitize=address -g -c enregistrement_solution.c -o enregistrement_solution.o

liste.o: header.h liste.c
	cc -Wall -fsanitize=address -g -c liste.c -o liste.o

reinitialiser.o: header.h reinitialiser.c
	cc -Wall -fsanitize=address -g -c reinitialiser.c -o reinitialiser.o

save.o: header.h save.c
	cc -Wall -fsanitize=address -g -c  save.c -o save.o

clean:
	rm *.o
