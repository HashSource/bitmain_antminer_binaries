
undefined4 bm1740_parse_respond_len(byte *param_1,int param_2,undefined4 *param_3)

{
  undefined4 local_c;
  
  switch(state_6104) {
  case 0:
    if ((param_2 < 1) || (*param_1 != 0xaa)) {
      local_c = 0;
    }
    else {
      state_6104 = 1;
      local_c = 1;
    }
    *param_3 = 1;
    break;
  case 1:
    if ((param_2 < 1) || (*param_1 != 0x55)) {
      state_6104 = 0;
      local_c = 0;
    }
    else {
      state_6104 = 2;
      local_c = 1;
    }
    *param_3 = 1;
    break;
  case 2:
    if (param_2 < 1) {
      *param_3 = 1;
      local_c = 0;
      state_6104 = 0;
    }
    else {
      if ((*param_1 & 0xf0) == 0xe0) {
        *param_3 = 0x5a;
      }
      else if (*param_1 == 0xcc) {
        *param_3 = 6;
      }
      else {
        *param_3 = 6;
      }
      local_c = 1;
      state_6104 = 3;
    }
    break;
  case 3:
    local_c = 2;
    *param_3 = 1;
    state_6104 = 0;
    break;
  default:
    local_c = 0;
    *param_3 = 1;
    state_6104 = 0;
  }
  return local_c;
}

