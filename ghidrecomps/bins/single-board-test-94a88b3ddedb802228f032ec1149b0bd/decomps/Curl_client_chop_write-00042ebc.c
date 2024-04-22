
undefined4 Curl_client_chop_write(int *param_1,uint param_2,void *param_3,size_t param_4)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  code *pcVar8;
  undefined8 uVar9;
  
  iVar5 = *param_1;
  if (param_4 != 0) {
    if (*(int *)(iVar5 + 0x130) << 0x1b < 0) {
      if (*(uint *)(iVar5 + 0x85c0) != param_2) {
        return 0x38;
      }
      iVar7 = param_4 + *(int *)(iVar5 + 0x85bc);
      iVar3 = (**DAT_00043054)(*(undefined4 *)(iVar5 + 0x85b8),iVar7);
      if (iVar3 == 0) {
        return 0x1b;
      }
      memcpy((void *)(iVar3 + *(int *)(iVar5 + 0x85bc)),param_3,param_4);
      *(int *)(iVar5 + 0x85b8) = iVar3;
      *(int *)(iVar5 + 0x85bc) = iVar7;
      return 0;
    }
    pcVar6 = (code *)(param_2 & 1);
    if (pcVar6 != (code *)0x0) {
      pcVar6 = *(code **)(iVar5 + 0x1a8);
    }
    pcVar8 = (code *)(param_2 & 2);
    if (((pcVar8 != (code *)0x0) && (pcVar8 = *(code **)(iVar5 + 0x1ac), pcVar8 == (code *)0x0)) &&
       (*(int *)(iVar5 + 0x168) != 0)) {
      pcVar8 = *(code **)(iVar5 + 0x1a8);
    }
    do {
      uVar4 = param_4;
      if (0x3fff < param_4) {
        uVar4 = 0x4000;
      }
      if (pcVar6 != (code *)0x0) {
        uVar9 = (*pcVar6)(param_3,1,uVar4,*(undefined4 *)(iVar5 + 0x160));
        uVar1 = (uint)uVar9;
        if (uVar1 == 0x10000001) {
          if ((*(uint *)(param_1[0x86] + 0x40) & 0x10) != 0) {
            Curl_failf(iVar5,DAT_00043044);
            return 0x17;
          }
          pvVar2 = (void *)(**DAT_0004304c)(param_4,(int)((ulonglong)uVar9 >> 0x20),0x10000001);
          if (pvVar2 == (void *)0x0) {
            return 0x1b;
          }
          memcpy(pvVar2,param_3,param_4);
          *(void **)(iVar5 + 0x85b8) = pvVar2;
          *(size_t *)(iVar5 + 0x85bc) = param_4;
          *(uint *)(iVar5 + 0x85c0) = param_2;
          *(uint *)(iVar5 + 0x130) = *(uint *)(iVar5 + 0x130) | 0x10;
          return 0;
        }
        if (uVar1 != uVar4) {
          Curl_failf(iVar5,DAT_00043048,uVar1,uVar4);
          return 0x17;
        }
      }
      if (pcVar8 != (code *)0x0) {
        uVar1 = (*pcVar8)(param_3,1,uVar4,*(undefined4 *)(iVar5 + 0x168));
        if (uVar1 == 0x10000001) {
          pvVar2 = (void *)(**DAT_0004304c)(param_4);
          if (pvVar2 == (void *)0x0) {
            return 0x1b;
          }
          memcpy(pvVar2,param_3,param_4);
          *(void **)(iVar5 + 0x85b8) = pvVar2;
          *(size_t *)(iVar5 + 0x85bc) = param_4;
          *(undefined4 *)(iVar5 + 0x85c0) = 2;
          *(uint *)(iVar5 + 0x130) = *(uint *)(iVar5 + 0x130) | 0x10;
          return 0;
        }
        if (uVar1 != uVar4) {
          Curl_failf(iVar5,DAT_00043050);
          return 0x17;
        }
      }
      param_4 = param_4 - uVar4;
      param_3 = (void *)((int)param_3 + uVar4);
    } while (param_4 != 0);
  }
  return 0;
}

