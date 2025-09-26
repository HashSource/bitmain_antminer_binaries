
int SCT_CTX_verify(int *param_1,int *param_2)

{
  int iVar1;
  EVP_MD_CTX *ctx;
  EVP_MD *type;
  int iVar2;
  int iVar3;
  size_t cnt;
  void *d;
  bool bVar4;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  
  iVar1 = SCT_is_complete(param_2);
  if ((((iVar1 == 0) || (*param_1 == 0)) || (param_2[0xd] == -1)) ||
     ((param_2[0xd] == 1 && (param_1[3] == 0)))) {
    ERR_put_error(0x32,0x80,0x6a,"crypto/ct/ct_vfy.c",0x68);
    return 0;
  }
  if (*param_2 != 0) {
    ERR_put_error(0x32,0x80,0x73,"crypto/ct/ct_vfy.c",0x6c);
    return 0;
  }
  if ((param_2[4] != param_1[2]) ||
     (iVar1 = memcmp((void *)param_2[3],(void *)param_1[1],param_2[4]), iVar1 != 0)) {
    ERR_put_error(0x32,0x80,0x72,"crypto/ct/ct_vfy.c",0x71);
    return 0;
  }
  bVar4 = (uint)param_2[7] <= (uint)param_1[0xb];
  if (param_1[0xb] == param_2[7]) {
    bVar4 = (uint)param_2[6] <= (uint)param_1[10];
  }
  if (!bVar4) {
    ERR_put_error(0x32,0x80,0x74,"crypto/ct/ct_vfy.c",0x75);
    return 0;
  }
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx != (EVP_MD_CTX *)0x0) {
    type = EVP_sha256();
    iVar1 = EVP_DigestVerifyInit(ctx,(EVP_PKEY_CTX **)0x0,type,(ENGINE *)0x0,(EVP_PKEY *)*param_1);
    if (((iVar1 != 0) && (iVar1 = param_2[0xd], iVar1 != -1)) && ((iVar1 != 1 || (param_1[3] != 0)))
       ) {
      iVar2 = param_2[6];
      iVar3 = param_2[7];
      local_1a = (undefined1)((uint)iVar1 >> 8);
      local_1b = (undefined1)iVar2;
      local_1d = (undefined1)((uint)iVar2 >> 0x10);
      local_1c = (undefined1)((uint)iVar2 >> 8);
      local_1f = (undefined1)iVar3;
      local_19 = (undefined1)iVar1;
      local_1e = (undefined1)((uint)iVar2 >> 0x18);
      local_22 = (undefined1)((uint)iVar3 >> 0x18);
      local_21 = (undefined1)((uint)iVar3 >> 0x10);
      local_20 = (undefined1)((uint)iVar3 >> 8);
      local_24 = (undefined1)*param_2;
      local_23 = 0;
      iVar1 = EVP_DigestUpdate(ctx,&local_24,0xc);
      if (iVar1 != 0) {
        if (param_2[0xd] == 0) {
          d = (void *)param_1[5];
          cnt = param_1[6];
        }
        else {
          iVar1 = EVP_DigestUpdate(ctx,(void *)param_1[3],param_1[4]);
          if (iVar1 == 0) goto LAB_0011f366;
          d = (void *)param_1[7];
          cnt = param_1[8];
        }
        if (d != (void *)0x0) {
          local_22 = (undefined1)cnt;
          local_24 = (undefined1)(cnt >> 0x10);
          local_23 = (undefined1)(cnt >> 8);
          iVar1 = EVP_DigestUpdate(ctx,&local_24,3);
          if ((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(ctx,d,cnt), iVar1 != 0)) {
            local_23 = (undefined1)param_2[9];
            local_24 = (undefined1)((uint)param_2[9] >> 8);
            iVar1 = EVP_DigestUpdate(ctx,&local_24,2);
            if ((iVar1 != 0) &&
               ((param_2[9] == 0 ||
                (iVar1 = EVP_DigestUpdate(ctx,(void *)param_2[8],param_2[9]), iVar1 != 0)))) {
              iVar1 = EVP_DigestVerifyFinal(ctx,(uchar *)param_2[0xb],param_2[0xc]);
              if (iVar1 == 0) {
                ERR_put_error(0x32,0x80,0x6b,"crypto/ct/ct_vfy.c",0x87);
              }
              goto LAB_0011f36a;
            }
          }
        }
      }
    }
  }
LAB_0011f366:
  iVar1 = 0;
LAB_0011f36a:
  EVP_MD_CTX_free(ctx);
  return iVar1;
}

