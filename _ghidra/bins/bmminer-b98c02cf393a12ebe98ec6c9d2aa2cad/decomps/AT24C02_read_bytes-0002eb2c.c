
void AT24C02_read_bytes(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_1 + param_4 < 0x101) {
    AT24C02_read_bytes_part_7();
    return;
  }
  return;
}

