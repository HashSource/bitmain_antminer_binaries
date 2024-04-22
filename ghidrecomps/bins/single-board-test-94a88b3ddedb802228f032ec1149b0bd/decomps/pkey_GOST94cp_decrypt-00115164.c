
undefined4
pkey_GOST94cp_decrypt
          (EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4,
          undefined4 param_5)

{
  EVP_PKEY *pEVar1;
  int *piVar2;
  EVP_PKEY *peer;
  int iVar3;
  EVP_PKEY *pEVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
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
  pEVar1 = EVP_PKEY_CTX_get0_pkey(param_1);
  if (param_2 == 0) {
    *param_3 = 0x20;
    return 1;
  }
  piVar2 = (int *)d2i_GOST_KEY_TRANSPORT(0,&local_1090,param_5);
  if (piVar2 == (int *)0x0) {
    ERR_GOST_error(0x7a,0x68,DAT_00115300,0xe6);
    return 0;
  }
  peer = X509_PUBKEY_get(*(X509_PUBKEY **)(piVar2[1] + 4));
  if (peer == (EVP_PKEY *)0x0) {
    iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
    if (iVar3 < 1) {
      ERR_GOST_error(0x7a,0x84,DAT_00115300,0xf4);
      goto LAB_001152b2;
    }
  }
  else {
    iVar3 = EVP_PKEY_derive_set_peer(param_1,peer);
    if (iVar3 < 1) {
      ERR_GOST_error(0x7a,0x83,DAT_00115300,0xed);
      goto LAB_001152b2;
    }
  }
  pEVar4 = EVP_PKEY_CTX_get0_peerkey(param_1);
  if (pEVar4 == (EVP_PKEY *)0x0) {
    ERR_GOST_error(0x7a,0x78,DAT_00115300,0xfa);
  }
  else {
    iVar3 = get_encryption_params(*(undefined4 *)piVar2[1]);
    if (iVar3 != 0) {
      gost_init(auStack_1040,*(undefined4 *)(iVar3 + 4));
      piVar6 = *(int **)(piVar2[1] + 8);
      if (*piVar6 != 8) {
        OpenSSLDie(DAT_00115300,0x104,DAT_00115304);
        piVar6 = *(int **)(piVar2[1] + 8);
      }
      local_106c = *(undefined4 *)piVar6[2];
      uStack_1068 = ((undefined4 *)piVar6[2])[1];
      piVar6 = *(int **)*piVar2;
      if (*piVar6 != 0x20) {
        OpenSSLDie(DAT_00115300,0x106,DAT_00115308);
        piVar6 = *(int **)*piVar2;
      }
      puVar7 = (undefined4 *)piVar6[2];
      local_1064 = *puVar7;
      uStack_1060 = puVar7[1];
      uStack_105c = puVar7[2];
      uStack_1058 = puVar7[3];
      uStack_104c = puVar7[6];
      uStack_1048 = puVar7[7];
      local_1054 = puVar7[4];
      uStack_1050 = puVar7[5];
      piVar6 = *(int **)(*piVar2 + 4);
      if (*piVar6 != 4) {
        OpenSSLDie(DAT_00115300,0x108,DAT_0011530c);
        piVar6 = *(int **)(*piVar2 + 4);
      }
      local_1044 = *(undefined4 *)piVar6[2];
      uVar5 = gost_get0_priv_key(pEVar1);
      make_cp_exchange_key(uVar5,pEVar4,auStack_108c);
      iVar3 = keyUnwrapCryptoPro(auStack_1040,auStack_108c,&local_106c,param_2);
      if (iVar3 != 0) {
        EVP_PKEY_free(peer);
        GOST_KEY_TRANSPORT_free(piVar2);
        return 1;
      }
      ERR_GOST_error(0x7a,0x66,DAT_00115300,0x10d);
    }
  }
LAB_001152b2:
  EVP_PKEY_free(peer);
  GOST_KEY_TRANSPORT_free(piVar2);
  return 0xffffffff;
}

