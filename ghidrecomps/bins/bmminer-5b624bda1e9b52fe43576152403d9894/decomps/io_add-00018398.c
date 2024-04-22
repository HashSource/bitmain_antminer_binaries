
/* WARNING: Unknown calling convention */

_Bool io_add(io_data *io_data,char *buf)

{
  size_t sVar1;
  size_t len;
  char *pcVar2;
  uint uVar3;
  size_t tot;
  char *__dest;
  size_t __size;
  size_t new;
  size_t dif;
  float fVar4;
  
  sVar1 = strlen(buf);
  __dest = io_data->cur;
  len = (size_t)io_data->ptr;
  uVar3 = ((int)__dest - len) + 0xc + sVar1;
  if (io_data->siz < uVar3) {
    __size = io_data->siz + 0x20000;
    if (__size < uVar3) {
      fVar4 = (float)FixedToFP(uVar3,0x20,0x20,0x10,1,0);
      __size = ((uint)(0.0 < fVar4) * (int)fVar4 + 2) * 0x10000;
    }
    pcVar2 = (char *)realloc((void *)len,__size);
    __dest = pcVar2 + ((int)__dest - len);
    io_data->ptr = pcVar2;
    io_data->cur = __dest;
    io_data->siz = __size;
  }
  memcpy(__dest,buf,sVar1 + 1);
  io_data->cur = io_data->cur + sVar1;
  return true;
}

