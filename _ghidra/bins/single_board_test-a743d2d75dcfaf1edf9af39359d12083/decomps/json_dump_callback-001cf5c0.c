
/* WARNING: Unknown calling convention */

int json_dump_callback(json_t *json,json_dump_callback_t callback,void *data,size_t flags)

{
  int iVar1;
  hashtable_t parents_set;
  
  if ((((int)(flags << 0x16) < 0) || ((json != (json_t *)0x0 && (json->type < JSON_STRING)))) &&
     (iVar1 = hashtable_init(&parents_set), iVar1 == 0)) {
    iVar1 = do_dump(json,flags,0,&parents_set,callback,data);
    hashtable_close(&parents_set);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

