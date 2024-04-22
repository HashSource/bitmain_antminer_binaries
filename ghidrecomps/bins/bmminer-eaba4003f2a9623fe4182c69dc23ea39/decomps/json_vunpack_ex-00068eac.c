
int json_vunpack_ex(json_t *root,json_error_t *error,size_t flags,char *fmt,va_list ap)

{
  int iVar1;
  char *fmt_local;
  size_t flags_local;
  json_error_t *error_local;
  json_t *root_local;
  va_list ap_copy;
  scanner_t s;
  
  if (root == (json_t *)0x0) {
    jsonp_error_init(error,"<root>");
    jsonp_error_set(error,-1,-1,0,"NULL root value");
    iVar1 = -1;
  }
  else if ((fmt == (char *)0x0) || (*fmt == '\0')) {
    jsonp_error_init(error,"<format>");
    jsonp_error_set(error,-1,-1,0,"NULL or empty format string");
    iVar1 = -1;
  }
  else {
    jsonp_error_init(error,(char *)0x0);
    scanner_init(&s,error,flags,fmt);
    next_token(&s);
    ap_copy = ap;
    iVar1 = unpack(&s,root,&ap_copy);
    if (iVar1 == 0) {
      next_token(&s);
      if (s.token.token == '\0') {
        iVar1 = 0;
      }
      else {
        set_error(&s,"<format>","Garbage after format string");
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}

