
bool RECORD_LAYER_processed_read_pending(int param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar3 = uVar5;
  if (uVar5 != 0) {
    if (*(int *)(param_1 + 0x2c8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar2 = 0;
      iVar4 = param_1 + 0x2a8;
      do {
        uVar2 = uVar2 + 1;
        uVar3 = uVar5;
        if (uVar5 == uVar2) break;
        piVar1 = (int *)(iVar4 + 0x50);
        uVar3 = uVar2;
        iVar4 = iVar4 + 0x30;
      } while (*piVar1 != 0);
    }
  }
  return uVar3 < uVar5;
}

