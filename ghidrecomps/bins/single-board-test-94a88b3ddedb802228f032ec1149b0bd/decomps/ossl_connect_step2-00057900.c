
undefined4 ossl_connect_step2(int *param_1,int param_2)

{
  int iVar1;
  ulong e;
  long n;
  char *pcVar2;
  SSL *s;
  SSL_CIPHER *c;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  void *local_120;
  int local_11c;
  char local_118 [4];
  undefined4 uStack_114;
  char acStack_110 [4];
  char acStack_10c [4];
  char local_108 [4];
  char acStack_104 [4];
  char acStack_100 [4];
  char acStack_fc [4];
  char local_f8 [228];
  
  iVar5 = *param_1;
  ERR_clear_error();
  iVar1 = SSL_connect((SSL *)param_1[param_2 * 6 + 0x62]);
  if (iVar1 != 1) {
    iVar1 = SSL_get_error((SSL *)param_1[param_2 * 6 + 0x62],iVar1);
    if ((iVar1 != 2) && (iVar1 != 3)) {
      local_118[0] = '\0';
      local_118[1] = '\0';
      local_118[2] = '\0';
      local_118[3] = '\0';
      memset(&uStack_114,0,0xfc);
      param_1[param_2 * 6 + 0x60] = 1;
      e = ERR_get_error();
      if ((e & 0xfff) == 0x86 && e >> 0x18 == 0x14) {
        n = SSL_get_verify_result((SSL *)param_1[param_2 * 6 + 0x62]);
        if (n == 0) {
          local_118[0] = 'S';
          local_118[1] = 'S';
          local_118[2] = 'L';
          local_118[3] = ' ';
          uStack_114._0_1_ = 'c';
          uStack_114._1_1_ = 'e';
          uStack_114._2_1_ = 'r';
          uStack_114._3_1_ = 't';
          acStack_110[0] = 'i';
          acStack_110[1] = 'f';
          acStack_110[2] = 'i';
          acStack_110[3] = 'c';
          acStack_10c[0] = 'a';
          acStack_10c[1] = 't';
          acStack_10c[2] = 'e';
          acStack_10c[3] = ' ';
          local_108[0] = 'v';
          local_108[1] = 'e';
          local_108[2] = 'r';
          local_108[3] = 'i';
          acStack_104[0] = 'f';
          acStack_104[1] = 'i';
          acStack_104[2] = 'c';
          acStack_104[3] = 'a';
          acStack_100[0] = 't';
          acStack_100[1] = 'i';
          acStack_100[2] = 'o';
          acStack_100[3] = 'n';
          acStack_fc[0] = ' ';
          acStack_fc[1] = 'f';
          acStack_fc[2] = 'a';
          acStack_fc[3] = 'i';
          local_f8[0] = 'l';
          local_f8[1] = 'e';
          local_f8[2] = 'd';
          local_f8[3] = '\0';
        }
        else {
          pcVar2 = X509_verify_cert_error_string(n);
          curl_msnprintf(local_118,0x100,"SSL certificate problem: %s",pcVar2);
        }
        uVar4 = 0x3c;
      }
      else {
        ERR_error_string_n(e,local_118,0x100);
        if (e == 0) {
          Curl_failf(iVar5,"Unknown SSL protocol error in connection to %s:%ld ",param_1[0x26],
                     param_1[0x2d]);
          return 0x23;
        }
        uVar4 = 0x23;
      }
      Curl_failf(iVar5,"%s",local_118);
      return uVar4;
    }
    param_1[param_2 * 6 + 0x60] = iVar1;
    return 0;
  }
  param_1[param_2 * 6 + 0x60] = 4;
  if ((SSL *)param_1[param_2 * 6 + 0x62] == (SSL *)0x0) {
    pcVar2 = "";
    s = (SSL *)0x0;
  }
  else {
    iVar1 = SSL_version((SSL *)param_1[param_2 * 6 + 0x62]);
    if (iVar1 == 0x301) {
      s = (SSL *)param_1[param_2 * 6 + 0x62];
      pcVar2 = "TLSv1.0";
    }
    else {
      if (iVar1 < 0x302) {
        if (iVar1 == 2) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          pcVar2 = "SSLv2";
          goto LAB_000579fe;
        }
        if (iVar1 == 0x300) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          pcVar2 = "SSLv3";
          goto LAB_000579fe;
        }
      }
      else {
        if (iVar1 == 0x302) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          pcVar2 = "TLSv1.1";
          goto LAB_000579fe;
        }
        if (iVar1 == 0x303) {
          s = (SSL *)param_1[param_2 * 6 + 0x62];
          pcVar2 = "TLSv1.2";
          goto LAB_000579fe;
        }
      }
      s = (SSL *)param_1[param_2 * 6 + 0x62];
      pcVar2 = "unknown";
    }
  }
LAB_000579fe:
  c = SSL_get_current_cipher(s);
  pcVar3 = SSL_CIPHER_get_name(c);
  Curl_infof(iVar5,"SSL connection using %s / %s\n",pcVar2,pcVar3);
  if (*(char *)(iVar5 + 0x43d) != '\0') {
    SSL_get0_alpn_selected(param_1[param_2 * 6 + 0x62],&local_120,&local_11c);
    if (local_11c == 0) {
      Curl_infof(iVar5,"ALPN, server did not agree to a protocol\n");
    }
    else {
      Curl_infof(iVar5,"ALPN, server accepted to use %.*s\n",local_11c,local_120);
      if ((local_11c == 8) && (iVar1 = memcmp(&DAT_0013ad70,local_120,8), iVar1 == 0)) {
        param_1[0x11d] = 2;
      }
    }
  }
  return 0;
}

