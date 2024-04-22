
int json_array_remove(json_t *json,size_t index)

{
  int iVar1;
  size_t index_local;
  json_t *json_local;
  json_array_t *array;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) {
    iVar1 = -1;
  }
  else if (index < json[1].refcount) {
    json_decref(*(json_t **)(json[2].type + index * 4));
    if (index < json[1].refcount - 1) {
      array_move((json_array_t *)json,index,index + 1,(json[1].refcount - index) - 1);
    }
    json[1].refcount = json[1].refcount - 1;
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

