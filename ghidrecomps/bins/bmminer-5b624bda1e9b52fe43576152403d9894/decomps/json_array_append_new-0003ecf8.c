
/* WARNING: Unknown calling convention */

int json_array_append_new(json_t *json,json_t *value)

{
  json_array_t *array;
  json_t **ppjVar1;
  size_t sVar2;
  
  if (value != (json_t *)0x0) {
    if ((((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) && (json != value)) &&
       (ppjVar1 = json_array_grow((json_array_t *)json,1,1), ppjVar1 != (json_t **)0x0)) {
      sVar2 = json[1].refcount;
      *(json_t **)(json[2].type + sVar2 * 4) = value;
      json[1].refcount = sVar2 + 1;
      return 0;
    }
    if ((value->refcount != 0xffffffff) &&
       (sVar2 = value->refcount - 1, value->refcount = sVar2, sVar2 == 0)) {
      json_delete(value);
    }
  }
  return -1;
}

