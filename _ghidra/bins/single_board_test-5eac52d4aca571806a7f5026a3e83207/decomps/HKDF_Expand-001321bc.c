
int HKDF_Expand(EVP_MD *param_1,void *param_2,int param_3,uchar *param_4,size_t param_5,int param_6,
               uint param_7)

{
  size_t __n;
  size_t len;
  uint uVar1;
  HMAC_CTX *ctx;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uchar local_69;
  uchar auStack_68 [68];
  
  len = EVP_MD_size(param_1);
  uVar1 = __aeabi_uidiv(param_7,len);
  __aeabi_uidivmod(param_7,len);
  if (extraout_r1 != 0) {
    uVar1 = uVar1 + 1;
  }
  if ((0xff < uVar1 || param_6 == 0) || (ctx = (HMAC_CTX *)HMAC_CTX_new(), ctx == (HMAC_CTX *)0x0))
  {
    return 0;
  }
  iVar2 = HMAC_Init_ex(ctx,param_2,param_3,param_1,(ENGINE *)0x0);
  if (iVar2 == 0) {
    param_6 = 0;
  }
  else if (uVar1 != 0) {
    uVar5 = 1;
    local_69 = '\x01';
    uVar4 = 0;
    while (((iVar2 = HMAC_Update(ctx,param_4,param_5), iVar2 != 0 &&
            (iVar2 = HMAC_Update(ctx,&local_69,1), iVar2 != 0)) &&
           (iVar2 = HMAC_Final(ctx,auStack_68,(uint *)0x0), iVar2 != 0))) {
      uVar3 = len + uVar4;
      __n = len;
      if (param_7 < uVar3) {
        uVar3 = param_7;
        __n = param_7 - uVar4;
      }
      uVar5 = uVar5 + 1;
      memcpy((void *)(param_6 + uVar4),auStack_68,__n);
      if (uVar1 < uVar5) goto LAB_001322b2;
      local_69 = (uchar)uVar5;
      iVar2 = HMAC_Init_ex(ctx,(void *)0x0,0,(EVP_MD *)0x0,(ENGINE *)0x0);
      if ((iVar2 == 0) || (iVar2 = HMAC_Update(ctx,auStack_68,len), uVar4 = uVar3, iVar2 == 0))
      break;
    }
    param_6 = 0;
  }
LAB_001322b2:
  OPENSSL_cleanse(auStack_68,0x40);
  HMAC_CTX_free(ctx);
  return param_6;
}

