
/* WARNING: Unknown calling convention */

void json_delete(json_t *json)

{
  json_t *json_00;
  json_type jVar1;
  size_t sVar2;
  uint uVar3;
  json_t *local_1c;
  json_t *local_18;
  json_t *local_14;
  json_t *local_10;
  json_t *local_c;
  
  if (json != (json_t *)0x0) {
    jVar1 = json->type;
    if (jVar1 == JSON_OBJECT) {
      local_14 = json;
      hashtable_close((hashtable_t *)(json + 1));
      _jsonp_free(&local_14);
    }
    else if (jVar1 == JSON_ARRAY) {
      local_10 = json;
      if (json[1].refcount != 0) {
        uVar3 = 0;
        do {
          json_00 = *(json_t **)(local_10[2].type + uVar3 * 4);
          uVar3 = uVar3 + 1;
          if (((json_00 != (json_t *)0x0) &&
              (sVar2 = json_00->refcount - 1, json_00->refcount != 0xffffffff)) &&
             (json_00->refcount = sVar2, sVar2 == 0)) {
            json_delete(json_00);
          }
        } while (uVar3 < local_10[1].refcount);
      }
      _jsonp_free((void **)(local_10 + 2));
      _jsonp_free(&local_10);
    }
    else if (jVar1 == JSON_STRING) {
      local_c = json;
      _jsonp_free((void **)(json + 1));
      _jsonp_free(&local_c);
    }
    else if (jVar1 == JSON_INTEGER) {
      local_1c = json;
      _jsonp_free(&local_1c);
    }
    else if (jVar1 == JSON_REAL) {
      local_18 = json;
      _jsonp_free(&local_18);
    }
  }
  return;
}

