
json_t * pack_object(scanner_t *s,va_list *ap)

{
  int iVar1;
  va_list *ap_local;
  scanner_t *s_local;
  int ours;
  size_t len;
  json_t *value;
  char *key;
  json_t *object;
  
  object = json_object();
  next_token(s);
  while( true ) {
    if ((s->token).token == '}') {
      return object;
    }
    if ((s->token).token == '\0') break;
    if ((s->token).token != 's') {
      set_error(s,"<format>","Expected format \'s\', got \'%c\'",(uint)(byte)(s->token).token);
      goto error;
    }
    key = read_string(s,ap,"object key",&len,&ours);
    if (key == (char *)0x0) goto error;
    next_token(s);
    value = pack(s,ap);
    if (value == (json_t *)0x0) {
      if (ours != 0) {
        jsonp_free(key);
      }
      goto error;
    }
    iVar1 = json_object_set_new_nocheck(object,key,value);
    if (iVar1 != 0) {
      set_error(s,"<internal>","Unable to add key \"%s\"",key);
      if (ours != 0) {
        jsonp_free(key);
      }
      goto error;
    }
    if (ours != 0) {
      jsonp_free(key);
    }
    next_token(s);
  }
  set_error(s,"<format>","Unexpected end of format string");
error:
  json_decref(object);
  return (json_t *)0x0;
}

