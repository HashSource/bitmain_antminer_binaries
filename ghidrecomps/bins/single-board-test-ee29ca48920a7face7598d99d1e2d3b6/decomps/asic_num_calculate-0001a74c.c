
void asic_num_calculate(void)

{
  int iVar1;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_18;
  undefined local_17;
  undefined local_16;
  undefined4 local_14;
  int local_c;
  
  local_1f = 1;
  local_20 = 0;
  local_1e = 0;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x20),0,&local_20);
  }
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    local_18 = (undefined)local_c;
    local_17 = 0;
    local_16 = 0;
    local_14 = 0;
    iVar1 = read_reg_item(&local_18,500);
    if (0 < iVar1) {
      (&asic_num)[local_c] = (&asic_num)[local_c] + 1;
    }
  }
  return;
}

