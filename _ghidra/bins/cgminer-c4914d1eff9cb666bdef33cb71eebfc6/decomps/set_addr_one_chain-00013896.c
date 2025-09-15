
void set_addr_one_chain(uint8_t chain)

{
  FILE *__stream;
  int iVar1;
  uint8_t chain_local;
  FILE *pFile;
  uchar chip_addr;
  int j;
  
  if (4 < log_level) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: -- %d, -- interval %d\n","asic.c",0x2b0,"set_addr_one_chain",
              (uint)chain,(uint)dev->addrInterval);
    }
    fclose(__stream);
  }
  if ((dev->chain_exist[chain] == 1) && (dev->chain_asic_num[chain] != '\0')) {
    chip_addr = '\0';
    chain_inactive(chain);
    cgsleep_ms(0x1e);
    chain_inactive(chain);
    cgsleep_ms(0x1e);
    chain_inactive(chain);
    cgsleep_ms(0x1e);
    for (j = 0; iVar1 = __aeabi_idiv(0x100,dev->addrInterval), j < iVar1; j = j + 1) {
      set_address(chain,'\0',chip_addr);
      cgsleep_ms(2);
      set_core_number_BM1390(chain,chip_addr);
      chip_addr = chip_addr + dev->addrInterval;
      cgsleep_ms(0x32);
    }
  }
  return;
}

