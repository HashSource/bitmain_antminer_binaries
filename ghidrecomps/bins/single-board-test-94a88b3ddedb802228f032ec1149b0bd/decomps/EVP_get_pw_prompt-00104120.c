
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * EVP_get_pw_prompt(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_00104130;
  if (*DAT_00104130 == '\0') {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

