
undefined4
ssl3_send_finished(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  size_t __n;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x34) == param_2) {
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 100);
    iVar4 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    iVar3 = *(int *)(iVar2 + 0x3c);
    __n = (**(code **)(iVar2 + 0x14))(param_1,param_4,param_5,*(int *)(param_1 + 0x58) + 0x234);
    if ((int)__n < 1) {
      return 0;
    }
    iVar2 = *(int *)(param_1 + 0x58);
    *(size_t *)(iVar2 + 0x2b4) = __n;
    memcpy((void *)(iVar4 + iVar3),(void *)(iVar2 + 0x234),__n);
    if (*(int *)(param_1 + 4) == 0x1000) {
      if (0x40 < (int)__n) {
        OpenSSLDie(DAT_0006d1a8,0xb5,DAT_0006d1ac);
      }
      memcpy((void *)(*(int *)(param_1 + 0x58) + 0x394),(void *)(*(int *)(param_1 + 0x58) + 0x234),
             __n);
      *(char *)(*(int *)(param_1 + 0x58) + 0x3d4) = (char)__n;
    }
    else {
      if (0x40 < (int)__n) {
        OpenSSLDie(DAT_0006d1a8,0xb9,DAT_0006d1ac);
      }
      memcpy((void *)(*(int *)(param_1 + 0x58) + 0x3d5),(void *)(*(int *)(param_1 + 0x58) + 0x234),
             __n);
      *(char *)(*(int *)(param_1 + 0x58) + 0x415) = (char)__n;
    }
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x40))(param_1,0x14,__n);
    *(undefined4 *)(param_1 + 0x34) = param_3;
  }
  uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
  return uVar1;
}

