/* Internal interfaces for the GNU/Linux specific target code for gdbserver.
   Copyright 2002, Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifdef HAVE_LINUX_REGSETS
typedef void (*regset_func) (void *);
struct regset_info
{
  int get_request, set_request;
  int size;
  regset_func fill_function, store_function;
};
extern struct regset_info target_regsets[];
#endif

struct linux_target_ops
{
  int num_regs;
  int *regmap;
  int (*cannot_fetch_register) (int);

  /* Returns 0 if we can store the register, 1 if we can not
     store the register, and 2 if failure to store the register
     is acceptable.  */
  int (*cannot_store_register) (int);
};

extern struct linux_target_ops the_low_target;
