
/* WARNING: Unknown calling convention */

void * hashtable_iter(hashtable_t *hashtable)

{
  hashtable_list *phVar1;
  
  phVar1 = (hashtable->ordered_list).next;
  if (phVar1 == &hashtable->ordered_list) {
    phVar1 = (hashtable_list *)0x0;
  }
  return phVar1;
}

