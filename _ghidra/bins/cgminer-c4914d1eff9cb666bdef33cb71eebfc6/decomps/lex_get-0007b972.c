
int lex_get(lex_t *lex,json_error_t *error)

{
  int iVar1;
  json_error_t *error_local;
  lex_t *lex_local;
  
  iVar1 = stream_get(&lex->stream,error);
  return iVar1;
}

