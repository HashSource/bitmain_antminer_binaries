
uchar c2hex(uchar value)

{
  uchar value_local;
  uchar ret;
  
  ret = 0xff;
  if ((value < 0x30) || (0x39 < value)) {
    if ((value == 'a') || (value == 'A')) {
      ret = '\n';
    }
    else if ((value == 'b') || (value == 'B')) {
      ret = '\v';
    }
    else if ((value == 'c') || (value == 'C')) {
      ret = '\f';
    }
    else if ((value == 'd') || (value == 'D')) {
      ret = '\r';
    }
    else if ((value == 'e') || (value == 'E')) {
      ret = '\x0e';
    }
    else if ((value == 'f') || (value == 'F')) {
      ret = '\x0f';
    }
    else {
      printf("input value error: %c\n",(uint)value);
    }
  }
  else {
    ret = value & 0xf;
  }
  return ret;
}

