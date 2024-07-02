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

   cerr << "Entering `pure'." << endl;

   cerr << std::fixed;

   float fundamental = 110; // 110;

   float curr_frequency;

   float comparison_val = 3.0;

   int j, k;

   bool found = false;

   int octave_ctr = 1;
   bool octave_flag = false;

   stringstream s;

   float et_freq; // equal tempered

   vector<float> et_vector;
   et_vector.push_back(fundamental);  

   float alpha = powf(2.0, 1.0/12.0);
   float beta  = powf(2.0, 1.0/24.0);

#if 0 
   cerr << "alpha == " << alpha << endl
        << "beta  == " << beta  << endl;
#endif 

/* ** (2) Calculate equal-tempered intervals.  */

   float curr_freq = fundamental;

   for (int i = 1; i <= 12; ++i)
   {
       curr_freq *= alpha;
       et_vector.push_back(curr_freq);
   }

   cerr << "Equal-tempered intervals:" << endl;

   j = 0;

   for (vector<float>::iterator iter = et_vector.begin();
        iter != et_vector.end();
        ++iter) 
   {
       if (j == 7)
          cerr << endl;
 
       cerr << setfill(' ') << setw(2) << j++ << ". " << *iter << endl;      
   }
 
/* ** (2) */


   for (int i = 1; i <= 64; ++i)
   {
      if (i == 32)
       comparison_val /= 2;

      curr_frequency = fundamental * i;

      s << setw(2) << setfill(' ') << i << ". "
        << "curr_frequency == " << std::fixed << setprecision(0) << setw(4) << curr_frequency << " ";

      while (curr_frequency > fundamental * 2.0)
      {
         curr_frequency /= 2.0;
      }  

      
         

      s <<  "--> " << setprecision(5) << setfill(' ') 
        << ((curr_frequency == 2 * fundamental) ? curr_frequency/2 : curr_frequency)
        << " ";

      if (curr_frequency == fundamental)
      {
         s <<  "(1/1)   Fundamental (OCTAVE 1)" << endl;
         cerr << s.str();
         s.str("");
         continue;
      }

      for (j = 2; j < 48; j++)
      {
          for (k = 1; k < j; k++)
          {
              if ((j == k) || ((j % 2 == 0) && (k % 2 == 0)))
                 continue;

              if (fabs(curr_frequency - ((j * fundamental) / k)) < comparison_val)
              {
                 s << "(" << j << "/" << k << ") ";

                 if (j == 2 && k == 1)
                 {
                    s << "  OCTAVE " << ++octave_ctr;
                    octave_flag = true;
                 }

                 else if (j == 3 && k == 2)
                 {
                    s << "  Perfect fifth.  " << "E.T. " << et_vector[7] << ", "
                      << "Difference: "; 

                    if (curr_frequency > et_vector[7])
                       s << "+";
                    else
                       s << "-";

                    s << fabs(curr_frequency - et_vector[7]);

                 }
                 else if (j == 5 && k == 4)
                 {
                    s << "  Maj. 3rd.  "
                      << "E.T. " << et_vector[4] << ", "
                      << "Difference: "; 

                    if (curr_frequency > et_vector[4])
                       s << "+";
                    else
                       s << "-";

                    s << fabs(curr_frequency - et_vector[4]);




                 }
                 else if (j == 7 && k == 4)
                 {
                    s << "  Min. 7th.  "
                      << "E.T. " << et_vector[10] << ", "
                      << "Difference: "; 

                    if (curr_frequency > et_vector[10])
                       s << "+";
                    else
                       s << "-";

                    s << fabs(curr_frequency - et_vector[10]);

                 }
                 else if (j == 8 && k == 7)
                 {
                    s << "  Maj. 2nd ";
                 }
                 else if (j == 7 && k == 5)
                 {
                    s << "  Fourth (+) ";
                 }
                 else if (j == 8 && k == 5)
                 {
                    s << "  Maj. 6th ";
                 }
                 else if (j == 13 && k == 7)
                 {
                    s << " Maj. 7th ";
                 }

                 else if (j == 13 && k == 12)
                 {
                    s << "Min. 2nd ";
                 }

                 else if (j == 6 && k == 5)
                 {
                    s << "  Min. 3rd ";
                 }

                 else if (j == 4 && k == 3)
                 {
                    s << "  Fourth (-) ";
                 }

                 else if (j == 10 && k == 7)
                 {
                    s << " Dim. 5th ";
                 }

                 else if (j == 11 && k == 7)
                 {
                    s << " Min. 6th ";
                 }

                 found = true;
                 break;
              }
          } /* inner for  */

          if (found)
          {
             found = false;
             break;
          }
      }

      s <<  endl;

      if (octave_flag)
      {
         cerr << endl;
         octave_flag = false;
      }

      cerr << s.str();
      s.str("");

   }


/* ** (2) */

   cerr << "Exiting `pure' successfully with return value 0." << endl;

   return 0;

}

#if 0

      else if (curr_frequency == 2*fundamental)
         cerr << "    Octave";
      else if (curr_frequency == 3*fundamental/2)
         cerr << "    Fifth (3/2)";
      else if (fabs(curr_frequency - 4*fundamental/3) <= comparison_val)
      {
         cerr << "    Fourth (4/3)";
      }
      else if (fabs(curr_frequency - 5*fundamental/4) <= comparison_val)
      {
         cerr << "    Maj. 3rd (5/4)";
      }
      else if (fabs(curr_frequency - 5*fundamental/3) <= comparison_val)
      {
         cerr << "    (5/3)";
      }
      else if (fabs(curr_frequency - 5*fundamental/3) <= comparison_val)
      {
         cerr << "    (5/3)";
      }
      else if (fabs(curr_frequency - 6*fundamental/5) <= comparison_val)
      {
         cerr << "    (6/5)";
      }
      else if (fabs(curr_frequency - 7*fundamental/6) <= comparison_val)
      {
         cerr << "    (7/6)";
      }
      else if (fabs(curr_frequency - 8*fundamental/7) <= comparison_val)
      {
         cerr << "    (8/7)";
      }
      else if (fabs(curr_frequency - 9*fundamental/8) <= comparison_val)
      {
         cerr << "    (9/8)";
      }
      else if (fabs(curr_frequency - 10*fundamental/9) <= comparison_val)
      {
         cerr << "    (10/9)";
      }
      else if (fabs(curr_frequency - 11*fundamental/10) <= comparison_val)
      {
         cerr << "    (11/10)";
      }
      else if (fabs(curr_frequency - 12*fundamental/11) <= comparison_val)
      {
         cerr << "    (12/11)";
      }
      else if (fabs(curr_frequency - 13*fundamental/12) <= comparison_val)
      {
         cerr << "    (13/12)";
      }
      else if (fabs(curr_frequency - 14*fundamental/13) <= comparison_val)
      {
         cerr << "    (14/13)";
      }
      else if (fabs(curr_frequency - 15*fundamental/14) <= comparison_val)
      {
         cerr << "    (15/14)";
      }
      else if (fabs(curr_frequency - 16*fundamental/15) <= comparison_val)
      {
         cerr << "    (16/15)";
      }
      else if (fabs(curr_frequency - 5*fundamental/3) <= comparison_val)
      {
         cerr << "    Maj. 6th (5/3)";
      }
      else if (fabs(curr_frequency - 5*fundamental/2) <= comparison_val)
      {
         cerr << "    (5/2)";
      }
      else if (fabs(curr_frequency - 7*fundamental/5) <= comparison_val)
      {
         cerr << "    (7/5)";
      }
      else if (fabs(curr_frequency - 7*fundamental/4) <= comparison_val)
      {
         cerr << "    Min. 7th (7/4)";
      }
      else if (fabs(curr_frequency - 7*fundamental/3) <= comparison_val)
      {
         cerr << "    (7/3)";
      }
      else if (fabs(curr_frequency - 7*fundamental/2) <= comparison_val)
      {
         cerr << "    (7/2)";
      }

#endif 


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


