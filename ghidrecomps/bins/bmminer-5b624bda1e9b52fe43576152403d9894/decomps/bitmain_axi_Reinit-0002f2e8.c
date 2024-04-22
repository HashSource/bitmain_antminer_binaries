
/* WARNING: Unknown calling convention */

int bitmain_axi_Reinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint data;
  char logstr [256];
  
  uVar4 = **(uint **)(DAT_0002f354 + 0x8d4);
  if ((undefined *)(uVar4 & 0xffff) != &LAB_0000c500_1) {
    sprintf(logstr,DAT_0002f358,uVar4);
    writeInitLogFile(logstr);
  }
  iVar1 = DAT_0002f360;
  sprintf(logstr,DAT_0002f35c,uVar4);
  writeInitLogFile(logstr);
  iVar2 = DAT_0002f364;
  uVar4 = *(uint *)(iVar1 + 0x8c);
  iVar3 = *(int *)(DAT_0002f364 + 0x200);
  *(int *)(DAT_0002f364 + 0x204) = iVar3;
  *(int *)(iVar2 + 0x208) = iVar3 + 0x200000;
  *(int *)(iVar2 + 0x20c) = iVar3 + 0x210000;
  set_nonce2_and_job_id_store_address(uVar4);
  set_job_start_address(*(int *)(iVar1 + 0x8c) + 0x200000);
  return 0;
}

