
size_t json_object_size(json_t *json)

{
  json_type jVar1;
  json_t *json_local;
  json_object_t *object;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_OBJECT)) {
    jVar1 = JSON_OBJECT;
  }
  else {
    jVar1 = json[1].type;
  }
  return jVar1;
}

