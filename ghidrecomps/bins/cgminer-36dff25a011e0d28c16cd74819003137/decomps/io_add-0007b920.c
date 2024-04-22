
_Bool io_add(io_data *io_data,char *buf)

{
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  char *buf_local;
  io_data *io_data_local;
  size_t tot;
  size_t dif;
  size_t len;
  size_t new;
  
  sVar1 = strlen(buf);
  iVar3 = (int)io_data->cur - (int)io_data->ptr;
  uVar4 = sVar1 + iVar3 + 0xc;
  if (io_data->siz < uVar4) {
    new = io_data->siz + 0x20000;
    if (new < uVar4) {
      new = ((uint)(0.0 < (float)(ulonglong)uVar4 / DAT_0007ba68) *
             (int)((float)(ulonglong)uVar4 / DAT_0007ba68) + 2) * 0x10000;
    }
    pcVar2 = (char *)_cgrealloc(io_data->ptr,new,"api-btm.c","io_add",0x2fe);
    io_data->ptr = pcVar2;
    io_data->cur = io_data->ptr + iVar3;
    io_data->siz = new;
  }
  memcpy(io_data->cur,buf,sVar1 + 1);
  io_data->cur = io_data->cur + sVar1;
  return true;
}

