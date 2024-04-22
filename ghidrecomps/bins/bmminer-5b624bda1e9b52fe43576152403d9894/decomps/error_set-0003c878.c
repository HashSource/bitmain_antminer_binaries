
void error_set(json_error_t *error,lex_t *lex,char *msg,...)

{
  char *pcVar1;
  char *saved_text;
  undefined4 in_r3;
  char *pcVar2;
  int column;
  size_t position;
  int line;
  va_list ap;
  char msg_text [160];
  char msg_with_context [160];
  char *msg_local;
  undefined4 uStack_4;
  
  if (error != (json_error_t *)0x0) {
    uStack_4 = in_r3;
    vsnprintf(msg_text,0xa0,msg,&uStack_4);
    msg_text[159] = '\0';
    if (lex == (lex_t *)0x0) {
      column = -1;
      line = -1;
      pcVar2 = msg_text;
      position = 0;
    }
    else {
      pcVar1 = strbuffer_value(&lex->saved_text);
      line = (lex->stream).line;
      column = (lex->stream).column;
      position = (lex->stream).position;
      if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
        pcVar2 = msg_text;
        if ((lex->stream).state != -2) {
          snprintf(msg_with_context,0xa0,DAT_0003c920);
          pcVar2 = msg_with_context;
          msg_with_context[159] = '\0';
        }
      }
      else {
        pcVar2 = msg_text;
        if ((lex->saved_text).length < 0x15) {
          snprintf(msg_with_context,0xa0,DAT_0003c924,msg_text,pcVar1);
          pcVar2 = msg_with_context;
          msg_with_context[159] = '\0';
        }
      }
    }
    jsonp_error_set(error,line,column,position,DAT_0003c91c,pcVar2);
  }
  return;
}

