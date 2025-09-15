
void fan_control(uchar level)

{
  uchar level_local;
  uint speed;
  
  switch(level) {
  case '\0':
    speed = 100;
    break;
  case '\x01':
    speed = 0xa005a;
    break;
  case '\x02':
    speed = 0x140050;
    break;
  case '\x03':
    speed = 0x1e0046;
    break;
  case '\x04':
    speed = 0x28003c;
    break;
  case '\x05':
    speed = 0x320032;
    break;
  case '\x06':
    speed = 0x3c0028;
    break;
  case '\a':
    speed = 0x46001e;
    break;
  case '\b':
    speed = 0x500014;
    break;
  case '\t':
    speed = 0x5a000a;
    break;
  case '\n':
    speed = 0x640000;
    break;
  default:
    speed = 0x640000;
  }
  set_fan_speed(speed);
  return;
}

