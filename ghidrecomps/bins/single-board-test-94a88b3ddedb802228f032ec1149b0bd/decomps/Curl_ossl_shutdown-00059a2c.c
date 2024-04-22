
int Curl_ossl_shutdown(int *param_1,int param_2)

{
  char cVar1;
  ulong e;
  char *pcVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_90 [120];
  
  iVar6 = *param_1;
  if (*(int *)(iVar6 + 800) == 2) {
    SSL_shutdown((SSL *)param_1[param_2 * 6 + 0x62]);
  }
  iVar4 = param_1[param_2 * 6 + 0x62];
  if (iVar4 != 0) {
    while( true ) {
      iVar4 = Curl_socket_check(param_1[param_2 + 0x55],0xffffffff,0xffffffff,10000);
      if (iVar4 < 1) break;
      ERR_clear_error();
      iVar4 = SSL_read((SSL *)param_1[param_2 * 6 + 0x62],acStack_90,0x78);
      iVar4 = SSL_get_error((SSL *)param_1[param_2 * 6 + 0x62],iVar4);
      switch(iVar4) {
      case 0:
      case 6:
        cVar1 = *(char *)(iVar6 + 0x310);
        iVar4 = 0;
        goto joined_r0x00059aaa;
      default:
        e = ERR_get_error();
        iVar5 = *param_1;
        pcVar2 = ERR_error_string(e,acStack_90);
        piVar3 = __errno_location();
        iVar4 = 0;
        Curl_failf(iVar5,DAT_00059b68,pcVar2,*piVar3);
        goto LAB_00059aa6;
      case 2:
        Curl_infof(iVar6,DAT_00059b60);
        break;
      case 3:
        iVar4 = 0;
        Curl_infof(iVar6,DAT_00059b5c);
        goto LAB_00059aa6;
      }
    }
    if (iVar4 == 0) {
      Curl_failf(iVar6,DAT_00059b6c);
      iVar4 = 0;
    }
    else {
      piVar3 = __errno_location();
      iVar4 = -1;
      Curl_failf(iVar6,DAT_00059b70,*piVar3);
    }
LAB_00059aa6:
    cVar1 = *(char *)(iVar6 + 0x310);
joined_r0x00059aaa:
    if (cVar1 != '\0') {
      iVar5 = SSL_get_shutdown((SSL *)param_1[param_2 * 6 + 0x62]);
      if (iVar5 == 2) {
        Curl_infof(iVar6,DAT_00059b74);
      }
      else if (iVar5 == 3) {
        Curl_infof(iVar6,DAT_00059b78);
      }
      else if (iVar5 == 1) {
        Curl_infof(iVar6,DAT_00059b64);
      }
    }
    SSL_free((SSL *)param_1[param_2 * 6 + 0x62]);
    param_1[param_2 * 6 + 0x62] = 0;
  }
  return iVar4;
}

