
void blake2b_final(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = 0;
  uVar1 = *(uint *)(param_1 + 0xd0);
  uVar4 = *(uint *)(param_1 + 0xc0) + uVar1;
  iVar5 = *(int *)(param_1 + 0xc4) + (uint)CARRY4(*(uint *)(param_1 + 0xc0),uVar1);
  *(uint *)(param_1 + 0xc0) = uVar4;
  *(int *)(param_1 + 0xc4) = iVar5;
  uVar2 = uVar1;
  if (iVar5 == 0 && uVar4 < uVar1) {
    uVar2 = *(uint *)(param_1 + 200) + 1;
    iVar3 = *(int *)(param_1 + 0xcc) + (uint)(0xfffffffe < *(uint *)(param_1 + 200));
    *(uint *)(param_1 + 200) = uVar2;
    *(int *)(param_1 + 0xcc) = iVar3;
  }
  if (uVar1 < 0x80) {
    iVar3 = 0;
    do {
      *(undefined *)(param_1 + uVar1) = 0;
      uVar1 = uVar1 + 1;
    } while (uVar1 != 0x80);
    *(undefined4 *)(param_1 + 0xd0) = 0x80;
  }
  blake2b_compress(param_1,1,uVar2,iVar3,param_4);
  if (*(int *)(param_1 + 0xd4) == 0) {
    return;
  }
  uVar2 = 0;
  do {
    iVar5 = (uVar2 & 7) * 8;
    iVar3 = (uVar2 >> 3) + 0x10;
    uVar1 = *(uint *)(param_1 + iVar3 * 8 + 4);
    *(byte *)(param_2 + uVar2) =
         (byte)(*(uint *)(param_1 + iVar3 * 8) >> iVar5) |
         (byte)(uVar1 << ((uVar2 & 7) * -8 + 0x20 & 0xff)) | (byte)(uVar1 >> (iVar5 - 0x20U & 0xff))
    ;
    uVar2 = uVar2 + 1;
  } while (uVar2 < *(uint *)(param_1 + 0xd4));
  return;
}

