
undefined4 EC_POINT_set_compressed_coordinates_GF2m(uint **param_1,uint **param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  
  puVar2 = *param_1;
  if (((code *)puVar2[0x13] == (code *)0x0) && ((*puVar2 & 1) == 0)) {
    ERR_put_error(0x10,0xba,0x42,DAT_000a39ec,0x72);
    uVar1 = 0;
  }
  else if (puVar2 == *param_2) {
    if ((*puVar2 & 1) != 0) {
      if (puVar2[1] != 0x196) {
        uVar1 = ec_GF2m_simple_set_compressed_coordinates();
        return uVar1;
      }
      uVar1 = ec_GFp_simple_set_compressed_coordinates();
      return uVar1;
    }
    uVar1 = (*(code *)puVar2[0x13])();
  }
  else {
    ERR_put_error(0x10,0xba,0x65,DAT_000a39ec,0x77);
    uVar1 = 0;
  }
  return uVar1;
}

