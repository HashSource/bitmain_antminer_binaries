
int * OSSL_STORE_open(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  char *local_130 [2];
  char acStack_128 [260];
  
  local_130[0] = "file";
  OPENSSL_strlcpy(acStack_128,param_1,0x100);
  pcVar2 = strchr(acStack_128,0x3a);
  if (pcVar2 != (char *)0x0) {
    *pcVar2 = '\0';
    iVar3 = strcasecmp(acStack_128,"file");
    if (iVar3 != 0) {
      iVar3 = strncmp(pcVar2 + 1,"//",2);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
      local_130[iVar3] = acStack_128;
      uVar7 = iVar3 + 1;
      ERR_set_mark();
      goto LAB_001c3b62;
    }
  }
  uVar7 = 1;
  ERR_set_mark();
LAB_001c3b62:
  uVar6 = 0;
  do {
    iVar3 = ossl_store_get0_loader_int(local_130[uVar6]);
    if (iVar3 == 0) {
      bVar1 = true;
      iVar4 = 0;
    }
    else {
      iVar4 = (**(code **)(iVar3 + 8))(iVar3,param_1,param_2,param_3);
      bVar1 = iVar4 == 0;
    }
    uVar6 = uVar6 + 1;
    if (uVar7 <= uVar6) {
      bVar1 = false;
    }
  } while (bVar1);
  if (iVar4 != 0) {
    piVar5 = (int *)CRYPTO_zalloc(0x20,"crypto/store/store_lib.c",0x53);
    if (piVar5 != (int *)0x0) {
      *piVar5 = iVar3;
      piVar5[1] = iVar4;
      piVar5[2] = param_2;
      piVar5[3] = param_3;
      piVar5[4] = param_4;
      piVar5[5] = param_5;
      ERR_pop_to_mark();
      return piVar5;
    }
    ERR_put_error(0x2c,0x72,0x41,"crypto/store/store_lib.c",0x54);
    ERR_clear_last_mark();
    (**(code **)(iVar3 + 0x24))(iVar4);
    return (int *)0x0;
  }
  ERR_clear_last_mark();
  return (int *)0x0;
}

