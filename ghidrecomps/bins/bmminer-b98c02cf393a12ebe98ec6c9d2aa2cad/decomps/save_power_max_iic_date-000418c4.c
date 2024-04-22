
void save_power_max_iic_date(undefined param_1)

{
  FILE *__stream;
  undefined local_14 [8];
  
  __stream = fopen("/config/vol_iic_data","wb+");
  if (__stream != (FILE *)0x0) {
    fseek(__stream,1,0);
    local_14[0] = param_1;
    fwrite(local_14,1,1,__stream);
    fclose(__stream);
  }
  return;
}

