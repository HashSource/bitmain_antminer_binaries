
int ocsp_ext_d2i_SCT_LIST(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = d2i_SCT_LIST();
  if (iVar1 != 0) {
    iVar4 = 0;
    while( true ) {
      iVar3 = OPENSSL_sk_num(iVar1);
      if (iVar3 <= iVar4) break;
      uVar2 = OPENSSL_sk_value(iVar1,iVar4);
      iVar3 = SCT_set_source(uVar2,3);
      iVar4 = iVar4 + 1;
      if (iVar3 != 1) {
        SCT_LIST_free(iVar1);
        *param_1 = 0;
        return 0;
      }
    }
  }
  return iVar1;
}

