
undefined4 pkey_gost_mac_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,undefined4 *param_3)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_1c;
  
  if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0')) {
    sVar1 = strlen((char *)param_3);
    if (sVar1 == 0x20) {
      puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      uVar8 = param_3[1];
      uVar7 = param_3[2];
      uVar4 = 1;
      uVar6 = param_3[3];
      puVar3[2] = *param_3;
      puVar3[3] = uVar8;
      puVar3[4] = uVar7;
      puVar3[5] = uVar6;
      uVar8 = param_3[5];
      uVar7 = param_3[6];
      uVar6 = param_3[7];
      puVar3[6] = param_3[4];
      puVar3[7] = uVar8;
      puVar3[8] = uVar7;
      puVar3[9] = uVar6;
      *puVar3 = 1;
    }
    else {
      ERR_GOST_error(0x81,0x6f,DAT_000dfd6c,0x1f7);
      uVar4 = 0;
    }
  }
  else {
    iVar2 = strcmp(param_2,DAT_000dfd70);
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)string_to_hex((char *)param_3,&local_1c);
      if ((puVar3 == (undefined4 *)0x0) || (local_1c != 0x20)) {
        ERR_GOST_error(0x81,0x6f,DAT_000dfd6c,0x203);
        CRYPTO_free(puVar3);
        uVar4 = 0;
      }
      else {
        puVar5 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
        uVar7 = puVar3[1];
        uVar6 = puVar3[2];
        uVar4 = puVar3[3];
        puVar5[2] = *puVar3;
        puVar5[3] = uVar7;
        puVar5[4] = uVar6;
        puVar5[5] = uVar4;
        uVar7 = puVar3[5];
        uVar6 = puVar3[6];
        uVar4 = puVar3[7];
        puVar5[6] = puVar3[4];
        puVar5[7] = uVar7;
        puVar5[8] = uVar6;
        puVar5[9] = uVar4;
        *puVar5 = 1;
        CRYPTO_free(puVar3);
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 0xfffffffe;
    }
  }
  return uVar4;
}

