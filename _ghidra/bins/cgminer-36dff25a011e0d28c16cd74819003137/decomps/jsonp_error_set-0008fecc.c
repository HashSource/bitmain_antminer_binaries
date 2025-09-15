
void jsonp_error_set(json_error_t *error,int line,int column,size_t position,char *msg,...)

{
  size_t position_local;
  int column_local;
  int line_local;
  json_error_t *error_local;
  va_list ap;
  
  jsonp_error_vset(error,line,column,position,msg,(va_list)&stack0x00000004);
  return;
}

