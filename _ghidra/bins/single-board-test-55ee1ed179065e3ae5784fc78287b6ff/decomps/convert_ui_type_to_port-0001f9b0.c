
undefined4 convert_ui_type_to_port(uint param_1)

{
  undefined4 local_c;
  
  local_c = 0;
  if (param_1 == 2) {
    local_c = 0x3ae;
  }
  else if (param_1 < 3) {
    if (param_1 == 1) {
      local_c = 0x3ad;
    }
  }
  else if (param_1 == 0x100) {
    local_c = 0x399;
  }
  else if (param_1 == 0x101) {
    local_c = 0x3af;
  }
  return local_c;
}

