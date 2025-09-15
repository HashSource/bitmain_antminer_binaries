
undefined4 hal_key_ipreport_addr(void)

{
  undefined4 uVar1;
  
  uVar1 = ipreport_addr;
  if (conf_loaded == 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

