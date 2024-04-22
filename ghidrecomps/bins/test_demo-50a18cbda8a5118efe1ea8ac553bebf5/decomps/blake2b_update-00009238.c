
void blake2b_update(undefined *param_1,undefined *param_2,int param_3,undefined4 param_4)

{
  undefined uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  bool bVar7;
  
  if (param_3 != 0) {
    iVar4 = *(int *)(param_1 + 0xd0);
    puVar5 = param_2;
    do {
      while (iVar2 = iVar4 + 1, iVar4 == 0x80) {
        uVar3 = *(uint *)(param_1 + 0xc0) + 0x80;
        iVar4 = *(int *)(param_1 + 0xc4) + (uint)(0xffffff7f < *(uint *)(param_1 + 0xc0));
        bVar7 = iVar4 == 0;
        if (iVar4 == 0) {
          bVar7 = uVar3 < 0x80;
        }
        *(uint *)(param_1 + 0xc0) = uVar3;
        *(int *)(param_1 + 0xc4) = iVar4;
        if (bVar7) {
          uVar3 = *(uint *)(param_1 + 200);
          *(uint *)(param_1 + 200) = uVar3 + 1;
          *(uint *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + (uint)(0xfffffffe < uVar3);
        }
        blake2b_compress(param_1,0,0x80,iVar2,param_4);
        *(undefined4 *)(param_1 + 0xd0) = 0;
        puVar6 = puVar5 + 1;
        uVar1 = *puVar5;
        *(undefined4 *)(param_1 + 0xd0) = 1;
        *param_1 = uVar1;
        iVar4 = 1;
        puVar5 = puVar6;
        if (puVar6 == param_2 + param_3) {
          return;
        }
      }
      puVar6 = puVar5 + 1;
      uVar1 = *puVar5;
      *(int *)(param_1 + 0xd0) = iVar2;
      param_1[iVar4] = uVar1;
      iVar4 = iVar2;
      puVar5 = puVar6;
    } while (puVar6 != param_2 + param_3);
  }
  return;
}

