
json_t * pack_array(scanner_t *s,va_list *ap)

{
  json_t *json;
  json_t *value_00;
  int iVar1;
  va_list *ap_local;
  scanner_t *s_local;
  json_t *value;
  json_t *array;
  
  json = json_array();
  next_token(s);
  while( true ) {
    if ((s->token).token == ']') {
      return json;
    }
    if ((s->token).token == '\0') break;
    value_00 = pack(s,ap);
    if (value_00 == (json_t *)0x0) goto LAB_00067f9e;
    iVar1 = json_array_append_new(json,value_00);
    if (iVar1 != 0) {
      set_error(s,"<internal>","Unable to append to array");
      goto LAB_00067f9e;
    }
    next_token(s);
  }
  set_error(s,"<format>","Unexpected end of format string");
LAB_00067f9e:
  json_decref(json);
  return (json_t *)0x0;
}

