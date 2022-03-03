# 参考 https://docs.oracle.com/cd/E19620-01/805-5827/6j5gfrank/index.html
#      https://d-rissoku.net/2013/06/makefile-別ディレクトリに中間ファイル-自動依存関係/
#      https://gmaj7sus4.hatenablog.com/entry/2013/12/18/165224
#      http://nenya.cis.ibaraki.ac.jp/TIPS/makefile2.html
#      https://voidy21.hatenablog.jp/entry/20091110/1257872751
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -MMD -MP

ONJ_DIR = ./obj/

init: obj
obj:
	mkdir obj
all: $(BIN_DIR)cgradient.o
$(BIN_DIR)cgradient.o: cgradient.c
	$(CC) $(CFLAGS) -c $^ $@


clean:
