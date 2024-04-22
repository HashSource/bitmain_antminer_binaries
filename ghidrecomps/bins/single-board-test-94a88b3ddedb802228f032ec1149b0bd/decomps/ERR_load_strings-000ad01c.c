
void ERR_load_strings(int lib,ERR_STRING_DATA *str)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  iVar1 = DAT_000ad118;
  if (*(int *)(DAT_000ad118 + 0x2f4) == 0) {
    CRYPTO_lock(9,1,DAT_000ad128,0x127);
    if (*(int *)(iVar1 + 0x2f4) == 0) {
      *(undefined4 *)(iVar1 + 0x2f4) = DAT_000ad12c;
    }
    CRYPTO_lock(10,1,DAT_000ad128,0x12a);
  }
  iVar2 = DAT_000ad130;
  piVar5 = (int *)(DAT_000ad130 + 8);
  iVar3 = *(int *)(DAT_000ad130 + 8);
  while (iVar3 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0xc))(piVar5);
    piVar5 = piVar5 + 2;
    iVar3 = *piVar5;
  }
  iVar3 = *(int *)(iVar2 + 0xf0);
  piVar5 = DAT_000ad11c;
  while (iVar3 != 0) {
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0xc))(piVar5);
    piVar5 = piVar5 + 2;
    iVar3 = *piVar5;
  }
  uVar4 = *(uint *)(iVar2 + 0x218);
  puVar6 = DAT_000ad120;
  iVar2 = DAT_000ad124;
  while (DAT_000ad124 = iVar2, uVar4 != 0) {
    iVar2 = *(int *)(iVar1 + 0x2f4);
    *puVar6 = uVar4 | 0x2000000;
    (**(code **)(iVar2 + 0xc))(puVar6);
    puVar6 = puVar6 + 2;
    iVar2 = DAT_000ad124;
    uVar4 = *puVar6;
  }
  build_SYS_str_reasons();
  uVar4 = *(uint *)(iVar2 + 0xc);
  if (uVar4 != 0) {
    puVar6 = (uint *)(iVar2 + 0xc);
    do {
      iVar2 = *(int *)(iVar1 + 0x2f4);
      *puVar6 = uVar4 | 0x2000000;
      (**(code **)(iVar2 + 0xc))(puVar6);
      puVar6 = puVar6 + 2;
      uVar4 = *puVar6;
    } while (uVar4 != 0);
  }
  uVar4 = str->error;
  if (uVar4 == 0) {
    return;
  }
  if (lib != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x2f4);
      str->error = uVar4 | lib << 0x18;
      (**(code **)(iVar2 + 0xc))(str);
      str = str + 1;
      uVar4 = str->error;
    } while (uVar4 != 0);
    return;
  }
  do {
    (**(code **)(*(int *)(iVar1 + 0x2f4) + 0xc))(str);
    str = str + 1;
  } while (str->error != 0);
  return;
}

