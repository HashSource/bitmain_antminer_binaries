
void DTLS_RECORD_LAYER_set_saved_w_epoch(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x8e8);
  if (param_2 == *(ushort *)(iVar1 + 2) - 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x8dc);
    *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(param_1 + 0x8d8);
    *(undefined4 *)(iVar1 + 0x40) = uVar2;
    iVar1 = *(int *)(param_1 + 0x8e8);
    uVar2 = *(undefined4 *)(iVar1 + 0x38);
    *(undefined4 *)(param_1 + 0x8d8) = *(undefined4 *)(iVar1 + 0x34);
    *(undefined4 *)(param_1 + 0x8dc) = uVar2;
  }
  else if (param_2 == *(ushort *)(iVar1 + 2) + 1) {
    uVar2 = *(undefined4 *)(param_1 + 0x8dc);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_1 + 0x8d8);
    *(undefined4 *)(iVar1 + 0x38) = uVar2;
    iVar1 = *(int *)(param_1 + 0x8e8);
    uVar2 = *(undefined4 *)(iVar1 + 0x40);
    *(undefined4 *)(param_1 + 0x8d8) = *(undefined4 *)(iVar1 + 0x3c);
    *(undefined4 *)(param_1 + 0x8dc) = uVar2;
    *(short *)(iVar1 + 2) = (short)param_2;
    return;
  }
  *(short *)(iVar1 + 2) = (short)param_2;
  return;
}

