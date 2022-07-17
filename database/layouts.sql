/* layouts.sql  */
/* Created by Laurence D. Finston (LDF) Sun 17 Jul 2022 11:16:18 PM CEST  */

/* * Copyright and License.*/

/* This file is part of songlist, a package for keeping track of songs. */
/* Copyright (C) 2022 Laurence D. Finston */

/* Scale_Layouts is free software; you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation; either version 3 of the License, or */
/* (at your option) any later version. */

/* Scale_Layouts is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with Scale_Layouts; if not, write to the Free Software */
/* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA */

/* Please send bug reports to Laurence.Finston@gmx.de */

create database Scale_Layouts;

show databases;

use Scale_Layouts;

show tables;

create table Tuning_Systems
(
    id int unsigned not null default 0 unique
);

