
void ClearWorkFIFOAndResetRegisters(void)

{
  uint uVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 | 0x80);
  cgsleep_ms(1);
  set_asic_ticket_mask(0);
  set_hcnt(0);
  set_sno(0,extraout_r1,extraout_r2,in_r3);
  return;
}

