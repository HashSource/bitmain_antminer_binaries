
DH * DHparams_dup(DH *param_1)

{
  DH *dh;
  int iVar1;
  
  dh = DH_new();
  if ((dh != (DH *)0x0) && (iVar1 = int_dh_param_copy(dh,param_1,0xffffffff), iVar1 == 0)) {
    DH_free(dh);
    dh = (DH *)0x0;
  }
  return dh;
}

