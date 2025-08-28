
undefined4 pkey_gost_mac_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  uchar *ptr;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_1c;
  
  if ((((*param_2 == 'k') && (param_2[1] == 'e')) && (param_2[2] == 'y')) && (param_2[3] == '\0')) {
    sVar1 = strlen(param_3);
    if (sVar1 == 0x20) {
      puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      uVar7 = *(undefined4 *)(param_3 + 4);
      uVar6 = *(undefined4 *)(param_3 + 8);
      uVar4 = 1;
      uVar5 = *(undefined4 *)(param_3 + 0xc);
      puVar3[2] = *(undefined4 *)param_3;
      puVar3[3] = uVar7;
      puVar3[4] = uVar6;
      puVar3[5] = uVar5;
      uVar7 = *(undefined4 *)(param_3 + 0x14);
      uVar6 = *(undefined4 *)(param_3 + 0x18);
      uVar5 = *(undefined4 *)(param_3 + 0x1c);
      puVar3[6] = *(undefined4 *)(param_3 + 0x10);
      puVar3[7] = uVar7;
      puVar3[8] = uVar6;
      puVar3[9] = uVar5;
      *puVar3 = 1;
    }
    else {
      ERR_GOST_error(0x81,0x6f,"gost_pmeth.c",0x1f7);
      uVar4 = 0;
    }
  }
  else {
    iVar2 = strcmp(param_2,"hexkey");
    if (iVar2 == 0) {
      ptr = string_to_hex(param_3,&local_1c);
      if ((ptr == (uchar *)0x0) || (local_1c != 0x20)) {
        ERR_GOST_error(0x81,0x6f,"gost_pmeth.c",0x203);
        CRYPTO_free(ptr);
        uVar4 = 0;
      }
      else {
        puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
        uVar6 = *(undefined4 *)(ptr + 4);
        uVar5 = *(undefined4 *)(ptr + 8);
        uVar4 = *(undefined4 *)(ptr + 0xc);
        puVar3[2] = *(undefined4 *)ptr;
        puVar3[3] = uVar6;
        puVar3[4] = uVar5;
        puVar3[5] = uVar4;
        uVar6 = *(undefined4 *)(ptr + 0x14);
        uVar5 = *(undefined4 *)(ptr + 0x18);
        uVar4 = *(undefined4 *)(ptr + 0x1c);
        puVar3[6] = *(undefined4 *)(ptr + 0x10);
        puVar3[7] = uVar6;
        puVar3[8] = uVar5;
        puVar3[9] = uVar4;
        *puVar3 = 1;
        CRYPTO_free(ptr);
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 0xfffffffe;
    }
  }
  return uVar4;
}

