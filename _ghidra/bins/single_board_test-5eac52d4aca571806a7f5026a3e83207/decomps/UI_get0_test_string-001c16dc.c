
char * UI_get0_test_string(UI_STRING *uis)

{
  char *pcVar1;
  
  if (*(int *)uis == 2) {
    pcVar1 = *(char **)(uis + 0x1c);
  }
  else {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

