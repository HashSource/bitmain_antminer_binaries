
undefined4 engine_free_util(void *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if (param_1 == (void *)0x0) {
    return 1;
  }
  if (param_2 != 0) {
    piVar1 = (int *)((int)param_1 + 0x50);
    do {
      ExclusiveAccess(piVar1);
      iVar2 = *piVar1;
      bVar5 = (bool)hasExclusiveAccess(piVar1);
    } while (!bVar5);
    *piVar1 = iVar2 + -1;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      DataMemoryBarrier(0x1b);
    }
    else {
LAB_0012f97a:
      if (0 < iVar2) {
        return 1;
      }
    }
    engine_pkey_meths_free();
    engine_pkey_asn1_meths_free(param_1);
    if (*(code **)((int)param_1 + 0x2c) != (code *)0x0) {
      (**(code **)((int)param_1 + 0x2c))(param_1);
    }
    engine_remove_dynamic_id(param_1,param_2);
    CRYPTO_free_ex_data(10,param_1,(CRYPTO_EX_DATA *)((int)param_1 + 0x58));
    CRYPTO_free(param_1);
    return 1;
  }
  DataMemoryBarrier(0x1b);
  piVar1 = (int *)((int)param_1 + 0x50);
  DataMemoryBarrier(0x1b);
  iVar2 = *(int *)((int)param_1 + 0x50) + -1;
  DataMemoryBarrier(0x1b);
  iVar4 = *(int *)((int)param_1 + 0x50);
LAB_0012f9a0:
  ExclusiveAccess(piVar1);
  iVar3 = *piVar1;
  bVar5 = iVar3 == iVar4;
  if (bVar5) goto code_r0x0012f9a8;
  goto LAB_0012f9b2;
code_r0x0012f9a8:
  bVar5 = (bool)hasExclusiveAccess(piVar1);
  if (bVar5) {
    *piVar1 = iVar2;
LAB_0012f9b2:
    DataMemoryBarrier(0x1b);
    if (!bVar5) {
      iVar2 = iVar3 + -1;
      DataMemoryBarrier(0x1b);
      iVar4 = iVar3;
      goto LAB_0012f9a0;
    }
    goto LAB_0012f97a;
  }
  goto LAB_0012f9a0;
}

