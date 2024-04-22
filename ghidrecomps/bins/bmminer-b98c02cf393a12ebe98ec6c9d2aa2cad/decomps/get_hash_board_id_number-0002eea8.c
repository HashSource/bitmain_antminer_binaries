
void get_hash_board_id_number(undefined4 param_1,undefined4 param_2)

{
  AT24C02_read_bytes_part_7(0x80,param_2,param_1,0xc);
  return;
}

