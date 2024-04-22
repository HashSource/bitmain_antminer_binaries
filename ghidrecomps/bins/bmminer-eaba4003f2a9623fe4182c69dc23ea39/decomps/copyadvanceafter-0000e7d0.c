
void copyadvanceafter(char ch,char **param,char **buf)

{
  char *pcVar1;
  char *pcVar2;
  char **buf_local;
  char **param_local;
  char ch_local;
  
  while ((**param != '\0' && (ch != **param))) {
    if ((**param == '\\') && ((*param)[1] != '\0')) {
      *param = *param + 1;
    }
    pcVar2 = *buf;
    pcVar1 = *param;
    *pcVar2 = *pcVar1;
    *buf = pcVar2 + 1;
    *param = pcVar1 + 1;
  }
  if (**param != '\0') {
    *param = *param + 1;
  }
  pcVar2 = *buf;
  *pcVar2 = '\0';
  *buf = pcVar2 + 1;
  return;
}

