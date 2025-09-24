
undefined4 tls_parse_ctos_session_ticket(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((*(code **)(param_1 + 0x584) != (code *)0x0) &&
     (iVar1 = (**(code **)(param_1 + 0x584))
                        (param_1,*param_2,param_2[1],*(undefined4 *)(param_1 + 0x588)), iVar1 == 0))
  {
    ossl_statem_fatal(param_1,0x50,0x23e,0x44,"ssl/statem/extensions_srvr.c",0x11a);
    return 0;
  }
  return 1;
}

