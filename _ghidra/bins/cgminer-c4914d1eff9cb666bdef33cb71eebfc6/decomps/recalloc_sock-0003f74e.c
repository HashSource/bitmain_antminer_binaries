
void recalloc_sock(pool *pool,size_t len)

{
  size_t sVar1;
  char *pcVar2;
  uint uVar3;
  size_t size;
  size_t len_local;
  pool *pool_local;
  size_t news;
  size_t old;
  
  sVar1 = strlen(pool->sockbuf);
  uVar3 = len + sVar1 + 1;
  if (pool->sockbuf_size <= uVar3) {
    size = (uVar3 & 0xffffe000) + 0x2000;
    pcVar2 = (char *)_cgrealloc(pool->sockbuf,size,"util.c","recalloc_sock",0x747);
    pool->sockbuf = pcVar2;
    memset(pool->sockbuf + sVar1,0,size - sVar1);
    pool->sockbuf_size = size;
  }
  return;
}

