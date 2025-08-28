
undefined4 tls1_ec_curve_id2nid(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 - 1U < 0x1c) {
    uVar1 = *(undefined4 *)(nid_list + (param_1 - 1U) * 4);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

