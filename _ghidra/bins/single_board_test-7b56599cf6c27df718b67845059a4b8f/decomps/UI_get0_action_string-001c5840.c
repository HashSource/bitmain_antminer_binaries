
char * UI_get0_action_string(UI_STRING *uis)

{
  char *pcVar1;
  
  if (*(int *)uis == 3) {
    pcVar1 = *(char **)(uis + 0x14);
  }
  else {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}

