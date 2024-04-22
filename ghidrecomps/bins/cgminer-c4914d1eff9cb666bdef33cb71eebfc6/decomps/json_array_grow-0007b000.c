
json_t ** json_array_grow(json_array_t *array,size_t amount,int copy)

{
  json_t **ppjVar1;
  uint uVar2;
  json_t **src;
  uint uVar3;
  int copy_local;
  size_t amount_local;
  json_array_t *array_local;
  json_t **new_table;
  size_t new_size;
  json_t **old_table;
  
  if (array->size < array->entries + amount) {
    src = array->table;
    uVar2 = array->size << 1;
    uVar3 = amount + array->size;
    if (uVar3 < uVar2) {
      uVar3 = uVar2;
    }
    ppjVar1 = (json_t **)jsonp_malloc(uVar3 << 2);
    if (ppjVar1 == (json_t **)0x0) {
      src = (json_t **)0x0;
    }
    else {
      array->size = uVar3;
      array->table = ppjVar1;
      if (copy != 0) {
        array_copy(array->table,0,src,0,array->entries);
        jsonp_free(src);
        src = array->table;
      }
    }
  }
  else {
    src = array->table;
  }
  return src;
}

