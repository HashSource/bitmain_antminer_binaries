
char * SSL_COMP_get_name(COMP_METHOD *comp)

{
  char *pcVar1;
  
  if (comp != (COMP_METHOD *)0x0) {
    pcVar1 = (char *)COMP_get_name();
    return pcVar1;
  }
  return (char *)0x0;
}

