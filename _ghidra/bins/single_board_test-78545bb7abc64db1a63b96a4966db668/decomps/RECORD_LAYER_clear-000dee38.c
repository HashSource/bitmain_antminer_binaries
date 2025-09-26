
void RECORD_LAYER_clear(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                       )

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  param_1[2] = 0xf0;
  param_1[0x22a] = 0;
  param_1[0x22b] = 0;
  param_1[0x22c] = 0;
  param_1[0x22d] = 0;
  param_1[0x22e] = 0;
  param_1[0x230] = 0;
  param_1[0x231] = 0;
  param_1[0x232] = 0;
  param_1[0x233] = 0;
  SSL3_BUFFER_clear();
  ssl3_release_write_buffer(*param_1);
  param_1[3] = 0;
  SSL3_RECORD_clear(param_1 + 0xaa,0x20);
  RECORD_LAYER_reset_read_sequence(param_1);
  RECORD_LAYER_reset_write_sequence(param_1);
  if (param_1[0x23a] != 0) {
    DTLS_RECORD_LAYER_clear(param_1,extraout_r1,extraout_r2,param_4);
    return;
  }
  return;
}

