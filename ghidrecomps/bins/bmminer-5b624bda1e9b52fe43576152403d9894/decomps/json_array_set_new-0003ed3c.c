
/* WARNING: Unknown calling convention */

int json_array_set_new(json_t *json,size_t index,json_t *value)

{
  json_array_t *array;
  json_t *json_00;
  size_t sVar1;
  json_t **ppjVar2;
  
  if (value != (json_t *)0x0) {
    if ((((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) && (json != value)) &&
       (index < json[1].refcount)) {
      json_00 = *(json_t **)(json[2].type + index * 4);
      ppjVar2 = (json_t **)(json[2].type + index * 4);
      if (((json_00 != (json_t *)0x0) && (json_00->refcount != 0xffffffff)) &&
         (sVar1 = json_00->refcount - 1, json_00->refcount = sVar1, sVar1 == 0)) {
        json_delete(json_00);
        ppjVar2 = (json_t **)(json[2].type + index * 4);
      }
      *ppjVar2 = value;
      return 0;
    }
    if ((value->refcount != 0xffffffff) &&
       (sVar1 = value->refcount - 1, value->refcount = sVar1, sVar1 == 0)) {
      json_delete(value);
    }
  }
  return -1;
}

