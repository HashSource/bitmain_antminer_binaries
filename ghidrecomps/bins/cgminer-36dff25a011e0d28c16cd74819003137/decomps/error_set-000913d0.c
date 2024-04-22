
void error_set(json_error_t *error,lex_t *lex,char *msg,...)

{
  char *pcVar1;
  undefined4 in_r3;
  lex_t *lex_local;
  json_error_t *error_local;
  char msg_with_context [160];
  char msg_text [160];
  va_list ap;
  char *saved_text;
  char *result;
  size_t pos;
  int col;
  int line;
  char *msg_local;
  undefined4 uStack_4;
  
  line = -1;
  col = -1;
  pos = 0;
  result = msg_text;
  if (error != (json_error_t *)0x0) {
    uStack_4 = in_r3;
    vsnprintf(msg_text,0xa0,msg,&uStack_4);
    msg_text[159] = '\0';
    if (lex != (lex_t *)0x0) {
      pcVar1 = strbuffer_value(&lex->saved_text);
      line = (lex->stream).line;
      col = (lex->stream).column;
      pos = (lex->stream).position;
      if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
        if ((lex->stream).state == -2) {
          result = msg_text;
        }
        else {
          snprintf(msg_with_context,0xa0,"%s near end of file",msg_text);
          msg_with_context[159] = '\0';
          result = msg_with_context;
        }
      }
      else if ((lex->saved_text).length < 0x15) {
        snprintf(msg_with_context,0xa0,"%s near \'%s\'",msg_text,pcVar1);
        msg_with_context[159] = '\0';
        result = msg_with_context;
      }
    }
    jsonp_error_set(error,line,col,pos,"%s",result);
  }
  return;
}

