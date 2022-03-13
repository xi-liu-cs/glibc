/* pthread_mutex_destroy.  Hurd version.
   Copyright (C) 2016-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library;  if not, see
   <https://www.gnu.org/licenses/>.  */

#include <pthread.h>
#include <stdlib.h>
#include <assert.h>
#include <pt-internal.h>
#include "pt-mutex.h"
#include <hurdlock.h>

int
__pthread_mutex_destroy (pthread_mutex_t *mtxp)
{
  atomic_read_barrier ();
  if (*(volatile unsigned int *) &mtxp->__lock != 0)
    return EBUSY;

  mtxp->__type = -1;
  return 0;
}

weak_alias (__pthread_mutex_destroy, pthread_mutex_destroy)
hidden_def (__pthread_mutex_destroy)
