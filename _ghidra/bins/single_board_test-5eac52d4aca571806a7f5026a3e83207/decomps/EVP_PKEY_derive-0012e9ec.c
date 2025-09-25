
int EVP_PKEY_derive(EVP_PKEY_CTX *ctx,uchar *key,size_t *keylen)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  int iVar2;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar2 = *(int *)ctx, iVar2 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar2 + 0x60), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x99,0x96,"crypto/evp/pmeth_fn.c",0x120);
    iVar2 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x400) {
    if (-1 < *(int *)(iVar2 + 4) << 0x1e) {
LAB_0012ea30:
                    /* WARNING: Could not recover jumptable at 0x0012ea3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*UNRECOVERED_JUMPTABLE)(ctx,key,keylen);
      return iVar2;
    }
    uVar1 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (uVar1 == 0) {
      ERR_put_error(6,0x99,0xa3,"crypto/evp/pmeth_fn.c",0x127);
      iVar2 = 0;
    }
    else if (key == (uchar *)0x0) {
      *keylen = uVar1;
      iVar2 = 1;
    }
    else {
      if (uVar1 <= *keylen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x60);
        goto LAB_0012ea30;
      }
      ERR_put_error(6,0x99,0x9b,"crypto/evp/pmeth_fn.c",0x127);
      iVar2 = 0;
    }
  }
  else {
    ERR_put_error(6,0x99,0x97,"crypto/evp/pmeth_fn.c",0x124);
    iVar2 = -1;
  }
  return iVar2;
}

