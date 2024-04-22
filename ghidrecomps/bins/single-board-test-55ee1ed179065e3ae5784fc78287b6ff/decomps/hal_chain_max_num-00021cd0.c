
int hal_chain_max_num(void)

{
  int local_c;
  
  if (conf_loaded == 0) {
    local_c = -1;
  }
  else {
    local_c = 0;
    while ((local_c < 0x10 &&
           ((((*(int *)(chains + local_c * 0x10) != 0xff ||
              (*(int *)(chains + local_c * 0x10 + 4) != 0xff)) ||
             (*(int *)(chains + local_c * 0x10 + 8) != 0xff)) ||
            (*(int *)(chains + local_c * 0x10 + 0xc) != 0xff))))) {
      local_c = local_c + 1;
    }
  }
  return local_c;
}

