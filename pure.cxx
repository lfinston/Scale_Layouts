/* pure.cxx  */
/* Created by Laurence D. Finston (LDF) Di 2. Jul 17:38:33 CEST 2024 */

/* * (1) Copyright and License. */

/* Copyright 2022 Laurence D. Finston */

/* This file is part of Scale_Layouts, a package for generating scale layouts. */

/* Scale_Layouts is free software; you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation; either version 3 of the License, or */
/* (at your option) any later version.  */

/* Scale_Layouts is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details.  */

/* You should have received a copy of the GNU General Public License */
/* along with GNU 3DLDF; if not, write to the Free Software */
/* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */

/* ("@@" stands for a single at-sign in the following paragraph.) */

/* Please send bug reports to Laurence.Finston@@gmx.de */

/* The author can be contacted at: */

/* Laurence D. Finston                 */
/* Laurence.Finston@@gmx.de (@@ stands for a single "at" sign.) */

#include <stdlib.h>
#include <cstdio>
#include <float.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <math.h>
#include <new>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

stringstream s;

// (setq outline-regexp "/\\* [*\f]+")

/* * (1) */



int
main(int argc, char *argv[])
{
/* ** (2) */

   std::cerr << std::fixed;

   cerr << "Entering `pure'." << endl;

   float fundamental = 110;

   float curr_frequency;

   for (int i = 1; i <= 32; ++i)
   {
      curr_frequency = fundamental * i;

      

      cerr << "curr_frequency == " << setprecision(0) << setw(4) << curr_frequency << "    ";

      while (curr_frequency > fundamental * 2.0)
      {
         curr_frequency /= 2.0;
      }  

      cerr << " --> " << setprecision(5) << setfill('0') << curr_frequency;

      if (curr_frequency == 220)
         cerr << "    Octave";

      cerr << endl;
   }


/* ** (2) */

   cerr << "Exiting `pure' successfully with return value 0." << endl;

   return 0;

}

/* * Emacs-Lisp code for use in indirect buffers when using the          */
/*   GNU Emacs editor.  The local variable list is not evaluated when an */
/*   indirect buffer is visited, so it's necessary to evaluate the       */
/*   following s-expression in order to use the facilities normally      */
/*   accessed via the local variables list.                              */
/*   \initials{LDF 2004.02.12}.                                          */
/*   (progn (cweb-mode) (outline-minor-mode t))                          */

/* * Local variables for Emacs.*/
/* Local Variables: */
/* mode:CWEB */
/* eval:(display-time) */
/* eval:(read-abbrev-file) */
/* indent-tabs-mode:nil */
/* eval:(outline-minor-mode) */
/* fill-column:80 */
/* End: */


