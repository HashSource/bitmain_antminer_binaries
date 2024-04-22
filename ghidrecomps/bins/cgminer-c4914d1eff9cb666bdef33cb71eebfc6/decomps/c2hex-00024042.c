
uchar c2hex(uchar value)

{
  FILE *__stream;
  uchar value_local;
  FILE *pFile;
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
    else if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: input value error: %c\n","driver-btm-soc.c",0x12f2,"c2hex",
                (uint)value);
      }
      fclose(__stream);
    }
  }
  else {
    ret = value & 0xf;
  }
  return ret;
}

