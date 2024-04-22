
UI_string_types UI_get_string_type(UI_STRING *uis)

{
  if (uis != (UI_STRING *)0x0) {
    uis = *(UI_STRING **)uis;
  }
  return (UI_string_types)uis;
}

