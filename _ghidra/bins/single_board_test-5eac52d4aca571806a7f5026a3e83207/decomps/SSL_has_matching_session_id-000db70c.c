
int SSL_has_matching_session_id(SSL *ssl,uchar *id,uint id_len)

{
  int iVar1;
  int local_214 [82];
  uint local_cc;
  undefined1 auStack_c8 [184];
  
  if (0x20 < id_len) {
    return 0;
  }
  local_214[0] = ssl->version;
  local_cc = id_len;
  memcpy(auStack_c8,id,id_len);
  CRYPTO_THREAD_read_lock(*(undefined4 *)(ssl[3].max_send_fragment + 0x218));
  iVar1 = OPENSSL_LH_retrieve(*(undefined4 *)(ssl[3].max_send_fragment + 0x14),local_214);
  CRYPTO_THREAD_unlock(*(undefined4 *)(ssl[3].max_send_fragment + 0x218));
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

