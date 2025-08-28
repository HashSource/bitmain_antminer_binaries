
/* WARNING: Unknown calling convention */

void * hashtable_iter_next(hashtable_t *hashtable,void *iter)

{
  undefined1 *puVar1;
  
  puVar1 = *(undefined1 **)((int)iter + 4);
  if ((hashtable_list *)puVar1 == &hashtable->list) {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}

