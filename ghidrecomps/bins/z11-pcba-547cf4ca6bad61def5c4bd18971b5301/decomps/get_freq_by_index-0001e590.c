
undefined4 get_freq_by_index(int param_1)

{
  return *(undefined4 *)(freq_pll + param_1 * 0x10);
}

