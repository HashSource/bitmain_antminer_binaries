
/* WARNING: Unknown calling convention */

uchar is_work_fifo_ready(uint32_t chain)

{
  uint32_t val;
  
  fpga_read(3,&val);
  return (byte)(1 << (chain & 0xff)) & (byte)val;
}

