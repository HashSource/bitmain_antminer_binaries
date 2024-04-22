
void set_baud_by_chain(uchar bauddiv,int chain)

{
  FILE *pFVar1;
  uint uVar2;
  char *in_stack_ffffffd0;
  int in_stack_ffffffd4;
  int chain_local;
  uchar bauddiv_local;
  uint value;
  FILE *pFile_1;
  uint ret;
  FILE *pFile;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      in_stack_ffffffd0 = "set_baud_by_chain";
      in_stack_ffffffd4 = chain;
      fprintf(pFVar1,"%s:%d:%s: chain %d set baud=%d\n","asic.c",0x498,"set_baud_by_chain",chain,
              (uint)bauddiv);
    }
    fclose(pFVar1);
  }
  set_baud_one_chain(bauddiv,0,(uint8_t)chain);
  cgsleep_us(CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0));
  uVar2 = get_BC_write_command();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: read bc write is 0x%0x\n","asic.c",0x4a0,"set_baud_by_chain",uVar2);
    }
    fclose(pFVar1);
  }
  set_BC_write_command(bauddiv & 0x3f | uVar2 & 0xffffffc0);
  dev->baud = bauddiv;
  return;
}

