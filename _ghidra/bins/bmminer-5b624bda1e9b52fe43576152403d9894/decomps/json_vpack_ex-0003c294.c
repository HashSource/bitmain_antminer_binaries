
/* WARNING: Unknown calling convention */

json_t * json_vpack_ex(json_error_t *error,size_t flags,char *fmt,va_list ap)

{
  json_t *json;
  size_t sVar1;
  va_list ap_copy;
  scanner_t s;
  
  if ((fmt == (char *)0x0) || (*fmt == '\0')) {
    jsonp_error_init(error,"<format>");
    json = (json_t *)0x0;
    jsonp_error_set(error,-1,-1,0,"NULL or empty format string");
  }
  else {
    jsonp_error_init(error,(char *)0x0);
    s.prev_token.line = 0;
    s.prev_token.column = 0;
    s.prev_token.pos = 0;
    s.prev_token.token = '\0';
    s.prev_token._13_3_ = 0;
    s.token.line = 0;
    s.token.column = 0;
    s.token.pos = 0;
    s.token.token = '\0';
    s.token._13_3_ = 0;
    s.next_token.line = 0;
    s.next_token.column = 0;
    s.next_token.pos = 0;
    s.next_token.token = '\0';
    s.next_token._13_3_ = 0;
    s.column = 0;
    s.pos = 0;
    s.line = 1;
    s.start = fmt;
    s.fmt = fmt;
    s.error = error;
    s.flags = flags;
    next_token(&s);
    ap_copy = ap;
    json = pack(&s,&ap_copy);
    if ((json != (json_t *)0x0) && (next_token(&s), s.token.token != '\0')) {
      if ((json->refcount != 0xffffffff) &&
         (sVar1 = json->refcount - 1, json->refcount = sVar1, sVar1 == 0)) {
        json_delete(json);
      }
      json = (json_t *)0x0;
      set_error(&s,"<format>","Garbage after format string");
    }
  }
  return json;
}

