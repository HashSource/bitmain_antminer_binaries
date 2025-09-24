
/* WARNING: Variable defined which should be unmapped: ap */

void error_set(json_error_t *error,lex_t *lex,json_error_code code,char *msg,...)

{
  char *pcVar1;
  char *pcVar2;
  int column;
  size_t position;
  int line;
  va_list ap;
  char msg_text [160];
  char msg_with_context [160];
  char *msg_local;
  
  if (error != (json_error_t *)0x0) {
    vsnprintf(msg_text,0xa0,msg,&stack0x00000000);
    msg_text[0x9f] = '\0';
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
        if (code == json_error_invalid_syntax) {
          code = json_error_premature_end_of_input;
        }
        pcVar2 = msg_text;
        if ((lex->stream).state != -2) {
          snprintf(msg_with_context,0xa0,"%s near end of file");
          pcVar2 = msg_with_context;
          msg_with_context[0x9f] = '\0';
        }
      }
      else {
        pcVar2 = msg_text;
        if ((lex->saved_text).length < 0x15) {
          snprintf(msg_with_context,0xa0,"%s near \'%s\'",msg_text,pcVar1);
          pcVar2 = msg_with_context;
          msg_with_context[0x9f] = '\0';
        }
      }
    }
    jsonp_error_set(error,line,column,position,code,"%s",pcVar2);
  }
  return;
}

