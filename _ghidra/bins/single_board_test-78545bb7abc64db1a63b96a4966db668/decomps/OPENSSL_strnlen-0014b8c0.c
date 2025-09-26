
int OPENSSL_strnlen(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  if (*param_1 == '\0') {
    return 0;
  }
  pcVar1 = param_1 + 1;
  do {
    pcVar2 = pcVar1;
    if (param_1 + param_2 == pcVar2) {
      return (int)(param_1 + param_2) - (int)param_1;
    }
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  return (int)pcVar2 - (int)param_1;
}

