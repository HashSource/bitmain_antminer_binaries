
int aep_get_connection(undefined4 *param_1)

{
  __pid_t _Var1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar5 = DAT_000d99c4;
  CRYPTO_lock(9,0x1e,DAT_000d99c8,0x36a);
  _Var1 = getpid();
  iVar7 = DAT_000d99c4;
  if (*(int *)(iVar5 + 0x828) == _Var1) {
    iVar2 = 0;
    do {
      iVar4 = iVar2 * 8;
      iVar3 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      if (*(int *)(iVar5 + 0x28 + iVar4) == 1) {
        iVar3 = DAT_000d99c4 + iVar3;
        iVar2 = 0;
        *(undefined4 *)(iVar3 + 0x28) = 2;
        *param_1 = *(undefined4 *)(iVar3 + 0x2c);
        goto LAB_000d98e2;
      }
    } while (iVar2 != 0x100);
    iVar2 = 0;
    do {
      iVar4 = iVar2 * 8;
      iVar3 = iVar2 * 8;
      iVar2 = iVar2 + 1;
      if (*(int *)(iVar5 + 0x28 + iVar4) == 0) {
        iVar2 = (**(code **)(DAT_000d99c4 + 0x1c))(param_1);
        if (iVar2 == 0) {
          uVar6 = *param_1;
          iVar7 = iVar7 + iVar3;
          *(undefined4 *)(iVar7 + 0x28) = 2;
          *(undefined4 *)(iVar7 + 0x2c) = uVar6;
        }
        else {
          iVar5 = *(int *)(iVar7 + 4);
          if (iVar5 == 0) {
            iVar5 = ERR_get_next_error_library();
            *(int *)(iVar7 + 4) = iVar5;
          }
          ERR_put_error(iVar5,0x66,0x73,DAT_000d99c8,0x3c9);
        }
        goto LAB_000d98e2;
      }
    } while (iVar2 != 0x100);
    iVar2 = 0x10000001;
  }
  else {
    *(__pid_t *)(iVar5 + 0x828) = _Var1;
    (**(code **)(iVar5 + 0x14))();
    iVar2 = (**(code **)(iVar5 + 0x18))(0);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(iVar5 + 0x20))(DAT_000d99d4,DAT_000d99cc,DAT_000d99d0);
      if (iVar2 == 0) {
        do {
          iVar7 = iVar5 + 0x28 + iVar2;
          *(undefined4 *)(iVar5 + 0x28 + iVar2) = 0;
          iVar2 = iVar2 + 8;
          *(undefined4 *)(iVar7 + 4) = 0;
          iVar7 = DAT_000d99c4;
        } while (iVar2 != 0x800);
        iVar2 = (**(code **)(DAT_000d99c4 + 0x1c))(param_1);
        if (iVar2 == 0) {
          uVar6 = *param_1;
          *(undefined4 *)(iVar7 + 0x28) = 2;
          *(undefined4 *)(iVar7 + 0x2c) = uVar6;
        }
        else {
          iVar4 = *(int *)(iVar7 + 4);
          if (iVar4 == 0) {
            iVar4 = ERR_get_next_error_library();
            *(int *)(iVar7 + 4) = iVar4;
          }
          ERR_put_error(iVar4,0x66,0x73,DAT_000d99c8,0x3aa);
          *(undefined4 *)(iVar5 + 0x828) = 0;
        }
      }
      else {
        iVar7 = *(int *)(iVar5 + 4);
        if (iVar7 == 0) {
          iVar7 = ERR_get_next_error_library();
          *(int *)(iVar5 + 4) = iVar7;
        }
        ERR_put_error(iVar7,0x66,0x72,DAT_000d99c8,0x391);
        *(undefined4 *)(iVar5 + 0x828) = 0;
      }
    }
    else {
      iVar7 = *(int *)(iVar5 + 4);
      if (iVar7 == 0) {
        iVar7 = ERR_get_next_error_library();
        *(int *)(iVar5 + 4) = iVar7;
      }
      ERR_put_error(iVar7,0x66,0x6b,DAT_000d99c8,900);
      *(undefined4 *)(iVar5 + 0x828) = 0;
    }
  }
LAB_000d98e2:
  CRYPTO_lock(10,0x1e,DAT_000d99c8,0x3d4);
  return iVar2;
}

