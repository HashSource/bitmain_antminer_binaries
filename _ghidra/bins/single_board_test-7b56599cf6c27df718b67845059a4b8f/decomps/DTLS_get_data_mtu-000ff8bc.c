
int DTLS_get_data_mtu(SSL *param_1)

{
  SSL_CIPHER *pSVar1;
  int iVar2;
  int extraout_r1;
  ENGINE *pEVar3;
  int local_20;
  ENGINE *local_1c;
  int local_18;
  int local_14;
  
  pSVar1 = SSL_get_current_cipher(param_1);
  if (pSVar1 != (SSL_CIPHER *)0x0) {
    pEVar3 = param_1->enc_read_ctx[2].engine;
    iVar2 = ssl_cipher_get_overhead(pSVar1,&local_20,&local_1c,&local_18,&local_14);
    if (iVar2 != 0) {
      if (*(int *)param_1->mac_flags << 0x17 < 0) {
        local_14 = local_20 + local_14;
      }
      else {
        local_1c = local_1c + local_20;
      }
      if ((ENGINE *)(local_14 + 0xd) < pEVar3) {
        pEVar3 = pEVar3 + (-0xd - local_14);
        if (local_18 != 0) {
          __aeabi_uidivmod(pEVar3);
          pEVar3 = pEVar3 + -extraout_r1;
        }
        if (local_1c < pEVar3) {
          return (int)pEVar3 - (int)local_1c;
        }
      }
    }
  }
  return 0;
}

