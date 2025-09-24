
bool dtls_buffer_listen_record(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = param_4;
  memset((void *)(param_1 + 0x8f8),0,0x30);
  *(int *)(param_1 + 0x900) = param_2;
  *(undefined4 *)(param_1 + 0x8fc) = 0x16;
  uVar3 = *param_3;
  uVar2 = param_3[1];
  *(int *)(param_1 + 0xefc) = param_2 + 0xd;
  *(undefined4 *)(param_1 + 0x920) = uVar3;
  *(undefined4 *)(param_1 + 0x924) = uVar2;
  *(undefined4 *)(param_1 + 0x908) = param_4;
  *(int *)(param_1 + 0xef8) = *(int *)(param_1 + 0x664);
  *(int *)(param_1 + 0x90c) = *(int *)(param_1 + 0x664) + 0xd;
  iVar1 = dtls1_buffer_record(param_1,*(int *)(param_1 + 0xf38) + 0x24,param_1 + 0x920,uVar2,uVar4);
  return 0 < iVar1;
}

