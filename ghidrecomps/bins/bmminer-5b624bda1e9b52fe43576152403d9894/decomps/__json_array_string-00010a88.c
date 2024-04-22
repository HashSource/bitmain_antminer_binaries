
/* WARNING: Unknown calling convention */

char * __json_array_string(json_t *val,uint entry)

{
  size_t sVar1;
  json_t *json;
  json_t *arr_entry;
  char *pcVar2;
  
  if ((((val != (json_t *)0x0) && (val->type != JSON_NULL)) && (val->type == JSON_ARRAY)) &&
     (((sVar1 = json_array_size(val), entry <= sVar1 &&
       (json = json_array_get(val,entry), json != (json_t *)0x0)) && (json->type == JSON_STRING))))
  {
    pcVar2 = json_string_value(json);
    return pcVar2;
  }
  return (char *)0x0;
}

