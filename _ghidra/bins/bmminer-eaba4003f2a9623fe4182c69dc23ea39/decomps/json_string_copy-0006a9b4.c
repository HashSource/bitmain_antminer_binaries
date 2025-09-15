
json_t * json_string_copy(json_t *string)

{
  json_t *pjVar1;
  json_t *string_local;
  json_string_t *s;
  
  if ((string == (json_t *)0x0) || (string->type != JSON_STRING)) {
    pjVar1 = (json_t *)0x0;
  }
  else {
    pjVar1 = json_stringn_nocheck((char *)string[1].type,string[1].refcount);
  }
  return pjVar1;
}

