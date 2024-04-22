
/* WARNING: Unknown calling convention */

void jsonp_error_vset(json_error_t *error,int line,int column,size_t position,char *msg,va_list ap)

{
  __gnuc_va_list in_stack_00000004;
  
  if ((error != (json_error_t *)0x0) && (error->text[0] == '\0')) {
    error->line = line;
    error->column = column;
    error->position = position;
    vsnprintf(error->text,0xa0,msg,in_stack_00000004);
    error->text[0x9f] = '\0';
  }
  return;
}

