# Sumii's Makefile for Min-Caml (for GNU Make)
# 
# ack.ml¤Ê¤É¤Î¥Æ¥¹¥È¥×¥í¥°¥é¥à¤òtest/¤ËÍÑ°Õ¤·¤Æmake do_test¤ò¼Â¹Ô¤¹¤ë¤È¡¢
# min-caml¤Èocaml¤Ç¥³¥ó¥Ñ¥¤¥ë¡¦¼Â¹Ô¤·¤¿·ë²Ì¤ò¼«Æ°¤ÇÈæ³Ó¤·¤Þ¤¹¡£

RESULT = min-caml
NCSUFFIX = .opt
CC = gcc
CFLAGS = -g -O2 -Wall
OCAMLLDFLAGS=-warn-error -31

default: debug-code $(RESULT) do_test
$(RESULT): debug-code
## [¼«Ê¬¡Ê½»°æ¡ËÍÑ¤ÎÃí]
## ¡¦OCamlMakefile¤ä¸Å¤¤GNU Make¤Î¥Ð¥°(?)¤Ç¾å¤Î¤è¤¦¤ÊÄêµÁ¤¬É¬Í×(??)
## ¡¦OCamlMakefile¤Ç¤Ïdebug-code¤Ènative-code¤Î¤½¤ì¤¾¤ì¤Ç
##   .mli¤¬¥³¥ó¥Ñ¥¤¥ë¤µ¤ì¤Æ¤·¤Þ¤¦¤Î¤Ç¡¢Î¾Êý¤È¤âdefault:¤Î±¦ÊÕ¤ËÆþ¤ì¤ë¤È
##   ºÆmake»þ¤Ë¡Ê.mli¤¬ÊÑ¹¹¤µ¤ì¤Æ¤¤¤ë¤Î¤Ç¡Ë.ml¤âºÆ¥³¥ó¥Ñ¥¤¥ë¤µ¤ì¤ë
cleanobackup

#â¤·¼ÂÁõ¤ò²þÂ¤¤·¤¿¤é¡¢¤½¤ì¤Ë¹ç¤ï¤»¤ÆÊÑ¤¨¤ë
SOURCES = float.c type.ml id.ml m.ml s.ml \
syntax.ml parser.mly lexer.mll typing.mli typing.ml kNormal.mli kNormal.ml \
alpha.mli alpha.ml beta.mli beta.ml assoc.mli assoc.ml \
inline.mli inline.ml constFold.mli constFold.ml elim.mli elim.ml \
closure.mli closure.ml asm.mli asm.ml virtual.mli virtual.ml \
simm.mli simm.ml regAlloc.mli regAlloc.ml emit.mli emit.ml \
main.mli main.ml

# ¢­¥Æ¥¹¥È¥×¥í¥°¥é¥à¤¬Áý¤¨¤¿¤é¡¢¤³¤ì¤âÁý¤ä¤¹
TESTS = print sum-tail gcd sum fib ack even-odd \
adder adder2 funcomp cls-rec cls-bug cls-bug2 cls-reg-bug \
shuffle spill spill2 spill3 join-stack join-stack2 join-stack3 \
join-reg join-reg2 non-tail-if non-tail-if2 \
inprod inprod-rec inprod-loop matmul matmul-flat \
manyargs

do_test: $(TESTS:%=test/%.cmp)

.PRECIOUS: test/%.s test/% test/%.res test/%.ans test/%.cmp
TRASH = $(TESTS:%=test/%.s) $(TESTS:%=test/%) $(TESTS:%=test/%.res) $(TESTS:%=test/%.ans) $(TESTS:%=test/%.cmp)

test/%.s: $(RESULT) test/%.ml
	./$(RESULT) test/$*
test/%: test/%.s libmincaml.S stub.c
	$(CC) $(CFLAGS) -m32 $^ -lm -o $@
test/%.res: test/%
	$< > $@
test/%.ans: test/%.ml
	ocaml $< > $@
test/%.cmp: test/%.res test/%.ans
	diff $^ > $@

min-caml.html: main.mli main.ml id.ml m.ml s.ml \
		syntax.ml type.ml parser.mly lexer.mll typing.mli typing.ml kNormal.mli kNormal.ml \
		alpha.mli alpha.ml beta.mli beta.ml assoc.mli assoc.ml \
		inline.mli inline.ml constFold.mli constFold.ml elim.mli elim.ml \
		closure.mli closure.ml asm.mli asm.ml virtual.mli virtual.ml \
		simm.mli simm.ml regAlloc.mli regAlloc.ml emit.mli emit.ml
	./to_sparc
	caml2html -o min-caml.html $^
	sed 's/.*<\/title>/MinCaml Source Code<\/title>/g' < min-caml.html > min-caml.tmp.html
	mv min-caml.tmp.html min-caml.html
	sed 's/charset=iso-8859-1/charset=euc-jp/g' < min-caml.html > min-caml.tmp.html
	mv min-caml.tmp.html min-caml.html
	ocaml str.cma anchor.ml < min-caml.html > min-caml.tmp.html
	mv min-caml.tmp.html min-caml.html

release: min-caml.html
	rm -fr tmp ; mkdir tmp ; cd tmp ; cvs -d:ext:sumii@min-caml.cvs.sf.net://cvsroot/min-caml export -Dtomorrow min-caml ; tar cvzf ../min-caml.tar.gz min-caml ; cd .. ; rm -fr tmp
	cp Makefile stub.c SPARC/libmincaml.S min-caml.html min-caml.tar.gz ../htdocs/

include OCamlMakefile
