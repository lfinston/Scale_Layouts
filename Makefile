#### Makefile
#### Created by Laurence D. Finston (LDF) Sun 17 Jul 2022 06:16:10 PM CEST

#### * (1) Copyright and License.

#### Copyright 2022 Laurence D. Finston 

#### This file is part of Scale_Layouts, a package for generating scale layouts. 

#### Scale_Layouts is free software; you can redistribute it and/or modify 
#### it under the terms of the GNU General Public License as published by 
#### the Free Software Foundation; either version 3 of the License, or 
#### (at your option) any later version.  

#### Scale_Layouts is distributed in the hope that it will be useful, 
#### but WITHOUT ANY WARRANTY; without even the implied warranty of 
#### MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
#### GNU General Public License for more details.  

#### You should have received a copy of the GNU General Public License 
#### along with GNU 3DLDF; if not, write to the Free Software 
#### Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#### ("@@" stands for a single at-sign in the following paragraph.) 

#### Please send bug reports to Laurence.Finston@@gmx.de

#### The author can be contacted at: 

#### Laurence Finston                 
#### Laurence.Finston@gmx.de 

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
	pythagorean$(EXEEXT) 440
