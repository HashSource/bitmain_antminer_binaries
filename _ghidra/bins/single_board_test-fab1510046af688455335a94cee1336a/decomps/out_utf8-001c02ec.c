
undefined4 out_utf8(ulong param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  iVar1 = UTF8_putc((uchar *)0x0,-1,param_1);
  *param_2 = iVar2 + iVar1;
  return 1;
}

