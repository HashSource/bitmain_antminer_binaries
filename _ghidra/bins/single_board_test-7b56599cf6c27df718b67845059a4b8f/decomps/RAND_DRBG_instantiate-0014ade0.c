
bool RAND_DRBG_instantiate(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  time_t tVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  int local_28;
  int local_24 [2];
  
  uVar3 = 0;
  local_28 = 0;
  local_24[0] = 0;
  if (*(uint *)(param_1 + 0x38) < param_3) {
    pcVar6 = (code *)0x0;
    ERR_put_error(0x24,0x6c,0x74,"crypto/rand/drbg_lib.c",299);
  }
  else if (*(int *)(param_1 + 0xf0) == 0) {
    ERR_put_error(0x24,0x6c,0x80,"crypto/rand/drbg_lib.c",0x131);
    uVar3 = 0;
    pcVar6 = (code *)0x0;
  }
  else if (*(int *)(param_1 + 0x5c) == 0) {
    *(undefined4 *)(param_1 + 0x5c) = 2;
    iVar4 = *(int *)(param_1 + 0x20);
    uVar7 = *(uint *)(param_1 + 0x28);
    uVar8 = *(uint *)(param_1 + 0x2c);
    if ((*(int *)(param_1 + 0x30) != 0) && (*(int *)(param_1 + 0xfc) == 0)) {
      uVar7 = uVar7 + *(int *)(param_1 + 0x30);
      iVar4 = iVar4 + iVar4 / 2;
      uVar8 = uVar8 + *(int *)(param_1 + 0x34);
    }
    if (*(code **)(param_1 + 0xf4) == (code *)0x0) {
      bVar1 = false;
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)(param_1 + 0xf4))(param_1,local_24,iVar4,uVar7,uVar8,0);
      if (uVar8 < uVar3) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (uVar3 < uVar7) {
      bVar1 = true;
    }
    if (bVar1) {
      pcVar6 = (code *)0x0;
      ERR_put_error(0x24,0x6c,0x6e,"crypto/rand/drbg_lib.c",0x14f);
    }
    else {
      if (*(int *)(param_1 + 0x30) == 0) {
        pcVar6 = (code *)0x0;
      }
      else {
        pcVar6 = *(code **)(param_1 + 0xfc);
        if ((pcVar6 != (code *)0x0) &&
           ((pcVar6 = (code *)(*pcVar6)(param_1,&local_28,*(int *)(param_1 + 0x20) / 2,
                                        *(int *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34)),
            pcVar6 < *(code **)(param_1 + 0x30) || (*(code **)(param_1 + 0x34) < pcVar6)))) {
          ERR_put_error(0x24,0x6c,0x6f,"crypto/rand/drbg_lib.c",0x157);
          goto LAB_0014ae22;
        }
      }
      iVar4 = (*(code *)**(undefined4 **)(param_1 + 0xf0))
                        (param_1,local_24[0],uVar3,local_28,pcVar6,param_2,param_3);
      if (iVar4 == 0) {
        ERR_put_error(0x24,0x6c,0x6c,"crypto/rand/drbg_lib.c",0x15e);
      }
      else {
        *(undefined4 *)(param_1 + 0x5c) = 1;
        *(undefined4 *)(param_1 + 0x40) = 1;
        tVar2 = time((time_t *)0x0);
        *(time_t *)(param_1 + 0x48) = tVar2;
        if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 4) == 0)) {
          piVar5 = (int *)(param_1 + 0x54);
          do {
            ExclusiveAccess(piVar5);
            bVar1 = (bool)hasExclusiveAccess(piVar5);
          } while (!bVar1);
          *piVar5 = *piVar5 + 1;
        }
      }
    }
  }
  else {
    uVar3 = 0;
    pcVar6 = (code *)0x0;
    if (*(int *)(param_1 + 0x5c) == 2) {
      iVar4 = 0x72;
    }
    else {
      iVar4 = 0x67;
    }
    ERR_put_error(0x24,0x6c,iVar4,"crypto/rand/drbg_lib.c",0x138);
  }
LAB_0014ae22:
  if ((local_24[0] != 0) && (*(code **)(param_1 + 0xf8) != (code *)0x0)) {
    (**(code **)(param_1 + 0xf8))(param_1,local_24[0],uVar3);
  }
  if ((local_28 != 0) && (*(code **)(param_1 + 0x100) != (code *)0x0)) {
    (**(code **)(param_1 + 0x100))(param_1,local_28,pcVar6);
  }
  return *(int *)(param_1 + 0x5c) == 1;
}

