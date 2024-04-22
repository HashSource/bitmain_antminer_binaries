
/* WARNING: Unknown calling convention */

int lex_init(lex_t *lex,get_func get,void *data)

{
  int iVar1;
  
  (lex->stream).get = get;
  (lex->stream).data = data;
  (lex->stream).line = 1;
  (lex->stream).buffer[0] = '\0';
  (lex->stream).buffer_pos = 0;
  (lex->stream).state = 0;
  (lex->stream).column = 0;
  (lex->stream).position = 0;
  iVar1 = strbuffer_init(&lex->saved_text);
  if (iVar1 == 0) {
    lex->token = -1;
    return 0;
  }
  return -1;
}

