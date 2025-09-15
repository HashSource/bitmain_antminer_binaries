
void json_decref(json_t *json)

{
  json_t *json_local;
  
  if (((json != (json_t *)0x0) && (json->refcount != 0xffffffff)) &&
     (json->refcount = json->refcount - 1, json->refcount == 0)) {
    json_delete(json);
  }
  return;
}

