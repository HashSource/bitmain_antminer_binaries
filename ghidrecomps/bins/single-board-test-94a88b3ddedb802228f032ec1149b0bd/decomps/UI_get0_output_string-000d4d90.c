
char * UI_get0_output_string(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    uis = *(UI_STRING **)(uis + 4);
  }
  return (char *)uis;
}

