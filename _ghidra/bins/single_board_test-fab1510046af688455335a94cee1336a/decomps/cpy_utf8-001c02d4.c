
undefined4 cpy_utf8(ulong param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = UTF8_putc((uchar *)*param_2,0xff,param_1);
  *param_2 = *param_2 + iVar1;
  return 1;
}

