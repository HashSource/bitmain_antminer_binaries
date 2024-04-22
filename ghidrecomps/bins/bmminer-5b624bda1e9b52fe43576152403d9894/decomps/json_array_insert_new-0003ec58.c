
/* WARNING: Unknown calling convention */

int json_array_insert_new(json_t *json,size_t index,json_t *value)

{
  json_array_t *array;
  json_t **old_table;
  size_t sVar1;
  json_t **local_1c;
  
  if (value != (json_t *)0x0) {
    if ((((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) && (json != value)) &&
       ((index <= json[1].refcount &&
        (local_1c = json_array_grow((json_array_t *)json,1,0), local_1c != (json_t **)0x0)))) {
      if (local_1c == (json_t **)json[2].type) {
        memmove(local_1c + index + 1,local_1c + index,(json[1].refcount - index) * 4);
      }
      else {
        memcpy((json_t **)json[2].type,local_1c,index * 4);
        memcpy((void *)(json[2].type + (index + 1) * 4),local_1c + index,
               (json[1].refcount - index) * 4);
        _jsonp_free(&local_1c);
      }
      sVar1 = json[1].refcount;
      *(json_t **)(json[2].type + index * 4) = value;
      json[1].refcount = sVar1 + 1;
      return 0;
    }
    if ((value->refcount != 0xffffffff) &&
       (sVar1 = value->refcount - 1, value->refcount = sVar1, sVar1 == 0)) {
      json_delete(value);
    }
  }
  return -1;
}

