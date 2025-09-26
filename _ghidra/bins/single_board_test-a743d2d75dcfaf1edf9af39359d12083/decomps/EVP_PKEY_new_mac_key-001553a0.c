
EVP_PKEY * EVP_PKEY_new_mac_key(int type,ENGINE *e,uchar *key,int keylen)

{
  EVP_PKEY_CTX *ctx;
  EVP_PKEY *pkey;
  int iVar1;
  code *pcVar2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  EVP_PKEY *pEVar4;
  
  ctx = EVP_PKEY_CTX_new_id(type,e);
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    return (EVP_PKEY *)0x0;
  }
  iVar1 = *(int *)ctx;
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x20) == 0)) {
    ERR_put_error(6,0x93,0x96,"pmeth_gn.c",0x76);
  }
  else {
    pcVar2 = *(code **)(iVar1 + 0x1c);
    *(undefined4 *)(ctx + 0x10) = 4;
    if (pcVar2 != (code *)0x0) {
      iVar1 = (*pcVar2)();
      uVar3 = extraout_r3;
      if (iVar1 < 1) {
        uVar3 = 0;
      }
      if (iVar1 < 1) {
        *(undefined4 *)(ctx + 0x10) = uVar3;
        goto LAB_00155428;
      }
    }
    iVar1 = EVP_PKEY_CTX_ctrl(ctx,-1,4,6,keylen,key);
    if (0 < iVar1) {
      if ((*(int *)ctx == 0) || (*(int *)(*(int *)ctx + 0x20) == 0)) {
        ERR_put_error(6,0x92,0x96,"pmeth_gn.c",0x88);
        pEVar4 = (EVP_PKEY *)0x0;
      }
      else if (*(int *)(ctx + 0x10) == 4) {
        pkey = EVP_PKEY_new();
        iVar1 = (**(code **)(*(int *)ctx + 0x20))(ctx,pkey);
        pEVar4 = pkey;
        if (iVar1 < 1) {
          pEVar4 = (EVP_PKEY *)0x0;
          EVP_PKEY_free(pkey);
        }
      }
      else {
        ERR_put_error(6,0x92,0x97,"pmeth_gn.c",0x8c);
        pEVar4 = (EVP_PKEY *)0x0;
      }
      goto LAB_0015542a;
    }
  }
LAB_00155428:
  pEVar4 = (EVP_PKEY *)0x0;
LAB_0015542a:
  EVP_PKEY_CTX_free(ctx);
  return pEVar4;
}

