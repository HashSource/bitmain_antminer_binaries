
void eeprom_dump(uint8_t chain)

{
  uint8_t chain_local;
  uint8_t bom;
  uint8_t pcb;
  uint8_t buf [6];
  uint32_t len;
  int i;
  
  if (chain_list[chain] != 0) {
    travel_eeprom_store(chain);
    eeprom_get_inbalance_info(chain,buf,&len);
    printf("inbalance ASIC info: ");
    if (len < 7) {
      for (i = 0; (uint)i < len; i = i + 1) {
        printf("IC[%03d] ",(uint)buf[i]);
      }
    }
    putchar(10);
    eeprom_get_pcb_version(chain,&pcb);
    eeprom_get_bom_version(chain,&bom);
    printf("PCB_Ver:0x%02x  BOM_Ver:0x%02x\n",(uint)pcb,(uint)bom);
  }
  return;
}

