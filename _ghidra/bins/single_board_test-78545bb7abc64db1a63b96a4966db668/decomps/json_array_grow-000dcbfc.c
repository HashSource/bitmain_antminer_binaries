
/* WARNING: Unknown calling convention */

json_t ** json_array_grow(json_array_t *array,size_t amount,int copy)

{
  json_t **__dest;
  uint uVar1;
  uint uVar2;
  json_t **__src;
  size_t new_size;
  
  uVar1 = array->size;
  if (uVar1 < amount + array->entries) {
    uVar2 = amount + uVar1;
    __src = array->table;
    if (uVar2 < uVar1 << 1) {
      uVar2 = uVar1 << 1;
    }
    __dest = (json_t **)jsonp_malloc(uVar2 << 2);
    if (__dest == (json_t **)0x0) {
      return (json_t **)0x0;
    }
    array->size = uVar2;
    array->table = __dest;
    if (copy == 0) {
      return __src;
    }
    memcpy(__dest,__src,array->entries << 2);
    jsonp_free(__src);
  }
  return array->table;
}

