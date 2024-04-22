
void smb_format_message(int *param_1,void *param_2,undefined param_3,short param_4)

{
  __pid_t _Var1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0x14c);
  memset(param_2,0,0x24);
  *(undefined *)((int)param_2 + 8) = param_3;
  *(undefined4 *)((int)param_2 + 4) = DAT_0013aad4;
  *(undefined *)((int)param_2 + 0xd) = 0x18;
  *(undefined *)((int)param_2 + 0xe) = 0x41;
  *(undefined *)((int)param_2 + 0xf) = 0;
  *(ushort *)((int)param_2 + 2) = (param_4 + 0x20U) * 0x100 | (ushort)(param_4 + 0x20U) >> 8;
  *(undefined2 *)((int)param_2 + 0x20) = *(undefined2 *)(param_1 + 0xf6);
  *(undefined2 *)((int)param_2 + 0x1c) = *(undefined2 *)(iVar2 + 0xc);
  _Var1 = getpid();
  *(short *)((int)param_2 + 0x1e) = (short)_Var1;
  *(short *)((int)param_2 + 0x10) = (short)((uint)_Var1 >> 0x10);
  return;
}

