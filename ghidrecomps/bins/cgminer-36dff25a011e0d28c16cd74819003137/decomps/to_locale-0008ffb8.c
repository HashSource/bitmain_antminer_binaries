
void to_locale(strbuffer_t *strbuffer)

{
  lconv *plVar1;
  char *pcVar2;
  char *pcVar3;
  strbuffer_t *strbuffer_local;
  char *pos;
  char *point;
  
  plVar1 = localeconv();
  pcVar3 = plVar1->decimal_point;
  if (*pcVar3 != '.') {
    pcVar2 = strchr(strbuffer->value,0x2e);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = *pcVar3;
    }
  }
  return;
}

