
/* WARNING: Unknown calling convention */

void get_hash_board_id_number(uchar chain,uchar *id)

{
  uchar which_iic;
  
  if (*DAT_0002cde0 < 0xe) {
    AT24C02_read_bytes(0x80,id,chain / 3,'\f');
    return;
  }
  if (chain - 1 < 0xd) {
    which_iic = *(uchar *)(DAT_0002cde4 + (chain - 1) * 4 + 0x9b8);
  }
  else {
    which_iic = '\0';
  }
  AT24C02_read_bytes(0x80,id,which_iic,'\f');
  return;
}

