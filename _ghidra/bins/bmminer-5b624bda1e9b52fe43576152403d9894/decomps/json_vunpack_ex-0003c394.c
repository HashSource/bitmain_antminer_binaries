
/* WARNING: Unknown calling convention */

int json_vunpack_ex(json_t *root,json_error_t *error,size_t flags,char *fmt,va_list ap)

{
  int iVar1;
  void *in_stack_00000000;
  va_list ap_copy;
  scanner_t s;
  
  if (root == (json_t *)0x0) {
    jsonp_error_init(error,"<root>");
    jsonp_error_set(error,-1,-1,0,"NULL root value");
  }
  else if ((fmt == (char *)0x0) || (*fmt == '\0')) {
    jsonp_error_init(error,"<format>");
    jsonp_error_set(error,-1,-1,0,"NULL or empty format string");
  }
  else {
    jsonp_error_init(error,(char *)0x0);
    s.line = 1;
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
    s.start = fmt;
    s.fmt = fmt;
    s.error = error;
    s.flags = flags;
    next_token(&s);
    ap_copy.__ap = in_stack_00000000;
    iVar1 = unpack(&s,root,&ap_copy);
    if (iVar1 == 0) {
      next_token(&s);
      if ((s.token._12_4_ & 0xff) == 0) {
        return 0;
      }
      set_error(&s,"<format>","Garbage after format string");
    }
  }
  return -1;
}

