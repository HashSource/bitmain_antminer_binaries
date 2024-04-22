
void lex_save(lex_t *lex,int c)

{
  int c_local;
  lex_t *lex_local;
  
  strbuffer_append_byte(&lex->saved_text,(char)c);
  return;
}

