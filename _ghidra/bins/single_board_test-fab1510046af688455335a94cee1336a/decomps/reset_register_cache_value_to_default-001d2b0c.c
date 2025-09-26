
/* WARNING: Unknown calling convention */

int32_t reset_register_cache_value_to_default(uint8_t which_chain)

{
  asic_register_value_t (*paaVar1) [128];
  asic_register_value_t (*__dest) [128];
  asic_register_value_t (*paaVar2) [128];
  uint uVar3;
  asic_register_value_t (*__dest_00) [128];
  
  if (which_chain < 4) {
    __dest_00 = hashboard_register_value;
    uVar3 = 0;
    paaVar1 = hashboard_asic_register_value[0];
    do {
      __dest = paaVar1;
      if (which_chain == uVar3) {
        do {
          paaVar2 = __dest + 1;
          memcpy(__dest,default_register_value,0x400);
          __dest = paaVar2;
        } while (paaVar2 != paaVar1 + 0x100);
        memcpy(__dest_00,default_register_value,0x400);
      }
      uVar3 = uVar3 + 1;
      __dest_00 = __dest_00 + 1;
      paaVar1 = paaVar1 + 0x100;
    } while (uVar3 != 4);
    return 0;
  }
  return -1;
}

