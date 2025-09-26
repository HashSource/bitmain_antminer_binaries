
undefined4 write_string(undefined4 param_1,UI_STRING *param_2)

{
  UI_string_types UVar1;
  char *__s;
  
  UVar1 = UI_get_string_type(param_2);
  if (UVar1 - UIT_INFO < 2) {
    __s = UI_get0_output_string(param_2);
    fputs(__s,tty_out);
    fflush(tty_out);
  }
  return 1;
}

