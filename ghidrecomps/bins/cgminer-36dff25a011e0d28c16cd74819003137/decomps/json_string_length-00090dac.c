
size_t json_string_length(json_t *json)

{
  size_t sVar1;
  json_t *json_local;
  
  if ((json == (json_t *)0x0) || (json->type != JSON_STRING)) {
    sVar1 = 0;
  }
  else {
    sVar1 = json[1].refcount;
  }
  return sVar1;
}

