
undefined4 def_init_WIN32(int *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0010d9b8;
  if (param_1 != (int *)0x0) {
    param_1[2] = 0;
    *param_1 = iVar1;
    param_1[1] = iVar1 + 0x28;
    return 1;
  }
  return 0;
}

