
char * get_gost_engine_param(int param_1)

{
  char **ppcVar1;
  char *pcVar2;
  
  ppcVar1 = DAT_00117768;
  if (param_1 != 0) {
    return (char *)0x0;
  }
  pcVar2 = *DAT_00117768;
  if (pcVar2 == (char *)0x0) {
    pcVar2 = getenv(DAT_0011776c);
    if (pcVar2 == (char *)0x0) {
      return (char *)0x0;
    }
    pcVar2 = BUF_strdup(pcVar2);
    *ppcVar1 = pcVar2;
  }
  return pcVar2;
}

