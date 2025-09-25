
undefined4 secmem_new(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *ptr;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  ptr = (int *)CRYPTO_zalloc(8,"crypto/bio/bss_mem.c",0x73,param_4,param_4);
  if (ptr != (int *)0x0) {
    iVar1 = BUF_MEM_new_ex(1);
    *ptr = iVar1;
    if (iVar1 == 0) {
      CRYPTO_free(ptr);
      uVar7 = 0;
    }
    else {
      puVar2 = (undefined4 *)CRYPTO_zalloc(0x10,"crypto/bio/bss_mem.c",0x7b);
      ptr[1] = (int)puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        BUF_MEM_free((BUF_MEM *)*ptr);
        CRYPTO_free(ptr);
        uVar7 = 0;
      }
      else {
        puVar5 = (undefined4 *)*ptr;
        uVar7 = 1;
        uVar3 = puVar5[1];
        uVar4 = puVar5[2];
        uVar6 = puVar5[3];
        *puVar2 = *puVar5;
        puVar2[1] = uVar3;
        puVar2[2] = uVar4;
        puVar2[3] = uVar6;
        *(int **)(param_1 + 0x24) = ptr;
        *(undefined4 *)(param_1 + 0x14) = 1;
        *(undefined4 *)(param_1 + 0x10) = 1;
        *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
      }
    }
    return uVar7;
  }
  return 0;
}

