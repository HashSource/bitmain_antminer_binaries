
int json_array_insert_new(json_t *json,size_t index,json_t *value)

{
  json_t **src;
  int iVar1;
  json_t *value_local;
  size_t index_local;
  json_t *json_local;
  json_t **old_table;
  json_array_t *array;
  
  if (value == (json_t *)0x0) {
    iVar1 = -1;
  }
  else if (((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (json == value)) {
    json_decref(value);
    iVar1 = -1;
  }
  else if (json[1].refcount < index) {
    json_decref(value);
    iVar1 = -1;
  }
  else {
    src = json_array_grow((json_array_t *)json,1,0);
    if (src == (json_t **)0x0) {
      json_decref(value);
      iVar1 = -1;
    }
    else {
      if ((json_t **)json[2].type == src) {
        array_move((json_array_t *)json,index + 1,index,json[1].refcount - index);
      }
      else {
        array_copy((json_t **)json[2].type,0,src,0,index);
        array_copy((json_t **)json[2].type,index + 1,src,index,json[1].refcount - index);
        jsonp_free(src);
      }
      *(json_t **)(json[2].type + index * 4) = value;
      json[1].refcount = json[1].refcount + 1;
      iVar1 = 0;
    }
  }
  return iVar1;
}

