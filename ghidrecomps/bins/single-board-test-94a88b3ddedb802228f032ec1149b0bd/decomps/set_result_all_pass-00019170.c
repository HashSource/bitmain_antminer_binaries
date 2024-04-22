
void set_result_all_pass(int param_1)

{
  int local_c;
  
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    *(undefined4 *)(last_result + (local_c + param_1 * 0x100) * 4) = 1;
  }
  return;
}

