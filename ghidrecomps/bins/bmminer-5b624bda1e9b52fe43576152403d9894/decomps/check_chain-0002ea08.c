
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void check_chain(void)

{
  all_parameters *paVar1;
  int iVar2;
  all_parameters *paVar3;
  uint uVar4;
  uint uVar5;
  all_parameters *paVar6;
  bool bVar7;
  
  dev->chain_num = '\0';
  iVar2 = get_hash_on_plug();
  paVar1 = dev;
  if (iVar2 < 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      check_chain();
      return;
    }
  }
  else {
    uVar5 = 0;
    paVar3 = dev;
    paVar6 = dev;
    do {
      uVar4 = uVar5 & 0xff;
      uVar5 = uVar5 + 1;
      uVar4 = iVar2 >> uVar4 & 1;
      bVar7 = uVar4 == 0;
      if (!bVar7) {
        paVar3->chain_exist[0] = 1;
      }
      paVar3 = (all_parameters *)&paVar3->pwm_value;
      if (!bVar7) {
        uVar4 = (uint)paVar1->chain_num;
      }
      if (bVar7) {
        paVar6->chain_exist[0] = uVar4;
      }
      paVar6 = (all_parameters *)&paVar6->pwm_value;
      if (!bVar7) {
        paVar1->chain_num = (char)uVar4 + '\x01';
      }
    } while (uVar5 != 0x10);
  }
  return;
}

