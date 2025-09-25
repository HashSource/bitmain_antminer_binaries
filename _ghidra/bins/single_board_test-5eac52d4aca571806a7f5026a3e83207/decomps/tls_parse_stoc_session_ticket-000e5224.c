
undefined4 tls_parse_stoc_session_ticket(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((*(code **)(param_1 + 0x584) != (code *)0x0) &&
     (iVar1 = (**(code **)(param_1 + 0x584))
                        (param_1,*param_2,param_2[1],*(undefined4 *)(param_1 + 0x588)), iVar1 == 0))
  {
    ossl_statem_fatal(param_1,0x28,0x248,0x6e,"ssl/statem/extensions_clnt.c",0x58d);
    return 0;
  }
  iVar1 = tls_use_ticket(param_1);
  if (iVar1 == 0) {
    ossl_statem_fatal(param_1,0x6e,0x248,0x6e,"ssl/statem/extensions_clnt.c",0x593);
    return 0;
  }
  if (param_2[1] == 0) {
    *(undefined4 *)(param_1 + 0x55c) = 1;
    return 1;
  }
  ossl_statem_fatal(param_1,0x32,0x248,0x6e,"ssl/statem/extensions_clnt.c",0x598);
  return 0;
}

