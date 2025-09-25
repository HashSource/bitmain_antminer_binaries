
/* WARNING: Unknown calling convention */

json_t * json_object(void)

{
  json_t *ptr;
  int iVar1;
  
  ptr = (json_t *)jsonp_malloc(0x24);
  if (ptr != (json_t *)0x0) {
    if (hashtable_seed == 0) {
      json_object_seed(0);
    }
    ptr->type = JSON_OBJECT;
    ptr->refcount = 1;
    iVar1 = hashtable_init((hashtable_t *)(ptr + 1));
    if (iVar1 != 0) {
      jsonp_free(ptr);
      return (json_t *)0x0;
    }
  }
  return ptr;
}

