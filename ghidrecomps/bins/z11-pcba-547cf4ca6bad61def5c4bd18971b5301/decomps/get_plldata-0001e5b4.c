
void get_plldata(int param_1,undefined4 *param_2)

{
  uint local_c;
  
  for (local_c = 0; (local_c < 0x65 && (*(int *)(freq_pll + local_c * 0x10) != param_1));
      local_c = local_c + 1) {
  }
  if (local_c == 0x65) {
    local_c = 4;
  }
  *param_2 = *(undefined4 *)(freq_pll + local_c * 0x10 + 0xc);
  return;
}

