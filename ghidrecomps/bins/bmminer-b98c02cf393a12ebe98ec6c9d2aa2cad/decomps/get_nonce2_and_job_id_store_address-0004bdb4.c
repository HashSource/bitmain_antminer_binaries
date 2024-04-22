
undefined4 get_nonce2_and_job_id_store_address(void)

{
  FILE *__stream;
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(axi_fpga_addr + 0x110);
  if (log_level < 6) {
    return uVar1;
  }
  __stream = fopen(log_file,(char *)&DAT_0005e760);
  if (__stream != (FILE *)0x0) {
    fprintf(__stream,"%s:%d:%s: nonce2_and_job_id_store_address is 0x%x\n","znyq7010.c",0x7e,
            DAT_0004be1c,uVar1);
  }
  fclose(__stream);
  return uVar1;
}

