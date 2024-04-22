
void save_power_working_iic_date(undefined param_1)

{
  undefined local_10 [4];
  FILE *local_c;
  
  local_c = fopen("/config/vol_iic_data","wb+");
  if (local_c != (FILE *)0x0) {
    fseek(local_c,0,0);
    local_10[0] = param_1;
    fwrite(local_10,1,1,local_c);
    fclose(local_c);
  }
  return;
}

