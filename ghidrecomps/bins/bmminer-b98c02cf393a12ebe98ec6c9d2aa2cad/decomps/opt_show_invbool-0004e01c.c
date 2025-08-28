
void opt_show_invbool(char *param_1,char *param_2)

{
  char *__src;
  
  __src = "false";
  if (*param_2 == '\0') {
    __src = "true";
  }
  strncpy(param_1,__src,0x50);
  return;
}

