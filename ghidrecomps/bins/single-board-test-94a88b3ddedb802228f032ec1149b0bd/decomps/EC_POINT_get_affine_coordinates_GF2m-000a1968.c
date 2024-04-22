
undefined4 EC_POINT_get_affine_coordinates_GF2m(int *param_1,int *param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*param_1 + 0x48);
  if (pcVar2 == (code *)0x0) {
    ERR_put_error(0x10,0xb7,0x42,DAT_000a19b0,0x389);
    uVar1 = 0;
  }
  else if (*param_1 == *param_2) {
    uVar1 = (*pcVar2)();
  }
  else {
    ERR_put_error(0x10,0xb7,0x65,DAT_000a19b0,0x38e);
    uVar1 = 0;
  }
  return uVar1;
}

