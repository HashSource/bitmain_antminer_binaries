
void RECORD_LAYER_release(undefined4 *param_1)

{
  if (param_1[5] != 0) {
    ssl3_release_read_buffer(*param_1);
  }
  if (param_1[4] != 0) {
    ssl3_release_write_buffer(*param_1);
  }
  SSL3_RECORD_release(param_1 + 0xaa,0x20);
  return;
}

