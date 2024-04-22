
void dtls1_reset_seq_numbers(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 << 0x1f < 0) {
    iVar4 = *(int *)(param_1 + 0x5c);
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x58) + 8);
    *(undefined4 *)(iVar4 + 0x20c) = *(undefined4 *)(iVar4 + 0x218);
    *(undefined4 *)(iVar4 + 0x210) = *(undefined4 *)(iVar4 + 0x21c);
    *(undefined4 *)(iVar4 + 0x214) = *(undefined4 *)(iVar4 + 0x220);
    iVar3 = *(int *)(param_1 + 0x5c);
    *(short *)(iVar4 + 0x208) = *(short *)(iVar4 + 0x208) + 1;
    *(undefined *)(iVar3 + 0x218) = 0;
    *(undefined *)(iVar3 + 0x219) = 0;
    *(undefined *)(iVar3 + 0x21a) = 0;
    *(undefined *)(iVar3 + 0x21b) = 0;
    *(undefined *)(iVar3 + 0x21c) = 0;
    *(undefined *)(iVar3 + 0x21d) = 0;
    *(undefined *)(iVar3 + 0x21e) = 0;
    *(undefined *)(iVar3 + 0x21f) = 0;
    *(undefined *)(iVar3 + 0x220) = 0;
    *(undefined *)(iVar3 + 0x221) = 0;
    *(undefined *)(iVar3 + 0x222) = 0;
    *(undefined *)(iVar3 + 0x223) = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x5c);
    puVar1 = (undefined4 *)(*(int *)(param_1 + 0x58) + 0x54);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x58);
    *(undefined4 *)(iVar3 + 0x22a) = *puVar1;
    *(undefined4 *)(iVar3 + 0x22e) = uVar2;
    *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) = *(short *)(*(int *)(param_1 + 0x5c) + 0x20a) + 1;
  }
  *(undefined *)puVar1 = 0;
  *(undefined *)((int)puVar1 + 1) = 0;
  *(undefined *)((int)puVar1 + 2) = 0;
  *(undefined *)((int)puVar1 + 3) = 0;
  *(undefined *)(puVar1 + 1) = 0;
  *(undefined *)((int)puVar1 + 5) = 0;
  *(undefined *)((int)puVar1 + 6) = 0;
  *(undefined *)((int)puVar1 + 7) = 0;
  return;
}

