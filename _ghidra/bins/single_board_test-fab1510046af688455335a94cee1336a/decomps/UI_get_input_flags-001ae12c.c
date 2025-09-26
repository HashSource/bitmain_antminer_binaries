
int UI_get_input_flags(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    uis = *(UI_STRING **)(uis + 8);
  }
  return (int)uis;
}

