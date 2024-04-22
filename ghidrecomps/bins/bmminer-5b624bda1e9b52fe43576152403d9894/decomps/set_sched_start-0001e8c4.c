
/* WARNING: Unknown calling convention */

char * set_sched_start(char *arg)

{
  int iVar1;
  
  iVar1 = sscanf(arg,DAT_0001e900,DAT_0001e8fc,DAT_0001e8fc + -4);
  if (iVar1 != 2) {
    return DAT_0001e904;
  }
  if ((((*(int *)(DAT_0001e908 + 0xc) < 0x18) && (*(int *)(DAT_0001e908 + 8) < 0x3c)) &&
      (-1 < *(int *)(DAT_0001e908 + 0xc))) && (-1 < *(int *)(DAT_0001e908 + 8))) {
    *DAT_0001e908 = 1;
    return (char *)0x0;
  }
  return DAT_0001e90c;
}

