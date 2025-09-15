
void set_error(scanner_t *s,char *source,char *fmt,...)

{
  undefined4 in_r3;
  char *source_local;
  scanner_t *s_local;
  va_list ap;
  char *fmt_local;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  jsonp_error_vset(s->error,(s->token).line,(s->token).column,(s->token).pos,fmt,(va_list)&uStack_4)
  ;
  jsonp_error_set_source(s->error,source);
  return;
}

