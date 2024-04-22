
/* WARNING: Unknown calling convention */

json_t ** json_array_grow(json_array_t *array,size_t amount,int copy)

{
  json_t **__dest;
  json_t **new_table;
  uint uVar1;
  uint uVar2;
  size_t new_size;
  json_t **local_14;
  
  uVar1 = array->size;
  if (uVar1 < amount + array->entries) {
    local_14 = array->table;
    uVar2 = amount + uVar1;
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
      return local_14;
    }
    memcpy(__dest,local_14,array->entries << 2);
    _jsonp_free(&local_14);
  }
  return array->table;
}

