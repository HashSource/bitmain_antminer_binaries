
/* WARNING: Unknown calling convention */

json_t * json_array(void)

{
  json_t *json;
  void *pvVar1;
  json_array_t *array;
  
  json = (json_t *)jsonp_malloc(0x18);
  if (json == (json_t *)0x0) {
    json = (json_t *)0x0;
  }
  else {
    json_init(json,JSON_ARRAY);
    json[1].refcount = 0;
    json[1].type = 8;
    pvVar1 = jsonp_malloc(json[1].type << 2);
    json[2].type = (json_type)pvVar1;
    if (json[2].type == JSON_OBJECT) {
      jsonp_free(json);
      json = (json_t *)0x0;
    }
    else {
      json[2].refcount = 0;
    }
  }
  return json;
}

