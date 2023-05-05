FLAG = g++ -pedantic-errors -std=c++11

word_game.o: word_game.cpp word_game.h
	$(FLAG) -c $<

symbolCombi.o: symbolCombi.cpp symbolCombi.h
	$(FLAG) -c $<

leaderboard.o: leaderboard.cpp leaderboard.h
	$(FLAG) -c $<

cut_wire.o: cut_wire.cpp cut_wire.h
	$(FLAG) -c $<

number_game.o: number_game.cpp number_game.h
	$(FLAG) -c $<

main.o: main.cpp symbolCombi.h word_game.h leaderboard.h cut_wire.h number_game.h
	$(FLAG) -c $<

game: main.o symbolCombi.o word_game.o leaderboard.o cut_wire.o number_game.o
	$(FLAG) $^ -o $@

clean:
	rm -rf main.o symbolCombi.o word_game.o leaderboard.o game save.txt cut_wire.o number_game.o

.PHONY: clean
