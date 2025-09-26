
uchar c2hex(uchar value)

{
  uchar value_local;
  char time_stamp [48];
  char tmp1 [256];
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
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : input value error: %c\n\n","c2hex",(uint)value);
      snprintf(tmp1,0x100,"input value error: %c\n",(uint)value);
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    ret = value & 0xf;
  }
  return ret;
}

