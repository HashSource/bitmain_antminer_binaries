
char * UI_get0_result_string(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    if (*(int *)uis - 1U < 2) {
      return *(char **)(uis + 0xc);
    }
    uis = (UI_STRING *)0x0;
  }
  return (char *)uis;
}

