
void ERR_error_string_n(ulong e,char *buf,size_t len)

{
  char *buf_00;
  char *buf_01;
  char *buf_02;
  size_t sVar1;
  uint uVar2;
  char acStack_e8 [64];
  char acStack_a8 [64];
  char acStack_68 [68];
  
  if (len == 0) {
    return;
  }
  buf_00 = ERR_lib_error_string(e);
  if (buf_00 == (char *)0x0) {
    buf_00 = acStack_e8;
    BIO_snprintf(buf_00,0x40,"lib(%lu)",e >> 0x18);
  }
  uVar2 = (e << 8) >> 0x14;
  buf_01 = ERR_func_error_string(e);
  if (buf_01 == (char *)0x0) {
    buf_01 = acStack_a8;
    BIO_snprintf(buf_01,0x40,"func(%lu)",uVar2);
  }
  buf_02 = ERR_reason_error_string(e);
  if (buf_02 == (char *)0x0) {
    buf_02 = acStack_68;
    BIO_snprintf(buf_02,0x40,"reason(%lu)",e & 0xfff);
  }
  BIO_snprintf(buf,len,"error:%08lX:%s:%s:%s",e,buf_00,buf_01,buf_02);
  sVar1 = strlen(buf);
  if (sVar1 == len - 1) {
    BIO_snprintf(buf,len,"err:%lx:%lx:%lx:%lx",e,e >> 0x18,uVar2,e & 0xfff);
  }
  return;
}

