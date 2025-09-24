
int EVP_PKEY_encrypt(EVP_PKEY_CTX *ctx,uchar *out,size_t *outlen,uchar *in,size_t inlen)

{
  int iVar1;
  uint uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (iVar1 = *(int *)ctx, iVar1 == 0)) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x50), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    ERR_put_error(6,0x69,0x96,"crypto/evp/pmeth_fn.c",0x9f);
    iVar1 = -2;
  }
  else if (*(int *)(ctx + 0x10) == 0x100) {
    if (-1 < *(int *)(iVar1 + 4) << 0x1e) {
LAB_0013290e:
                    /* WARNING: Could not recover jumptable at 0x00132922. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)(ctx,out,outlen,in);
      return iVar1;
    }
    uVar2 = EVP_PKEY_size(*(EVP_PKEY **)(ctx + 8));
    if (uVar2 == 0) {
      ERR_put_error(6,0x69,0xa3,"crypto/evp/pmeth_fn.c",0xa6);
      iVar1 = 0;
    }
    else if (out == (uchar *)0x0) {
      *outlen = uVar2;
      iVar1 = 1;
    }
    else {
      if (uVar2 <= *outlen) {
        UNRECOVERED_JUMPTABLE = *(code **)(*(int *)ctx + 0x50);
        goto LAB_0013290e;
      }
      ERR_put_error(6,0x69,0x9b,"crypto/evp/pmeth_fn.c",0xa6);
      iVar1 = 0;
    }
  }
  else {
    ERR_put_error(6,0x69,0x97,"crypto/evp/pmeth_fn.c",0xa3);
    iVar1 = -1;
  }
  return iVar1;
}

