
/* WARNING: Unknown calling convention */

void cg_savelogwork(work *work,uchar *nonce_bin)

{
  int iVar1;
  char *__ptr;
  char *__ptr_00;
  char *__ptr_01;
  char *__ptr_02;
  char *__ptr_03;
  char *__ptr_04;
  size_t sVar2;
  uchar uVar3;
  uint uVar4;
  uchar uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  uchar nonce_bytes [4];
  char nonce [9];
  uchar midstate_tmp [32];
  uchar data_tmp [32];
  uchar hash_tmp [32];
  char szmsg [1024];
  
  if (fd_log == (FILE *)0x0) {
    fd_log = (FILE *)fopen("/etc/config/worklog.txt","wb");
  }
  memset(szmsg,0,0x400);
  midstate_tmp._0_4_ = *(undefined4 *)work->midstate;
  midstate_tmp._4_4_ = *(undefined4 *)(work->midstate + 4);
  iVar8 = 0;
  midstate_tmp._8_4_ = *(undefined4 *)(work->midstate + 8);
  midstate_tmp._12_4_ = *(undefined4 *)(work->midstate + 0xc);
  data_tmp[0xc] = '\0';
  data_tmp[0xd] = '\0';
  data_tmp[0xe] = '\0';
  data_tmp[0xf] = '\0';
  data_tmp[0x10] = '\0';
  data_tmp[0x11] = '\0';
  data_tmp[0x12] = '\0';
  data_tmp[0x13] = '\0';
  midstate_tmp._16_4_ = *(undefined4 *)(work->midstate + 0x10);
  midstate_tmp._20_4_ = *(undefined4 *)(work->midstate + 0x14);
  midstate_tmp._24_4_ = *(undefined4 *)(work->midstate + 0x18);
  midstate_tmp._28_4_ = *(undefined4 *)(work->midstate + 0x1c);
  uVar7 = 0;
  data_tmp[0x14] = '\0';
  data_tmp[0x15] = '\0';
  data_tmp[0x16] = '\0';
  data_tmp[0x17] = '\0';
  data_tmp[0x18] = '\0';
  data_tmp[0x19] = '\0';
  data_tmp[0x1a] = '\0';
  data_tmp[0x1b] = '\0';
  data_tmp._0_4_ = *(undefined4 *)(work->data + 0x40);
  data_tmp[0x1c] = '\0';
  data_tmp[0x1d] = '\0';
  data_tmp[0x1e] = '\0';
  data_tmp[0x1f] = '\0';
  data_tmp._4_4_ = *(undefined4 *)(work->data + 0x44);
  data_tmp._8_4_ = *(undefined4 *)(work->data + 0x48);
  hash_tmp._0_4_ = *(undefined4 *)work->hash;
  hash_tmp._4_4_ = *(undefined4 *)(work->hash + 4);
  hash_tmp._8_4_ = *(undefined4 *)(work->hash + 8);
  hash_tmp._12_4_ = *(undefined4 *)(work->hash + 0xc);
  hash_tmp._24_4_ = *(undefined4 *)(work->hash + 0x18);
  hash_tmp._28_4_ = *(undefined4 *)(work->hash + 0x1c);
  hash_tmp._16_4_ = *(undefined4 *)(work->hash + 0x10);
  hash_tmp._20_4_ = *(undefined4 *)(work->hash + 0x14);
  rev(midstate_tmp,0x20);
  rev(data_tmp,0xc);
  rev(hash_tmp,0x20);
  __ptr = bin2hex(work->data,0x80);
  __ptr_00 = bin2hex(midstate_tmp,0x20);
  __ptr_01 = bin2hex(data_tmp,0xc);
  __ptr_02 = bin2hex(nonce_bin,4);
  __ptr_03 = bin2hex(nonce_bin,5);
  __ptr_04 = bin2hex(hash_tmp,0x20);
  while (sVar2 = strlen(nonce), uVar7 < sVar2) {
    uVar6 = (uint)(byte)nonce[uVar7];
    uVar4 = uVar6 - 0x30 & 0xff;
    if (9 < uVar4) {
      iVar1 = -0x37;
      if (uVar6 - 0x61 < 6) {
        iVar1 = -0x57;
      }
      uVar4 = uVar6 + iVar1 & 0xff;
      if ((5 < uVar6 - 0x61) && (5 < uVar6 - 0x41)) break;
    }
    uVar3 = (uchar)uVar4;
    bVar9 = (int)(uVar7 << 0x1f) < 0;
    uVar5 = (uchar)(uVar4 << 4);
    if (bVar9) {
      uVar5 = nonce_bytes[iVar8];
    }
    uVar7 = uVar7 + 1;
    if (bVar9) {
      uVar3 = uVar3 + uVar5;
    }
    else {
      nonce_bytes[iVar8] = uVar5;
    }
    if (bVar9) {
      nonce_bytes[iVar8] = uVar3;
      iVar8 = iVar8 + 1;
    }
  }
  sprintf(szmsg,"midstate %s data %s nonce %s \r\n",__ptr_00,__ptr_01,__ptr_02);
  sVar2 = strlen(szmsg);
  fwrite(szmsg,sVar2,1,(FILE *)fd_log);
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
  if (__ptr_02 != (char *)0x0) {
    free(__ptr_02);
  }
  if (__ptr_03 != (char *)0x0) {
    free(__ptr_03);
  }
  if (__ptr_04 != (char *)0x0) {
    free(__ptr_04);
  }
  return;
}

