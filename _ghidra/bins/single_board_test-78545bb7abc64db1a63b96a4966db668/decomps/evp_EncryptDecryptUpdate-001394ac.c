
bool evp_EncryptDecryptUpdate
               (EVP_CIPHER_CTX *param_1,uchar *param_2,size_t *param_3,uchar *param_4,uint param_5)

{
  int iVar1;
  EVP_CIPHER *cipher;
  ulong uVar2;
  size_t sVar3;
  uint uVar4;
  size_t __n;
  
  iVar1 = EVP_CIPHER_CTX_test_flags(param_1,0x2000);
  uVar4 = param_5 + 7 >> 3;
  if (iVar1 == 0) {
    uVar4 = param_5;
  }
  if ((int)param_5 < 0) {
LAB_00139512:
    *param_3 = 0;
    return param_5 == 0;
  }
  cipher = param_1->cipher;
  sVar3 = cipher->block_size;
  if (param_5 == 0) {
    uVar2 = EVP_CIPHER_flags(cipher);
    if ((uVar2 & 0xf0007) != 7) goto LAB_00139512;
    cipher = param_1->cipher;
  }
  if ((cipher->flags & 0x100000) != 0) {
    if (sVar3 == 1) {
      iVar1 = is_partially_overlapping(param_2,param_4,uVar4);
      if (iVar1 != 0) {
        ERR_put_error(6,0xdb,0xa2,"crypto/evp/evp_enc.c",0x144);
        return false;
      }
      cipher = param_1->cipher;
    }
    sVar3 = (*cipher->do_cipher)(param_1,param_2,param_4,param_5);
    if ((int)sVar3 < 0) {
      return false;
    }
    *param_3 = sVar3;
    return true;
  }
  iVar1 = is_partially_overlapping(param_2 + param_1->buf_len,param_4,uVar4);
  if (iVar1 != 0) {
    ERR_put_error(6,0xdb,0xa2,"crypto/evp/evp_enc.c",0x151);
    return false;
  }
  iVar1 = param_1->buf_len;
  if (iVar1 == 0) {
    if ((param_5 & param_1->block_mask) == 0) {
      iVar1 = (*param_1->cipher->do_cipher)(param_1,param_2,param_4,param_5);
      if (iVar1 != 0) {
        *param_3 = param_5;
        return true;
      }
      *param_3 = 0;
      return false;
    }
    if (0x20 < (int)sVar3) {
LAB_00139678:
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: bl <= (int)sizeof(ctx->buf)","crypto/evp/evp_enc.c",0x15f);
    }
    *param_3 = 0;
  }
  else {
    if (0x20 < (int)sVar3) goto LAB_00139678;
    __n = sVar3 - iVar1;
    if ((int)param_5 < (int)__n) {
      memcpy(param_1->buf + iVar1,param_4,param_5);
      param_1->buf_len = param_1->buf_len + param_5;
      *param_3 = 0;
      return true;
    }
    param_5 = param_5 - __n;
    if ((int)(0x7fffffff - sVar3) < (int)(-sVar3 & param_5)) {
      ERR_put_error(6,0xdb,0xb8,"crypto/evp/evp_enc.c",0x172);
      return false;
    }
    memcpy(param_1->buf + iVar1,param_4,__n);
    iVar1 = (*param_1->cipher->do_cipher)(param_1,param_2,param_1->buf,sVar3);
    if (iVar1 == 0) {
      return false;
    }
    param_4 = param_4 + __n;
    param_2 = param_2 + sVar3;
    *param_3 = sVar3;
  }
  uVar4 = sVar3 - 1 & param_5;
  sVar3 = param_5 - uVar4;
  if (0 < (int)sVar3) {
    iVar1 = (*param_1->cipher->do_cipher)(param_1,param_2,param_4,sVar3);
    if (iVar1 == 0) {
      return false;
    }
    *param_3 = *param_3 + sVar3;
  }
  if (uVar4 != 0) {
    memcpy(param_1->buf,param_4 + sVar3,uVar4);
  }
  param_1->buf_len = uVar4;
  return true;
}

