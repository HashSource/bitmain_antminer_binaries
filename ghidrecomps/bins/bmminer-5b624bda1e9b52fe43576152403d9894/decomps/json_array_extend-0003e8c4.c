
/* WARNING: Unknown calling convention */

int json_array_extend(json_t *json,json_t *other_json)

{
  json_array_t *array;
  json_t **ppjVar1;
  json_array_t *other;
  int *__src;
  size_t sVar2;
  size_t __n;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  if ((((json != (json_t *)0x0) && (json->type == JSON_ARRAY)) && (other_json != (json_t *)0x0)) &&
     ((other_json->type == JSON_ARRAY &&
      (other = (json_array_t *)other_json[1].refcount,
      ppjVar1 = json_array_grow((json_array_t *)json,(size_t)other,1), ppjVar1 != (json_t **)0x0))))
  {
    sVar2 = other_json[1].refcount;
    __src = (int *)other_json[2].type;
    __n = sVar2;
    if (sVar2 != 0) {
      __n = sVar2 * 4;
      piVar4 = __src;
      do {
        piVar5 = piVar4 + 1;
        iVar3 = *piVar4;
        if (iVar3 != 0) {
          if (*(int *)(iVar3 + 4) != -1) {
            *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
          }
        }
        piVar4 = piVar5;
      } while (piVar5 != __src + sVar2);
    }
    memcpy((void *)(json[2].type + json[1].refcount * 4),__src,__n);
    json[1].refcount = json[1].refcount + other_json[1].refcount;
    return 0;
  }
  return -1;
}

