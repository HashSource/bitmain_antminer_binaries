
/* WARNING: Unknown calling convention */

void * hashtable_iter_key(void *iter)

{
  return (void *)((int)iter + 0x10);
}

