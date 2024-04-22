
/* WARNING: Unknown calling convention */

void enable_crab_circuit(void)

{
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      dsPIC33EP16GS202_crab_circuit_control((uint8_t)chain,'\x01');
    }
  }
  return;
}

