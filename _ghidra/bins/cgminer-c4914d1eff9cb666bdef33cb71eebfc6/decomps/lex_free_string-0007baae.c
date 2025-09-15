
void lex_free_string(lex_t *lex)

{
  lex_t *lex_local;
  
  jsonp_free((lex->value).string.val);
  (lex->value).string.val = (char *)0x0;
  (lex->value).string.len = 0;
  return;
}

