
int json_real(void)

{
  int iVar1;
  double in_d0;
  undefined4 local_18;
  undefined4 uStack_14;
  
  iVar1 = __isnan(in_d0);
  if ((iVar1 == 0) && (iVar1 = __isinf(in_d0), iVar1 == 0)) {
    iVar1 = jsonp_malloc(0x10);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      json_init(iVar1,4);
      local_18 = SUB84(in_d0,0);
      uStack_14 = (undefined4)((ulonglong)in_d0 >> 0x20);
      *(undefined4 *)(iVar1 + 8) = local_18;
      *(undefined4 *)(iVar1 + 0xc) = uStack_14;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

