
void ClearWorkFIFOAndResetRegisters
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 extraout_r1;
  
  uVar1 = get_dhash_acc_control();
  set_dhash_acc_control(uVar1 | 0x80);
  cgsleep_ms(1);
  set_asic_ticket_mask(0);
  set_hcnt(0);
  set_sno(0,extraout_r1,param_3,param_4);
  return;
}

