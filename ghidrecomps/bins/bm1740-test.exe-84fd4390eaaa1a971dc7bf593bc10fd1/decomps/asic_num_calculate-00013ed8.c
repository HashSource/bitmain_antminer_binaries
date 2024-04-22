
void asic_num_calculate(void)

{
  int iVar1;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined4 local_18;
  int local_10;
  int local_c;
  
  local_23 = 1;
  local_24 = 0;
  local_22 = 0;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    midd_ioctl(*(undefined4 *)(g_chain + local_c * 0x28),0,&local_24);
  }
  usleep(1000000);
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    local_1c = (undefined)local_c;
    local_1b = 0;
    local_1a = 0;
    local_18 = 0;
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      iVar1 = read_reg_item(&local_1c);
      if (0 < iVar1) {
        (&asic_num)[local_c] = (&asic_num)[local_c] + 1;
        printf("chain_id %d, asic_id %d, value %08x\n",local_c,local_10,local_18);
      }
    }
  }
  return;
}

