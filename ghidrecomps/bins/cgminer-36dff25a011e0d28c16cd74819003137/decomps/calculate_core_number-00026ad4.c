
int calculate_core_number(uint actual_core_number)

{
  uint actual_core_number_local;
  int core_number;
  
  core_number = 1;
  if (actual_core_number == 0) {
    core_number = 0;
  }
  else {
    for (; (uint)core_number < actual_core_number; core_number = core_number << 1) {
    }
  }
  return core_number;
}

