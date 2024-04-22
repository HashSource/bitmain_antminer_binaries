
void from_locale(char *param_1)

{
  lconv *plVar1;
  char *pcVar2;
  
  plVar1 = localeconv();
  if (*plVar1->decimal_point != 0x2e) {
    pcVar2 = strchr(param_1,(uint)(byte)*plVar1->decimal_point);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '.';
    }
  }
  return;
}

