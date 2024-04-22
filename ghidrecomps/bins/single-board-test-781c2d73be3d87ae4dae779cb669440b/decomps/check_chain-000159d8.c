
/* WARNING: Unknown calling convention */

int check_chain(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  chain_info *pcVar6;
  
  iVar2 = DAT_00015ac4;
  printf("\n--- %s\n","check_chain");
  *(undefined4 *)(iVar2 + 0x2ec) = 0;
  uVar1 = read_axi_fpga(2);
  if (uVar1 - 1 < 2 || (uVar1 - 4 & 0xfffffffb) == 0) {
    pcVar6 = chain_info;
    puVar4 = (undefined4 *)(iVar2 + 0x2f8);
    uVar3 = 0;
    do {
      chain_info[uVar3].which_chain = '\0';
      pcVar6->which_i2c = '\0';
      if (((int)uVar1 >> (uVar3 & 0xff) & 1U) == 0) {
        *puVar4 = 0;
      }
      else {
        *puVar4 = 1;
        gI2c = '\0';
        iVar5 = *(int *)(iVar2 + 0x2ec);
        gChain = (uchar)uVar3;
        chain_info[uVar3].which_chain = (uchar)uVar3;
        *(int *)(iVar2 + 0x2ec) = iVar5 + 1;
        printf("\n--- %s: gChain = %d, gI2c = %d\n","check_chain",uVar3,0);
      }
      uVar3 = uVar3 + 1;
      pcVar6 = pcVar6 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 != 4);
    iVar2 = 0;
  }
  else {
    printf("\n!!! %s: Test zhiju only support 1 plug, but now is 0x%08x\n","check_chain",uVar1);
    iVar2 = -1;
  }
  return iVar2;
}

