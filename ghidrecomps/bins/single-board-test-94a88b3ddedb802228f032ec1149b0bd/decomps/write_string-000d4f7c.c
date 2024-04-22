
undefined4 write_string(undefined4 param_1,UI_STRING *param_2)

{
  int iVar1;
  UI_string_types UVar2;
  char *__s;
  
  UVar2 = UI_get_string_type(param_2);
  iVar1 = DAT_000d4fa4;
  if (UVar2 + ~UIT_BOOLEAN < 2) {
    __s = UI_get0_output_string(param_2);
    fputs(__s,*(FILE **)(iVar1 + 8));
    fflush(*(FILE **)(iVar1 + 8));
  }
  return 1;
}

