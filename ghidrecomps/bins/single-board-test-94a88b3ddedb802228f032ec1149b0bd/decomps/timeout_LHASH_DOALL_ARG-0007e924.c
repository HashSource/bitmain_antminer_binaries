
void timeout_LHASH_DOALL_ARG(void *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  
  if ((param_2[1] == 0) ||
     (*(int *)((int)param_1 + 0xac) + *(int *)((int)param_1 + 0xa8) < param_2[1])) {
    lh_delete((_LHASH *)param_2[2],param_1);
    iVar3 = *(int *)((int)param_1 + 0xcc);
    iVar1 = *param_2;
    if ((iVar3 != 0) && (iVar2 = *(int *)((int)param_1 + 200), iVar2 != 0)) {
      if (iVar3 == iVar1 + 0x1c) {
        bVar5 = iVar2 == iVar1 + 0x18;
        if (bVar5) {
          iVar3 = 0;
        }
        if (!bVar5) {
          *(int *)(iVar1 + 0x1c) = iVar2;
        }
        if (bVar5) {
          *(int *)(iVar1 + 0x18) = iVar3;
        }
        if (bVar5) {
          *(int *)(iVar1 + 0x1c) = iVar3;
        }
        if (!bVar5) {
          *(int *)(iVar2 + 0xcc) = iVar3;
        }
      }
      else {
        bVar5 = iVar2 == iVar1 + 0x18;
        if (!bVar5) {
          *(int *)(iVar3 + 200) = iVar2;
          iVar2 = *(int *)((int)param_1 + 200);
        }
        if (bVar5) {
          *(int *)(iVar1 + 0x18) = iVar3;
        }
        if (bVar5) {
          *(int *)(iVar3 + 200) = iVar2;
        }
        if (!bVar5) {
          *(int *)(iVar2 + 0xcc) = iVar3;
        }
      }
      *(undefined4 *)((int)param_1 + 0xcc) = 0;
      *(undefined4 *)((int)param_1 + 200) = 0;
    }
    pcVar4 = *(code **)(iVar1 + 0x2c);
    *(undefined4 *)((int)param_1 + 0x94) = 1;
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(iVar1,param_1);
    }
    iVar1 = CRYPTO_add_lock((int *)((int)param_1 + 0xa4),-1,0xe,DAT_0007e9d0,0x352);
    if (iVar1 < 1) {
      SSL_SESSION_free_part_0(param_1);
      return;
    }
  }
  return;
}

