
int hal_fan_number(void)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  if (conf_loaded == 0) {
    local_c = -1;
  }
  else {
    for (local_10 = 0; local_10 < 6; local_10 = local_10 + 1) {
      if (*(int *)(fans + local_10 * 0xc) != -1) {
        local_c = local_c + 1;
      }
    }
  }
  return local_c;
}

