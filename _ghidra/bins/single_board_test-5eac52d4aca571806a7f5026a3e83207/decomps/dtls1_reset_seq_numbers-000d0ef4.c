
void dtls1_reset_seq_numbers(int param_1,int param_2)

{
  undefined4 uVar1;
  short *psVar2;
  int iVar3;
  
  if (-1 < param_2 << 0x1f) {
    iVar3 = *(int *)(param_1 + 0xf38);
    uVar1 = *(undefined4 *)(param_1 + 0xf28);
    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(param_1 + 0xf2c);
    *(undefined4 *)(iVar3 + 0x34) = uVar1;
    *(short *)(*(int *)(param_1 + 0xf38) + 2) = *(short *)(*(int *)(param_1 + 0xf38) + 2) + 1;
    *(undefined4 *)(param_1 + 0xf28) = 0;
    *(undefined4 *)(param_1 + 0xf2c) = 0;
    return;
  }
  psVar2 = *(short **)(param_1 + 0xf38);
  *psVar2 = *psVar2 + 1;
  *(undefined4 *)(psVar2 + 2) = *(undefined4 *)(psVar2 + 8);
  *(undefined4 *)(psVar2 + 4) = *(undefined4 *)(psVar2 + 10);
  *(undefined4 *)(psVar2 + 6) = *(undefined4 *)(psVar2 + 0xc);
  iVar3 = *(int *)(param_1 + 0xf38);
  *(undefined4 *)(iVar3 + 0x10) = 0;
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined4 *)(iVar3 + 0x18) = 0;
  dtls1_clear_received_buffer();
  *(undefined4 *)(param_1 + 0xf20) = 0;
  *(undefined4 *)(param_1 + 0xf24) = 0;
  return;
}

