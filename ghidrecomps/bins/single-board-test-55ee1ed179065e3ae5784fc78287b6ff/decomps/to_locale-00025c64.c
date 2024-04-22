
void to_locale(char **param_1)

{
  lconv *plVar1;
  char *pcVar2;
  char *pcVar3;
  
  plVar1 = localeconv();
  pcVar3 = plVar1->decimal_point;
  if (*pcVar3 != '.') {
    pcVar2 = strchr(*param_1,0x2e);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = *pcVar3;
    }
  }
  return;
}

