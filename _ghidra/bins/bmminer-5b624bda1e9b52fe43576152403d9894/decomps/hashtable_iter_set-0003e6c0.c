
/* WARNING: Unknown calling convention */

void hashtable_iter_set(void *iter,json_t *value)

{
  json_t *json;
  size_t sVar1;
  
  json = *(json_t **)((int)iter + 8);
  if (((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) &&
     (sVar1 = json->refcount - 1, json->refcount = sVar1, sVar1 == 0)) {
    json_delete(json);
    *(json_t **)((int)iter + 8) = value;
    return;
  }
  *(json_t **)((int)iter + 8) = value;
  return;
}

