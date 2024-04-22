
int dtls1_set_message_header
              (int param_1,int param_2,undefined param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if ((param_5 == 0) && (*(int *)(iVar1 + 0x254) == 0)) {
    *(short *)(iVar1 + 0x224) = *(short *)(iVar1 + 0x226);
    *(short *)(iVar1 + 0x226) = *(short *)(iVar1 + 0x226) + 1;
  }
  *(undefined *)(iVar1 + 0x260) = param_3;
  *(undefined4 *)(iVar1 + 0x264) = param_4;
  *(int *)(iVar1 + 0x26c) = param_5;
  *(undefined4 *)(iVar1 + 0x270) = param_6;
  *(undefined2 *)(iVar1 + 0x268) = *(undefined2 *)(iVar1 + 0x224);
  return param_2 + 0xc;
}

