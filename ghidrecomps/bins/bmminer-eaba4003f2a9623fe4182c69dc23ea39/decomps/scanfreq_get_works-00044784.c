
/* WARNING: Unknown calling convention */

int scanfreq_get_works(void)

{
  int iVar1;
  int iVar2;
  SCAN_FREQ_WORK *pSVar3;
  FILE *pFVar4;
  int iVar5;
  FILE *stream;
  char tmp42 [2048];
  char strFilePath [64];
  int AsicNum;
  int CoreNum;
  int asic_work_num;
  int j;
  int i;
  
  memset(strFilePath,0,0x40);
  iVar2 = scanfreq_info.CoreNum;
  iVar1 = scanfreq_info.AsicNum;
  i = 0;
  while( true ) {
    if (iVar1 <= i) {
      return 0;
    }
    asic_work_num = 0;
    pSVar3 = (SCAN_FREQ_WORK *)malloc(scanfreq_info.AsicWorkCount * 0x74);
    scanfreq_info.works[i] = pSVar3;
    if (scanfreq_info.works[i] == (SCAN_FREQ_WORK *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
        tmp42[0] = s_malloc_struct_work_err_00077cc4[0];
        tmp42[1] = s_malloc_struct_work_err_00077cc4[1];
        tmp42[2] = s_malloc_struct_work_err_00077cc4[2];
        tmp42[3] = s_malloc_struct_work_err_00077cc4[3];
        tmp42[4] = s_malloc_struct_work_err_00077cc4[4];
        tmp42[5] = s_malloc_struct_work_err_00077cc4[5];
        tmp42[6] = s_malloc_struct_work_err_00077cc4[6];
        tmp42[7] = s_malloc_struct_work_err_00077cc4[7];
        tmp42[8] = s_malloc_struct_work_err_00077cc4[8];
        tmp42[9] = s_malloc_struct_work_err_00077cc4[9];
        tmp42[10] = s_malloc_struct_work_err_00077cc4[10];
        tmp42[11] = s_malloc_struct_work_err_00077cc4[11];
        tmp42[12] = s_malloc_struct_work_err_00077cc4[12];
        tmp42[13] = s_malloc_struct_work_err_00077cc4[13];
        tmp42[14] = s_malloc_struct_work_err_00077cc4[14];
        tmp42[15] = s_malloc_struct_work_err_00077cc4[15];
        tmp42[16] = s_malloc_struct_work_err_00077cc4[16];
        tmp42[17] = s_malloc_struct_work_err_00077cc4[17];
        tmp42[18] = s_malloc_struct_work_err_00077cc4[18];
        tmp42[19] = s_malloc_struct_work_err_00077cc4[19];
        tmp42[20] = s_malloc_struct_work_err_00077cc4[20];
        tmp42[21] = s_malloc_struct_work_err_00077cc4[21];
        tmp42[22] = s_malloc_struct_work_err_00077cc4[22];
        tmp42[23] = s_malloc_struct_work_err_00077cc4[23];
        _applog(5,tmp42,false);
      }
      return -1;
    }
    for (j = 0; j < iVar2; j = j + 1) {
      sprintf(strFilePath,"%s%02i%s%02i.txt",DAT_00044a78,i,DAT_00044a74,j);
      pFVar4 = fopen(strFilePath,"r");
      scanfreq_info.fps[iVar2 * i + j] = (FILE *)pFVar4;
      if (scanfreq_info.fps[iVar2 * i + j] == (FILE *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
          snprintf(tmp42,0x800,"Open test file %s error\n",strFilePath);
          _applog(5,tmp42,false);
        }
        return -1;
      }
      stream = scanfreq_info.fps[iVar2 * i + j];
      iVar5 = __aeabi_idiv(scanfreq_info.AsicWorkCount,iVar2);
      iVar5 = get_work_of_core(i,j,stream,iVar5);
      asic_work_num = asic_work_num + iVar5;
      fclose((FILE *)scanfreq_info.fps[iVar2 * i + j]);
    }
    if (asic_work_num < scanfreq_info.AsicWorkCount) break;
    i = i + 1;
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (4 < opt_log_level)) {
    snprintf(tmp42,0x800,"Error: Asic %d get %d work, required work=%d\n",i,asic_work_num,
             scanfreq_info.AsicWorkCount);
    _applog(5,tmp42,false);
  }
  return -1;
}

