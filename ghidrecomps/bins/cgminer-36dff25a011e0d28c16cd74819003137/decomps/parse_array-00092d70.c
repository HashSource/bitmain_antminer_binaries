
json_t * parse_array(lex_t *lex,size_t flags,json_error_t *error)

{
  json_t *array_00;
  json_t *value;
  int iVar1;
  json_error_t *error_local;
  size_t flags_local;
  lex_t *lex_local;
  json_t *elem;
  json_t *array;
  
  array_00 = json_array();
  if (array_00 == (json_t *)0x0) {
    array_00 = (json_t *)0x0;
  }
  else {
    lex_scan(lex,error);
    if (lex->token != 0x5d) {
      while (lex->token != 0) {
        value = parse_value(lex,flags,error);
        if (value == (json_t *)0x0) goto error;
        iVar1 = json_array_append(array_00,value);
        if (iVar1 != 0) {
          json_decref(value);
          goto error;
        }
        json_decref(value);
        lex_scan(lex,error);
        if (lex->token != 0x2c) break;
        lex_scan(lex,error);
      }
      if (lex->token != 0x5d) {
        error_set(error,lex,"\']\' expected");
error:
        json_decref(array_00);
        array_00 = (json_t *)0x0;
      }
    }
  }
  return array_00;
}

