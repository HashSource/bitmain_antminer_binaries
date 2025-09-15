
int get_context_constprop_2(void)

{
  int iVar1;
  undefined1 *local_418;
  undefined4 uStack_414;
  undefined1 auStack_410 [1028];
  
  local_418 = auStack_410;
  uStack_414 = 0x400;
  iVar1 = (*p_hwcrhk_Init)(hwcrhk_globals,0x54,&local_418,password_context);
  hwcrhk_context = iVar1;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

