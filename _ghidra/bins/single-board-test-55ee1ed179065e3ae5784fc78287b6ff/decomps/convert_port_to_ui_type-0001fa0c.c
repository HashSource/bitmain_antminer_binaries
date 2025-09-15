
undefined4 convert_port_to_ui_type(int param_1)

{
  undefined4 local_c;
  
  local_c = 0x102;
  if (param_1 == 0x399) {
    local_c = 0x100;
  }
  else if (param_1 == 0x3af) {
    local_c = 0x101;
  }
  return local_c;
}

