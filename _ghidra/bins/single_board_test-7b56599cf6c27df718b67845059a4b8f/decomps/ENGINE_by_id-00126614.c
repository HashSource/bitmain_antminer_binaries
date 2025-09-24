
ENGINE * ENGINE_by_id(char *id)

{
  int iVar1;
  ENGINE *pEVar2;
  char *arg;
  ENGINE *pEVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  bool bVar9;
  
  if (id == (char *)0x0) {
    ERR_put_error(0x26,0x6a,0x43,"crypto/engine/eng_list.c",0x171);
    return (ENGINE *)0x0;
  }
  iVar1 = CRYPTO_THREAD_run_once(&engine_lock_init,0x125c79);
  if ((iVar1 == 0) || (do_engine_lock_init_ossl_ret_ == 0)) {
    ERR_put_error(0x26,0x6a,0x41,"crypto/engine/eng_list.c",0x175);
    return (ENGINE *)0x0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  for (pEVar3 = engine_list_head; pEVar3 != (ENGINE *)0x0; pEVar3 = *(ENGINE **)(pEVar3 + 0x60)) {
    iVar1 = strcmp(id,*(char **)pEVar3);
    if (iVar1 == 0) {
      if (-1 < *(int *)(pEVar3 + 0x4c) << 0x1d) {
        DataMemoryBarrier(0x1b);
        pEVar2 = pEVar3 + 0x50;
        DataMemoryBarrier(0x1b);
        iVar4 = *(int *)(pEVar3 + 0x50) + 1;
        DataMemoryBarrier(0x1b);
        iVar1 = *(int *)(pEVar3 + 0x50);
        goto LAB_001267a4;
      }
      pEVar2 = ENGINE_new();
      if (pEVar2 != (ENGINE *)0x0) {
        uVar8 = *(undefined4 *)(pEVar3 + 4);
        uVar7 = *(undefined4 *)(pEVar3 + 8);
        *(undefined4 *)pEVar2 = *(undefined4 *)pEVar3;
        uVar5 = *(undefined4 *)(pEVar3 + 0xc);
        *(undefined4 *)(pEVar2 + 4) = uVar8;
        uVar8 = *(undefined4 *)(pEVar3 + 0x10);
        *(undefined4 *)(pEVar2 + 8) = uVar7;
        uVar7 = *(undefined4 *)(pEVar3 + 0x14);
        *(undefined4 *)(pEVar2 + 0xc) = uVar5;
        uVar5 = *(undefined4 *)(pEVar3 + 0x18);
        *(undefined4 *)(pEVar2 + 0x10) = uVar8;
        uVar8 = *(undefined4 *)(pEVar3 + 0x1c);
        *(undefined4 *)(pEVar2 + 0x14) = uVar7;
        uVar7 = *(undefined4 *)(pEVar3 + 0x20);
        *(undefined4 *)(pEVar2 + 0x18) = uVar5;
        uVar5 = *(undefined4 *)(pEVar3 + 0x24);
        *(undefined4 *)(pEVar2 + 0x1c) = uVar8;
        uVar8 = *(undefined4 *)(pEVar3 + 0x2c);
        *(undefined4 *)(pEVar2 + 0x20) = uVar7;
        uVar7 = *(undefined4 *)(pEVar3 + 0x30);
        *(undefined4 *)(pEVar2 + 0x24) = uVar5;
        uVar5 = *(undefined4 *)(pEVar3 + 0x34);
        *(undefined4 *)(pEVar2 + 0x2c) = uVar8;
        uVar8 = *(undefined4 *)(pEVar3 + 0x38);
        *(undefined4 *)(pEVar2 + 0x30) = uVar7;
        uVar7 = *(undefined4 *)(pEVar3 + 0x3c);
        *(undefined4 *)(pEVar2 + 0x34) = uVar5;
        uVar5 = *(undefined4 *)(pEVar3 + 0x40);
        *(undefined4 *)(pEVar2 + 0x3c) = uVar7;
        *(undefined4 *)(pEVar2 + 0x38) = uVar8;
        *(undefined4 *)(pEVar2 + 0x40) = uVar5;
        uVar7 = *(undefined4 *)(pEVar3 + 0x4c);
        uVar5 = *(undefined4 *)(pEVar3 + 0x6c);
        *(undefined4 *)(pEVar2 + 0x48) = *(undefined4 *)(pEVar3 + 0x48);
        *(undefined4 *)(pEVar2 + 0x4c) = uVar7;
        *(undefined4 *)(pEVar2 + 0x6c) = uVar5;
        engine_add_dynamic_id(pEVar2,0,0);
        pEVar3 = pEVar2;
        goto LAB_001266d0;
      }
      break;
    }
  }
  CRYPTO_THREAD_unlock(global_engine_lock);
  iVar1 = strcmp(id,"dynamic");
  if (iVar1 != 0) {
    arg = (char *)ossl_safe_getenv("OPENSSL_ENGINES");
    if (arg == (char *)0x0) {
      arg = "/home/mylz4/openssl/install/lib/engines-1.1";
    }
    pEVar3 = ENGINE_by_id("dynamic");
    if (pEVar3 != (ENGINE *)0x0) {
      iVar1 = ENGINE_ctrl_cmd_string(pEVar3,"ID",id,0);
      if ((((iVar1 != 0) && (iVar1 = ENGINE_ctrl_cmd_string(pEVar3,"DIR_LOAD","2",0), iVar1 != 0))
          && (iVar1 = ENGINE_ctrl_cmd_string(pEVar3,"DIR_ADD",arg,0), iVar1 != 0)) &&
         ((iVar1 = ENGINE_ctrl_cmd_string(pEVar3,"LIST_ADD","1",0), iVar1 != 0 &&
          (iVar1 = ENGINE_ctrl_cmd_string(pEVar3,"LOAD",(char *)0x0,0), iVar1 != 0)))) {
        return pEVar3;
      }
      goto LAB_001267e8;
    }
  }
  pEVar3 = (ENGINE *)0x0;
LAB_001267e8:
  ENGINE_free(pEVar3);
  ERR_put_error(0x26,0x6a,0x74,"crypto/engine/eng_list.c",0x1a5);
  ERR_add_error_data(2,&DAT_0020f2b0,id);
  return (ENGINE *)0x0;
LAB_001267a4:
  ExclusiveAccess(pEVar2);
  iVar6 = *(int *)pEVar2;
  bVar9 = iVar6 == iVar1;
  if (bVar9) goto code_r0x001267ac;
  goto LAB_001267b4;
code_r0x001267ac:
  bVar9 = (bool)hasExclusiveAccess(pEVar2);
  if (bVar9) {
    *(int *)pEVar2 = iVar4;
LAB_001267b4:
    DataMemoryBarrier(0x1b);
    if (bVar9) {
LAB_001266d0:
      CRYPTO_THREAD_unlock(global_engine_lock);
      return pEVar3;
    }
    iVar4 = iVar6 + 1;
    DataMemoryBarrier(0x1b);
    iVar1 = iVar6;
  }
  goto LAB_001267a4;
}

