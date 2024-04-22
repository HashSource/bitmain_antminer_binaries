
void from_locale(char *buffer)

{
  lconv *plVar1;
  char *pcVar2;
  char *buffer_local;
  char *pos;
  char *point;
  
  plVar1 = localeconv();
  if (*plVar1->decimal_point != 0x2e) {
    pcVar2 = strchr(buffer,(uint)(byte)*plVar1->decimal_point);
    if (pcVar2 != (char *)0x0) {
      *pcVar2 = '.';
    }
  }
  return;
}

