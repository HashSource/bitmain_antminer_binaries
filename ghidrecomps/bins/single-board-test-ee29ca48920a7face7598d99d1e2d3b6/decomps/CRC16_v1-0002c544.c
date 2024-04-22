
undefined2 CRC16_v1(undefined *param_1,int param_2)

{
  int local_18;
  undefined *local_14;
  undefined2 local_a;
  
  local_a = 0xffff;
  local_18 = param_2;
  local_14 = param_1;
  while (local_18 != 0) {
    local_a = crc_itu_t_byte(local_a,*local_14);
    local_18 = local_18 + -1;
    local_14 = local_14 + 1;
  }
  return local_a;
}

