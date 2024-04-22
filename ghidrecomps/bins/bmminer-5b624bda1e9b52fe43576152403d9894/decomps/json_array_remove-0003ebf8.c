
/* WARNING: Unknown calling convention */

int json_array_remove(json_t *json,size_t index)

{
  json_array_t *array;
  json_t *json_00;
  size_t sVar1;
  size_t sVar2;
  uint uVar3;
  
  if (((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) &&
     (sVar2 = json[1].refcount, index < sVar2)) {
    json_00 = *(json_t **)(json[2].type + index * 4);
    if (((json_00 != (json_t *)0x0) && (json_00->refcount != 0xffffffff)) &&
       (sVar1 = json_00->refcount - 1, json_00->refcount = sVar1, sVar1 == 0)) {
      json_delete(json_00);
      sVar2 = json[1].refcount;
    }
    uVar3 = sVar2 - 1;
    if (index < uVar3) {
      memmove((void *)(json[2].type + index * 4),(void *)(json[2].type + (index + 1) * 4),
              (uVar3 - index) * 4);
      uVar3 = json[1].refcount - 1;
    }
    json[1].refcount = uVar3;
    return 0;
  }
  return -1;
}

