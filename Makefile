#### Makefile
#### Created by Laurence D. Finston (LDF) Sun 17 Jul 2022 06:16:10 PM CEST

#### Automatic Variables.  For more, see Section 10.5.3, "Automatic Variables"
#### of the Make info manual.
#### LDF 2009.12.29.

#### $@:  Target
#### $<:  First prerequisite
#### $^:  The names of all the prerequisites, with spaces between them.
#### $*:  The stem with which an implicit rule matches


pythagorean.cxx: pythagorean.web
	$(CTANGLE) $< - $@

pythagorean$(EXEEXT): pythagorean.o
	g++ -o $@ $^

pythagorean.o: pythagorean.cxx
	g++ -c -g $<


.PHONY: run
run: pythagorean$(EXEEXT)
	pythagorean$(EXEEXT) 45
