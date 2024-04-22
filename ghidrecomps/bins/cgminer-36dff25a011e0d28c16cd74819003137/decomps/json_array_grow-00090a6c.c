
json_t ** json_array_grow(json_array_t *array,size_t amount,int copy)

{
  uint uVar1;
  json_t **ppjVar2;
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
    uVar1 = array->size << 1;
    uVar3 = array->size + amount;
    if (uVar1 < uVar3) {
      uVar1 = uVar3;
    }
    ppjVar2 = (json_t **)jsonp_malloc(uVar1 << 2);
    if (ppjVar2 == (json_t **)0x0) {
      src = (json_t **)0x0;
    }
    else {
      array->size = uVar1;
      array->table = ppjVar2;
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

