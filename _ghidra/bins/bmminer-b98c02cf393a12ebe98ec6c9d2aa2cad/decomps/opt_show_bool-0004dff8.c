
void opt_show_bool(char *param_1,char *param_2)

{
  char *__src;
  
  __src = "true";
  if (*param_2 == '\0') {
    __src = "false";
  }
  strncpy(param_1,__src,0x50);
  return;
}

