CC=gcc
PRJ_NME=c-serializer
DBG_DIR=debug
RLS_DIR=release
SRC_FLS=main.c ./**/*.c
HDR_FLS=main.c ./**/*.h
DBG_FLGS=-Wall -Wextra -pedantic -Og -g
RLS_FLGS=-Wall -Wextra -O2

clean:
	@rm -rf $(DBG_DIR) $(RLS_DIR) *.txt

format:
	@clang-format -i -style=Chromium $(SRC_FLS) $(HDR_FLS)

build-dbg: clean format
	@mkdir $(DBG_DIR)
	@$(CC) $(DBG_FLGS) $(SRC_FLS) -o $(DBG_DIR)/$(PRJ_NME)

build-rls: clean format
	@mkdir $(RLS_DIR)
	@$(CC) $(RLS_FLGS) $(SRC_FLS) -o $(RLS_DIR)/$(PRJ_NME)

run-dbg: build-dbg
	@./$(DBG_DIR)/$(PRJ_NME)

run-rls: build-rls
	@./$(RLS_DIR)/$(PRJ_NME)
