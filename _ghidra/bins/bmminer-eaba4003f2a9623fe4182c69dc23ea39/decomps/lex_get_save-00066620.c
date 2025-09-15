
int lex_get_save(lex_t *lex,json_error_t *error)

{
  int c_00;
  json_error_t *error_local;
  lex_t *lex_local;
  int c;
  
  c_00 = stream_get(&lex->stream,error);
  if ((c_00 != -1) && (c_00 != -2)) {
    lex_save(lex,c_00);
  }
  return c_00;
}

