
bool SCT_set_log_entry_type(int param_1,uint param_2)

{
  if (param_2 < 2) {
    *(uint *)(param_1 + 0x34) = param_2;
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (param_2 >= 2) {
    ERR_put_error(0x32,0x66,0x66,"crypto/ct/ct_sct.c",0x4c);
  }
  return param_2 < 2;
}

