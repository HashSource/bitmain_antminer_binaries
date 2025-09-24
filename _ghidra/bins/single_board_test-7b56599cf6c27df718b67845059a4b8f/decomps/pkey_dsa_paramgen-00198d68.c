
int pkey_dsa_paramgen(int param_1,EVP_PKEY *param_2)

{
  DSA *r;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  puVar3 = *(undefined4 **)(param_1 + 0x14);
  if (iVar2 != 0) {
    iVar2 = BN_GENCB_new();
    if (iVar2 == 0) {
      return 0;
    }
    evp_pkey_set_cb_translate(iVar2,param_1);
  }
  r = DSA_new();
  if (r == (DSA *)0x0) {
    BN_GENCB_free(iVar2);
  }
  else {
    iVar1 = dsa_builtin_paramgen(r,*puVar3,puVar3[1],puVar3[2],0,0,0,0,0,iVar2);
    BN_GENCB_free(iVar2);
    if (iVar1 != 0) {
      EVP_PKEY_assign(param_2,0x74,r);
      return iVar1;
    }
    DSA_free(r);
  }
  return 0;
}

