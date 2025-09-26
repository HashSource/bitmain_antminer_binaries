
/* WARNING: Unknown calling convention */

json_t * json_array(void)

{
  json_t *ptr;
  void *pvVar1;
  
  ptr = (json_t *)jsonp_malloc(0x14);
  if (ptr == (json_t *)0x0) {
    return (json_t *)0x0;
  }
  ptr->type = JSON_ARRAY;
  ptr->refcount = 1;
  ptr[1].refcount = 0;
  ptr[1].type = 8;
  pvVar1 = jsonp_malloc(0x20);
  ptr[2].type = (json_type)pvVar1;
  if (pvVar1 != (void *)0x0) {
    return ptr;
  }
  jsonp_free(ptr);
  return (json_t *)0x0;
}

