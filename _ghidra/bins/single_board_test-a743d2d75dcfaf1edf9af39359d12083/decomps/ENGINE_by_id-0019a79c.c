
ENGINE * ENGINE_by_id(char *id)

{
  ENGINE *pEVar1;
  int iVar2;
  char *arg;
  ENGINE *pEVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  if (id == (char *)0x0) {
    ERR_put_error(0x26,0x6a,0x43,"eng_list.c",0x149);
    return (ENGINE *)0x0;
  }
  CRYPTO_lock(9,0x1e,"eng_list.c",0x14c);
  for (pEVar3 = engine_list_head; pEVar3 != (ENGINE *)0x0; pEVar3 = *(ENGINE **)(pEVar3 + 0x6c)) {
    iVar2 = strcmp(id,*(char **)pEVar3);
    if (iVar2 == 0) {
      if (*(int *)(pEVar3 + 0x54) << 0x1d < 0) {
        pEVar1 = ENGINE_new();
        if (pEVar1 == (ENGINE *)0x0) break;
        uVar8 = *(undefined4 *)(pEVar3 + 4);
        uVar7 = *(undefined4 *)(pEVar3 + 0xc);
        uVar4 = *(undefined4 *)(pEVar3 + 0x14);
        *(undefined4 *)pEVar1 = *(undefined4 *)pEVar3;
        *(undefined4 *)(pEVar1 + 4) = uVar8;
        uVar8 = *(undefined4 *)(pEVar3 + 0x18);
        uVar6 = *(undefined4 *)(pEVar3 + 0x10);
        *(undefined4 *)(pEVar1 + 8) = *(undefined4 *)(pEVar3 + 8);
        uVar5 = *(undefined4 *)(pEVar3 + 0x1c);
        uVar9 = *(undefined4 *)(pEVar3 + 0x3c);
        *(undefined4 *)(pEVar1 + 0xc) = uVar7;
        *(undefined4 *)(pEVar1 + 0x1c) = uVar5;
        uVar5 = *(undefined4 *)(pEVar3 + 0x20);
        uVar7 = *(undefined4 *)(pEVar3 + 0x44);
        *(undefined4 *)(pEVar1 + 0x14) = uVar4;
        *(undefined4 *)(pEVar1 + 0x20) = uVar5;
        uVar4 = *(undefined4 *)(pEVar3 + 0x24);
        *(undefined4 *)(pEVar1 + 0x18) = uVar8;
        *(undefined4 *)(pEVar1 + 0x10) = uVar6;
        *(undefined4 *)(pEVar1 + 0x24) = uVar4;
        uVar4 = *(undefined4 *)(pEVar3 + 0x28);
        *(undefined4 *)(pEVar1 + 0x3c) = uVar9;
        *(undefined4 *)(pEVar1 + 0x28) = uVar4;
        *(undefined4 *)(pEVar1 + 0x2c) = *(undefined4 *)(pEVar3 + 0x2c);
        *(undefined4 *)(pEVar1 + 0x34) = *(undefined4 *)(pEVar3 + 0x34);
        *(undefined4 *)(pEVar1 + 0x38) = *(undefined4 *)(pEVar3 + 0x38);
        *(undefined4 *)(pEVar1 + 0x40) = *(undefined4 *)(pEVar3 + 0x40);
        *(undefined4 *)(pEVar1 + 0x44) = uVar7;
        uVar4 = *(undefined4 *)(pEVar3 + 0x50);
        uVar8 = *(undefined4 *)(pEVar3 + 0x54);
        *(undefined4 *)(pEVar1 + 0x48) = *(undefined4 *)(pEVar3 + 0x48);
        *(undefined4 *)(pEVar1 + 0x50) = uVar4;
        *(undefined4 *)(pEVar1 + 0x54) = uVar8;
      }
      else {
        *(int *)(pEVar3 + 0x58) = *(int *)(pEVar3 + 0x58) + 1;
        pEVar1 = pEVar3;
      }
      CRYPTO_lock(10,0x1e,"eng_list.c",0x163);
      return pEVar1;
    }
  }
  CRYPTO_lock(10,0x1e,"eng_list.c",0x163);
  iVar2 = strcmp(id,"dynamic");
  if (iVar2 != 0) {
    arg = getenv("OPENSSL_ENGINES");
    if (arg == (char *)0x0) {
      arg = "/home/XILINX/bin/lib/engines";
    }
    pEVar3 = ENGINE_by_id("dynamic");
    if (pEVar3 != (ENGINE *)0x0) {
      iVar2 = ENGINE_ctrl_cmd_string(pEVar3,"ID",id,0);
      if ((((iVar2 != 0) && (iVar2 = ENGINE_ctrl_cmd_string(pEVar3,"DIR_LOAD","2",0), iVar2 != 0))
          && (iVar2 = ENGINE_ctrl_cmd_string(pEVar3,"DIR_ADD",arg,0), iVar2 != 0)) &&
         ((iVar2 = ENGINE_ctrl_cmd_string(pEVar3,"LIST_ADD","1",0), iVar2 != 0 &&
          (iVar2 = ENGINE_ctrl_cmd_string(pEVar3,"LOAD",(char *)0x0,0), iVar2 != 0)))) {
        return pEVar3;
      }
      goto LAB_0019a872;
    }
  }
  pEVar3 = (ENGINE *)0x0;
LAB_0019a872:
  ENGINE_free(pEVar3);
  ERR_put_error(0x26,0x6a,0x74,"eng_list.c",0x185);
  ERR_add_error_data(2,&DAT_002231c8,id);
  return (ENGINE *)0x0;
}

