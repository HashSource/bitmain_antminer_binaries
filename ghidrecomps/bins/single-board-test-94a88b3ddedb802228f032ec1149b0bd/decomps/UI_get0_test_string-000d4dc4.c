
char * UI_get0_test_string(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    if (*(int *)uis == 2) {
      return *(char **)(uis + 0x18);
    }
    uis = (UI_STRING *)0x0;
  }
  return (char *)uis;
}

