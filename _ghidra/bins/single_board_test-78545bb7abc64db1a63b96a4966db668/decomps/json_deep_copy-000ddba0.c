
/* WARNING: Unknown calling convention */

json_t * json_deep_copy(json_t *json)

{
  int iVar1;
  json_t *pjVar2;
  hashtable_t parents_set;
  
  iVar1 = hashtable_init(&parents_set);
  if (iVar1 == 0) {
    pjVar2 = do_deep_copy(json,&parents_set);
    hashtable_close(&parents_set);
  }
  else {
    pjVar2 = (json_t *)0x0;
  }
  return pjVar2;
}

