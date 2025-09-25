
int dtls1_clear(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  bool bVar8;
  
  DTLS_RECORD_LAYER_clear(param_1 + 0x194);
  iVar1 = param_1[0x20];
  if (iVar1 != 0) {
    uVar7 = *(undefined4 *)(iVar1 + 0x194);
    uVar4 = *(undefined4 *)(iVar1 + 0x110);
    uVar3 = *(undefined4 *)(iVar1 + 0x114);
    uVar5 = *(undefined4 *)(iVar1 + 0x11c);
    uVar6 = *(undefined4 *)(iVar1 + 0x118);
    dtls1_clear_received_buffer(param_1);
    dtls1_clear_sent_buffer(param_1);
    memset((void *)param_1[0x20],0,0x198);
    iVar1 = param_1[7];
    iVar2 = param_1[0x20];
    *(undefined4 *)(iVar2 + 0x194) = uVar7;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar2 + 0x100) = 0x100;
    }
    iVar1 = SSL_get_options(param_1);
    iVar2 = param_1[0x20];
    bVar8 = iVar1 << 0x13 < 0;
    if (bVar8) {
      *(undefined4 *)(iVar2 + 0x11c) = uVar5;
    }
    if (bVar8) {
      *(undefined4 *)(iVar2 + 0x118) = uVar6;
    }
    *(undefined4 *)(iVar2 + 0x110) = uVar4;
    *(undefined4 *)(iVar2 + 0x114) = uVar3;
  }
  iVar1 = ssl3_clear(param_1);
  if (iVar1 != 0) {
    if (*(int *)param_1[1] == 0x1ffff) {
      *param_1 = 0xfefd;
      return 1;
    }
    if (param_1[0x13b] << 0x10 < 0) {
      *param_1 = 0x100;
      param_1[0x141] = 0x100;
      return 1;
    }
    iVar1 = 1;
    *param_1 = *(int *)param_1[1];
  }
  return iVar1;
}

