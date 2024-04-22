
int json_real(void)

{
  int iVar1;
  double in_d0;
  
  iVar1 = __isnan(in_d0);
  if ((iVar1 == 0) && (iVar1 = __isinf(in_d0), iVar1 == 0)) {
    iVar1 = jsonp_malloc(0x10);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      json_init(iVar1,4);
      *(int *)(iVar1 + 8) = SUB84(in_d0,0);
      *(int *)(iVar1 + 0xc) = (int)((ulonglong)in_d0 >> 0x20);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

