
/* WARNING: Unknown calling convention */

json_t * json_array(void)

{
  json_t *pjVar1;
  json_array_t *array;
  void *pvVar2;
  json_t *local_14 [2];
  
  pjVar1 = (json_t *)jsonp_malloc(0x18);
  local_14[0] = pjVar1;
  if (pjVar1 != (json_t *)0x0) {
    pjVar1->type = JSON_ARRAY;
    pjVar1->refcount = 1;
    pjVar1[1].refcount = 0;
    pjVar1[1].type = 8;
    pvVar2 = jsonp_malloc(0x20);
    pjVar1[2].type = (json_type)pvVar2;
    if (local_14[0][2].type == JSON_OBJECT) {
      _jsonp_free(local_14);
      local_14[0] = (json_t *)0x0;
    }
    else {
      local_14[0][2].refcount = 0;
    }
  }
  return local_14[0];
}

