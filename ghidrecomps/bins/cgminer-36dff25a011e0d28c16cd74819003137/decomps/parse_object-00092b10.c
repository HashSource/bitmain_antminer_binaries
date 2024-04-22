
json_t * parse_object(lex_t *lex,size_t flags,json_error_t *error)

{
  void *pvVar1;
  json_t *pjVar2;
  int iVar3;
  json_error_t *error_local;
  size_t flags_local;
  lex_t *lex_local;
  size_t len;
  json_t *value;
  char *key;
  json_t *object;
  
  object = json_object();
  if (object == (json_t *)0x0) {
    object = (json_t *)0x0;
  }
  else {
    lex_scan(lex,error);
    if (lex->token != 0x7d) {
      while (lex->token == 0x100) {
        key = lex_steal_string(lex,&len);
        if (key == (char *)0x0) {
          return (json_t *)0x0;
        }
        pvVar1 = rpl_memchr(key,0,len);
        if (pvVar1 != (void *)0x0) {
          jsonp_free(key);
          error_set(error,lex,"NUL byte in object key not supported");
          goto error;
        }
        if (((flags & 1) != 0) && (pjVar2 = json_object_get(object,key), pjVar2 != (json_t *)0x0)) {
          jsonp_free(key);
          error_set(error,lex,"duplicate object key");
          goto error;
        }
        lex_scan(lex,error);
        if (lex->token != 0x3a) {
          jsonp_free(key);
          error_set(error,lex,"\':\' expected");
          goto error;
        }
        lex_scan(lex,error);
        value = parse_value(lex,flags,error);
        if (value == (json_t *)0x0) {
          jsonp_free(key);
          goto error;
        }
        iVar3 = json_object_set_nocheck(object,key,value);
        if (iVar3 != 0) {
          jsonp_free(key);
          json_decref(value);
          goto error;
        }
        json_decref(value);
        jsonp_free(key);
        lex_scan(lex,error);
        if (lex->token != 0x2c) {
          if (lex->token == 0x7d) {
            return object;
          }
          error_set(error,lex,"\'}\' expected");
          goto error;
        }
        lex_scan(lex,error);
      }
      error_set(error,lex,"string or \'}\' expected");
error:
      json_decref(object);
      object = (json_t *)0x0;
    }
  }
  return object;
}

