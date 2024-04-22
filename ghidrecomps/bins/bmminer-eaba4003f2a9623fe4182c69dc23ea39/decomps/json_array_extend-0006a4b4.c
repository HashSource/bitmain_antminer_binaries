
int json_array_extend(json_t *json,json_t *other_json)

{
  json_t **ppjVar1;
  int iVar2;
  json_t *other_json_local;
  json_t *json_local;
  json_array_t *other;
  json_array_t *array;
  size_t i;
  
  if ((((json == (json_t *)0x0) || (json->type != JSON_ARRAY)) || (other_json == (json_t *)0x0)) ||
     (other_json->type != JSON_ARRAY)) {
    iVar2 = -1;
  }
  else {
    ppjVar1 = json_array_grow((json_array_t *)json,other_json[1].refcount,1);
    if (ppjVar1 == (json_t **)0x0) {
      iVar2 = -1;
    }
    else {
      for (i = 0; i < other_json[1].refcount; i = i + 1) {
        json_incref(*(json_t **)(other_json[2].type + i * 4));
      }
      array_copy((json_t **)json[2].type,json[1].refcount,(json_t **)other_json[2].type,0,
                 other_json[1].refcount);
      json[1].refcount = json[1].refcount + other_json[1].refcount;
      iVar2 = 0;
    }
  }
  return iVar2;
}

