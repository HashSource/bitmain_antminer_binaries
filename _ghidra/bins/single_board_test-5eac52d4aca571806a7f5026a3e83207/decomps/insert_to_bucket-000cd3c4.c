
/* WARNING: Unknown calling convention */

void insert_to_bucket(hashtable_t *hashtable,bucket_t *bucket,list_t *list)

{
  hashtable_list *phVar1;
  hashtable_list *phVar2;
  
  phVar2 = bucket->first;
  if ((phVar2 == &hashtable->list) && (phVar2 == bucket->last)) {
    phVar1 = (hashtable->list).prev;
    list->next = phVar2;
    list->prev = phVar1;
    phVar2 = (hashtable->list).prev;
    (hashtable->list).prev = list;
    phVar2->next = list;
    bucket->last = list;
    bucket->first = list;
  }
  else {
    list->prev = phVar2->prev;
    list->next = phVar2;
    phVar1 = phVar2->prev;
    phVar2->prev = list;
    phVar1->next = list;
    bucket->first = list;
  }
  return;
}

