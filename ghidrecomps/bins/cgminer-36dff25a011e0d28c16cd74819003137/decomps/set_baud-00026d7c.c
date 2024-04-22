
/* WARNING: Variable defined which should be unmapped: no_use-local */

void set_baud(int baud,int no_use)

{
  int no_use_local;
  int baud_local;
  int chain;
  
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    set_baud_one_chain(baud,0,(uchar)chain);
  }
  cgsleep_us(CONCAT44(baud,no_use));
  set_baud_fpga(baud);
  dev->baud = baud;
  return;
}

