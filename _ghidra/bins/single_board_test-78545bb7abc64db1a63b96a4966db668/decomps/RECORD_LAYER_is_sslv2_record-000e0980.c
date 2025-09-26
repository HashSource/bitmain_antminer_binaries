
bool RECORD_LAYER_is_sslv2_record(int param_1)

{
  return *(int *)(param_1 + 0x2a8) == 2;
}

