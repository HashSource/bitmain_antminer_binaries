
void DTLS_RECORD_LAYER_set_write_sequence(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x8d8) = *param_2;
  *(undefined4 *)(param_1 + 0x8dc) = uVar1;
  return;
}

