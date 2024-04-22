
/* WARNING: Unknown calling convention */
/* Local variable list:list_t *[r1:4] conflicts with parameter, skipped. */

void * hashtable_iter_next(hashtable_t *hashtable,void *iter)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)iter + 4);
  if ((hashtable_list *)puVar1 == &hashtable->list) {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}

