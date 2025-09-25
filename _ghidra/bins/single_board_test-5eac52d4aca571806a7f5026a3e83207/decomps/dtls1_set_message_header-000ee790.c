
void dtls1_set_message_header
               (int param_1,undefined1 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)(param_1 + 0x80);
  if (param_4 == 0) {
    sVar2 = *(short *)(iVar1 + 0x10a);
    *(short *)(iVar1 + 0x108) = sVar2;
    *(short *)(iVar1 + 0x10a) = sVar2 + 1;
  }
  else {
    sVar2 = *(short *)(iVar1 + 0x108);
  }
  *(undefined1 *)(iVar1 + 0x120) = param_2;
  *(short *)(iVar1 + 0x128) = sVar2;
  *(undefined4 *)(iVar1 + 0x130) = param_5;
  *(undefined4 *)(iVar1 + 0x124) = param_3;
  *(int *)(iVar1 + 300) = param_4;
  return;
}

