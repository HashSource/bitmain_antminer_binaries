
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_register_buf(void)

{
  char tmp42 [256];
  
  if (reg_value_buf == (reg_buf *)0x0) {
    reg_value_buf = (reg_buf *)malloc(0x27fc);
    if (reg_value_buf == (reg_buf *)0x0) {
      builtin_strncpy(tmp42,"malloc reg_value_buf failed",0x1c);
      puts(tmp42);
    }
    else {
      memset(reg_value_buf,0,0x27fc);
    }
  }
  else {
    memset(reg_value_buf,0,0x27fc);
  }
  return;
}

