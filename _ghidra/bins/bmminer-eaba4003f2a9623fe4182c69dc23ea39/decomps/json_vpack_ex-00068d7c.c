
json_t * json_vpack_ex(json_error_t *error,size_t flags,char *fmt,va_list ap)

{
  json_t *json;
  va_list ap_local;
  char *fmt_local;
  size_t flags_local;
  json_error_t *error_local;
  va_list ap_copy;
  scanner_t s;
  json_t *value;
  
  if ((fmt == (char *)0x0) || (*fmt == '\0')) {
    jsonp_error_init(error,"<format>");
    jsonp_error_set(error,-1,-1,0,"NULL or empty format string");
    json = (json_t *)0x0;
  }
  else {
    jsonp_error_init(error,(char *)0x0);
    scanner_init(&s,error,flags,fmt);
    next_token(&s);
    ap_copy = ap;
    json = pack(&s,&ap_copy);
    if (json == (json_t *)0x0) {
      json = (json_t *)0x0;
    }
    else {
      next_token(&s);
      if (s.token.token != '\0') {
        json_decref(json);
        set_error(&s,"<format>","Garbage after format string");
        json = (json_t *)0x0;
      }
    }
  }
  return json;
}

