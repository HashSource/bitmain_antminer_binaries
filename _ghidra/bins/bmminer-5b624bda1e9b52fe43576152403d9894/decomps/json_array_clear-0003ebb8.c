
/* WARNING: Unknown calling convention */

int json_array_clear(json_t *json)

{
  json_t *json_00;
  uint uVar1;
  size_t sVar2;
  uint uVar3;
  
  if ((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) {
    uVar1 = json[1].refcount;
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        json_00 = *(json_t **)(json[2].type + uVar3 * 4);
        uVar3 = uVar3 + 1;
        if (((json_00 != (json_t *)0x0) &&
            (sVar2 = json_00->refcount - 1, json_00->refcount != 0xffffffff)) &&
           (json_00->refcount = sVar2, sVar2 == 0)) {
          json_delete(json_00);
          uVar1 = json[1].refcount;
        }
      } while (uVar3 < uVar1);
    }
    json[1].refcount = 0;
    return 0;
  }
  return -1;
}

