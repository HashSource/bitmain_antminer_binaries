
void set_error(scanner_t *s,char *source,char *fmt,...)

{
  va_list unaff_r4;
  va_list ap;
  char *fmt_local;
  
  jsonp_error_vset(s->error,(s->token).line,(s->token).column,(s->token).pos,fmt,unaff_r4);
  jsonp_error_set_source(s->error,source);
  return;
}

