
void set_asic_ticket_mask(uint ticket_mask)

{
  uint ticket_mask_local;
  uint8_t tmp;
  int ticket_mask_bit_swap;
  int i;
  
  ticket_mask_bit_swap = 0;
  ticket_mask_local = ticket_mask;
  for (i = 0; (uint)i < 4; i = i + 1) {
    ticket_mask_bit_swap =
         ticket_mask_bit_swap | (uint)bit_swap_table[ticket_mask_local & 0xff] << ((i & 0x1fU) << 3)
    ;
    ticket_mask_local = ticket_mask_local >> 8;
  }
  send_set_config_command_all_chain('\x01','\0','\x14',ticket_mask_bit_swap);
  return;
}

