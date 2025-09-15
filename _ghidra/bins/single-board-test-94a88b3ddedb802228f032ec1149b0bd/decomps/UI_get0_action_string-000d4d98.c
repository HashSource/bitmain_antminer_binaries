
char * UI_get0_action_string(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    if ((*(int *)uis == 1) || (*(int *)uis == 3)) {
      return *(char **)(uis + 0x10);
    }
    uis = (UI_STRING *)0x0;
  }
  return (char *)uis;
}

