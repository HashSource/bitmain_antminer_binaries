
/* WARNING: Unknown calling convention */

int get_vol_comp_from_power(void)

{
  float fVar1;
  char time_stamp [48];
  char tmp1 [2048];
  int diff;
  float power;
  int comp;
  
  fVar1 = get_miner_power();
  comp = 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: power = %f \n","get_vol_comp_from_power",SUB84((double)fVar1,0),
         (int)((ulonglong)(double)fVar1 >> 0x20));
  snprintf(tmp1,0x800,"power = %f ",tmp1,(double)fVar1);
  log_to_file(tmp1,time_stamp);
  if ((0 < (int)(1500.0 - fVar1)) && (comp = ((int)(1500.0 - fVar1) / 0x28) * 0x14, 0x27 < comp)) {
    comp = 0x28;
  }
  return comp;
}

