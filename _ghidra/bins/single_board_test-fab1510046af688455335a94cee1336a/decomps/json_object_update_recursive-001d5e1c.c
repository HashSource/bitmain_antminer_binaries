
/* WARNING: Unknown calling convention */

int json_object_update_recursive(json_t *object,json_t *other)

{
  int iVar1;
  hashtable_t parents_set;
  
  iVar1 = hashtable_init(&parents_set);
  if (iVar1 == 0) {
    iVar1 = do_object_update_recursive(object,other,&parents_set);
    hashtable_close(&parents_set);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

