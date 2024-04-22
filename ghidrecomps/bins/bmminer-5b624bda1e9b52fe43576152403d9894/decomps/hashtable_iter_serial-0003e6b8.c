
/* WARNING: Unknown calling convention */

size_t hashtable_iter_serial(void *iter)

{
  return *(size_t *)((int)iter + 0xc);
}

