
void lex_close(lex_t *lex)

{
  lex_t *lex_local;
  
  if (lex->token == 0x100) {
    lex_free_string(lex);
  }
  strbuffer_close(&lex->saved_text);
  return;
}

