
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void fpga_chain_reset_all(void)

{
  uint32_t val;
  
  val = 0;
  fpga_read(0xd,&val);
  fpga_write(0xd,~(~(val >> 0x10) << 0x10));
  sleep(3);
  fpga_read(0xd,&val);
  fpga_write(0xd,val & 0xffff0000);
  sleep(1);
  stop_generate_work_for_job();
  return;
}

