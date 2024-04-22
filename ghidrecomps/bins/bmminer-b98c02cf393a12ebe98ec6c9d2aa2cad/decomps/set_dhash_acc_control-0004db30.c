
void set_dhash_acc_control(uint param_1)

{
  uint uVar1;
  FILE *pFVar2;
  int iVar3;
  
  uVar1 = log_level;
  *(uint *)(axi_fpga_addr + 0x100) = param_1;
  if (5 < uVar1) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: set DHASH_ACC_CONTROL is 0x%x\n","znyq7010.c",0x2fe,DAT_0004dc0c,
              param_1);
    }
    fclose(pFVar2);
  }
  iVar3 = 10;
  do {
    uVar1 = get_dhash_acc_control();
    if ((param_1 | 0x80) == (uVar1 | 0x80)) {
      return;
    }
    *(uint *)(axi_fpga_addr + 0x100) = param_1;
    usleep(2000);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (log_level < 6) {
    return;
  }
  pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
  if (pFVar2 != (FILE *)0x0) {
    fprintf(pFVar2,"%s:%d:%s: set DHASH_ACC_CONTROL failed!","znyq7010.c",0x308,DAT_0004dc0c);
  }
  (*(code *)PTR_fclose_0007cfe8)(pFVar2);
  return;
}

