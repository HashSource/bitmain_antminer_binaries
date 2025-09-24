
char * UI_get0_result_string(UI_STRING *uis)

{
  char *pcVar1;
  
  if (*(int *)uis - 1U < 2) {
    pcVar1 = *(char **)(uis + 0xc);
  }
  else {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

