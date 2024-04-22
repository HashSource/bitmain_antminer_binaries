
void fan_control(undefined param_1)

{
  undefined4 local_c;
  
  switch(param_1) {
  case 0:
    local_c = 100;
    break;
  case 1:
    local_c = 0xa005a;
    break;
  case 2:
    local_c = 0x140050;
    break;
  case 3:
    local_c = 0x1e0046;
    break;
  case 4:
    local_c = 0x28003c;
    break;
  case 5:
    local_c = 0x320032;
    break;
  case 6:
    local_c = 0x3c0028;
    break;
  case 7:
    local_c = 0x46001e;
    break;
  case 8:
    local_c = 0x500014;
    break;
  case 9:
    local_c = 0x5a000a;
    break;
  case 10:
    local_c = 0x640000;
    break;
  default:
    local_c = 0x640000;
  }
  set_fan_speed(local_c);
  return;
}

