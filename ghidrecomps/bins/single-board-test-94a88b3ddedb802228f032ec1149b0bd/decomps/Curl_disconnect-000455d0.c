
undefined4 Curl_disconnect(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (param_1[0x12] != 0) {
      Curl_resolv_unlock(iVar1);
      param_1[0x12] = 0;
    }
    Curl_hostcache_prune(iVar1);
    Curl_http_ntlm_cleanup(param_1);
    if (*(code **)(param_1[0x86] + 0x30) != (code *)0x0) {
      (**(code **)(param_1[0x86] + 0x30))(param_1,param_2);
    }
    Curl_infof(iVar1,DAT_00045648,param_1[0x11]);
    Curl_conncache_remove_conn(*(undefined4 *)(iVar1 + 0x580),param_1);
    Curl_ssl_close(param_1,0);
    iVar1 = Curl_pipeline_wanted(*(undefined4 *)(iVar1 + 0x40),3);
    if (iVar1 != 0) {
      signalPipeClose_constprop_6(param_1[0x96]);
      signalPipeClose_constprop_6(param_1[0x97]);
    }
    conn_free(param_1);
  }
  return 0;
}

