
uint SCT_validate(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  EVP_PKEY *pEVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  X509_PUBKEY *local_20;
  X509_PUBKEY *local_1c [2];
  
  local_20 = (X509_PUBKEY *)0x0;
  local_1c[0] = (X509_PUBKEY *)0x0;
  if (*param_1 != 0) {
    param_1[0xf] = 5;
    return 0;
  }
  iVar1 = CTLOG_STORE_get0_log_by_id(param_2[2],param_1[3],param_1[4]);
  if (iVar1 == 0) {
    param_1[0xf] = 1;
    return 0;
  }
  iVar2 = SCT_CTX_new();
  if (iVar2 != 0) {
    pEVar3 = (EVP_PKEY *)CTLOG_get0_public_key(iVar1);
    iVar1 = X509_PUBKEY_set(local_1c,pEVar3);
    if ((iVar1 == 1) && (iVar1 = SCT_CTX_set1_pubkey(iVar2,local_1c[0]), iVar1 == 1)) {
      uVar6 = SCT_get_log_entry_type(param_1);
      uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 == 1) {
        if (param_2[1] != 0) {
          pEVar3 = (EVP_PKEY *)X509_get0_pubkey();
          iVar1 = X509_PUBKEY_set(&local_20,pEVar3);
          if (iVar1 == 1) {
            uVar6 = SCT_CTX_set1_issuer_pubkey(iVar2,local_20);
            uVar4 = (undefined4)((ulonglong)uVar6 >> 0x20);
            if ((int)uVar6 == 1) goto LAB_00111010;
          }
          goto LAB_00110fd4;
        }
      }
      else {
LAB_00111010:
        SCT_CTX_set_time(iVar2,uVar4,param_2[4],param_2[5]);
        iVar1 = SCT_CTX_set1_cert(iVar2,*param_2,0);
        if (iVar1 == 1) {
          iVar1 = SCT_CTX_verify(iVar2,param_1);
          if (iVar1 == 1) {
            iVar1 = 2;
          }
          else {
            iVar1 = 3;
          }
          param_1[0xf] = iVar1;
          uVar5 = (uint)(iVar1 == 2);
          goto LAB_00110fd8;
        }
      }
      uVar5 = 0;
      param_1[0xf] = 4;
      goto LAB_00110fd8;
    }
  }
LAB_00110fd4:
  uVar5 = 0xffffffff;
LAB_00110fd8:
  X509_PUBKEY_free(local_20);
  X509_PUBKEY_free(local_1c[0]);
  SCT_CTX_free(iVar2);
  return uVar5;
}

