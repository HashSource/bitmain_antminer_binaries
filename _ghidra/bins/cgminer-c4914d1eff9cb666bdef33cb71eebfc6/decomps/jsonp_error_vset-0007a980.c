
void jsonp_error_vset(json_error_t *error,int line,int column,size_t position,char *msg,va_list ap)

{
  size_t position_local;
  int column_local;
  int line_local;
  json_error_t *error_local;
  
  if ((error != (json_error_t *)0x0) && (error->text[0] == '\0')) {
    error->line = line;
    error->column = column;
    error->position = position;
    vsnprintf(error->text,0xa0,msg,ap.__ap);
    error->text[0x9f] = '\0';
  }
  return;
}

