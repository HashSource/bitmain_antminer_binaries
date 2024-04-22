
void engine_table_doall(_LHASH *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  if (param_1 != (_LHASH *)0x0) {
    local_10 = param_2;
    uStack_c = param_3;
    lh_doall_arg(param_1,DAT_00101cdc,&local_10);
  }
  return;
}

