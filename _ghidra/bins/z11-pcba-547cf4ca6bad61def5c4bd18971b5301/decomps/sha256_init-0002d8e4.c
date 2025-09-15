
void sha256_init(undefined4 *param_1)

{
  int local_c;
  
  for (local_c = 0; local_c < 8; local_c = local_c + 1) {
    param_1[local_c + 0x22] = *(undefined4 *)(&sha256_h0 + local_c * 4);
  }
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

