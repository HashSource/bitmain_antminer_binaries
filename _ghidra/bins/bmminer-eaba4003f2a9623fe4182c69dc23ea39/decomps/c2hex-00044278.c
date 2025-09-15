
uchar c2hex(uchar value)

{
  uchar value_local;
  char tmp42 [2048];
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
    else if ((use_syslog) || ((opt_log_output || (2 < opt_log_level)))) {
      snprintf(tmp42,0x800,"input value error: %c\n",(uint)value);
      _applog(3,tmp42,false);
    }
  }
  else {
    ret = value & 0xf;
  }
  return ret;
}

