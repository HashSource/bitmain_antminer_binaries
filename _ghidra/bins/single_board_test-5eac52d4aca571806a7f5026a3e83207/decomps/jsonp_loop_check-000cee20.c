
/* WARNING: Unknown calling convention */

int jsonp_loop_check(hashtable_t *parents,json_t *json,char *key,size_t key_size)

{
  void *pvVar1;
  int iVar2;
  
  snprintf(key,key_size,"%p",json);
  pvVar1 = hashtable_get(parents,key);
  if (pvVar1 == (void *)0x0) {
    iVar2 = hashtable_set(parents,key,&json_null::the_null);
    return iVar2;
  }
  return -1;
}

