
void scanner_init(scanner_t *s,json_error_t *error,size_t flags,char *fmt)

{
  char *fmt_local;
  size_t flags_local;
  json_error_t *error_local;
  scanner_t *s_local;
  
  s->error = error;
  s->flags = flags;
  s->start = fmt;
  s->fmt = s->start;
  memset(&s->prev_token,0,0x10);
  memset(&s->token,0,0x10);
  memset(&s->next_token,0,0x10);
  s->line = 1;
  s->column = 0;
  s->pos = 0;
  return;
}

