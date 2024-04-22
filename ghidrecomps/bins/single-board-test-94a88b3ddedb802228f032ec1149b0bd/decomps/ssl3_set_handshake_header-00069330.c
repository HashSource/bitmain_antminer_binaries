
void ssl3_set_handshake_header(int param_1,undefined param_2,int param_3)

{
  undefined *puVar1;
  
  puVar1 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
  *puVar1 = param_2;
  puVar1[3] = (char)param_3;
  puVar1[1] = (char)((uint)param_3 >> 0x10);
  puVar1[2] = (char)((uint)param_3 >> 8);
  *(int *)(param_1 + 0x44) = param_3 + 4;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return;
}

