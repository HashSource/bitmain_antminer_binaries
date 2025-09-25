
void set_freq(uint32_t chain,uint8_t mode,uint8_t chip_addr,uint8_t pll_id,pll_conf pll_config)

{
  undefined4 uVar1;
  uint8_t uVar2;
  uint8_t uVar4;
  uint8_t uVar6;
  undefined1 uVar8;
  uint8_t pll_id_local;
  uint8_t chip_addr_local;
  uint8_t mode_local;
  uint32_t chain_local;
  undefined4 uVar3;
  undefined3 uVar5;
  undefined2 uVar7;
  
  if (mode == '\0') {
    uVar1 = pll_config.pll_param._0_4_;
    uVar2 = (char)uVar1;
    register0x0000002d = (char)((uint)uVar1 >> 8);
    register0x0000002e = (char)((uint)uVar1 >> 0x10);
    register0x0000002f = (char)((uint)uVar1 >> 0x18);
    set_asic_pllparameter
              ((uint8_t)chain,(uint)chip_addr,pll_id,
               (pllparameter_t)CONCAT24(pll_config.pll_param._0_2_,uVar3));
  }
  else {
    set_chain_pllparameter((uint8_t)chain,pll_id,pll_config.pll_param);
  }
  return;
}

