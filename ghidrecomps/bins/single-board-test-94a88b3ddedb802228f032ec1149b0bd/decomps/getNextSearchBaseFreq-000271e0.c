
int getNextSearchBaseFreq(int param_1)

{
  int local_c;
  
  if (param_1 < 0) {
    local_c = 0x42;
  }
  else if (param_1 < 0x42) {
    if (param_1 < 0x3a) {
      if (param_1 < 0x2c) {
        if (param_1 < 0x1c) {
          local_c = param_1 + -1;
        }
        else {
          local_c = 0xc;
        }
      }
      else {
        local_c = 0x1c;
      }
    }
    else {
      local_c = 0x2c;
    }
  }
  else {
    local_c = 0x3a;
  }
  return local_c;
}

