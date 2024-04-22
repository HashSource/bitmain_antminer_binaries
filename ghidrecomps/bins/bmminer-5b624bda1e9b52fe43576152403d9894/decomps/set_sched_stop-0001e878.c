
/* WARNING: Unknown calling convention */

char * set_sched_stop(char *arg)

{
  int iVar1;
  
  iVar1 = sscanf(arg,DAT_0001e8b4,DAT_0001e8b0,DAT_0001e8b0 + -4);
  if (iVar1 != 2) {
    return DAT_0001e8b8;
  }
  if ((((*(int *)(DAT_0001e8bc + 0xc) < 0x18) && (*(int *)(DAT_0001e8bc + 8) < 0x3c)) &&
      (-1 < *(int *)(DAT_0001e8bc + 0xc))) && (-1 < *(int *)(DAT_0001e8bc + 8))) {
    *DAT_0001e8bc = 1;
    return (char *)0x0;
  }
  return DAT_0001e8c0;
}

