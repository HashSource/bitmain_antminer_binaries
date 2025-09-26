
size_t SSL_get_peer_finished(SSL *s,void *buf,size_t count)

{
  ssl3_state_st *psVar1;
  uint uVar2;
  
  psVar1 = s->s3;
  if (psVar1 != (ssl3_state_st *)0x0) {
    uVar2 = (psVar1->tmp).peer_finish_md_len;
    if (uVar2 <= count) {
      count = uVar2;
    }
    memcpy(buf,(psVar1->tmp).peer_finish_md,count);
    return uVar2;
  }
  return 0;
}

