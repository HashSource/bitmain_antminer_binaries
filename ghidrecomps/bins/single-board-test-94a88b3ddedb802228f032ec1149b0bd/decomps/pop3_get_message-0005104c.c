
void pop3_get_message(int param_1,char **param_2)

{
  char cVar1;
  size_t sVar2;
  char *pcVar3;
  char *__s;
  
  __s = (char *)(param_1 + 2);
  if (*(char *)(param_1 + 2) == ' ' || *(char *)(param_1 + 2) == '\t') {
    pcVar3 = (char *)(param_1 + 3);
    do {
      __s = pcVar3;
      pcVar3 = __s + 1;
    } while (*__s == ' ' || *__s == '\t');
  }
  sVar2 = strlen(__s);
  pcVar3 = __s + sVar2;
  while( true ) {
    if (sVar2 == 0) {
      *param_2 = __s;
      return;
    }
    pcVar3 = pcVar3 + -1;
    cVar1 = *pcVar3;
    if (((cVar1 != '\n' && cVar1 != '\r') && (cVar1 != ' ')) && (cVar1 != '\t')) break;
    sVar2 = sVar2 - 1;
  }
  __s[sVar2] = '\0';
  *param_2 = __s;
  return;
}

