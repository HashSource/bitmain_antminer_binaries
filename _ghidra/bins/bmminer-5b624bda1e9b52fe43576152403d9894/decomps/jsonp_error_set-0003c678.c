
/* WARNING: Unknown calling convention */

void jsonp_error_set(json_error_t *error,int line,int column,size_t position,char *msg,...)

{
  va_list unaff_r4;
  va_list ap;
  
  jsonp_error_vset(error,line,column,position,msg,unaff_r4);
  return;
}

