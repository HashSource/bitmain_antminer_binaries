
void _copy_work(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_1c [2];
  
  uVar3 = *(undefined4 *)(param_1 + 0x154);
  clean_work();
  _cg_memcpy(param_1,param_2,0x1c0,"cgminer.c",DAT_0001cc44,0x130a);
  iVar1 = *(int *)(param_2 + 0x120);
  *(undefined4 *)(param_1 + 0x154) = uVar3;
  if (iVar1 != 0) {
    uVar3 = __strdup();
    *(undefined4 *)(param_1 + 0x120) = uVar3;
  }
  if (*(int *)(param_2 + 0x140) != 0) {
    uVar3 = __strdup();
    *(undefined4 *)(param_1 + 0x140) = uVar3;
  }
  iVar1 = *(int *)(param_2 + 0x134);
  if (iVar1 == 0) {
    if (param_3 != 0) {
      uVar2 = *(uint *)(param_1 + 0x44);
      uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18) + param_3;
      *(uint *)(param_1 + 0x44) =
           uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
           uVar2 >> 0x18;
    }
  }
  else if (param_3 == 0) {
    uVar3 = __strdup(iVar1);
    *(undefined4 *)(param_1 + 0x134) = uVar3;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x44);
    uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
            uVar2 >> 0x18) + param_3;
    *(uint *)(param_1 + 0x44) =
         uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
         uVar2 >> 0x18;
    hex2bin(local_1c,iVar1,4);
    uVar2 = (local_1c[0] << 0x18 | (local_1c[0] >> 8 & 0xff) << 0x10 |
             (local_1c[0] >> 0x10 & 0xff) << 8 | local_1c[0] >> 0x18) + param_3;
    local_1c[0] = uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                  uVar2 >> 0x18;
    uVar3 = bin2hex(local_1c,4);
    *(undefined4 *)(param_1 + 0x134) = uVar3;
  }
  if (*(int *)(param_2 + 0x148) != 0) {
    uVar3 = __strdup();
    *(undefined4 *)(param_1 + 0x148) = uVar3;
  }
  *(undefined4 *)(param_1 + 0x1bc) = *(undefined4 *)(param_2 + 0x1bc);
  return;
}

