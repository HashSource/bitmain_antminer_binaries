
int decompress_file(FILE *f_in,FILE *f_out)

{
  uint uVar1;
  char *pcVar2;
  size_t sVar3;
  LZ4F_errorCode_t code;
  int iVar4;
  FILE *f_out_local;
  FILE *f_in_local;
  LZ4_readFile_t *lz4fRead;
  void *buf;
  LZ4F_errorCode_t ret;
  
  if (f_in == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("f_in != ((void *)0)","../zhiju/log_file/fileCompress.c",0x55,"decompress_file");
  }
  if (f_out == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("f_out != ((void *)0)","../zhiju/log_file/fileCompress.c",0x55,"decompress_file");
  }
  ret = 0;
  buf = malloc(0x4000);
  if (buf == (void *)0x0) {
    puts("error: memory allocation failed ");
  }
  ret = LZ4F_readOpen(&lz4fRead,f_in);
  uVar1 = LZ4F_isError(ret);
  if (uVar1 == 0) {
    do {
      ret = LZ4F_read(lz4fRead,buf,0x4000);
      uVar1 = LZ4F_isError(ret);
      if (uVar1 != 0) {
        pcVar2 = LZ4F_getErrorName(ret);
        printf("LZ4F_read error: %s\n",pcVar2);
        goto LAB_00068c52;
      }
      if (ret == 0) goto LAB_00068c52;
      sVar3 = fwrite(buf,1,ret,(FILE *)f_out);
    } while (sVar3 == ret);
    puts("write error!");
LAB_00068c52:
    free(buf);
    code = LZ4F_readClose(lz4fRead);
    uVar1 = LZ4F_isError(code);
    if (uVar1 == 0) {
      if (ret == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = 1;
      }
    }
    else {
      pcVar2 = LZ4F_getErrorName(ret);
      printf("LZ4F_readClose: %s\n",pcVar2);
      iVar4 = 1;
    }
  }
  else {
    pcVar2 = LZ4F_getErrorName(ret);
    printf("LZ4F_readOpen error: %s\n",pcVar2);
    free(buf);
    iVar4 = 1;
  }
  return iVar4;
}

