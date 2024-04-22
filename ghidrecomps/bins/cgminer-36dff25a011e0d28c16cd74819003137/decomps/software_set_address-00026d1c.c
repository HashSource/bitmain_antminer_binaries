
/* WARNING: Unknown calling convention */

void software_set_address(void)

{
  uint8_t i;
  
  dev->addrInterval = '\x05';
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    set_addr_one_chain(i);
  }
  return;
}

