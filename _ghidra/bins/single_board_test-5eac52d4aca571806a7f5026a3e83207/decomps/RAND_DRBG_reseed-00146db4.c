
bool RAND_DRBG_reseed(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  time_t tVar3;
  int *piVar4;
  code *pcVar5;
  int local_1c;
  
  local_1c = 0;
  if (*(int *)(param_1 + 0x5c) == 2) {
    ERR_put_error(0x24,0x6e,0x72,"crypto/rand/drbg_lib.c",0x199);
    return false;
  }
  if (*(int *)(param_1 + 0x5c) == 0) {
    ERR_put_error(0x24,0x6e,0x73,"crypto/rand/drbg_lib.c",0x19d);
    return false;
  }
  if (param_2 == 0) {
    pcVar5 = *(code **)(param_1 + 0xf4);
    *(undefined4 *)(param_1 + 0x5c) = 2;
    param_3 = 0;
    if (pcVar5 != (code *)0x0) goto LAB_00146de4;
    param_3 = 0;
    pcVar5 = (code *)0x0;
LAB_00146e3e:
    if (*(int *)(param_1 + 0x28) == 0) {
      pcVar5 = (code *)0x0;
LAB_00146e46:
      iVar2 = (**(code **)(*(int *)(param_1 + 0xf0) + 4))(param_1,local_1c,pcVar5,param_2,param_3);
      if (iVar2 != 0) {
        *(undefined4 *)(param_1 + 0x5c) = 1;
        *(undefined4 *)(param_1 + 0x40) = 1;
        tVar3 = time((time_t *)0x0);
        *(time_t *)(param_1 + 0x48) = tVar3;
        if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 4) == 0)) {
          piVar4 = (int *)(param_1 + 0x54);
          do {
            ExclusiveAccess(piVar4);
            bVar1 = (bool)hasExclusiveAccess(piVar4);
          } while (!bVar1);
          *piVar4 = *piVar4 + 1;
        }
      }
      goto LAB_00146e1c;
    }
  }
  else {
    if (*(uint *)(param_1 + 0x3c) < param_3) {
      ERR_put_error(0x24,0x6e,0x66,"crypto/rand/drbg_lib.c",0x1a4);
      return false;
    }
    pcVar5 = *(code **)(param_1 + 0xf4);
    *(undefined4 *)(param_1 + 0x5c) = 2;
    if (pcVar5 == (code *)0x0) goto LAB_00146e3e;
LAB_00146de4:
    pcVar5 = (code *)(*pcVar5)(param_1,&local_1c,*(undefined4 *)(param_1 + 0x20),
                               *(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x2c),
                               param_4);
    if ((*(code **)(param_1 + 0x28) <= pcVar5) && (pcVar5 <= *(code **)(param_1 + 0x2c)))
    goto LAB_00146e46;
  }
  ERR_put_error(0x24,0x6e,0x6e,"crypto/rand/drbg_lib.c",0x1b0);
LAB_00146e1c:
  if ((local_1c != 0) && (*(code **)(param_1 + 0xf8) != (code *)0x0)) {
    (**(code **)(param_1 + 0xf8))(param_1,local_1c,pcVar5);
  }
  return *(int *)(param_1 + 0x5c) == 1;
}

