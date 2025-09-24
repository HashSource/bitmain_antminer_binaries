
char * __json_array_string(json_t *val,uint entry)

{
  size_t sVar1;
  json_t *json;
  char *pcVar2;
  uint entry_local;
  json_t *val_local;
  json_t *arr_entry;
  
  if ((val == (json_t *)0x0) || (val->type != JSON_NULL)) {
    if ((val == (json_t *)0x0) || (val->type != JSON_ARRAY)) {
      pcVar2 = (char *)0x0;
    }
    else {
      sVar1 = json_array_size(val);
      if (sVar1 < entry) {
        pcVar2 = (char *)0x0;
      }
      else {
        json = json_array_get(val,entry);
        if ((json == (json_t *)0x0) || (json->type != JSON_STRING)) {
          pcVar2 = (char *)0x0;
        }
        else {
          pcVar2 = json_string_value(json);
        }
      }
    }
  }
  else {
    pcVar2 = (char *)0x0;
  }
  return pcVar2;
}

