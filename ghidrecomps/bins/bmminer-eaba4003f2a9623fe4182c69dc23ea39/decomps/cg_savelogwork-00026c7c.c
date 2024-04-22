
void cg_savelogwork(work *work,uchar *nonce_bin)

{
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  char *nonce4;
  char *__ptr_02;
  char *__ptr_03;
  size_t __size;
  uchar *nonce_bin_local;
  work *work_local;
  uchar midstate_tmp [32];
  uchar data_tmp [32];
  uchar hash_tmp [32];
  char szmsg [1024];
  int chipIndex;
  uint64_t worksharediff;
  int asicnum;
  char *szhash;
  char *sznonce5;
  char *sznonce4;
  char *szdata;
  char *szmidstate;
  char *szworkdata;
  
  if (fd_log == (FILE *)0x0) {
    fd_log = (FILE *)fopen("/etc/config/worklog.txt","wb");
  }
  memset(szmsg,0,0x400);
  data_tmp[0] = '\0';
  data_tmp[1] = '\0';
  data_tmp[2] = '\0';
  data_tmp[3] = '\0';
  data_tmp[4] = '\0';
  data_tmp[5] = '\0';
  data_tmp[6] = '\0';
  data_tmp[7] = '\0';
  data_tmp[8] = '\0';
  data_tmp[9] = '\0';
  data_tmp[10] = '\0';
  data_tmp[11] = '\0';
  data_tmp[12] = '\0';
  data_tmp[13] = '\0';
  data_tmp[14] = '\0';
  data_tmp[15] = '\0';
  data_tmp[16] = '\0';
  data_tmp[17] = '\0';
  data_tmp[18] = '\0';
  data_tmp[19] = '\0';
  data_tmp[20] = '\0';
  data_tmp[21] = '\0';
  data_tmp[22] = '\0';
  data_tmp[23] = '\0';
  data_tmp[24] = '\0';
  data_tmp[25] = '\0';
  data_tmp[26] = '\0';
  data_tmp[27] = '\0';
  data_tmp[28] = '\0';
  data_tmp[29] = '\0';
  data_tmp[30] = '\0';
  data_tmp[31] = '\0';
  hash_tmp[0] = '\0';
  hash_tmp[1] = '\0';
  hash_tmp[2] = '\0';
  hash_tmp[3] = '\0';
  hash_tmp[4] = '\0';
  hash_tmp[5] = '\0';
  hash_tmp[6] = '\0';
  hash_tmp[7] = '\0';
  hash_tmp[8] = '\0';
  hash_tmp[9] = '\0';
  hash_tmp[10] = '\0';
  hash_tmp[11] = '\0';
  hash_tmp[12] = '\0';
  hash_tmp[13] = '\0';
  hash_tmp[14] = '\0';
  hash_tmp[15] = '\0';
  hash_tmp[16] = '\0';
  hash_tmp[17] = '\0';
  hash_tmp[18] = '\0';
  hash_tmp[19] = '\0';
  hash_tmp[20] = '\0';
  hash_tmp[21] = '\0';
  hash_tmp[22] = '\0';
  hash_tmp[23] = '\0';
  hash_tmp[24] = '\0';
  hash_tmp[25] = '\0';
  hash_tmp[26] = '\0';
  hash_tmp[27] = '\0';
  hash_tmp[28] = '\0';
  hash_tmp[29] = '\0';
  hash_tmp[30] = '\0';
  hash_tmp[31] = '\0';
  midstate_tmp._0_4_ = *(undefined4 *)work->midstate;
  midstate_tmp._4_4_ = *(undefined4 *)(work->midstate + 4);
  midstate_tmp._8_4_ = *(undefined4 *)(work->midstate + 8);
  midstate_tmp._12_4_ = *(undefined4 *)(work->midstate + 0xc);
  midstate_tmp._16_4_ = *(undefined4 *)(work->midstate + 0x10);
  midstate_tmp._20_4_ = *(undefined4 *)(work->midstate + 0x14);
  midstate_tmp._24_4_ = *(undefined4 *)(work->midstate + 0x18);
  midstate_tmp._28_4_ = *(undefined4 *)(work->midstate + 0x1c);
  memcpy(data_tmp,work->data + 0x40,0xc);
  hash_tmp._0_4_ = *(undefined4 *)work->hash;
  hash_tmp._4_4_ = *(undefined4 *)(work->hash + 4);
  hash_tmp._8_4_ = *(undefined4 *)(work->hash + 8);
  hash_tmp._12_4_ = *(undefined4 *)(work->hash + 0xc);
  hash_tmp._16_4_ = *(undefined4 *)(work->hash + 0x10);
  hash_tmp._20_4_ = *(undefined4 *)(work->hash + 0x14);
  hash_tmp._24_4_ = *(undefined4 *)(work->hash + 0x18);
  hash_tmp._28_4_ = *(undefined4 *)(work->hash + 0x1c);
  rev(midstate_tmp,0x20);
  rev(data_tmp,0xc);
  rev(hash_tmp,0x20);
  __ptr = bin2hex(work->data,0x80);
  __ptr_00 = bin2hex(midstate_tmp,0x20);
  __ptr_01 = bin2hex(data_tmp,0xc);
  nonce4 = bin2hex(nonce_bin,4);
  __ptr_02 = bin2hex(nonce_bin,5);
  __ptr_03 = bin2hex(hash_tmp,0x20);
  share_ndiff(work);
  getChipIndex(nonce4);
  sprintf(szmsg,"midstate %s data %s nonce %s \r\n",__ptr_00,__ptr_01,nonce4);
  __size = strlen(szmsg);
  fwrite(szmsg,__size,1,(FILE *)fd_log);
  fflush((FILE *)fd_log);
  if (__ptr != (char *)0x0) {
    free(__ptr);
  }
  if (__ptr_00 != (char *)0x0) {
    free(__ptr_00);
  }
  if (__ptr_01 != (char *)0x0) {
    free(__ptr_01);
  }
  if (nonce4 != (char *)0x0) {
    free(nonce4);
  }
  if (__ptr_02 != (char *)0x0) {
    free(__ptr_02);
  }
  if (__ptr_03 != (char *)0x0) {
    free(__ptr_03);
  }
  return;
}

