
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * EVP_get_pw_prompt(void)

{
  char *pcVar1;
  
  if (prompt_string == '\0') {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = &prompt_string;
  }
  return pcVar1;
}

