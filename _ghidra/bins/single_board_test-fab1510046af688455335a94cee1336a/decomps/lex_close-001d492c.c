
/* WARNING: Unknown calling convention */

void lex_close(lex_t *lex)

{
  if (lex->token == 0x100) {
    jsonp_free((lex->value).string.val);
    (lex->value).string.val = (char *)0x0;
    (lex->value).string.len = 0;
  }
  strbuffer_close(&lex->saved_text);
  return;
}

