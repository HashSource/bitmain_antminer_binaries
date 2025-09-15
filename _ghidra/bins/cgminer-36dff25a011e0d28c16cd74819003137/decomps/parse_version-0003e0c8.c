
_Bool parse_version(pool *pool,json_t *val)

{
  json_t *json;
  size_t sVar1;
  json_int_t jVar2;
  json_t *val_local;
  pool *pool_local;
  int i;
  
  for (i = 0; sVar1 = json_array_size(val), (uint)i < sVar1; i = i + 1) {
    json = json_array_get(val,i);
    jVar2 = json_integer_value(json);
    pool->version[i] = (int)jVar2;
  }
  return true;
}

