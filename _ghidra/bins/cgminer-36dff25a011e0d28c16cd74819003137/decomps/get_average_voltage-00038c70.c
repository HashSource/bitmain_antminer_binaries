
/* WARNING: Unknown calling convention */

double get_average_voltage(void)

{
  FILE *pFVar1;
  double dVar2;
  FILE *pFile;
  FILE *pFile_1;
  FILE *pFile_2;
  double tmp;
  double volt;
  int i;
  int total_chain;
  
  total_chain = 0;
  volt = 0.0;
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] == 1) {
      dVar2 = dsPIC33EP16GS202_pic_get_an_voltage2((uchar)i);
      volt = volt + dVar2;
      total_chain = total_chain + 1;
      if (3 < log_level) {
        print_crt_time_to_file(power_log_file,3);
        pFVar1 = fopen(power_log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          tmp._0_4_ = SUB84(dVar2,0);
          tmp._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
          fprintf(pFVar1,"%s:%d:%s: chain[%d], voltage is: %f \n","power.c",0x438,
                  "get_average_voltage",i,tmp._0_4_,tmp._4_4_);
        }
        fclose(pFVar1);
      }
    }
  }
  if (total_chain == 0) {
    if (3 < log_level) {
      print_crt_time_to_file(power_log_file,3);
      pFVar1 = fopen(power_log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: error: total_chain get 0 !!","power.c",0x43e,"get_average_voltage"
               );
      }
      fclose(pFVar1);
    }
    volt._0_4_ = 0;
    volt._4_4_ = 0;
  }
  else {
    dVar2 = volt / (double)(longlong)total_chain;
    if (3 < log_level) {
      print_crt_time_to_file(power_log_file,3);
      pFVar1 = fopen(power_log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,"%s:%d:%s: aveage voltage is: %f \n","power.c",0x443,"get_average_voltage");
      }
      fclose(pFVar1);
    }
    volt._0_4_ = SUB84(dVar2,0);
    volt._4_4_ = (undefined4)((ulonglong)dVar2 >> 0x20);
  }
  return (double)CONCAT44(volt._4_4_,volt._0_4_);
}

