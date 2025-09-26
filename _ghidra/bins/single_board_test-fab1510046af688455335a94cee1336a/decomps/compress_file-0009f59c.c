
int compress_file(FILE *f_in,FILE *f_out)

{
  uint uVar1;
  char *pcVar2;
  LZ4F_errorCode_t code;
  int iVar3;
  FILE *f_out_local;
  FILE *f_in_local;
  LZ4F_preferences_t m_prefsPtr;
  LZ4_writeFile_t *lz4fWrite;
  size_t len;
  void *buf;
  LZ4F_errorCode_t ret;
  
  if (f_in == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("f_in != ((void *)0)","../zhiju/log_file/fileCompress.c",0x18,"compress_file");
  }
  if (f_out == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("f_out != ((void *)0)","../zhiju/log_file/fileCompress.c",0x18,"compress_file");
  }
  ret = 0;
  buf = malloc(0x4000);
  if (buf == (void *)0x0) {
    puts("error: memory allocation failed ");
  }
  memset(&m_prefsPtr,0,0x38);
  m_prefsPtr.compressionLevel = 0xc;
  ret = LZ4F_writeOpen(&lz4fWrite,f_out,&m_prefsPtr);
  uVar1 = LZ4F_isError(ret);
  if (uVar1 == 0) {
    do {
      len = fread(buf,1,0x4000,(FILE *)f_in);
      iVar3 = ferror((FILE *)f_in);
      if (iVar3 != 0) {
        puts("fread error");
        goto LAB_0009f6c4;
      }
      if (len == 0) goto LAB_0009f6c4;
      ret = LZ4F_write(lz4fWrite,buf,len);
      uVar1 = LZ4F_isError(ret);
    } while (uVar1 == 0);
    pcVar2 = LZ4F_getErrorName(ret);
    printf("LZ4F_write: %s\n",pcVar2);
LAB_0009f6c4:
    free(buf);
    code = LZ4F_writeClose(lz4fWrite);
    uVar1 = LZ4F_isError(code);
    if (uVar1 == 0) {
      iVar3 = 0;
    }
    else {
      pcVar2 = LZ4F_getErrorName(ret);
      printf("LZ4F_writeClose: %s\n",pcVar2);
      iVar3 = 1;
    }
  }
  else {
    pcVar2 = LZ4F_getErrorName(ret);
    printf("LZ4F_writeOpen error: %s\n",pcVar2);
    free(buf);
    iVar3 = 1;
  }
  return iVar3;
}

