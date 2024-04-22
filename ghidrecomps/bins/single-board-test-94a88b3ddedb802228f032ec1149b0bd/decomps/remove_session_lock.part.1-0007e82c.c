
int remove_session_lock_part_1(int param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  bool bVar5;
  
  if (param_3 != 0) {
    CRYPTO_lock(9,0xc,DAT_0007e920,0x336);
  }
  pvVar1 = lh_retrieve(*(_LHASH **)(param_1 + 0x10),param_2);
  if (param_2 == pvVar1) {
    pvVar1 = lh_delete(*(_LHASH **)(param_1 + 0x10),param_2);
    iVar4 = *(int *)((int)param_2 + 0xcc);
    if ((iVar4 == 0) || (iVar2 = *(int *)((int)param_2 + 200), iVar2 == 0)) {
      iVar4 = 1;
    }
    else {
      if (iVar4 == param_1 + 0x1c) {
        bVar5 = iVar2 == param_1 + 0x18;
        if (bVar5) {
          iVar4 = 0;
        }
        if (!bVar5) {
          *(int *)(param_1 + 0x1c) = iVar2;
        }
        if (bVar5) {
          *(int *)(param_1 + 0x18) = iVar4;
        }
        if (bVar5) {
          *(int *)(param_1 + 0x1c) = iVar4;
        }
        if (!bVar5) {
          *(int *)(iVar2 + 0xcc) = iVar4;
        }
      }
      else {
        bVar5 = iVar2 == param_1 + 0x18;
        if (!bVar5) {
          *(int *)(iVar4 + 200) = iVar2;
          iVar2 = *(int *)((int)param_2 + 200);
        }
        if (bVar5) {
          *(int *)(param_1 + 0x18) = iVar4;
        }
        if (bVar5) {
          *(int *)(iVar4 + 200) = iVar2;
        }
        if (!bVar5) {
          *(int *)(iVar2 + 0xcc) = iVar4;
        }
      }
      iVar4 = 1;
      *(undefined4 *)((int)param_2 + 0xcc) = 0;
      *(undefined4 *)((int)param_2 + 200) = 0;
    }
  }
  else {
    iVar4 = 0;
  }
  if (param_3 != 0) {
    CRYPTO_lock(10,0xc,DAT_0007e920,0x33e);
  }
  if (iVar4 != 0) {
    pcVar3 = *(code **)(param_1 + 0x2c);
    *(undefined4 *)((int)pvVar1 + 0x94) = 1;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(param_1,pvVar1);
    }
    iVar2 = CRYPTO_add_lock((int *)((int)pvVar1 + 0xa4),-1,0xe,DAT_0007e920,0x352);
    if (iVar2 < 1) {
      SSL_SESSION_free_part_0(pvVar1);
    }
  }
  return iVar4;
}

