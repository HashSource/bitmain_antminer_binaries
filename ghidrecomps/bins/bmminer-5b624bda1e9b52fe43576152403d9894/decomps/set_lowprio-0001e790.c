
/* WARNING: Unknown calling convention */

void set_lowprio(void)

{
  int iVar1;
  int ret;
  
  iVar1 = nice(10);
  if ((iVar1 == 0) && (((*DAT_0001e7b8 != '\0' || (*DAT_0001e7bc != '\0')) || (5 < *DAT_0001e7c0))))
  {
    set_lowprio();
    return;
  }
  return;
}

