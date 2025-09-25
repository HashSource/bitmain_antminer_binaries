
undefined4 tls_construct_finished(int param_1,undefined4 param_2)

{
  int iVar1;
  uint __n;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar3 = *(int *)(param_1 + 0x7c);
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 100);
LAB_000ef800:
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
    uVar4 = *(undefined4 *)(iVar1 + 0x24);
    goto LAB_000ef7e2;
  }
  if (*(int *)(param_1 + 0x5f4) != 4) {
    *(undefined4 *)(param_1 + 0x54) = 1;
  }
  iVar1 = (*(int **)(param_1 + 4))[0x19];
  if (*(int *)(iVar1 + 0x30) << 0x1c < 0) {
LAB_000ef7da:
    iVar3 = *(int *)(param_1 + 0x7c);
  }
  else {
    iVar5 = **(int **)(param_1 + 4);
    iVar3 = iVar5 + -0x10000;
    if (iVar3 != 0) {
      iVar3 = 1;
    }
    if (iVar5 < 0x304) {
      iVar3 = 0;
    }
    if (iVar3 == 0) goto LAB_000ef7da;
    iVar3 = *(int *)(param_1 + 0x7c);
    if (*(int *)(iVar3 + 0x218) == 0) {
      iVar1 = (**(code **)(iVar1 + 0x10))(param_1,0x92);
      if (iVar1 == 0) {
        return 0;
      }
      iVar3 = *(int *)(param_1 + 0x7c);
      iVar1 = *(int *)(*(int *)(param_1 + 4) + 100);
      if (*(int *)(param_1 + 0x1c) != 0) goto LAB_000ef800;
    }
  }
  uVar2 = *(undefined4 *)(iVar1 + 0x18);
  uVar4 = *(undefined4 *)(iVar1 + 0x1c);
LAB_000ef7e2:
  __n = (**(code **)(iVar1 + 0x14))(param_1,uVar2,uVar4,iVar3 + 0x100);
  if (__n != 0) {
    iVar1 = *(int *)(param_1 + 0x7c);
    *(uint *)(iVar1 + 0x180) = __n;
    iVar1 = WPACKET_memcpy(param_2,iVar1 + 0x100,__n);
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,0x167,0x44,"ssl/statem/statem_lib.c",0x23f);
      return 0;
    }
    if (((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
        (iVar1 = **(int **)(param_1 + 4), 0x303 < iVar1 && iVar1 != 0x10000)) ||
       (iVar1 = ssl_log_secret(param_1,"CLIENT_RANDOM",*(int *)(param_1 + 0x474) + 0x48,
                               *(undefined4 *)(*(int *)(param_1 + 0x474) + 4)), iVar1 != 0)) {
      if (__n < 0x41) {
        iVar1 = *(int *)(param_1 + 0x7c);
        if (*(int *)(param_1 + 0x1c) != 0) {
          memcpy((void *)(iVar1 + 0x2f4),(void *)(iVar1 + 0x100),__n);
          *(uint *)(*(int *)(param_1 + 0x7c) + 0x334) = __n;
          return 1;
        }
        memcpy((void *)(iVar1 + 0x2b0),(void *)(iVar1 + 0x100),__n);
        *(uint *)(*(int *)(param_1 + 0x7c) + 0x2f0) = __n;
        return 1;
      }
      ossl_statem_fatal(param_1,0x50,0x167,0x44,"ssl/statem/statem_lib.c",0x253);
    }
  }
  return 0;
}

