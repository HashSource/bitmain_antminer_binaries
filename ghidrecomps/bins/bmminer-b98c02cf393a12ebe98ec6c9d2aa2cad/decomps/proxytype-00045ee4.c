
char * proxytype(int param_1)

{
  char *pcVar1;
  undefined1 *puVar2;
  
  if (param_1 == 0) {
    pcVar1 = "http:";
  }
  else {
    pcVar1 = "http0:";
    puVar2 = proxynames;
    do {
      if (*(int *)(puVar2 + 0xc) == param_1) {
        return pcVar1;
      }
      pcVar1 = *(char **)(puVar2 + 0x10);
      puVar2 = puVar2 + 8;
    } while (pcVar1 != (char *)0x0);
    pcVar1 = "invalid";
  }
  return pcVar1;
}

