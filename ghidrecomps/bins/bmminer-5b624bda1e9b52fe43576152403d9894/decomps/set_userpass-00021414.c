
/* WARNING: Unknown calling convention */

char * set_userpass(char *arg)

{
  char *pcVar1;
  char *updup;
  char *pcVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  pool *pool;
  
  iVar6 = DAT_00021498;
  pcVar1 = DAT_000214a8;
  if ((*(int *)(DAT_00021498 + 0x484) == 0) && (*(int *)(DAT_00021498 + 0x488) == 0)) {
    iVar4 = *DAT_0002149c;
    iVar5 = *(int *)(DAT_00021498 + 0x48c) + 1;
    *(int *)(DAT_00021498 + 0x48c) = iVar5;
    if (iVar4 < iVar5) {
      add_pool();
      iVar5 = *(int *)(iVar6 + 0x48c);
    }
    iVar6 = *(int *)(*DAT_000214a0 + (iVar5 + -1) * 4);
    pcVar1 = (char *)__strdup(arg);
    opt_set_charp(arg,(char **)(iVar6 + 0xa8));
    pcVar2 = strtok(pcVar1,DAT_000214a4);
    *(char **)(iVar6 + 0xac) = pcVar2;
    pcVar1 = DAT_000214ac;
    if (pcVar2 != (char *)0x0) {
      pcVar2 = strtok((char *)0x0,DAT_000214a4);
      *(char **)(iVar6 + 0xb0) = pcVar2;
      pcVar1 = (char *)0x0;
      if (pcVar2 == (char *)0x0) {
        pvVar3 = calloc(1,1);
        *(void **)(iVar6 + 0xb0) = pvVar3;
        pcVar1 = (char *)0x0;
      }
    }
  }
  return pcVar1;
}

