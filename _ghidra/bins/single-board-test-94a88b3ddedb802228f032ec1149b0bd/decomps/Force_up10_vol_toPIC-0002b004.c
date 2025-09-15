
void Force_up10_vol_toPIC(uint param_1)

{
  byte bVar1;
  FILE *__stream;
  undefined4 uVar2;
  
  *(int *)(chain_vol_value + param_1 * 4) = *(int *)(chain_vol_value + param_1 * 4) + 10;
  *(int *)(chain_vol_added + param_1 * 4) = *(int *)(chain_vol_added + param_1 * 4) + 1;
  bVar1 = getPICvoltageFromValue(*(undefined4 *)(chain_vol_value + param_1 * 4));
  uVar2 = *(undefined4 *)(chain_vol_value + param_1 * 4);
  if (3 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,
              "%s:%d: Force_up10_vol_toPIC fix hash_voltage pic value = %d [%d] of Chain[%d], voladded=%d\n"
              ,"main.c",0x10ee,(uint)bVar1,uVar2,param_1,
              *(undefined4 *)(chain_vol_added + param_1 * 4));
    }
    fclose(__stream);
  }
  set_pic_voltage(param_1 & 0xff,bVar1);
  return;
}

