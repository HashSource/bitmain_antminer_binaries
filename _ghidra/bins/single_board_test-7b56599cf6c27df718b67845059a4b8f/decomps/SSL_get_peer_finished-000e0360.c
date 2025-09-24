
size_t SSL_get_peer_finished(SSL *s,void *buf,size_t count)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = s->mac_flags;
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 0x204);
    if (uVar2 <= count) {
      count = uVar2;
    }
    memcpy(buf,(void *)(iVar1 + 0x184),count);
    return uVar2;
  }
  return 0;
}

