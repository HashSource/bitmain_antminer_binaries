
/* WARNING: Unknown calling convention */

int32_t set_chain_asic_nonce_space_divide
                  (uint8_t which_chain,uint32_t addr_interval,uint32_t asic_num)

{
  uint16_t chip_nonce_offset;
  uint uVar1;
  uint32_t which_asic_address;
  uint32_t uVar2;
  int iVar3;
  uint uVar4;
  
  if (asic_num == 0) {
    uVar4 = 0;
  }
  else {
    which_asic_address = 0;
    iVar3 = asic_num - 1;
    uVar2 = 0;
    uVar4 = 0;
    do {
      chip_nonce_offset = __aeabi_uidiv(iVar3,asic_num);
      uVar2 = uVar2 + 1;
      uVar1 = set_asic_chip_nonce_offset(which_chain,which_asic_address,true,chip_nonce_offset);
      iVar3 = iVar3 + 0x10000;
      which_asic_address = which_asic_address + addr_interval;
      uVar4 = uVar4 | uVar1;
    } while (uVar2 != asic_num);
  }
  return uVar4;
}

