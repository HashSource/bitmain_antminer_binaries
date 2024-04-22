
char * lex_steal_string(lex_t *lex,size_t *out_len)

{
  size_t *out_len_local;
  lex_t *lex_local;
  char *result;
  
  result = (char *)0x0;
  if (lex->token == 0x100) {
    result = (lex->value).string.val;
    *out_len = (lex->value).string.len;
    (lex->value).string.val = (char *)0x0;
    (lex->value).string.len = 0;
  }
  return result;
}

