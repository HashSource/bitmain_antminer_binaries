
undefined4 ossl_connect_step2(int *param_1,int param_2)

{
  int iVar1;
  ulong e;
  long n;
  char *pcVar2;
  SSL *s;
  SSL_CIPHER *c;
  undefined4 uVar3;
  int iVar4;
  void *local_120;
  int local_11c;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 local_f8;
  
  iVar4 = *param_1;
  ERR_clear_error();
  iVar1 = SSL_connect((SSL *)param_1[param_2 * 6 + 0x62]);
  if (iVar1 != 1) {
    iVar1 = SSL_get_error((SSL *)param_1[param_2 * 6 + 0x62],iVar1);
    if ((iVar1 != 2) && (iVar1 != 3)) {
      local_118 = 0;
      memset(&uStack_114,0,0xfc);
      param_1[param_2 * 6 + 0x60] = 1;
      e = ERR_get_error();
      if ((e & 0xfff) == 0x86 && e >> 0x18 == 0x14) {
        n = SSL_get_verify_result((SSL *)param_1[param_2 * 6 + 0x62]);
        if (n == 0) {
          local_118 = *DAT_00057a84;
          uStack_114 = DAT_00057a84[1];
          uStack_110 = DAT_00057a84[2];
          uStack_10c = DAT_00057a84[3];
          local_108 = DAT_00057a84[4];
          uStack_104 = DAT_00057a84[5];
          uStack_100 = DAT_00057a84[6];
          uStack_fc = DAT_00057a84[7];
          local_f8 = DAT_00057a84[8];
        }
        else {
          pcVar2 = X509_verify_cert_error_string(n);
          curl_msnprintf(&local_118,0x100,DAT_00057a74,pcVar2);
        }
        uVar3 = 0x3c;
      }
      else {
        ERR_error_string_n(e,(char *)&local_118,0x100);
        if (e == 0) {
          Curl_failf(iVar4,DAT_00057a80,param_1[0x26],param_1[0x2d]);
          return 0x23;
        }
        uVar3 = 0x23;
      }
      Curl_failf(iVar4,DAT_00057a78,&local_118);
      return uVar3;
    }
    param_1[param_2 * 6 + 0x60] = iVar1;
    return 0;
  }
  param_1[param_2 * 6 + 0x60] = 4;
  if ((SSL *)param_1[param_2 * 6 + 0x62] == (SSL *)0x0) {
    s = (SSL *)0x0;
    uVar3 = DAT_00057a8c;
  }
  else {
    iVar1 = SSL_version((SSL *)param_1[param_2 * 6 + 0x62]);
    if (iVar1 == 0x301) {
      s = (SSL *)param_1[param_2 * 6 + 0x62];
      uVar3 = DAT_00057aa0;
    }
    else {
      if (iVar1 < 0x302) {
        if (iVar1 == 2) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          uVar3 = DAT_00057aa8;
          goto LAB_000579fe;
        }
        if (iVar1 == 0x300) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          uVar3 = DAT_00057aa4;
          goto LAB_000579fe;
        }
      }
      else {
        if (iVar1 == 0x302) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          uVar3 = DAT_00057aac;
          goto LAB_000579fe;
        }
        if (iVar1 == 0x303) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          uVar3 = DAT_00057a88;
          goto LAB_000579fe;
        }
      }
      s = (SSL *)param_1[param_2 * 6 + 0x62];
      uVar3 = DAT_00057a7c;
    }
  }
LAB_000579fe:
  c = SSL_get_current_cipher(s);
  pcVar2 = SSL_CIPHER_get_name(c);
  Curl_infof(iVar4,DAT_00057a90,uVar3,pcVar2);
  if (*(char *)(iVar4 + 0x43d) != '\0') {
    SSL_get0_alpn_selected(param_1[param_2 * 6 + 0x62],&local_120,&local_11c);
    if (local_11c == 0) {
      Curl_infof(iVar4,DAT_00057a9c);
    }
    else {
      Curl_infof(iVar4,DAT_00057a94,local_11c,local_120);
      if ((local_11c == 8) && (iVar1 = memcmp(DAT_00057a98,local_120,8), iVar1 == 0)) {
        param_1[0x11d] = 2;
      }
    }
  }
  return 0;
}

