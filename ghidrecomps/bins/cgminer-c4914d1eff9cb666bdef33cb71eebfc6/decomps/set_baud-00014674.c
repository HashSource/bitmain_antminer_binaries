
/* WARNING: Variable defined which should be unmapped: no_use-local */

void set_baud(uchar bauddiv,int no_use)

{
  FILE *pFVar1;
  uint uVar2;
  char *in_stack_ffffffd0;
  uint in_stack_ffffffd4;
  int no_use_local;
  uchar bauddiv_local;
  uint value;
  FILE *pFile_1;
  uint ret;
  FILE *pFile;
  uint i;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      in_stack_ffffffd4 = (uint)bauddiv;
      in_stack_ffffffd0 = "set_baud";
      fprintf(pFVar1,"%s:%d:%s: set baud=%d\n","asic.c",0x481,"set_baud",in_stack_ffffffd4,no_use);
    }
    fclose(pFVar1);
  }
  for (i = 0; i < 0x10; i = i + 1) {
    set_baud_one_chain(bauddiv,0,(uint8_t)i);
  }
  cgsleep_us(CONCAT44(in_stack_ffffffd4,in_stack_ffffffd0));
  uVar2 = get_BC_write_command();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: read bc write is 0x%0x\n","asic.c",0x48c,"set_baud",uVar2);
    }
    fclose(pFVar1);
  }
  set_BC_write_command(bauddiv & 0x3f | uVar2 & 0xffffffc0);
  dev->baud = bauddiv;
  return;
}

