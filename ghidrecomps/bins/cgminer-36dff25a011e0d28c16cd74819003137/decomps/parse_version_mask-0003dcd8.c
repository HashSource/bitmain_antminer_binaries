
_Bool parse_version_mask(pool *pool,json_t *val)

{
  json_t *json;
  char *mask_00;
  json_t *val_local;
  pool *pool_local;
  char *mask;
  
  json = json_array_get(val,0);
  mask_00 = json_string_value(json);
  process_version_mask(pool,mask_00);
  return true;
}

