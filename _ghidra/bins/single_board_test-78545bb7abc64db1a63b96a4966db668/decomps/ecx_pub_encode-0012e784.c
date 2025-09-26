
undefined4 ecx_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  uchar *penc;
  ASN1_OBJECT *aobj;
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x18) == 0) {
    ERR_put_error(0x10,0x10c,0x74,"crypto/ec/ecx_meth.c",0x83);
    uVar2 = 0;
  }
  else {
    iVar1 = **(int **)(param_2 + 0xc);
    if (iVar1 == 0x40a || iVar1 == 0x43f) {
      uVar2 = 0x20;
    }
    else if (iVar1 == 0x40b) {
      uVar2 = 0x38;
    }
    else {
      uVar2 = 0x39;
    }
    penc = (uchar *)CRYPTO_memdup(*(int *)(param_2 + 0x18),uVar2,"crypto/ec/ecx_meth.c",0x87);
    if (penc == (uchar *)0x0) {
      ERR_put_error(0x10,0x10c,0x41,"crypto/ec/ecx_meth.c",0x89);
      uVar2 = 0;
    }
    else {
      aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
      iVar1 = **(int **)(param_2 + 0xc);
      if (iVar1 == 0x40a || iVar1 == 0x43f) {
        iVar1 = 0x20;
      }
      else if (iVar1 == 0x40b) {
        iVar1 = 0x38;
      }
      else {
        iVar1 = 0x39;
      }
      iVar1 = X509_PUBKEY_set0_param(param_1,aobj,-1,(void *)0x0,penc,iVar1);
      if (iVar1 == 0) {
        CRYPTO_free(penc);
        ERR_put_error(0x10,0x10c,0x41,"crypto/ec/ecx_meth.c",0x90);
        return 0;
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}

