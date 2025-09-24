
int UI_get_input_flags(UI_STRING *uis)

{
  return *(int *)(uis + 8);
}

