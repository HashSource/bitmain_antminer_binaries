
/* WARNING: Unknown calling convention */

void * hashtable_iter_value(void *iter)

{
  return *(void **)((int)iter + 8);
}

