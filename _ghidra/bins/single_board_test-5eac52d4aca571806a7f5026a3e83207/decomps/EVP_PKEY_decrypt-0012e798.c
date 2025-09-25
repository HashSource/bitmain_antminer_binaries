
int EVP_PKEY_decrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x58), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x68,0x96,"crypto/evp/pmeth_fn.c",0xc1);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x200) {
    if (-1 < *(int *)(iVar1 + 4) << 0x1e) {
LAB_0012e7de:
                    /* WARNING: Could not recover jumptable at 0x0012e7f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,out,outlen,in);
      return iVar1;
    }
    uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (uVar2 == 0) {
      ERR_put_error(6,0x68,0xa3,"crypto/evp/pmeth_fn.c",200);
      iVar1 = 0;
    }
    else if (out == (uchar *)0x0) {
      *outlen = uVar2;
      iVar1 = 1;
    }
    else {
      if (uVar2 <= *outlen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x58);
        goto LAB_0012e7de;
      }
      ERR_put_error(6,0x68,0x9b,"crypto/evp/pmeth_fn.c",200);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(6,0x68,0x97,"crypto/evp/pmeth_fn.c",0xc5);
    iVar1 = -1;
  }
  return iVar1;
}

