
int SSL_has_matching_session_id(SSL *ssl,uchar *id,uint id_len)

{
  void *pvVar1;
  int iVar2;
  int local_104 [17];
  uint local_c0;
  undefined auStack_bc [172];
  
  if (id_len < 0x21) {
    iVar2 = ssl->version;
    local_104[0] = iVar2;
    local_c0 = id_len;
    memcpy(auStack_bc,id,id_len);
    if ((iVar2 == 2) && (id_len < 0x10)) {
      memset(auStack_bc + id_len,0,0x10 - id_len);
      local_c0 = 0x10;
    }
    CRYPTO_lock(5,0xc,DAT_0007a250,0x1f6);
    pvVar1 = lh_retrieve(*(_LHASH **)(ssl->psk_server_callback + 0x10),local_104);
    CRYPTO_lock(6,0xc,DAT_0007a250,0x1f8);
    if (pvVar1 != (void *)0x0) {
      pvVar1 = (void *)0x1;
    }
  }
  else {
    pvVar1 = (void *)0x0;
  }
  return (int)pvVar1;
}

