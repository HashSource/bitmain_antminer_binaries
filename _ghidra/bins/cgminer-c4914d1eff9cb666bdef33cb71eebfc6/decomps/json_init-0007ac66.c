
void json_init(json_t *json,json_type type)

{
  json_type type_local;
  json_t *json_local;
  
  json->type = type;
  json->refcount = 1;
  return;
}

