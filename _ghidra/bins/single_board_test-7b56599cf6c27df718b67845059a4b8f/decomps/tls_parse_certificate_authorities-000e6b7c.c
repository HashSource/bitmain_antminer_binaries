
int tls_parse_certificate_authorities(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = parse_ca_names();
  if ((iVar1 != 0) && (iVar1 = 1, *(int *)(param_2 + 4) != 0)) {
    ossl_statem_fatal(param_1,0x32,0x236,0x6e,"ssl/statem/extensions.c",0x4f7);
    return 0;
  }
  return iVar1;
}

