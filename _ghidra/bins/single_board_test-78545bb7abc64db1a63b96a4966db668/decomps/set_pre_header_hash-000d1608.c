
/* WARNING: Unknown calling convention */

void set_pre_header_hash(uint32_t *value)

{
  uint32_t address;
  uint32_t uVar1;
  uint32_t *puVar2;
  
  puVar2 = value + -1;
  address = 0x31;
  do {
    uVar1 = address + 1;
    puVar2 = puVar2 + 1;
    fpga_write(address,*puVar2);
    address = uVar1;
  } while (uVar1 != 0x39);
  return;
}

