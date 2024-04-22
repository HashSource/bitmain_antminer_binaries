
int pkey_GOST01cp_decrypt
              (EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
              undefined4 param_5)

{
  EVP_PKEY *pkey;
  int *piVar1;
  EVP_PKEY *peer;
  int iVar2;
  EVP_PKEY *pkey_00;
  EC_KEY *key;
  EC_POINT *pEVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 local_1090;
  undefined auStack_108c [32];
  undefined4 local_106c;
  undefined4 uStack_1068;
  undefined4 local_1064;
  undefined4 uStack_1060;
  undefined4 uStack_105c;
  undefined4 uStack_1058;
  undefined4 local_1054;
  undefined4 uStack_1050;
  undefined4 uStack_104c;
  undefined4 uStack_1048;
  undefined4 local_1044;
  undefined auStack_1040 [4128];
  
  local_1090 = param_4;
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_2 == 0) {
    *param_3 = 0x20;
    return 1;
  }
  piVar1 = (int *)d2i_GOST_KEY_TRANSPORT(0,&local_1090,param_5);
  if (piVar1 == (int *)0x0) {
    ERR_GOST_error(0x76,0x68,DAT_00112424,0xee);
    return -1;
  }
  peer = X509_PUBKEY_get(*(X509_PUBKEY **)(piVar1[1] + 4));
  if (peer == (EVP_PKEY *)0x0) {
    iVar2 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
    if (iVar2 < 1) {
      ERR_GOST_error(0x76,0x84,DAT_00112424,0xfe);
      iVar2 = 0;
      goto LAB_00112394;
    }
LAB_001122c0:
    pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
    if (pkey_00 == (EVP_PKEY *)0x0) {
      ERR_GOST_error(0x76,0x78,DAT_00112424,0x104);
      iVar2 = 0;
    }
    else {
      iVar2 = get_encryption_params(*(undefined4 *)piVar1[1]);
      if (iVar2 != 0) {
        gost_init(auStack_1040,*(undefined4 *)(iVar2 + 4));
        piVar5 = *(int **)(piVar1[1] + 8);
        if (*piVar5 != 8) {
          OpenSSLDie(DAT_00112424,0x10e,DAT_00112428);
          piVar5 = *(int **)(piVar1[1] + 8);
        }
        local_106c = *(undefined4 *)piVar5[2];
        uStack_1068 = ((undefined4 *)piVar5[2])[1];
        piVar5 = *(int **)*piVar1;
        if (*piVar5 != 0x20) {
          OpenSSLDie(DAT_00112424,0x110,DAT_0011242c);
          piVar5 = *(int **)*piVar1;
        }
        puVar6 = (undefined4 *)piVar5[2];
        local_1064 = *puVar6;
        uStack_1060 = puVar6[1];
        uStack_105c = puVar6[2];
        uStack_1058 = puVar6[3];
        uStack_104c = puVar6[6];
        uStack_1048 = puVar6[7];
        local_1054 = puVar6[4];
        uStack_1050 = puVar6[5];
        piVar5 = *(int **)(*piVar1 + 4);
        if (*piVar5 != 4) {
          OpenSSLDie(DAT_00112424,0x112,DAT_00112430);
          piVar5 = *(int **)(*piVar1 + 4);
        }
        local_1044 = *(undefined4 *)piVar5[2];
        key = (EC_KEY *)EVP_PKEY_get0(pkey_00);
        pEVar3 = EC_KEY_get0_public_key(key);
        pvVar4 = EVP_PKEY_get0(pkey);
        VKO_compute_key_isra_0(auStack_108c,pEVar3,pvVar4,&local_106c);
        iVar2 = keyUnwrapCryptoPro(auStack_1040,auStack_108c,&local_106c,param_2);
        if (iVar2 == 0) {
          ERR_GOST_error(0x76,0x66,DAT_00112424,0x119);
          iVar2 = 0;
        }
        else {
          iVar2 = 1;
        }
      }
    }
    if (peer == (EVP_PKEY *)0x0) goto LAB_00112394;
  }
  else {
    iVar2 = EVP_PKEY_derive_set_peer(param_1,peer);
    if (0 < iVar2) goto LAB_001122c0;
    ERR_GOST_error(0x76,0x83,DAT_00112424,0xf7);
    iVar2 = 0;
  }
  EVP_PKEY_free(peer);
LAB_00112394:
  GOST_KEY_TRANSPORT_free(piVar1);
  return iVar2;
}

