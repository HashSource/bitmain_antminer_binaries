
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ERR_load_ERR_strings(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  iVar1 = DAT_000ad000;
  if (*(int *)(DAT_000ad000 + 0x2f4) == 0) {
    CRYPTO_lock(9,1,DAT_000ad014,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad018;
    }
    CRYPTO_lock(10,1,DAT_000ad014,0x12a);
  }
  iVar2 = DAT_000ad004;
  piVar5 = (int *)(DAT_000ad004 + 8);
  iVar3 = *(int *)(DAT_000ad004 + 8);
  while (iVar3 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0xc))(piVar5);
    piVar5 = piVar5 + 2;
    iVar3 = *piVar5;
  }
  iVar3 = *(int *)(iVar2 + 0xf0);
  piVar5 = DAT_000ad008;
  while (iVar3 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0xc))(piVar5);
    piVar5 = piVar5 + 2;
    iVar3 = *piVar5;
  }
  uVar4 = *(uint *)(iVar2 + 0x218);
  puVar6 = DAT_000ad00c;
  iVar2 = DAT_000ad010;
  while (DAT_000ad010 = iVar2, uVar4 != 0) {
    iVar2 = *(int *)(iVar1 + 0x2f4);
    *puVar6 = uVar4 | 0x2000000;
    (**(code **)(iVar2 + 0xc))(puVar6);
    puVar6 = puVar6 + 2;
    iVar2 = DAT_000ad010;
    uVar4 = *puVar6;
  }
  build_SYS_str_reasons();
  uVar4 = *(uint *)(iVar2 + 0xc);
  if (uVar4 == 0) {
    return;
  }
  puVar6 = (uint *)(iVar2 + 0xc);
  do {
    iVar2 = *(int *)(iVar1 + 0x2f4);
    *puVar6 = uVar4 | 0x2000000;
    (**(code **)(iVar2 + 0xc))(puVar6);
    puVar6 = puVar6 + 2;
    uVar4 = *puVar6;
  } while (uVar4 != 0);
  return;
}

