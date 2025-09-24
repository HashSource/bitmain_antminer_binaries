
int i2d_SSL_SESSION(SSL_SESSION *in,uchar **pp)

{
  ulong uVar1;
  int iVar2;
  uchar **ppuVar3;
  uint *puVar4;
  char *pcVar5;
  SSL_CIPHER *pSVar6;
  ssl_session_st *__s;
  undefined1 local_15d;
  undefined1 local_15c;
  undefined1 local_15b;
  undefined4 local_158 [2];
  undefined1 *local_150;
  undefined4 local_14c;
  uint local_148 [2];
  uchar *local_140;
  undefined4 local_13c;
  undefined4 local_138 [2];
  uchar *local_130;
  undefined4 local_12c;
  undefined4 local_128 [2];
  uchar *local_120;
  undefined4 local_11c;
  undefined4 local_118 [2];
  undefined1 *local_110;
  undefined4 local_10c;
  size_t local_108 [2];
  ssl_session_st *local_100;
  undefined4 local_fc;
  char *local_f8 [2];
  ssl_session_st **local_f0;
  undefined4 local_ec;
  size_t local_e8 [2];
  char *local_e0;
  undefined4 local_dc;
  size_t local_d8 [2];
  char *local_d0;
  undefined4 local_cc;
  size_t local_c8 [2];
  char *local_c0;
  undefined4 local_bc;
  uchar *local_b8 [2];
  uchar **local_b0;
  undefined4 local_ac;
  uint local_a8 [2];
  uint *local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 *local_90;
  undefined4 *local_8c;
  uint *local_88;
  undefined4 *local_84;
  int local_78;
  int iStack_74;
  int local_70;
  int iStack_6c;
  sess_cert_st *local_68;
  undefined4 *local_64;
  long local_60;
  size_t *local_5c;
  size_t local_58;
  undefined4 local_54;
  uchar *local_50;
  char **local_4c;
  size_t *local_48;
  size_t *local_44;
  size_t *local_40;
  undefined4 local_38;
  undefined4 local_34;
  size_t local_30;
  uchar **local_2c;
  uint local_28;
  uint *local_24;
  
  if (in == (SSL_SESSION *)0x0) {
    return 0;
  }
  pSVar6 = in->cipher;
  if (pSVar6 == (SSL_CIPHER *)0x0) {
    uVar1 = in->cipher_id;
    if (uVar1 == 0) {
      return 0;
    }
    memset(&local_98,0,0x78);
    local_94 = in->ssl_version;
  }
  else {
    memset(&local_98,0,0x78);
    uVar1 = pSVar6->algorithm_mkey;
    local_94 = in->ssl_version;
  }
  local_98 = 1;
  local_150 = &local_15c;
  local_15b = (undefined1)uVar1;
  local_15c = (undefined1)(uVar1 >> 8);
  local_90 = local_158;
  local_158[0] = 2;
  local_14c = 0;
  if (in->compress_meth != 0) {
    local_110 = &local_15d;
    local_8c = local_118;
    local_10c = 0;
    local_15d = (undefined1)in->compress_meth;
    local_118[0] = 1;
  }
  local_78 = in->time;
  local_88 = local_148;
  local_70 = in->timeout;
  local_148[0] = in->key_arg_length;
  local_140 = in->session_id;
  iStack_74 = local_78 >> 0x1f;
  local_138[0] = *(undefined4 *)(in->krb5_client_princ + 0xb8);
  iStack_6c = local_70 >> 0x1f;
  local_84 = local_138;
  __s = in->prev;
  local_130 = in->krb5_client_princ + 0xbc;
  local_120 = in->krb5_client_princ + 0xe0;
  local_64 = local_128;
  local_60 = in->verify_result;
  local_128[0] = *(undefined4 *)(in->krb5_client_princ + 0xdc);
  local_68 = in->sess_cert;
  local_13c = 0;
  local_12c = 0;
  local_11c = 0;
  if (__s != (ssl_session_st *)0x0) {
    local_108[0] = strlen((char *)__s);
    local_5c = local_108;
    local_fc = 0;
    local_100 = __s;
  }
  if (in->next != (ssl_session_st **)0x0) {
    local_f8[0] = in->tlsext_hostname;
    local_4c = local_f8;
    local_ec = 0;
    local_f0 = in->next;
  }
  if (in->tlsext_ecpointformatlist_length != 0) {
    local_54 = 0;
    local_58 = in->tlsext_ecpointformatlist_length;
  }
  pcVar5 = in->psk_identity_hint;
  local_50 = in->tlsext_ecpointformatlist;
  if (pcVar5 != (char *)0x0) {
    local_c8[0] = strlen(pcVar5);
    local_bc = 0;
    local_48 = local_c8;
    local_c0 = pcVar5;
  }
  pcVar5 = in->psk_identity;
  if (pcVar5 != (char *)0x0) {
    local_d8[0] = strlen(pcVar5);
    local_cc = 0;
    local_44 = local_d8;
    local_d0 = pcVar5;
  }
  pcVar5 = (char *)in->tlsext_tick_lifetime_hint;
  if (pcVar5 == (char *)0x0) {
    local_40 = (size_t *)0x0;
  }
  else {
    local_e8[0] = strlen(pcVar5);
    local_dc = 0;
    local_40 = local_e8;
    local_e0 = pcVar5;
  }
  ppuVar3 = (uchar **)in->tlsext_ellipticcurvelist;
  local_38 = *(undefined4 *)in[1].key_arg;
  local_30 = in->tlsext_ellipticcurvelist_length;
  local_34 = 0;
  local_2c = ppuVar3;
  if (ppuVar3 != (uchar **)0x0) {
    local_b8[0] = in->tlsext_tick;
    local_2c = local_b8;
    local_ac = 0;
    local_b0 = ppuVar3;
  }
  puVar4 = (uint *)in[1].ssl_version;
  local_28 = (uint)(byte)in->tlsext_ticklen;
  local_24 = puVar4;
  if (puVar4 != (uint *)0x0) {
    local_a8[0] = in[1].key_arg_length;
    local_24 = local_a8;
    local_9c = 0;
    local_a0 = puVar4;
  }
  iVar2 = ASN1_item_i2d((ASN1_VALUE *)&local_98,pp,(ASN1_ITEM *)&SSL_SESSION_ASN1_it);
  return iVar2;
}

