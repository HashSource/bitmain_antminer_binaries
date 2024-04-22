
void lex_save_cached(lex_t *lex)

{
  lex_t *lex_local;
  
  while ((lex->stream).buffer[(lex->stream).buffer_pos] != '\0') {
    lex_save(lex,(uint)(byte)(lex->stream).buffer[(lex->stream).buffer_pos]);
    (lex->stream).buffer_pos = (lex->stream).buffer_pos + 1;
    (lex->stream).position = (lex->stream).position + 1;
  }
  return;
}

