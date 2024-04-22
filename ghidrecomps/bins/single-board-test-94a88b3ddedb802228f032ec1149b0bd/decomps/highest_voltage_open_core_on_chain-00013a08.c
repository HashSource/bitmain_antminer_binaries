
void highest_voltage_open_core_on_chain(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  FILE *__stream;
  
  iVar1 = is_S9_Hydro();
  if (iVar1 == 0) {
    uVar2 = getPICvoltageFromValue(0x3a2);
    set_pic_voltage(param_1 & 0xff,uVar2);
  }
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: chain[%d] open core\n","board_frq_tuning.c",0x1bf,param_1);
    }
    fclose(__stream);
  }
  open_core_onChain(param_1,0x72,0x72,1);
  iVar1 = is_S9_Hydro();
  if (iVar1 == 0) {
    uVar2 = getPICvoltageFromValue(param_2);
    set_pic_voltage(param_1 & 0xff,uVar2);
  }
  return;
}

