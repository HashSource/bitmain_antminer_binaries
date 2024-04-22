
int get_fan_speed(uchar *fan_id,uint *fan_speed)

{
  FILE *__stream;
  uint uVar1;
  uint *fan_speed_local;
  uchar *fan_id_local;
  FILE *pFile;
  int ret;
  
  uVar1 = axi_fpga_addr[1];
  *fan_speed = uVar1 & 0xff;
  *fan_id = (byte)(uVar1 >> 8) & 7;
  if ((*fan_speed != 0) && (4 < log_level)) {
    print_crt_time_to_file(log_file,4);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: fan_id is 0x%x, fan_speed is 0x%x\n","zynq.c",0x118,
              "get_fan_speed",(uint)*fan_id,*fan_speed);
    }
    fclose(__stream);
  }
  return uVar1;
}

