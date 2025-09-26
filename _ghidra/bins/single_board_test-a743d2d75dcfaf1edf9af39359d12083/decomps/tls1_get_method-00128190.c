
undefined1 * tls1_get_method(int param_1)

{
  undefined1 *puVar1;
  
  if (param_1 == 0x303) {
    return &TLSv1_2_method_data_18471;
  }
  if (param_1 == 0x302) {
    return TLSv1_1_method_data_18475;
  }
  if (param_1 == 0x301) {
    puVar1 = TLSv1_method_data_18479;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  return puVar1;
}

