
byte c2hex(byte param_1)

{
  byte local_9;
  
  local_9 = 0xff;
  if ((param_1 < 0x30) || (0x39 < param_1)) {
    if ((param_1 == 0x61) || (param_1 == 0x41)) {
      local_9 = 10;
    }
    else if ((param_1 == 0x62) || (param_1 == 0x42)) {
      local_9 = 0xb;
    }
    else if ((param_1 == 99) || (param_1 == 0x43)) {
      local_9 = 0xc;
    }
    else if ((param_1 == 100) || (param_1 == 0x44)) {
      local_9 = 0xd;
    }
    else if ((param_1 == 0x65) || (param_1 == 0x45)) {
      local_9 = 0xe;
    }
    else if ((param_1 == 0x66) || (param_1 == 0x46)) {
      local_9 = 0xf;
    }
    else {
      printf("input value error: %c\n",(uint)param_1);
    }
  }
  else {
    local_9 = param_1 & 0xf;
  }
  return local_9;
}

