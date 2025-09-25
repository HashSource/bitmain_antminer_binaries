
/* WARNING: Unknown calling convention */

int32_t set_one_chip_ticketmask(uint8_t which_chain,uint32_t ticketmask,uint32_t which_asic_addr)

{
  int32_t iVar1;
  
  iVar1 = send_set_config_command
                    (which_chain,'\0',which_asic_addr,0x14,
                     CONCAT13(""[ticketmask >> 0x18],
                              CONCAT12(""[(ticketmask << 8) >> 0x18],
                                       CONCAT11(""[(ticketmask << 0x10) >> 0x18],
                                                ""[ticketmask & 0xff]))));
  return iVar1;
}

