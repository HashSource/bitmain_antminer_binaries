
json_t * json_incref(json_t *json)

{
  json_t *json_local;
  
  if ((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) {
    json->refcount = json->refcount + 1;
  }
  return json;
}

