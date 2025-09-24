
char * UI_get0_output_string(UI_STRING *uis)

{
  return *(char **)(uis + 4);
}

