NINE_INCLUDES+=-Iinclude
CC=g++
CFLAGS=-Wall -W

all: nine

nine: ConsoleGame.o Rank.o Suit.o Card.o Deck.o Game.o Utils.o Table.o Player.o SimplePlayer.o ConsolePlayer.o Main.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -o $@

Suit.o: Suit.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Rank.o: Rank.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Card.o: Card.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Deck.o: Deck.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

ConsoleGame.o: ConsoleGame.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Game.o: Game.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Utils.o: Utils.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Table.o: Table.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

Player.o: players/Player.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

SimplePlayer.o: players/SimplePlayer.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

ConsolePlayer.o: players/ConsolePlayer.cxx
	$(CC) $(NINE_INCLUDES) $(CFLAGS) $? $(LDFLAGS) -c -o $@

clean:
	@echo Cleaning up...
	@find . -name "*.o" -exec rm -f {} \;
	@rm -f nine

purge:
	@echo Deleting all backup files...
	@find . -name "*~" -exec rm {} \;
