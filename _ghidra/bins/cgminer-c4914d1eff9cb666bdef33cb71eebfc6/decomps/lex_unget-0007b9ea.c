
void lex_unget(lex_t *lex,int c)

{
  int c_local;
  lex_t *lex_local;
  
  stream_unget(&lex->stream,c);
  return;
}

