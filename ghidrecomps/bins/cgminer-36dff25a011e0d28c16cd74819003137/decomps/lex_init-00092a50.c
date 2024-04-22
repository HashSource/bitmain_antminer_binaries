
int lex_init(lex_t *lex,get_func get,size_t flags,void *data)

{
  int iVar1;
  void *data_local;
  size_t flags_local;
  get_func get_local;
  lex_t *lex_local;
  
  stream_init(&lex->stream,get,data);
  iVar1 = strbuffer_init(&lex->saved_text);
  if (iVar1 == 0) {
    lex->flags = flags;
    lex->token = -1;
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

